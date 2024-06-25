#include "stm32f10x.h"                  // Device header

void PWM_servo_Init(void)
{
	TIM_OCInitTypeDef TIM_OCInitStructure;
    GPIO_InitTypeDef    GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
    
    TIM_TimeBaseStructure.TIM_Period = 100-1;
    TIM_TimeBaseStructure.TIM_Prescaler = 36-1;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2 ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;          
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;        
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
   
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);


	TIM_CtrlPWMOutputs(TIM2,ENABLE);
    TIM_Cmd(TIM2, ENABLE);
}


//void PWM_SetCompare11(uint16_t Compare)
//{
//	TIM_SetCompare1(TIM2, Compare);
//}
//void PWM_SetCompare22(uint16_t Compare)
//{
//	TIM_SetCompare2(TIM2, Compare);
//}

void PWM_SetCompare33(uint16_t Compare)
{
	TIM_SetCompare3(TIM2, Compare);
}
//void PWM_SetCompare44(uint16_t Compare)
//{
//	TIM_SetCompare4(TIM2, Compare);
//}
