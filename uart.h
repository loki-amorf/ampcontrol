#ifndef UART_H
#define UART_H

#include "inttypes.h"

#define USART_BAUDRATE 115200UL
#define BAUD_PRESCALE ((F_CPU/(USART_BAUDRATE * 8)) - 1)

void uartInit(void);
void uartWriteString(char *string);

#endif // UART_H
