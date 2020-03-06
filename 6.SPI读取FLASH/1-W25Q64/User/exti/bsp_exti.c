#include "bsp_exti.h"

static void EXTI_NVIC_Config()
{
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);			//配置分组
	
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;			//选择EXTI0的通道，此处必须精准，使用PIN0，则打开EXTI0_IRQn，去stm32f10x.h中找
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;	//配置抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;			//配置子优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;			//使能	
	NVIC_Init(&NVIC_InitStruct);
	
	//KEY2
	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_Init(&NVIC_InitStruct);	
	
}

void EXTI_KEY_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct;	
	EXTI_InitTypeDef EXTI_InitStruct;
	
	//配置中断优先级
	EXTI_NVIC_Config();
	
	//初始化GPIO
	RCC_APB2PeriphClockCmd(KEY_INT_GPIO_CLK | KEY2_INT_GPIO_CLK, ENABLE);     //打开时钟	
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = KEY_INT_GPIO_PIN;	
	
	GPIO_Init(KEY_INT_GPIO_PORT, &GPIO_InitStruct);
	
	//KEY2
	GPIO_InitStruct.GPIO_Pin = KEY2_INT_GPIO_PIN;
	GPIO_Init(KEY2_INT_GPIO_PORT, &GPIO_InitStruct);

	
	//初始化EXTI
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);     //打开时钟	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);	//选择GPIO端口


	
	EXTI_InitStruct.EXTI_Line = EXTI_Line0;					//LINE0,因为是PIN0
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;		//中断模式
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;		//上升沿触发
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;					//使能
	
	EXTI_Init(&EXTI_InitStruct);
	
	//KEY2
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource13);	//选择GPIO端口	
	EXTI_InitStruct.EXTI_Line = EXTI_Line13;
	EXTI_Init(&EXTI_InitStruct);

}

/*
void EXTI_KEY_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct;	
	EXTI_InitTypeDef EXTI_InitStruct;
	
	//配置中断优先级
	EXTI_NVIC_Config();
	
	//初始化GPIO
	RCC_APB2PeriphClockCmd(KEY_INT_GPIO_CLK, ENABLE);     //打开时钟	
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = KEY_INT_GPIO_PIN;	
	
	GPIO_Init(KEY_INT_GPIO_PORT, &GPIO_InitStruct);
	
	//初始化EXTI
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);     //打开时钟	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);	//选择GPIO端口
	
	EXTI_InitStruct.EXTI_Line = EXTI_Line0;					//LINE0,因为是PIN0
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;		//中断模式
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;		//上升沿触发
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;					//使能
	
	EXTI_Init(&EXTI_InitStruct);
}
*/


