#include <include.h>
extern unsigned char t0_flag;
void delay_100uS(void)
{
//TIMER0 initialize 
//Clock: 8MHz
//WGM: Normal
//Timer0 Prescale£º8
//desired value: 10KHz
//actual value: 10.017KHz (0.2%)
	TCCR0A = 0x00; 
	TCNT0=0x9B;
	TCCR0B = 0x02; //start£¬Prescale£º8
	TIMSK0 = 0x01; //enable timer 0 overflow interrupt
	while (t0_flag == 0);
	t0_flag = 0;
	TCCR0B = 0x00; //stop
	TIMSK0 = 0x00; //disable timer 0 overflow interrupt
}

void delay_mS(unsigned int num_mS)
{
	unsigned int i;
	for (i=0; i<num_mS*10; i++)
		delay_100uS();
}

#pragma interrupt_handler timer0_ovf_isr:iv_TIM0_OVF
void timer0_ovf_isr(void)
{
	t0_flag = 1;
}

