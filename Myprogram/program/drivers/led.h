#ifndef __LED_H__
#define __LED_H__

#include"stm32f4xx.h"

void LED_GPIO_Config(void);

#define ON 0
#define OFF 1

#define LED1(st) if(st)\
					GPIO_SetBits(GPIOC,GPIO_Pin_1); \
				else  \
					GPIO_ResetBits(GPIOC,GPIO_Pin_1);
#endif
				