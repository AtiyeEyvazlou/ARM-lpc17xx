#include "lpc17xx_gpio.h"
#include "lpc17xx_pinsel.h"
#include "delay.h"


int main (void)
{	  
	
		PINSEL_CFG_Type PinCfg;

		GPIO_SetDir(0, 0x00000001, 0);
		GPIO_SetDir(2, 0x00000001, 1);
		
		PinCfg.Portnum=0;
		PinCfg.Pinnum=0;
		PinCfg.Pinmode=PINSEL_PINMODE_PULLUP;
		PinCfg.Funcnum = 0;
		PinCfg.OpenDrain = 0;
		PINSEL_ConfigPin (&PinCfg);

  while(1)
  {
		
		if ( ( GPIO_ReadValue(0) & 0x00000001) == 0)
		{
				GPIO_SetValue(2,0x00000001);
			  delay_ms(10000);
			  GPIO_ClearValue(2,0x00000001);
		}
			
				
	}
}

