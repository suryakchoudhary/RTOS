#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t Handle;
void task(void *tsk)
{
	while(1)
	{
		printf("Task is created\n");
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
	vTaskDelete(NULL);
}

void app_main()
{
	BaseType_t result;
	result = xTaskCreate(task, "taskkkk", 1024, NULL, 4, &Handle);

	if(result == pdPASS)
	{
		printf("Task Created\n");
	}
}
