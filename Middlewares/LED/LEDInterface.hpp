/*
 *  @file:   LEDInterface.hpp
 *  @Author: Denislav Trifonov
 *  @Date:   05.03.2022
 *  @brief: Interface class for LED component
 */

#pragma once

typedef enum {
	LED_UNINITIALIZED = 0,
	LED_OFF 		  = 1,
	LED_ON  		  = 2
}LED_STATE;

class LEDInterface {

public:
	virtual void LED_SetState(LED_STATE eState) = 0;
	virtual void LED_Toggle(void)               = 0;
	virtual LED_STATE LED_GetState(void) 		= 0;
};
