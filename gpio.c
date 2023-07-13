#include "lpc17xx.h"
#include <lpc17xx_gpio.h>
void delay()
{
   for(uint16_t count=0;count<UINT16_MAX*150;count++)
 	    
	     {
				 
			 }
}
		
int main(){
	GPIO_SetDir(0,0xf,1);
	while(1){
	GPIO_SetValue(0,0xf);
	delay();
	GPIO_ClearValue(0,0xf);
	delay();
	}
}
