#include "clcd.h"
#include "lpc17xx_pinsel.h"
#include <stdio.h>
#include "lpc17xx_timer.h"

int main()
{
	char* str;
	uint32_t Count;
	PINSEL_CFG_Type pincfg;
	GPIO_SetDir(0,(1<<4),0);
	pincfg.Funcnum = 3;
	pincfg.OpenDrain = 0;
	pincfg.Pinmode = 0;
	pincfg.Pinnum = 4;
	pincfg.Portnum = 0;
	PINSEL_ConfigPin(&pincfg);
	
	TIM_TIMERCFG_Type timercfg;
	timercfg.PrescaleOption=TIM_PRESCALE_TICKVAL;
	timercfg.PrescaleValue=0;
	TIM_Init(LPC_TIM2,TIM_COUNTER_RISING_MODE,&timercfg);
	TIM_Cmd(LPC_TIM2,ENABLE);
	LPC_TIM2->CTCR|=0x01;
	
	
	Delay_RIT_Init();
	lcd_init();
	
	
	while(1)
	{
		lcd_clear();
		Count = LPC_TIM2->TC;
		LPC_TIM2->TC = 0;
		sprintf(str,"F=%d",Count);
		lcd_puts(str);
		Delay_RIT_ms(1000);
	}
	
}


