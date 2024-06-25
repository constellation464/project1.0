#include "stm32f10x.h"                  // Device header
#include "PWM_servo.h"

void Servo_Init(void)
{
	PWM_servo_Init();
}

//void Servo_SetAngle11(float Angle)
//{
//	PWM_SetCompare11(Angle / 180 * 2000 + 500);
//}
//void Servo_SetAngle22(float Angle)
//{
//	PWM_SetCompare22(Angle / 180 * 2000 + 500);
//}
void Servo_SetAngle(float Angle)
{
	PWM_SetCompare33(Angle / 180 * 2000 + 500);
}
//void Servo_SetAngle44(float Angle)
//{
//	PWM_SetCompare44(Angle / 180 * 2000 + 500);
//}

