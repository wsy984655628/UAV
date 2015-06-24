#include "stm32f4xx_conf.h"
#include "main.h"
#include "led.h"
#include "usart.h"

int main()
{
	LED_GPIO_Config();
	LED1(ON);
	
	USART_DT_Config();
	
	printf("test\r\n");
}
