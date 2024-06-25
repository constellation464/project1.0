#include "stm32f10x.h"                  // Device header
#include "motor.h"


void GO_Straight(void)
{
	Motor_SetSpeed_A(40);
	Motor_SetSpeed_B(44);
	Motor_SetSpeed_C(40);
	Motor_SetSpeed_D(39);
}
void GO_Straight_SpeedUp(void)
{
	Motor_SetSpeed_A(80);
	Motor_SetSpeed_B(84);
	Motor_SetSpeed_C(80);
	Motor_SetSpeed_D(89);
}
void Back_Straight(void)
{
	Motor_SetSpeed_A(-40);
	Motor_SetSpeed_B(-44);
	Motor_SetSpeed_C(-40);
	Motor_SetSpeed_D(-39);
}
void Left_Straight(void)
{
	Motor_SetSpeed_A(-40);
	Motor_SetSpeed_B(44);
	Motor_SetSpeed_C(40);
	Motor_SetSpeed_D(-39);
}
void Right_Straight(void)
{
	Motor_SetSpeed_A(40);
	Motor_SetSpeed_B(-44);
	Motor_SetSpeed_C(-40);
	Motor_SetSpeed_D(39);
}
void Right_Turn(void)
{
	Motor_SetSpeed_A(40);
	Motor_SetSpeed_B(-44);
	Motor_SetSpeed_C(40);
	Motor_SetSpeed_D(-39);
}
void Left_Turn(void)
{
	Motor_SetSpeed_A(-40);
	Motor_SetSpeed_B(44);
	Motor_SetSpeed_C(-40);
	Motor_SetSpeed_D(39);
}
void Stop_Motor(void)
{
	Motor_SetSpeed_A(0);
	Motor_SetSpeed_B(0);
	Motor_SetSpeed_C(0);
	Motor_SetSpeed_D(0);
}
