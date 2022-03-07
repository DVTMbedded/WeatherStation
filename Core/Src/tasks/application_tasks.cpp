/*
 *  @file:   application_tasks.cpp
 *  @Author: Denislav Trifonov
 *  @Date:   05.03.2022
 *  @brief: all application tasks are defined here
 */


#include "application_tasks.hpp"
#include "LED.hpp"
#include "cmsis_os.h"

void LedsTask(void *argument)
{
	LED* ledObject = static_cast<LED *>(argument);

	while(1)
	{
		if (ledObject)
		{
			ledObject->LED_Toggle();
			vTaskDelay(pdMS_TO_TICKS(500));
		}
	}
}
