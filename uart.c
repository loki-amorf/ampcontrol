#include "uart.h"

#include <avr/io.h>
#include <avr/interrupt.h>

static char buf[5] = "aaaa";
static uint8_t pos = 0;

void uartInit(void)
{
	// Set UART prescaler (both UBRR0H and UBRR0L)
	UBRR0 = BAUD_PRESCALE;

	// Set double transmission speed
	UCSR0A = (1<<U2X0);

	// Enable RX complete interrupt and both receiver and transmitter
	UCSR0B = (1<<RXCIE0) | (1<<RXEN0) | (1<<TXEN0);

	// Set frame format (8data, 2stop)
	UCSR0C = (1<<USBS0) | (1<<UCSZ01) | (1<<UCSZ00);

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
// Write a string to the uart
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

	if (ch == '\r') {
		buf[pos] = '\0';
		pos = 0;
		uartWriteString(buf);
	} else {
		buf[pos] = ch;
		if (pos < sizeof(buf) - 1)
			pos++;
	}
}
