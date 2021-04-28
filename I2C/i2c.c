/*
 *----------------------------------------------------------------------------
 * [FILE NAME]: i2c.c
 *
 * [Author] : Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: Nov 13, 2020
 *
 * [DESCRIPTION]: 
 *----------------------------------------------------------------------------
 */


#include "i2c.h"

void TWI_init(void){
	/*
	 * To get bit rate = 400 kbps
	 */
	TWSR = 0;
	TWBR = 2;
	/*
	 *  pass the address of this MC if any master slave want to call this MC
	 */
	TWAR = (DEVICE_ID << 1);
	/*
	 * Enable I2C
	 */
	TWCR = 1 << TWEN;
}

void TWI_start(void){
	/*
	 * 	Clear the flag
	 * 	Send the Start BIT
	 * 	Enable I2C
	 */
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while(BIT_IS_CLEAR(TWCR, TWINT));
}
void TWI_stop(void){
	/*
	 * 	Clear the flag
	 * 	Send the stop BIT
	 * 	Enable I2C
	 */
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}
void TWI_write(uint8 a_data){
	/*
	 * 	Put the data in the register
	 */
	TWDR = a_data;
	/*
	 * 	Enable I2C
	 * 	Clear the flag
	 */
	TWCR = (1 << TWEN) | (1 << TWINT);
	/*
	 * 	Wait until I2C finished and make sure that the data is sent successfully
	 */
	while(BIT_IS_CLEAR(TWCR, TWINT));
}
uint8 TWI_readWithACK(void){
	/*
	 * 	Enable the I2C
	 * 	Enable the ACKNOWLEGEMENT
	 * 	Clear the flag
	 */
	TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT);
	/*
	 * 	Wait until I2C finish receiving and set the flag
	 */
	while(BIT_IS_CLEAR(TWCR, TWINT));
	/*
	 * 	Read the data
	 */
	return TWDR;

}
uint8 TWI_readWithNACK(void){
	/*
	 * 	Clear the INT flag
	 * 	Enable the I2C
	 */
	TWCR = (1 << TWEN) | (1 << TWINT);
	/*
	 *	Wait until I2C finish receiving and set the flag
	 */
	while(BIT_IS_CLEAR(TWCR, TWINT));
	/*
	 * Read the data
	 */
	return TWDR;
}

uint8 TWI_getStatus(void){
	/*
	 *  NO need to enable the TWI here (IMPORTANT)---------------
	 *
	 */

	/*
	 * 	anding with 0xf8 to delete the first 3 bits
	 * 	and get the most 5 bits (status bits)
	 */
	return (TWSR & 0xf8);

}
