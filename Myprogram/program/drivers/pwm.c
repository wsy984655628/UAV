#include "pwm.h"

uint16_t ch=1000;

void PwmInit(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef		TIM_TimeBaseStructure;
	TIM_OCInitTypeDef		TIM_OCInitSTructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,	ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_PinAFConfig(GPIOA,	GPIO_PinSource6,	GPIO_AF_TIM3);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_Init(GPIOA,	&GPIO_InitStructure);
	
	//100Hz
	TIM_TimeBaseStructure.TIM_ClockDivision	= 0;
	TIM_TimeBaseStructure.TIM_CounterMode	=	TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 10000;
	TIM_TimeBaseStructure.TIM_Prescaler	= 84;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
	TIM_OCInitSTructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitSTructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitSTructure.TIM_OutputState= TIM_OutputState_Enable;
	TIM_OCInitSTructure.TIM_Pulse = ch;
	
	TIM_OC1Init(TIM3, &TIM_OCInitSTructure);
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM3, ENABLE);
	
	TIM_Cmd(TIM3, ENABLE);
	
	

}
