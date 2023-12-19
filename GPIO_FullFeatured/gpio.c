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

#include "gpio.h"

/* Reference to the Data Direction Control Registers */
volatile uint8* const DDR_registers[PORT_MAX_NUMBER] = {&DDRA, &DDRB, &DDRC, &DDRD};
/* Reference to the Data PIN Register (Read and Write to Data Latch) */
volatile uint8* const PIN_registers[PORT_MAX_NUMBER]  = {&PINA , &PINB , &PINC , &PIND};
/* Reference to the Port Status Register  */
volatile uint8* const PORT_registers[PORT_MAX_NUMBER] = {&PORTA, &PORTB, &PORTC, &PORTD};

#if GPIO_PIN_CONFIGURATIONS==CONFIG_ENABLE

std_ReturnType gpio_pin_initialize(const Pin_Cfg_t* const cfg){
	std_ReturnType ret = E_OK;
	ret = gpio_pin_setDirection(cfg, cfg -> dir);
	if(LEVEL_HIGH == cfg -> lvl){
		ret = gpio_pin_set(cfg);
	}
	else{
		ret = gpio_pin_clear(cfg);
	}
	return ret;
}

std_ReturnType gpio_pin_setDirection(const Pin_Cfg_t* const cfg, const PinDirection_t dir){
	std_ReturnType ret = E_OK;
	if(NULL == cfg || cfg -> port > PORT_MAX_NUMBER - 1 || cfg -> pin > PIN_MAX_NUMBER - 1){
		ret = E_NOT_OK;
	}
	else{
		switch(dir){
		case DIR_INPUT:
			CLEAR_BIT(*DDR_registers[cfg -> port], cfg -> pin);
			ret = E_OK;
			break;
		case DIR_OUTPUT:
			SET_BIT(*DDR_registers[cfg -> port], cfg -> pin);
			ret = E_OK;
			break;
		default:
			ret = E_NOT_OK;
			break;
		}
	}
	return ret;
}

std_ReturnType gpio_pin_getDirection(const Pin_Cfg_t* const cfg, PinDirection_t* dir){
	std_ReturnType ret = E_OK;
	if(NULL == cfg || cfg -> port > PORT_MAX_NUMBER - 1 || cfg -> pin > PIN_MAX_NUMBER - 1 || NULL == dir){
		ret = E_NOT_OK;
	}
	else{
		*dir = BIT_IS_SET(*DDR_registers[cfg -> port], cfg -> pin) ? DIR_OUTPUT : DIR_INPUT;
		ret = E_OK;
	}
	return ret;
}

std_ReturnType gpio_pin_set(const Pin_Cfg_t* const cfg){
	std_ReturnType ret = E_OK;
	PinDirection_t dir;
	if(NULL == cfg || cfg -> port > PORT_MAX_NUMBER - 1 || cfg -> pin > PIN_MAX_NUMBER - 1){
		ret = E_NOT_OK;
	}
	else{
		if(gpio_pin_getDirection(cfg, &dir)){
			if(dir == DIR_OUTPUT){
				SET_BIT(*PORT_registers[cfg -> port], cfg -> pin);
			}
			else{
				ret = E_NOT_OK;
			}
		}
		else{
			ret = E_NOT_OK;
		}

	}
	return ret;
}

std_ReturnType gpio_pin_clear(const Pin_Cfg_t* const cfg){
	std_ReturnType ret = E_OK;
	PinDirection_t dir;
	if(NULL == cfg || cfg -> port > PORT_MAX_NUMBER - 1 || cfg -> pin > PIN_MAX_NUMBER - 1){
		ret = E_NOT_OK;
	}
	else{
		if(gpio_pin_getDirection(cfg, &dir)){
			if(dir == DIR_OUTPUT){
				CLEAR_BIT(*PORT_registers[cfg -> port], cfg -> pin);
			}
			else{
				ret = E_NOT_OK;
			}
		}
		else{
			ret = E_NOT_OK;
		}

	}
	return ret;
}

