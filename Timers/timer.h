/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <timer.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <6 - 11 - 2020>
 *
 * [DESCRIPTION]: <The header file for ATMEGA 16 Timers>
 * ---------------------------------------------------------------------------------------------------
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

#define OVERFLOW 0
#define CTC 1
#define PWM 2

/*
 * To be able to control the OC0 PIN to make it OUTPUT PIN
 */
#define TIMER0_OC0_PIN PB3
#define TIMER0_OC0_PORT_DIR DDRB

/*
 * 	Enter 1 to activate the timer, Or keep it 0
 * 	Note that:
 * 				Timer0 is 8-BIT timer
 * 				Timer1 is 16-BIT timer.
 * 				Timer2 is 8-BIT timer
 */
#define TIMER0_ENABLE 1
#define TIMER1_ENABLE 0
#define TIMER2_ENABLE 0

/*
 * 	Enter 0 for Overflow mode
 * 	Enter 1 for CTC mode
 * 	Enter 2 for PWM mode
 */

#define TIMER0_MODE 2
#define TIMER1_MODE 0
#define TIMER2_MODE 0

/*
 * 	To make function Arguments void in overflow mode
 * 	and make it uint8 a_compareValue to be able to set the compare value on it
 */
#if TIMER0_MODE == 0
#define TIMER0_ARG void
#else
#define TIMER0_ARG uint8 a_compareValue
#endif


#if TIMER0_MODE != OVERFLOW
	/*
	 * in case of CTC:
	 * 					set TIMER0_OUTPUT_MODE to 0 for Normal port operation, OC0 disconnected
	 * 					set TIMER0_OUTPUT_MODE to 1 for Toggle OC0 on compare match
	 * 					set TIMER0_OUTPUT_MODE to 2 for Clear OC0 on compare match
	 * 					set TIMER0_OUTPUT_MODE to 3 for Set OC0 on compare match
	 * 	In case of PWM:
	 * 					set TIMER0_OUTPUT_MODE to 0 for Normal port operation, OC0 disconnected.
	 * 					set TIMER0_OUTPUT_MODE to 2 for Clear OC0 on compare match, set OC0 at BOTTOM, (non-inverting mode)
	 * 					set TIMER0_OUTPUT_MODE to 3 for Set OC0 on compare match, clear OC0 at BOTTOM, (inverting mode)
	 */
	#define TIMER0_OUTPUT_MODE 2
#endif
/*
 * 		Set TIMER0_PRESCALER to 0 for No clock source (Timer/Counter stopped).
 * 		Set TIMER0_PRESCALER to 1 for (No prescaling)
 * 		Set TIMER0_PRESCALER to 2 for clkI/8 (From prescaler)
 * 		Set TIMER0_PRESCALER to 3 for clkI/64 (From prescaler)
 * 		Set TIMER0_PRESCALER to 4 for clkI/256 (From prescaler)
 * 		Set TIMER0_PRESCALER to 5 for clkI/1024 (From prescaler)
 * 		Set TIMER0_PRESCALER to 6 for External clock source on T0 pin. Clock on falling edge.
 * 		Set TIMER0_PRESCALER to 7 for External clock source on T0 pin. Clock on rising edge.
 */
#define TIMER0_PRESCALER 4

/*
 * to pass the prototype to the code to be able to use TIMER0
 */
#if TIMER0_ENABLE
	void TIMER0_init(TIMER0_ARG);
#endif

#if TIMER1_ENABLE
	void TIMER1_init(void);
#endif

#if TIMER2_ENABLE
	void TIMER2_init(void);
#endif

#endif /* TIMER_H_ */
