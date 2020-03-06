#include "bsp_led.h"

void LED_GPIO_Config(void)
{


	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK | LED_R_GPIO_CLK | LED_B_GPIO_CLK, ENABLE);     //��ʱ��
	
	GPIO_InitStruct.GPIO_Pin = LED_G_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;	    //���ú���Ϣ������Ĵ���
	
	GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStruct);		//д��Ĵ������˴���GPIOB�ļĴ���

	GPIO_InitStruct.GPIO_Pin = LED_R_GPIO_PIN;
	GPIO_Init(LED_R_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = LED_B_GPIO_PIN;
	GPIO_Init(LED_B_GPIO_PORT, &GPIO_InitStruct);

	/*�ص����е�*/	
	GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
	GPIO_SetBits(LED_R_GPIO_PORT, LED_R_GPIO_PIN);
	GPIO_SetBits(LED_B_GPIO_PORT, LED_B_GPIO_PIN);
	/*����
	�ٶ����Խṹ��Ϊ GPIO_InitTypeDef �� GPIO_InitStruct �������ú����ݣ�����GPIO_Init����
	  д�� LED_G_GPIO_PORT��GPIOB���ļĴ�����	
	�ڴ�ʱ�ӣ��ú��� RCC_APB2PeriphClockCmd
	*/
	
}

