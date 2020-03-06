#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f10x.h"

#define LED_G_GPIO_PIN      GPIO_Pin_0			//绿灯
#define LED_G_GPIO_PORT     GPIOB
#define LED_G_GPIO_CLK      RCC_APB2Periph_GPIOB

#define LED_R_GPIO_PIN      GPIO_Pin_5			//红灯
#define LED_R_GPIO_PORT     GPIOB
#define LED_R_GPIO_CLK      RCC_APB2Periph_GPIOB

#define LED_B_GPIO_PIN      GPIO_Pin_1			//蓝灯
#define LED_B_GPIO_PORT     GPIOB
#define LED_B_GPIO_CLK      RCC_APB2Periph_GPIOB

#define      ON         1
#define      OFF        0


#define LED_G(a)   if(a)\
						GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);\
				   else GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);

#define LED_R(a)   if(a)\
						GPIO_ResetBits(LED_R_GPIO_PORT, LED_R_GPIO_PIN);\
				   else GPIO_SetBits(LED_R_GPIO_PORT, LED_R_GPIO_PIN);

#define LED_B(a)   if(a)\
						GPIO_ResetBits(LED_B_GPIO_PORT, LED_B_GPIO_PIN);\
				   else GPIO_SetBits(LED_B_GPIO_PORT, LED_B_GPIO_PIN);

/* 直接操作寄存器的方法控制IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 //输出为高电平		
#define digitalLo(p,i)		 {p->BRR=i;}	 //输出低电平
#define digitalToggle(p,i) {p->ODR ^=i;} //输出反转状态


/* 定义控制IO的宏 */
#define LED_R_TOGGLE		 digitalToggle(LED_R_GPIO_PORT,LED_R_GPIO_PIN)
#define LED_R_OFF		   digitalHi(LED_R_GPIO_PORT,LED_R_GPIO_PIN)
#define LED_R_ON			   digitalLo(LED_R_GPIO_PORT,LED_R_GPIO_PIN)

#define LED_G_TOGGLE		 digitalToggle(LED_G_GPIO_PORT,LED_G_GPIO_PIN)
#define LED_G_OFF		   digitalHi(LED_G_GPIO_PORT,LED_G_GPIO_PIN)
#define LED_G_ON			   digitalLo(LED_G_GPIO_PORT,LED_G_GPIO_PIN)

#define LED_B_TOGGLE		 digitalToggle(LED_B_GPIO_PORT,LED_B_GPIO_PIN)
#define LED_B_OFF		   digitalHi(LED_B_GPIO_PORT,LED_B_GPIO_PIN)
#define LED_B_ON			   digitalLo(LED_B_GPIO_PORT,LED_B_GPIO_PIN)

/* 基本混色，后面高级用法使用PWM可混出全彩颜色,且效果更好 */

//红
#define LED_RED  \
					LED_R_ON;\
					LED_G_OFF\
					LED_B_OFF

//绿
#define LED_GREEN		\
					LED_R_OFF;\
					LED_G_ON\
					LED_B_OFF

//蓝
#define LED_BLUE	\
					LED_R_OFF;\
					LED_G_OFF\
					LED_B_ON

					
//黄(红+绿)					
#define LED_YELLOW	\
					LED_R_ON;\
					LED_G_ON\
					LED_B_OFF
//紫(红+蓝)
#define LED_PURPLE	\
					LED_R_ON;\
					LED_G_OFF\
					LED_B_ON

//青(绿+蓝)
#define LED_CYAN \
					LED_R_OFF;\
					LED_G_ON\
					LED_B_ON
					
//白(红+绿+蓝)
#define LED_WHITE	\
					LED_R_ON;\
					LED_G_ON\
					LED_B_ON
					
//黑(全部关闭)
#define LED_RGBOFF	\
					LED_R_OFF;\
					LED_G_OFF\
					LED_B_OFF
void LED_GPIO_Config(void);

#endif /* __BSP_LED_H */

/*
①LED的GPIO口为 PB0
②GPIOB的时钟为 RCC_APB2Periph_GPIOB
红灯 PB5
绿灯 PB0
蓝灯 PB1
*/
