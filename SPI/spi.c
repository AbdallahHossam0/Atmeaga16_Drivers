/*
 *----------------------------------------------------------------------------
 * [FILE NAME]: spi.c
 *
 * [Author] : Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: Nov 10, 2020
 *
 * [DESCRIPTION]: Source file for SPI [serial Peripheral Interface] driver.
 *----------------------------------------------------------------------------
 */

#include <spi.h>
#define END_CHARACTER '#'

void SPI_initMaster(void){
	SET_BIT(DDRB, PB4);
	SET_BIT(DDRB, PB5);
	SET_BIT(DDRB, PB7);
	CLEAR_BIT(DDRB, PB6);
	SET_BIT(SPCR, SPE);
	SET_BIT(SPCR, MSTR);


}
void SPI_initSlave(void){
	CLEAR_BIT(DDRB, PB4);
	CLEAR_BIT(DDRB, PB5);
	CLEAR_BIT(DDRB, PB7);
	SET_BIT(DDRB, PB6);
	SET_BIT(SPCR, SPE);

}
void SPI_sendByte(uint8 a_data){
	SPDR = a_data;
	while(BIT_IS_CLEAR(SPSR, SPIF));

}
uint8 SPI_receiveByte(void){
	While(BIT_IS_CLEAR(SPSR, SPIF));
	return SPDR;
}
void SPI_sendString(const uint8* str){
	while(*str != '\0'){
		SPI_sendByte(*str);
		str++;
	}
}
void SPI_receiveString(uint8* str){
	do{
		*str = SPI_receiveByte();
		str++;
	}while(*(str - 1) != END_CHARACTER);
	*(str - 1) = '\0';
}
