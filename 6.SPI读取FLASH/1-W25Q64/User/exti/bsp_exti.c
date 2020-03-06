#include "bsp_exti.h"

static void EXTI_NVIC_Config()
{
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);			//���÷���
	
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;			//ѡ��EXTI0��ͨ�����˴����뾫׼��ʹ��PIN0�����EXTI0_IRQn��ȥstm32f10x.h����
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;	//������ռ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;			//���������ȼ�
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;			//ʹ��	
	NVIC_Init(&NVIC_InitStruct);
	
	//KEY2
	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_Init(&NVIC_InitStruct);	
	
}

void EXTI_KEY_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct;	
	EXTI_InitTypeDef EXTI_InitStruct;
	
	//�����ж����ȼ�
	EXTI_NVIC_Config();
	
	//��ʼ��GPIO
	RCC_APB2PeriphClockCmd(KEY_INT_GPIO_CLK | KEY2_INT_GPIO_CLK, ENABLE);     //��ʱ��	
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = KEY_INT_GPIO_PIN;	
	
	GPIO_Init(KEY_INT_GPIO_PORT, &GPIO_InitStruct);
	
	//KEY2
	GPIO_InitStruct.GPIO_Pin = KEY2_INT_GPIO_PIN;
	GPIO_Init(KEY2_INT_GPIO_PORT, &GPIO_InitStruct);

	
	//��ʼ��EXTI
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);     //��ʱ��	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);	//ѡ��GPIO�˿�


	
	EXTI_InitStruct.EXTI_Line = EXTI_Line0;					//LINE0,��Ϊ��PIN0
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;		//�ж�ģʽ
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;		//�����ش���
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;					//ʹ��
	
	EXTI_Init(&EXTI_InitStruct);
	
	//KEY2
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13);	//ѡ��GPIO�˿�	
	EXTI_InitStruct.EXTI_Line = EXTI_Line13;
	EXTI_Init(&EXTI_InitStruct);

}

/*
void EXTI_KEY_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct;	
	EXTI_InitTypeDef EXTI_InitStruct;
	
	//�����ж����ȼ�
	EXTI_NVIC_Config();
	
	//��ʼ��GPIO
	RCC_APB2PeriphClockCmd(KEY_INT_GPIO_CLK, ENABLE);     //��ʱ��	
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = KEY_INT_GPIO_PIN;	
	
	GPIO_Init(KEY_INT_GPIO_PORT, &GPIO_InitStruct);
	
	//��ʼ��EXTI
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);     //��ʱ��	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);	//ѡ��GPIO�˿�
	
	EXTI_InitStruct.EXTI_Line = EXTI_Line0;					//LINE0,��Ϊ��PIN0
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;		//�ж�ģʽ
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;		//�����ش���
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;					//ʹ��
	
	EXTI_Init(&EXTI_InitStruct);
}
*/


