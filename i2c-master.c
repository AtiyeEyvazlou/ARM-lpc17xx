#include "clcd.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_i2c.h"
#include <stdio.h>

int main()
{
		FIO_SetDir(2,0x1,1);
	
		Delay_RIT_Init();
		lcd_init();
		//char* message = "hello!";
		PINSEL_CFG_Type PinCfg;
		PinCfg.Funcnum = 1;
		PinCfg.Pinnum = 27;
		PinCfg.Portnum = 0;
		PINSEL_ConfigPin(&PinCfg);
		PinCfg.Pinnum = 28;
		PINSEL_ConfigPin(&PinCfg);
		
		I2C_M_SETUP_Type transferCfg;
		
		uint8_t data_in[10], temp[10];
		
		char str[20];
		
		transferCfg.sl_addr7bit = 0x1F;
		transferCfg.tx_data = NULL;
		transferCfg.tx_length = 0;
		transferCfg.rx_data = data_in;
		transferCfg.rx_length = 10;
		//transferCfg.retransmissions_max = 2;
	
		I2C_Init(LPC_I2C0, 100000);
		I2C_Cmd(LPC_I2C0, I2C_MASTER_MODE, ENABLE);
		lcd_puts("waiting!");
		Delay_RIT_ms(2000);
		while(1)
		{
			
		
			lcd_clear();
				for(int i = 1;i<sizeof(data_in);i++)
				temp[i-1]=data_in[i];
			if (I2C_MasterTransferData(LPC_I2C0, &transferCfg, I2C_TRANSFER_POLLING)==SUCCESS){
				sprintf(str,"%s",temp);
				FIO_SetValue(2,0x1);
				lcd_puts(str);
			}
		else if (I2C_MasterTransferData(LPC_I2C0, &transferCfg, I2C_TRANSFER_POLLING)!=ERROR){
			lcd_puts("Disconnected");
		}
	
			Delay_RIT_ms(700);
		}
}
