/*1. Find what is the task priority numbering for the RTOS you are using. eg. Higher the
number higher the priority or vice-versa. Find the range of priority that can be assigned to
a task for your RTOS.*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>


TaskHandle_t xHandle_1;
TaskHandle_t xHandle_2;


void sensor(void *pvparameters)
{
	while(1)
	{
		printf("SENSOR TASK PRIORITY %d\n",uxTaskPriorityGet(NULL));
		vTaskDelay(1000/ portTICK_PERIOD_MS);
	}
}
void Alarm(void *pvparameters)
{

	while(1)
	{
		printf("ALARM TASK PRIORITY %d\n",uxTaskPriorityGet(NULL));

		vTaskDelay(2000/ portTICK_PERIOD_MS);
	}
}
void app_main()
{
	BaseType_t result;

	result=xTaskCreate(sensor,"sensortask_1",2048,NULL,5,&xHandle_1);

	if(result==pdPASS)
	{
		printf("sensortask created\n");
	}
	result=xTaskCreate(Alarm,"Alarmtask_1",2048,NULL,15,&xHandle_2);

	if(result==pdPASS)
	{
		printf("Alarmtask created\n");
	}
}
