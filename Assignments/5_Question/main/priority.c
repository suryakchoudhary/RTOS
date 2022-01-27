/*5. Swap the priority and observe the changes in the output. What is your conclusion on the
sequence of printing the messages.*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>


TaskHandle_t xHandle_1;
TaskHandle_t xHandle_2;


void sensortask_1(void *pvparameters)           //swapping the priority
{
	while(1)
	{
		printf("SENSOR TASK  RUNNING\n");
		vTaskDelay(1000/ portTICK_PERIOD_MS);
	}
}
void Alarmtask_1(void *pvparameters)
{

	while(1)
	{
		printf("ALARM TASK  RUNNING\n");

		vTaskDelay(1000/ portTICK_PERIOD_MS);
	}
}
void app_main()
{
	BaseType_t result;

	result=xTaskCreate(sensortask_1,"sensortask_1",1024,NULL,20,&xHandle_1);

	if(result!=pdPASS)
	{
		printf("sensortask not created\n");
	}
	result=xTaskCreate(Alarmtask_1,"Alarmtask_10",1024,NULL,2,&xHandle_2);

	if(result!=pdPASS)
	{
		printf("Alarmtask not created\n");
	}
}
