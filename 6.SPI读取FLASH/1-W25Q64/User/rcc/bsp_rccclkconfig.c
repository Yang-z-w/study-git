#include "bsp_rccclkconfig.h"

void HSE_SetSysClk(uint32_t RCC_PLLMul_x)
{
	ErrorStatus	HSEStatus;
	
	//��RCC�Ĵ�����λ�ɸ�λֵ
	RCC_DeInit();
		
	//ʹ�� HSE
	RCC_HSEConfig(RCC_HSE_ON);
	
	HSEStatus = RCC_WaitForHSEStartUp();
	
	if(HSEStatus == SUCCESS)
	{
		/*ʹ��Ԥȡָ*/
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		
		//�ӳ� 2 state
		FLASH_SetLatency(FLASH_Latency_2);
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);   			//����HCLK = SYSCLK = 72M
		RCC_PCLK1Config(RCC_HCLK_Div2);				//PCLK1 = HCLK = 36M
		RCC_PCLK2Config(RCC_HCLK_Div1);				//PCLK2 = HCLK/2 = 72M
		
		//PLL��ԴΪHSE����Ƶ����Ϊ9
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_x);
		RCC_PLLCmd(ENABLE);							//ʹ��PLL
		
		//�ȴ�PLL�ȶ�
		while( RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET );
		
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

		while( RCC_GetSYSCLKSource() != 0x08 );
	}
	else
	{
	/*���HSE����ʧ�ܣ��û�������������Ӵ������Ĵ���*/
	}
}
