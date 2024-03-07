#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>

void task1(void * params)
{
	while(true)
	{
		//printf("Leitura de sensores\n");
		ESP_LOGI("TASK1", "Leitura de sensores");
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}

void task2(void * params)
{
	while(true)
	{
		//printf("Escrever no display");
		ESP_LOGI("TASK2", "Escrever no display");
		vTaskDelay(5000 / portTICK_PERIOD_MS);
	}
}

void app_main(void)
{
  xTaskCreate(&task1, "leitura", 2048, "task_1", 1, NULL);
  xTaskCreate(&task2, "display", 2048, "task_2", 1, NULL);

}
