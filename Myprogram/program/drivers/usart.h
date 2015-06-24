#ifndef __USART_H__
#define	__USART_H__

#include"stm32f4xx.h"
#include <stdio.h>

void USART_DT_Config(void);
int fputc(int ch, FILE *f);
int fgetc(FILE *f);

#endif

