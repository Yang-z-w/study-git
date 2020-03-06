#include "bsp_rccclkconfig.h"

void HSE_SetSysClk(uint32_t RCC_PLLMul_x)
{
	ErrorStatus	HSEStatus;
	
	//把RCC寄存器复位成复位值
	RCC_DeInit();
		
	//使能 HSE
	RCC_HSEConfig(RCC_HSE_ON);
	
	HSEStatus = RCC_WaitForHSEStartUp();
	
	if(HSEStatus == SUCCESS)
	{
		/*使能预取指*/
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		
		//延迟 2 state
		FLASH_SetLatency(FLASH_Latency_2);
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);   			//配置HCLK = SYSCLK = 72M
		RCC_PCLK1Config(RCC_HCLK_Div2);				//PCLK1 = HCLK = 36M
		RCC_PCLK2Config(RCC_HCLK_Div1);				//PCLK2 = HCLK/2 = 72M
		
		//PLL来源为HSE，倍频因子为9
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_x);
		RCC_PLLCmd(ENABLE);							//使能PLL
		
		//等待PLL稳定
		while( RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET );
		
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

		while( RCC_GetSYSCLKSource() != 0x08 );
	}
	else
	{
	/*如果HSE启动失败，用户可以在这里添加处理错误的代码*/
	}
}
