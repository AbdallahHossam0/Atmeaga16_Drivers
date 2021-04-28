/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <adc.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <31 - 10 - 2020>
 *
 * [DESCRIPTION]: <Header file for ADC(Analog to Digital Converter>
 * ---------------------------------------------------------------------------------------------------
 */

/*
 * 		NOTE THAT :
 * 					The ADC must Work with FREQUENCY between 50 KHz to 200 KHz
 */


#ifndef ADC_H_
#define ADC_H_

#include "common_macros.h"
#include "std_types.h"
#include "micro_config.h"



#define INTERRUPT 1
/*
 * 	set it to 0 to work with Polling
 * 	set it to 1 to work with Interrupts
 */
#if INTERRUPT == 1
	/*
	 * 	Variable to get the data of ADC from ISR in interrupt mode
	 */
	extern volatile uint16 g_ADCdata;
#endif
#define VOLTAGE_REFERENCE 0
/*
 * 	set it to 0 to work with AREF PIN
 * 	set it to 1 to work with AVCC
 * 	set it to 2 to work with internal 2.56V
 */

#define PRESCALER 8
/*
 * 		to choose ADC prescaler
 * 		the Available input is {2, 4, 8, 16, 32, 64, 128}
 * 		The ADC must Work with FREQUENCY between 50 KHz to 200 KHz
 */
#if (INTERRUPT == 0)
	/*
	 *	TO make the return type of the function (ADC_readChannel) is (uint16)
	 */
	#define VOID_UINT16 uint16
#elif(INTERRUPT == 1)
	#define VOID_UINT16 void
	/*
	 * TO make the return type of the function (ADC_readChannel) is (void)
	 */
#endif

void ADC_init(void);
VOID_UINT16 ADC_readChannel(uint8 a_channelNum);

#endif /* ADC_H_ */
