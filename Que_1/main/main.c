#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>


QueueHandle_t xMsgQueue_1;

void Task_T1(void *pvParameters)
{
    while(1)
    {
        printf("task_T1 is here\n");
       
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task_T2(void *pvParameters)
{
    while(1)
    {
        printf("task_T2 is here\n");
       
        vTaskDelay(2000/ portTICK_PERIOD_MS);
    }
}

void Task_T3(void *pvParameters)
{
    while(1)
    {
        printf("task_T3 is here\n");
       
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}

void Task_T4(void *pvParameters)
{int i =0,count =0;
    printf("task_4 is here to send\n");
    while(1)
    {
        i++;
        count++;
        printf("integer data send = %d\n",i);
        xQueueSend(xMsgQueue_1,&i,portMAX_DELAY);
       if(count > 20)
       {
           printf("Task _T4 deleted \n")
           vTaskDelete(NULL );
       }
       
    }
}
void Task_T5(void *pvParameters)
{ int j=0;
printf("task_5 is here to recceive\n");
    while(1)
    {
        xQueueReceive(xMsgQueue_1,&j,portMAX_DELAY);
        printf("integer data received = %d\n",j);
        
    }
}


void app_main()
{
    xMsgQueue_1 = xQueueCreate( 10,sizeof(int));

    TaskHandle_t xHandle_Task_1 = NULL;
    BaseType_t xReturned_1;
    xReturned_1 = xTaskCreate(Task_T1,"TaskLogT1",2048,NULL,5,&xHandle_Task_1);
    TaskHandle_t xHandle_Task_2 = NULL;
    BaseType_t xReturned_2;
    xReturned_2 = xTaskCreate(Task_T2,"TaskLogT2",2048,NULL,6,&xHandle_Task_2);
    TaskHandle_t xHandle_Task_3 = NULL;
    BaseType_t xReturned_3;
    xReturned_3 = xTaskCreate(Task_T3,"TaskLogT3",2048,NULL,7,&xHandle_Task_3);
    TaskHandle_t xHandle_Task_4 = NULL;
    BaseType_t xReturned_4;
    xReturned_4 = xTaskCreate(Task_T4,"TaskLogT4",2048,NULL,8,&xHandle_Task_4);
    TaskHandle_t xHandle_Task_5 = NULL;
    BaseType_t xReturned_5;
    xReturned_5 = xTaskCreate(Task_T5,"TaskLogT5",2048,NULL,9,&xHandle_Task_5);



    if(xReturned_1 == pdPASS)
    {
        printf("task T1 created\n");
        
    }

    if(xReturned_2 == pdPASS)
    {
        printf("task T2 created\n");
       
    }
    if(xReturned_3 == pdPASS)
    {
        printf("task T3 created\n");
       
    }
    if(xReturned_4 == pdPASS)
    {
        printf("task T4 created\n");
       
    }
    if(xReturned_5 == pdPASS)
    {
        printf("task T5 created\n");
       
    }
}