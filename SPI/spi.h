/*
 *----------------------------------------------------------------------------
 * [FILE NAME]: spi.h
 *
 * [Author] : Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: Nov 10, 2020
 *
 * [DESCRIPTION]: Header file for SPI [serial Peripheral Interface] driver.
 *----------------------------------------------------------------------------
 */

#ifndef SPI_H_
#define SPI_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

/*
 * ------------------------------------------------------------------------------------------------
 * 		Function prototypes
 * 	------------------------------------------------------------------------------------------------
 */

void SPI_initMaster(void);
void SPI_initSlave(void);
void SPI_sendByte(uint8 a_data);
uint8 SPI_receiveByte(void);
void SPI_sendString(const uint8* str);
void SPI_receiveString(uint8* str);

#endif /* SPI_H_ */
