#include "stm32f4xx_conf.h"
#include "main.h"
#include "led.h"
#include "usart.h"
#include "pwm.h"

int main()
{
	LED_GPIO_Config();
	LED1(ON);
	
	USART_DT_Config();
	
	PwmInit();
	
	USART_SendData(USART2, 'A');
	printf(" test \r\n");
//	{
//		uint16_t i;
//		for (i=0; i<USART_SendBuffer_Size; i++)
//		{
//			USART_SendBuffer[i]= 'A' ;
//		}
//	}
//USART_DMACmd(USART2,USART_DMAReq_Tx,ENABLE);
	
}
