#include <stdio.h>
#include "lpc17xx_pinsel.h"
#include "lcd_4bit.h"
#include "lpc17xx_adc.h"
#include "delay.h"


int main (void)
{	  
		PINSEL_CFG_Type PinCfg;
		char str[100];
		uint16_t ADC_Buf=0;
	
	lcd_init();
	set_cursor(0,0);
	lcd_puts("UTabriz");
	set_cursor(0,1);
	lcd_puts("LPC1768 board");
	
	delay_ms(3000);
	lcd_clear();
	
	
		 /* Init ADC pin connect
	   * AD0.0 on P0.23	 */
	PinCfg.Funcnum = 1;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Pinnum = 23;
	PinCfg.Portnum = 0;
	PINSEL_ConfigPin(&PinCfg);

	 /*  Select: ADC channel 0 
	 *  ADC conversion rate = 200Khz
	 */
	ADC_Init(LPC_ADC, 100000);
	ADC_ChannelCmd (LPC_ADC , ADC_CHANNEL_0, ENABLE);
	while(1)
	{
		ADC_StartCmd(LPC_ADC,ADC_START_NOW);
		
	  while (!(ADC_ChannelGetStatus(LPC_ADC , ADC_CHANNEL_0 , ADC_DATA_DONE))){;}
		   ADC_Buf = ADC_ChannelGetData(LPC_ADC , 0);		
			 lcd_clear();
 			 sprintf(str,"ADC_Buf= %i",ADC_Buf);
       lcd_puts(str);
       delay_ms(1000);
			}

}

