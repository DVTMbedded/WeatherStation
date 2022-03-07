/*
 *  @file:   LED.cpp
 *  @Author: Denislav Trifonov
 *  @Date:   05.03.2022
 *  @brief: Implementation of the LED interface class
 */

#include "LED.hpp"

LED::LED(GPIO_TypeDef* ledDriver, uint16_t nLedPin) : m_pDriverLED(ledDriver), m_nPinLED(nLedPin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = nLedPin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	if (ledDriver)
	{
		HAL_GPIO_Init(ledDriver, &GPIO_InitStruct);
		HAL_GPIO_WritePin(ledDriver, nLedPin, GPIO_PIN_SET);
		m_eState = LED_OFF;
	}
}

void LED::LED_SetState(LED_STATE eState)
{
	if (m_eState != LED_UNINITIALIZED)
	{
		if (eState == LED_ON)
		{
			HAL_GPIO_WritePin(m_pDriverLED, m_nPinLED, GPIO_PIN_RESET);
		}
		else
		{
			HAL_GPIO_WritePin(m_pDriverLED, m_nPinLED, GPIO_PIN_SET);
		}

		m_eState = eState;
	}
}

void LED::LED_Toggle(void)
{
	if (m_eState != LED_UNINITIALIZED)
	{
		HAL_GPIO_TogglePin(m_pDriverLED, m_nPinLED);
		m_eState = (m_eState == LED_OFF)? LED_ON : LED_OFF;
	}
}

LED_STATE LED::LED_GetState(void)
{
	return m_eState;
}
