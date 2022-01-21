#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void task_1(void *tsk)
{
	while(1)
	{
		printf("TASK 1 IN PROCESS\n");
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
	vTaskDelete(NULL);
}

void task_2(void *tsk)
{
	while(1)
	{
		printf("TASK 2 IN PROCESS\n");
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
	vTaskDelete(NULL);
}

void app_main()
{
	BaseType_t result;

	result = xTaskCreate(task_1, "Process_1", 1024, NULL, 4, NULL);
	if(result != pdPASS) //pdFAIL
	{
		printf("Task 1 NOT CREATED\n");
	}


	result = xTaskCreate(task_2, "Process_2", 1024, NULL, 4, NULL);
	if(result != pdPASS)
	{
		printf("Task 2 NOT CREATED\n");
	}
}
