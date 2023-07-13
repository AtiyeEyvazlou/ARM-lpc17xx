#include <lpc17xx.h>
#include <lpc17xx_gpio.h>
#include <stdio.h>
#include <lcd_4bit.h>



void delay_ms (int Time)
{

    int counter=0;
        while (Time--) 
		{
        for (counter = 0; counter < 5000; counter++);
    }
}

int main(void)
{
	
	lcd_init();
	set_cursor(0,0);
	
	
	lcd_clear();
	
			
	    lcd_puts("Test Was Ok");
			delay_ms(100);
	    
	    		
    
}


