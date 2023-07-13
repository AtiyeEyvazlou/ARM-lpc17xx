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
	unsigned int s;
  char p[10];
	
	lcd_init();
	set_cursor(0,0);
	lcd_puts("UTabriz");
	set_cursor(0,1);
	lcd_puts("LPC1768 board");
	
	delay_ms(3000);
	lcd_clear();
	
    while(1){
			for (s=0;s<=10;s++)
			{
         sprintf(p," %i",s);
				 lcd_clear();
         lcd_puts(p);
				delay_ms(3000);
			}
	    set_cursor(0,0);
	    lcd_puts("Test Was Ok");
	    delay_ms(3000);
	    lcd_clear();			
    }
}


