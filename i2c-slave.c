#include "clcd.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_i2c.h"
#include <stdio.h>

int main()
{
	
		Delay_RIT_Init();
		lcd_init();
		
		char str[] ="!!!i2c!!!"; 
		
		PINSEL_CFG_Type PinCfg;
		PinCfg.Funcnum = 1;
		PinCfg.Pinnum = 27;
		PinCfg.Portnum = 0;
		PINSEL_ConfigPin(&PinCfg);
		PinCfg.Pinnum = 28;
		PINSEL_ConfigPin(&PinCfg);
		
	
		uint8_t slavebuff[20];
		uint8_t temp[19];
	
		//I2C_Init(LPC_I2C0, 100000);
		
		I2C_OWNSLAVEADDR_CFG_Type slavecfg;
		slavecfg.SlaveAddrChannel = 0;
		slavecfg.SlaveAddr_7bit = 0x1F;
		
		slavecfg.SlaveAddrMaskValue = 0x01;
		slavecfg.GeneralCallState = ENABLE;
		I2C_SetOwnSlaveAddr(LPC_I2C0, &slavecfg);
	
		I2C_Cmd(LPC_I2C0, I2C_SLAVE_MODE, ENABLE);

	
		I2C_S_SETUP_Type transferCfg;
		transferCfg.tx_data = (uint8_t *) str ;
		transferCfg.tx_length = 10;
		transferCfg.rx_data = NULL;
		transferCfg.rx_length = 0;
		
		lcd_puts("waiting!");
		Delay_RIT_ms(1000);
		
		//I2C_SlaveTransferData(LPC_I2C0,&transferCfg,I2C_TRANSFER_POLLING);
		
		while(1)
		{
			for(int i = 0;i<sizeof(temp);i++)
				temp[i]=NULL;
			
   		I2C_SlaveTransferData(LPC_I2C0,&transferCfg,I2C_TRANSFER_POLLING); 
			
			

			for(int i = 1;i<sizeof(slavebuff);i++)
				temp[i-1]=slavebuff[i];
			lcd_clear();
			//sprintf(str,"%s",temp);
			//*str = I2C_I2DAT_IDLE_CHAR;
			lcd_puts(str);
			//i++;
			//sprintf(str,"ARM %d",i);
			Delay_RIT_ms(1000);

		}
			
		}

