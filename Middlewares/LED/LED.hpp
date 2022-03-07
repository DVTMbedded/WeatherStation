/*
 *  @file:   LED.hpp
 *  @Author: Denislav Trifonov
 *  @Date:   05.03.2022
 *  @brief: Implementation of the LED interface class.
 *   	    It is using STM HAL library
 */

#pragma once

#include "LEDInterface.hpp"
#include "stm32h7xx_hal.h"

class LED : public LEDInterface {
public:
	LED(GPIO_TypeDef* ledDriver, uint16_t nLedPin);

	void LED_SetState(LED_STATE eState) override;
	void LED_Toggle(void) override;
	LED_STATE LED_GetState(void) override;

private:
GPIO_TypeDef* m_pDriverLED;
uint16_t      m_nPinLED;

LED_STATE m_eState = LED_UNINITIALIZED;

};
