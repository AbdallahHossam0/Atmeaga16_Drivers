/*
 *----------------------------------------------------------------------------
 * [FILE NAME]: i2c.h
 *
 * [Author] : Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: Nov 13, 2020
 *
 * [DESCRIPTION]: 
 *----------------------------------------------------------------------------
 */

#ifndef I2C_H_
#define I2C_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

/*
 * ------------------------------------------------------------------------------------------------
 * 		Preprocessor Macros
 * ------------------------------------------------------------------------------------------------
 */
/* I2C Status bits in the TWSR Register */
#define TW_START 0x08 				/* Start bit has been sent */
#define TW_REP_START 0x10 			/* Repeated start has been sent */
#define TW_MT_SLA_W_ACK 0x18 		/* Master transmit (write request) (slave address with ack received from the slave) */
#define TW_MT_SLA_R_ACK 0x40 		/* Master transmit (Read request) (slave address with ack received from the slave) */
#define TW_MT_DATA_ACK 0x28 		/* Master transmit data and ack has been received */
#define TW_MR_DATA_ACK 0x50 		/* Master received data and send ack to slave */
#define TW_MR_DATA_NACK 0x58		/* Master received data and don`t send ack to slave */


/* to define the Address if works as a slave */
#define DEVICE_ID 0x01


/*
 * ------------------------------------------------------------------------------------------------
 * 		Function Prototypes
 * ------------------------------------------------------------------------------------------------
 */
void TWI_init(void); 				/* to init TWI */
void TWI_start(void);				/* to send start bit and work as a Maste */
void TWI_stop(void);				/* to send the stop bit and end your work as a master*/
void TWI_write(uint8 a_data);		/* to send the data on the bus */
uint8 TWI_readWithACK(void);		/* read the data and send acknowledgment*/
uint8 TWI_readWithNACK(void);		/* read the data and don't send acknowledgment
									   as a master I tell the slave i don`t read
									   any more stop sending bytes */
uint8 TWI_getStatus(void);			/* To read the status register */
#endif /* I2C_H_ */
