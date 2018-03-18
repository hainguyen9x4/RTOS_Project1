#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
//
#include "user_gpio.h"
#include "user_usart.h"
//
xTaskHandle xTask1Handl;
xTaskHandle xTask1Hand2;
xQueueHandle xQueue;
#define mainSENDER_1 1
#define mainSENDER_2 2
#define mainSENDER_3 3
typedef struct
	{
		int iValue;
		int iMeaning;
	} xData;
 xData xStructsTodend[3]={{100,mainSENDER_1},{200,mainSENDER_2},{300,mainSENDER_3}};
xQueueHandle xGlobleQueue;
 xSemaphoreHandle binary_sem;
 //TASK
void vTaskRecFromUSART1(void *p)
{
	for(;;)
	{
		
	}
}
int main ( void )
{	
	SystemInit();
//Bat dau chuong trinh*********************
	USARTx_Configuration(USART1);
	GPIO_Configuration ();	         
	USARTx_SendString(USART1,"Khoi dong xong he thong\n\r");	
	//xQueue=xQueueCreate(5,sizeof(xData));
	//tao semaphore
	vSemaphoreCreateBinary(binary_sem);
	//tao queue
	xGlobleQueue=xQueueCreate(3,sizeof(int));
	if(xGlobleQueue!=NULL)
	{
		xTaskCreate( vTaskRecFromUSART1, "Task Send", 512, NULL, 1, NULL );
		//xTaskCreate( vTask2, "Task Rec", 512, NULL, 2, NULL );
	}
	else
	{
		USARTx_SendString(USART1,"Creat Queue is fiel\n\r");
	}

	vTaskStartScheduler();	

}

/*********************************************END OF FILE**********************/












