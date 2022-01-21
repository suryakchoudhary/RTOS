#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

//TaskHandle_t task_1, task_2;
#define BUZZER_PIN 15

void sensor(void *sens)
{
	while(1)
	{
		printf("Sensor is Functioning\n");
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
	vTaskDelete(sensor);
}

void buzzer(void *buz)
{
	esp_rom_gpio_pad_select_gpio(BUZZER_PIN);
	gpio_set_direction(BUZZER_PIN, GPIO_MODE_OUTPUT);
	while(1)
	{ 
		printf("Inside buzzer\n");
		gpio_set_level(BUZZER_PIN, 0);
		vTaskDelay(100/portTICK_PERIOD_MS);
		gpio_set_level(BUZZER_PIN, 1);
		vTaskDelay(100/portTICK_PERIOD_MS);
	}
//	vTaskDelete(buzzer);
}

void app_main()
{
	BaseType_t result;
	result = xTaskCreate(sensor, "Task_1", 1024, NULL, 4, NULL);
	if(result != pdPASS)
	{
		printf("SENSOR TASK NOT CREATED\n");
		exit(-1);
	}

	result = xTaskCreate(buzzer, "Task_2", 1024, NULL, 4, NULL);
	if(result != pdPASS)
	{
		printf("BUZZER TASK NOT CREATED\n");
		exit(-1);
	}
}


