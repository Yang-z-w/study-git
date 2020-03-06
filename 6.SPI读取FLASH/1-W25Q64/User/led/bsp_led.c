#include "bsp_led.h"

void LED_GPIO_Config(void)
{


	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK | LED_R_GPIO_CLK | LED_B_GPIO_CLK, ENABLE);     //打开时钟
	
	GPIO_InitStruct.GPIO_Pin = LED_G_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;	    //配置好信息，放入寄存器
	
	GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStruct);		//写入寄存器，此处是GPIOB的寄存器

	GPIO_InitStruct.GPIO_Pin = LED_R_GPIO_PIN;
	GPIO_Init(LED_R_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = LED_B_GPIO_PIN;
	GPIO_Init(LED_B_GPIO_PORT, &GPIO_InitStruct);

	/*关掉所有灯*/	
	GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
	GPIO_SetBits(LED_R_GPIO_PORT, LED_R_GPIO_PIN);
	GPIO_SetBits(LED_B_GPIO_PORT, LED_B_GPIO_PIN);
	/*步骤
	①定义以结构体为 GPIO_InitTypeDef 的 GPIO_InitStruct ，并配置好内容，利用GPIO_Init函数
	  写入 LED_G_GPIO_PORT（GPIOB）的寄存器中	
	②打开时钟，用函数 RCC_APB2PeriphClockCmd
	*/
	
}

