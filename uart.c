#include "uart.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

#include "input.h"

static struct {
	uint8_t pos;
	uint8_t ready;
	char buf[6];
} uRaw;

void uartInit(void)
{
	// Set UART prescaler (both UBRR0H and UBRR0L)
	UBRR0 = BAUD_PRESCALE;

	// Set double transmission speed
	UCSR0A = (1<<U2X0);

	// Enable RX complete interrupt and both receiver and transmitter
	UCSR0B = (1<<RXCIE0) | (1<<RXEN0) | (1<<TXEN0);

	// Set frame format (8 data bits, 1 stop bit)
	UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);

	uRaw.pos = 0;
	uRaw.ready = 0;

	return;
}

static void uartWriteByte(uint8_t data)
{
	// Wait for empty transmit buffer
	while (!(UCSR0A & (1<<UDRE0)));

	// Put data into buffer, sends data
	UDR0 = data;

	return;
}

void uartWriteString(char *string)
{
	while(*string)
		uartWriteByte(*string++);

	uartWriteByte('\r');
	uartWriteByte('\n');

	return;
}

ISR (USART_RX_vect)
{
	char ch = UDR0;

	if (ch == '\r' || ch == '\n') {
		if (uRaw.pos)
			uRaw.buf[uRaw.pos] = '\0';
		uRaw.pos = 0;
		uRaw.ready = 1;
	} else {
		if (uRaw.pos < sizeof(uRaw.buf) - 1) {
			uRaw.buf[uRaw.pos] = ch;
			uRaw.pos++;
		}
	}
}

static uint8_t uartParseHex(const char *hexStr)
{
	uint8_t ret = 0;
	uint8_t i;

	char ch;

	for (i = 0; i < 2; i++) {
		ret <<= 4;
		ch = hexStr[i];
		if (ch >= '0' && ch <= '9')
			ret += (ch - ('0' - 0x00));
		else if (ch >= 'A' && ch <= 'F')
			ret += (ch - ('A' - 0x0A));
		else
			return 0xFF;
	}

	return ret;
}

UARTData getUartData(void)
{
	UARTData ret = {UART_CMD_NO, CMD_RC_END};

	if (uRaw.ready) {
		uRaw.ready = 0;
		uartWriteString(uRaw.buf);

		// Check command type
		if (strncmp(&uRaw.buf[0], "RC ", 3) == 0) {
			ret.type = UART_CMD_RC;
			ret.command = uartParseHex(&uRaw.buf[3]);
		}

	}

	return ret;
}
