#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1|GPIO_Pin_2 | GPIO_Pin_3|GPIO_Pin_4 | GPIO_Pin_5|GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	
	PWM_Init();
}

void Motor_SetSpeed_A(int8_t SpeedA)
{
	if (SpeedA >= 0)
	{
		GPIO_SetBits(GPIOF, GPIO_Pin_0);
		GPIO_ResetBits(GPIOF, GPIO_Pin_1);
		PWM_SetCompare1(SpeedA);
	}
	else
	{
		GPIO_ResetBits(GPIOF, GPIO_Pin_0);
		GPIO_SetBits(GPIOF, GPIO_Pin_1);
		PWM_SetCompare1(-SpeedA);
	}
}
void Motor_SetSpeed_B(int8_t SpeedB)
{
	if (SpeedB >= 0)
	{
		GPIO_SetBits(GPIOF, GPIO_Pin_2);
		GPIO_ResetBits(GPIOF, GPIO_Pin_3);
		PWM_SetCompare2(SpeedB);
	}
	else
	{
		GPIO_ResetBits(GPIOF, GPIO_Pin_2);
		GPIO_SetBits(GPIOF, GPIO_Pin_3);
		PWM_SetCompare2(-SpeedB);
	}
}
void Motor_SetSpeed_C(int8_t SpeedC)
{
	if (SpeedC >= 0)
	{
		GPIO_SetBits(GPIOF, GPIO_Pin_4);
		GPIO_ResetBits(GPIOF, GPIO_Pin_5);
		PWM_SetCompare3(SpeedC);
	}
	else
	{
		GPIO_ResetBits(GPIOF, GPIO_Pin_4);
		GPIO_SetBits(GPIOF, GPIO_Pin_5);
		PWM_SetCompare3(-SpeedC);
	}
}
void Motor_SetSpeed_D(int8_t SpeedD)
{
	if (SpeedD >= 0)
	{
		GPIO_SetBits(GPIOF, GPIO_Pin_6);
		GPIO_ResetBits(GPIOF, GPIO_Pin_7);
		PWM_SetCompare4(SpeedD);
	}
	else
	{
		GPIO_ResetBits(GPIOF, GPIO_Pin_6);
		GPIO_SetBits(GPIOF, GPIO_Pin_7);
		PWM_SetCompare4(-SpeedD);
	}
}
