#include "lcd_4bit.h"
#include "lpc17xx_adc.h"
#include "lpc17xx_pinsel.h"
#include <stdio.h>
#include <lpc17xx_gpio.h>

void delay_ms (int Time)
{

    int counter=0;
        while (Time--) 
		{
        for (counter = 0; counter < 5000; counter++);
    }
}

int main()
{
	uint16_t ADC_BUF;
	
	
	PINSEL_CFG_Type PinCfg;
	PinCfg.Funcnum = 2;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Pinnum = 3;
	PinCfg.Portnum = 0;
	PINSEL_ConfigPin(&PinCfg);

	ADC_Init(LPC_ADC,100000);
	ADC_ChannelCmd(LPC_ADC,ADC_CHANNEL_6,ENABLE);
	
	lcd_init();
	
		
		while(1)
		{
			ADC_StartCmd(LPC_ADC,ADC_START_NOW);
			while(!(ADC_ChannelGetStatus(LPC_ADC,ADC_CHANNEL_6,ADC_DATA_DONE))) {}
			ADC_BUF = ADC_ChannelGetData(LPC_ADC,6);
			char* str;
			lcd_clear();
			ADC_BUF *=(10000/4096);
			sprintf(str,"R= %d ohm",ADC_BUF);
			lcd_puts(str);
			delay_ms(100);
			
	}
}
