/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: uart.c
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <10 - 11 - 2020>
 *
 * [DESCRIPTION]: <Header file for UART driver>
 * ---------------------------------------------------------------------------------------------------
 */
#ifndef UART_H_
#define UART_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

/*
 * ------------------------------------------------------------------------------------------------
 * 			Preprocessor  Macros
 * ------------------------------------------------------------------------------------------------
 */

/* To define the baud rate */
#define BAUD_RATE 9600
/* Keep receive the string until you find the '#' */
#define END_CHARACTER '#'

/*
 * ------------------------------------------------------------------------------------------------
 * 			Function prototypes
 * ------------------------------------------------------------------------------------------------
 */

void UART_init(void);
void UART_sendByte(uint8 a_data);
uint8 UART_recieveByte(void);
void UART_sendString(const uint8* str);
void UART_recieveString(uint8* str);


#endif /* UART_H_ */
