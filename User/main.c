#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Key.h"
#include "encoder.h"
#include "pstwo.h"
#include "usart.h"
#include "control.h"
#include "Servo.h"
#include "PWM_servo.h"
#include "led.h"
//uint8_t KeyNum;
//int8_t Speed;
float Angle;
int main(void)
{	
	
	int PS2_LX,PS2_LY,PS2_RX,PS2_RY,PS2_KEY;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	Encoder_Init();
	OLED_Init();
	LED_Init();
	Servo_Init();
	Motor_Init();
	Key_Init();
	uart_init(115200);	 
	PS2_Init();					
	delay_init();
	OLED_ShowString(1, 1, "SpeedA:");
	OLED_ShowString(2, 1, "SpeedB:");
	OLED_ShowString(3, 1, "SpeedC:");
	OLED_ShowString(4, 1, "SpeedD:");
//	Motor_SetSpeed_A(20);
//	Motor_SetSpeed_B(24);
//	Motor_SetSpeed_C(20);
//	Motor_SetSpeed_D(19);
Servo_SetAngle(0);
	while (1)
	{
		
		PS2_LX=PS2_AnologData(PSS_LX);
		PS2_LY=PS2_AnologData(PSS_LY);
		PS2_RX=PS2_AnologData(PSS_RX);
		PS2_RY=PS2_AnologData(PSS_RY);
		PS2_KEY=PS2_DataKey();
		
		printf("PS2_LX=%d    ",PS2_LX);
		printf("PS2_LY=%d    ",PS2_LY);
		printf("PS2_RX=%d    ",PS2_RX);
		printf("PS2_RY=%d    ",PS2_RY);
		printf("PS2_KEY=%d    \r\n",PS2_KEY);
		delay_ms(80);
		OLED_ShowSignedNum(1,9,Encoder_Get_A(),5);
		OLED_ShowSignedNum(2,9,Encoder_Get_B(),5);
		OLED_ShowSignedNum(3,9,Encoder_Get_C(),5);
		OLED_ShowSignedNum(4,9,Encoder_Get_D(),5);
//		delay_ms(250);
		switch(PS2_KEY)
		{
			case 5://按方向上
				LED1_ON();
			break;
			case 6://按方向zuo
				Left_Straight();
			break;
			case 7://按方向下
				Back_Straight();
			break;
			case 8://按方向yuo
				Right_Straight();
			break;
			case 14://按方向上
				Left_Turn();
			break;
			case 15://按方向上
				GO_Straight_SpeedUp();
			break;
			case 16://按方向上
				Right_Turn();
			break;
			default://不进行按键操作，电机不转
				Stop_Motor();
			break;
		}
	}
//	while (1)
//	{
//		OLED_ShowSignedNum(1,9,Encoder_Get_A(),5);
//		OLED_ShowSignedNum(2,9,Encoder_Get_B(),5);
//		OLED_ShowSignedNum(3,9,Encoder_Get_C(),5);
//		OLED_ShowSignedNum(4,9,Encoder_Get_D(),5);
//		delay_ms(500);
//	}
}
