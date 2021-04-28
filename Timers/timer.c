/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <timer.c>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <6 - 11 - 2020>
 *
 * [DESCRIPTION]: <The source file for ATMEGA 16 Timers>
 * ---------------------------------------------------------------------------------------------------
 */

#include "timer.h"

void TIMER0_init(TIMER0_ARG)
{
	TCNT0 = 0x00;	/* To initialize it with 0 */
	TCCR0 = 0x00;	/* To initialize it with 0 */

	#if TIMER0_MODE == OVERFLOW
		SET_BIT(TCCR0, FOC0);
		/* To make the timer work on OVF mode */
	#else
		#if TIMER0_MODE == CTC
		/* To make the timer work on CTC mode */
			SET_BIT(TCCR0, FOC0);
			SET_BIT(TCCR0, WGM01);
		#elif TIMER0_MODE == PWM
			/* to make the timer work on PWM mode */
			SET_BIT(TCCR0, WGM01);
			SET_BIT(TCCR0, WGM00);
		#endif

		/* in CTC moide and PWM mode i want to pass the input argument to OCR0 to use it*/
		OCR0 = a_compareValue;

		#if TIMER0_OUTPUT_MODE == 1
			#if TIMER0_MODE == CTC
				SET_BIT(TCCR0, COM00);
			#endif
		#elif TIMER0_OUTPUT_MODE == 2
				SET_BIT(TCCR0, COM01);
		#elif TIMER0_OUTPUT_MODE == 3
				SET_BIT(TCCR0, COM00);
				SET_BIT(TCCR0, COM01);
		#endif
	#endif

	/* to choose the prescaler*/
	#if TIMER0_PRESCALER == 0
		CLEAR_BIT(TCCR0, CS00);
		CLEAR_BIT(TCCR0, CS01);
		CLEAR_BIT(TCCR0, CS02);
	#elif TIMER0_PRESCALER == 1
		SET_BIT(TCCR0, CS00);
	#elif TIMER0_PRESCALER == 2
		SET_BIT(TCCR0, CS01);
	#elif TIMER0_PRESCALER == 3
		SET_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS01);
	#elif TIMER0_PRESCALER == 4
		SET_BIT(TCCR0, CS02);
	#elif TIMER0_PRESCALER == 5
		SET_BIT(TCCR0, CS00);
		SET_BIT(TCCR0, CS02);
	#elif TIMER0_PRESCALER == 6
		SET_BIT(TCCR0, CS02);
		SET_BIT(TCCR0, CS01);
	#elif TIMER0_PRESCALER == 7
		SET_BIT(TCCR0, CS02);
		SET_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);
	#endif

	/* to enable TIMER0 interrupts (MIE) */
#if TIMER0_MODE == OVERFLOW
		SET_BIT(TIMSK, TOIE0);
#else
	#if TIMER0_OUTPUT_MODE == 0
		SET_BIT(TIMSK, OCIE0);
#endif
#endif
		/* to make OC0 output PIN */
#if TIMER0_MODE == PWM || TIMER0_MODE ==CTC
#if TIMER0_OUTPUT_MODE != 0
		SET_BIT(TIMER0_OC0_PORT_DIR, TIMER0_OC0_PIN);
#endif
#endif

/* PUT HERE ISR if u want to use them */
}
