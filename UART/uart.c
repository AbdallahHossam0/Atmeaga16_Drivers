/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: uart.c
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <10 - 11 - 2020>
 *
 * [DESCRIPTION]: <Source file for UART driver>
 * ---------------------------------------------------------------------------------------------------
 */

#include "uart.h"
#define BAUD_PRESCALE (((F_CPU) / ((8UL) * (BAUD_RATE))) - 1)

void UART_init(void){
	/* To enable Double transmission speed*/
	SET_BIT(UCSRA, U2X);

	/*
	 * Set RXEN to enable the receiver
	 * set TXEB to enable the transmitter
	 */
	UCSRB = (1 << RXEN) | (1 << TXEN);

	/*
	 * set URSEL to permit me to write in UCSRC
	 * set UCSZ1 and UCSZ0 to work with 8-bit frame
	 * keep the other bits with 0 to:
	 *
	 * 		disable RX, TX and data register empty interrupts.
	 *
	 */
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
	/* to pass the baud rate to the UBRR register */
	UBRRH = BAUD_PRESCALE >> 8;
	UBRRL = BAUD_PRESCALE;
}
void UART_sendByte(uint8 a_data){
	/*
	 * check if the UDR is ready to receive new data.
	 * if it`s ready pass the data.
	 * if no wait until it is ready.
	 */
	while(BIT_IS_CLEAR(UCSRA, UDRE));
	UDR = a_data;
}
uint8 UART_recieveByte(void){
	/*
	 * check if it has been receive whole data
	 * if yes get the data back
	 * if no wait until the data be ready;
	 */
	while(BIT_IS_CLEAR(UCSRA, RXC));
	return UDR;
}
void UART_sendString(const uint8* str){
	for(; *str != '\0'; ){
		UART_sendByte(*str);
		str++;
	}
	UART_sendByte(END_CHARACTER);

}
void UART_recieveString(uint8* str){
	do{
		*str = UART_recieveByte();
		str++;
	}while(*(str - 1) != END_CHARACTER);
	*(str - 1) = '\0';

}
