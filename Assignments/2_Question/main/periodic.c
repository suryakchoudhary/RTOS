/*2. What is the mechanism used to make a task periodic for the RTOS you are using? Write a
program to make a task periodic with periodicity of 500ms.*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

TaskHandle_t xHandle_1;


void sensortask_1(void *pvparameters)
{
	while(1)
	{
		printf("SENSOR TASK  RUNNING\n");
		vTaskDelay(500/ portTICK_PERIOD_MS);    //periodic task running every 500ms
	}
}

void app_main()
{
	BaseType_t result;

	result=xTaskCreate(sensortask_1,"sensortask_1",2048,NULL,5,&xHandle_1);

	if(result==pdPASS)
	{
		printf("sensortask created\n");
	}

}
