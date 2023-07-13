#include "lpc17xx.h"
#include "lpc17xx_gpio.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_pwm.h"
#include "lpc17xx_adc.h"
#include "clcd.h"
#include "rtl.h"

__task void task1(void);
__task void my_ADC(void);
__task void my_LCD(void);
__task void my_PWM(void);
uint16_t ADC_BUF;

__task void task1 (void)
{
	os_tsk_create(my_ADC ,1);
	os_tsk_create(my_LCD ,2);
	os_tsk_create(my_PWM ,3);
	os_tsk_delete_self();

}

int main(){
	
	
	os_sys_init(task1);
	
	/*************************ADC*************************/
	
	PINSEL_CFG_Type PinCfg;
	PinCfg.Funcnum = 2;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Pinnum = 3;
	PinCfg.Portnum = 0;
	PINSEL_ConfigPin(&PinCfg);

	ADC_Init(LPC_ADC,100000);
	ADC_ChannelCmd(LPC_ADC,ADC_CHANNEL_6,ENABLE);	
	
	/*************************LCD*************************/
	

  lcd_clear();
	lcd_puts("Salam");
	
	/*************************PWM*************************/
	
	 PWM_TIMERCFG_Type pwmTimCfg;
 PWM_MATCHCFG_Type pwmMatch0;	
 PINSEL_CFG_Type  pwmPinsel;
	
	Delay_RIT_Init();
	
 
	pwmTimCfg.PrescaleOption=PWM_TIMER_PRESCALE_TICKVAL;
	pwmTimCfg.PrescaleValue=1;
	PWM_Init(LPC_PWM1,PWM_MODE_TIMER,&pwmTimCfg);

	pwmMatch0.IntOnMatch=DISABLE;
	pwmMatch0.MatchChannel=0;
	pwmMatch0.ResetOnMatch=ENABLE;
	pwmMatch0.StopOnMatch=DISABLE;
	
	PWM_ConfigMatch(LPC_PWM1,&pwmMatch0);
	
	PWM_MatchUpdate(LPC_PWM1,0,100,PWM_MATCH_UPDATE_NOW);
	
	PWM_ChannelCmd(LPC_PWM1,1,ENABLE);
	
	PWM_ResetCounter(LPC_PWM1);
	PWM_CounterCmd(LPC_PWM1,ENABLE);
	
	PWM_Cmd(LPC_PWM1,ENABLE);
	
	pwmPinsel.Funcnum=PINSEL_FUNC_1;
	pwmPinsel.OpenDrain=PINSEL_PINMODE_NORMAL;
	pwmPinsel.Pinmode=PINSEL_PINMODE_TRISTATE;
	pwmPinsel.Pinnum=0;
	pwmPinsel.Portnum=2;
	
	PINSEL_ConfigPin(&pwmPinsel);
	
	
	
	
	return(0);
	
}

__task void my_ADC(void){
	
	
	    ADC_StartCmd(LPC_ADC,ADC_START_NOW);
	
			while(!(ADC_ChannelGetStatus(LPC_ADC,ADC_CHANNEL_6,ADC_DATA_DONE))) {}
			ADC_BUF = ADC_ChannelGetData(LPC_ADC,6);

}
 

__task void my_LCD(void){

while(1)
{
	
	lcd_set_cursor(0,1);
	lcd_printf("Temp is %u",&ADC_BUF);
	
	Delay_RIT_ms(2500);
}
}


__task void my_PWM(void){

	PWM_MatchUpdate(LPC_PWM1,1,100,PWM_MATCH_UPDATE_NOW);
	Delay_RIT_ms(1000);	
	
}