std_ReturnType gpio_pin_toggle(const Pin_Cfg_t* const cfg){
	std_ReturnType ret = E_OK;
	PinDirection_t dir;
	if(NULL == cfg || cfg -> port > PORT_MAX_NUMBER - 1 || cfg -> pin > PIN_MAX_NUMBER - 1){
		ret = E_NOT_OK;
	}
	else{
		if(gpio_pin_getDirection(cfg, &dir)){
			if(dir == DIR_OUTPUT){
				TOGGLE_BIT(*PORT_registers[cfg -> port], cfg -> pin);
			}
			else{
				ret = E_NOT_OK;
			}
		}
		else{
			ret = E_NOT_OK;
		}

	}
	return ret;
}

std_ReturnType gpio_pin_enablePullUp(const Pin_Cfg_t* const cfg){
	std_ReturnType ret = E_OK;
	PinDirection_t dir;
	if(NULL == cfg || cfg -> port > PORT_MAX_NUMBER - 1 || cfg -> pin > PIN_MAX_NUMBER - 1){
		ret = E_NOT_OK;
	}
	else{
		if(gpio_pin_getDirection(cfg, &dir)){
			if(dir == DIR_INPUT){
				SET_BIT(*PORT_registers[cfg -> port], cfg -> pin);
			}
			else{
				ret = E_NOT_OK;
			}
		}
		else{
			ret = E_NOT_OK;
		}

	}
	return ret;
}

std_ReturnType gpio_pin_disablePullUp(const Pin_Cfg_t* const cfg){
	std_ReturnType ret = E_OK;
	PinDirection_t dir;
	if(NULL == cfg || cfg -> port > PORT_MAX_NUMBER - 1 || cfg -> pin > PIN_MAX_NUMBER - 1){
		ret = E_NOT_OK;
	}
	else{
		if(gpio_pin_getDirection(cfg, &dir)){
			if(dir == DIR_INPUT){
				CLEAR_BIT(*PORT_registers[cfg -> port], cfg -> pin);
			}
			else{
				ret = E_NOT_OK;
			}
		}
		else{
			ret = E_NOT_OK;
		}

	}
	return ret;
}

#endif

#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE

std_ReturnType gpio_port_initialize(const Port_t port, const uint8 dir, const uint8 lvl){
	std_ReturnType ret = E_OK;

	return ret;

}

std_ReturnType gpio_port_setDirection(const Port_t port, const uint8 dir){
	std_ReturnType ret = E_OK;
	if(port > PORT_MAX_NUMBER - 1){
		ret = E_NOT_OK;
	}
	else{
		*DDR_registers[port] = dir;
		ret = E_OK;
	}
	return ret;
}

std_ReturnType gpio_port_getDirection(const Port_t port, uint8* const dir){
	std_ReturnType ret = E_OK;
	if(NULL == dir || port > PORT_MAX_NUMBER - 1){
		ret = E_NOT_OK;
	}
	else{
		*dir = *DDR_registers[port];
		ret = E_OK;
	}
	return ret;
}

std_ReturnType gpio_port_setLevel(const Port_t port, const uint8 level){
	std_ReturnType ret = E_OK;
	if(port > PORT_MAX_NUMBER - 1){
		ret = E_NOT_OK;
	}
	else{
		*PORT_registers[port] = level;
		ret = E_OK;
	}
	return ret;
}

std_ReturnType gpio_port_getLevel(const Port_t port, uint8* const level){
	std_ReturnType ret = E_OK;
	if(NULL == level || port > PORT_MAX_NUMBER - 1){
		ret = E_NOT_OK;
	}
	else{
		*level = *PORT_registers[port];
		ret = E_OK;
	}
	return ret;
}

std_ReturnType gpio_port_toggleLevel(const Port_t port){
	std_ReturnType ret = E_OK;
	if(port > PORT_MAX_NUMBER - 1){
		ret = E_NOT_OK;
	}
	else{
		*PORT_registers[port] ^= FULL_PORT_MASK;
		ret = E_OK;
	}
	return ret;
}

#endif
