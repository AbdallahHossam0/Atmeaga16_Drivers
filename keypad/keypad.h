/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <ksyPad.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <30 - 10 -2020>
 *
 * [DESCRIPTION]: <Header file for keypad driver>
 * ---------------------------------------------------------------------------------------------------
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

#define COLUMNS 4
#define ROWS 4
#define calc 1

#define KEYPAD_PORT_DIR DDRA
#define KEYPAD_PORT_OUT PORTA
#define KEYPAD_PORT_IN PINA

uint8 KEYPAD_getPressedKey(void);


#endif /* KEYPAD_H_ */
