/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <filename.c here>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <put date>
 *
 * [DESCRIPTION]: <decsription here>
 * ---------------------------------------------------------------------------------------------------
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <avr/io.h>
#include "gpio_cfg.h"
#include "std_types.h"
#include "common_macros.h"

#define  BIT_MASK (1u)
#define FULL_PORT_MASK (0xffu)

#define PIN_MAX_NUMBER  (8u)
#define PORT_MAX_NUMBER      (4u)

#define CONFIG_ENABLE (0x01u)
#define CONFIG_DISABLE (0x00u)

typedef enum{
	LEVEL_LOW = 0,
	LEVEL_HIGH
}PinLevel_t;

typedef enum{
	DIR_INPUT,
	DIR_OUTPUT
}PinDirection_t;


typedef enum{
	PORT_A = 0,
	PORT_B,
	PORT_C,
	PORT_D
}Port_t;

typedef enum{
    PIN_0 = 0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7
}Pin_t;

typedef struct{
	uint8  port: 2;
	uint8  pin: 3;
	uint8  dir:1;
	uint8  lvl:1;
}Pin_Cfg_t;

#if GPIO_PIN_CONFIGURATIONS==CONFIG_ENABLE

std_ReturnType gpio_pin_initialize(const Pin_Cfg_t* const cfg);

std_ReturnType gpio_pin_setDirection(const Pin_Cfg_t* const cfg, const PinDirection_t dir);
std_ReturnType gpio_pin_getDirection(const Pin_Cfg_t* const cfg, PinDirection_t* dir);

std_ReturnType gpio_pin_set(const Pin_Cfg_t* const cfg);
std_ReturnType gpio_pin_clear(const Pin_Cfg_t* const cfg);
std_ReturnType gpio_pin_toggle(const Pin_Cfg_t* const cfg);

std_ReturnType gpio_pin_enablePullUp(const Pin_Cfg_t* const cfg);
std_ReturnType gpio_pin_disablePullUp(const Pin_Cfg_t* const cfg);

#endif

#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE

std_ReturnType gpio_port_initialize(const Port_t port, const uint8 dir, const uint8 lvl);

std_ReturnType gpio_port_setDirection(const Port_t port, const uint8 dir);
std_ReturnType gpio_port_getDirection(const Port_t port, uint8* const dir);

std_ReturnType gpio_port_setLevel(const Port_t port, const uint8 level);
std_ReturnType gpio_port_getLevel(const Port_t port, uint8* const level);

std_ReturnType gpio_port_toggleLevel(const Port_t port);

#endif


#endif


