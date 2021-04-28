/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <adc.c>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <31 - 10 - 2020>
 *
 * [DESCRIPTION]: <Source file of ADC(Analog to Digital Converter>
 * ---------------------------------------------------------------------------------------------------
 */


#include "adc.h"
#if INTERRUPT == 1
	/*
	* 	Variable to get the data of ADC from ISR in interrupt mode
	*/
	volatile uint16 g_ADCdata = 0;
#endif

/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]: ADC_init
 *
 * [DESCRIPTION]:	Function to initialize the ADC and SET the Prescaler and
 * 					Enable the ADC and set ADC Interrupt Enable if you working in interrupt mode
 *
 * [Args]:			None
 *
 * [IN]:			None
 *
 * [OUT]:			None
 *
 * [IN / OUT]:		None
 *
 * [RETURNS]:		None
 * ---------------------------------------------------------------------------------------------------
 */

void ADC_init(void){

	ADMUX = 0;

	#if VOLTAGE_REFERENCE == 1
		SET_BIT(ADMUX, REFS0);
	#elif(VOLTAGE_REFERENCE == 2)
		SET_BIT(ADMUX, REFS0);
		SET_BIT(ADMUX, REFS1);
	#endif
	#if(PRESCALER == 2)
		SET_BIT(ADCSRA, ADPS0);
	#elif(PRESCALER == 4)
		SET_BIT(ADCSRA, ADPS1);
	#elif(PRESCALER == 8)
		SET_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS0);
	#elif(PRESCALER == 16)
		SET_BIT(ADCSRA, ADPS2);
	#elif(PRESCALER == 32)
		SET_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS0);
	#elif(PRESCALER == 64)
		SET_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS2);
	#elif(PRESCALER == 128)
		SET_BIT(ADCSRA, ADPS0);
		SET_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS2);
	#endif
	SET_BIT(ADCSRA, ADEN);
#if (INTERRUPT)
		SET_BIT(ADCSRA, ADIE);
#endif
}

/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]:	ADC_readChannel
 *
 * [DESCRIPTION]:	Function to read channel to convert it from analog to digital
 *
 * [Args]:
 *
 * [IN]:			q_channelNum : Channel number the analog data connected to
 *
 * [OUT]:			None
 *
 * [IN / OUT]:		None
 *
 * [RETURNS]:		ADC value in case working with polling
 * 					None in case working with interrupts
 * ---------------------------------------------------------------------------------------------------
 */


VOID_UINT16 ADC_readChannel(uint8 a_channelNum){
	ADMUX = (ADMUX & ~(0x1f)) | (a_channelNum & 0x07);
	SET_BIT(ADCSRA, ADSC);
	#if(INTERRUPT == 0)
		while(BIT_IS_CLEAR(ADCSRA, ADIF));
		SET_BIT(ADCSRA, ADIF);
		return ADC;
	#endif
}

#if(INTERRUPT)
	ISR(ADC_vect){
		PORTB ^= 1;
		g_ADCdata = ADC;
	}
#endif







