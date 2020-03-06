#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f10x.h"

#define LED_G_GPIO_PIN      GPIO_Pin_0			//�̵�
#define LED_G_GPIO_PORT     GPIOB
#define LED_G_GPIO_CLK      RCC_APB2Periph_GPIOB

#define LED_R_GPIO_PIN      GPIO_Pin_5			//���
#define LED_R_GPIO_PORT     GPIOB
#define LED_R_GPIO_CLK      RCC_APB2Periph_GPIOB

#define LED_B_GPIO_PIN      GPIO_Pin_1			//����
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

/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 //���Ϊ�ߵ�ƽ		
#define digitalLo(p,i)		 {p->BRR=i;}	 //����͵�ƽ
#define digitalToggle(p,i) {p->ODR ^=i;} //�����ת״̬


/* �������IO�ĺ� */
#define LED_R_TOGGLE		 digitalToggle(LED_R_GPIO_PORT,LED_R_GPIO_PIN)
#define LED_R_OFF		   digitalHi(LED_R_GPIO_PORT,LED_R_GPIO_PIN)
#define LED_R_ON			   digitalLo(LED_R_GPIO_PORT,LED_R_GPIO_PIN)

#define LED_G_TOGGLE		 digitalToggle(LED_G_GPIO_PORT,LED_G_GPIO_PIN)
#define LED_G_OFF		   digitalHi(LED_G_GPIO_PORT,LED_G_GPIO_PIN)
#define LED_G_ON			   digitalLo(LED_G_GPIO_PORT,LED_G_GPIO_PIN)

#define LED_B_TOGGLE		 digitalToggle(LED_B_GPIO_PORT,LED_B_GPIO_PIN)
#define LED_B_OFF		   digitalHi(LED_B_GPIO_PORT,LED_B_GPIO_PIN)
#define LED_B_ON			   digitalLo(LED_B_GPIO_PORT,LED_B_GPIO_PIN)

/* ������ɫ������߼��÷�ʹ��PWM�ɻ��ȫ����ɫ,��Ч������ */

//��
#define LED_RED  \
					LED_R_ON;\
					LED_G_OFF\
					LED_B_OFF

//��
#define LED_GREEN		\
					LED_R_OFF;\
					LED_G_ON\
					LED_B_OFF

//��
#define LED_BLUE	\
					LED_R_OFF;\
					LED_G_OFF\
					LED_B_ON

					
//��(��+��)					
#define LED_YELLOW	\
					LED_R_ON;\
					LED_G_ON\
					LED_B_OFF
//��(��+��)
#define LED_PURPLE	\
					LED_R_ON;\
					LED_G_OFF\
					LED_B_ON

//��(��+��)
#define LED_CYAN \
					LED_R_OFF;\
					LED_G_ON\
					LED_B_ON
					
//��(��+��+��)
#define LED_WHITE	\
					LED_R_ON;\
					LED_G_ON\
					LED_B_ON
					
//��(ȫ���ر�)
#define LED_RGBOFF	\
					LED_R_OFF;\
					LED_G_OFF\
					LED_B_OFF
void LED_GPIO_Config(void);

#endif /* __BSP_LED_H */

/*
��LED��GPIO��Ϊ PB0
��GPIOB��ʱ��Ϊ RCC_APB2Periph_GPIOB
��� PB5
�̵� PB0
���� PB1
*/
