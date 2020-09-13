//MCU:168PA
//Clock: 8MHz  int RC 
#include <include.h>
extern unsigned char t0_flag;
void port_init(void)
{
	DDRB  = 0x02;  //PB7->IN,PB1->OUT
    PORTB = 0x80;  //PB7->UP-Pull,PB1->LOW
    DDRC  = 0x00;
    PORTC = 0x00;
    DDRD  = 0x00;
    PORTD = 0x00;
}
//TIMER0 initialize
void timer0_init(void)
{
    TCCR0B = 0x00; //stop
    TCNT0 = 0x00; //set count
    TCCR0A = 0x00;
    TIMSK0 = 0x00; //disable timer 0 overflow interrupt
}
//TIMER1 initialize 
void timer1_init(void)
{
    TCCR1A=0xC1; //OCB1 disconnect;OC1A Set OC1A on compare match,clear at BOTTOM (inverting mode)
    TCCR1B=0x08; //fast-PWM,8-bit(Top value 0x00FF);stop no clock source;
	TCCR1C=0x00; 
	TCNT1=0x0000;
	TIMSK1=0x00;// disable timer 1 all interrupts    
}
void init_devices(void)
{
	//stop errant interrupts until set up
	CLI();	//disable all interrupts
	port_init();

	MCUCR = 0x00;
	EICRA = 0x00; //extended ext ints
	EIMSK = 0x00;

	TIMSK0 = 0x00; //timer 0 interrupt sources
	TIMSK1 = 0x00; //timer 1 interrupt sources
	TIMSK2 = 0x00; //timer 2 interrupt sources

	PCMSK0 = 0x00; //pin change mask 0 
	PCMSK1 = 0x00; //pin change mask 1 
	PCMSK2 = 0x00; //pin change mask 2
	PCICR = 0x00; //pin change enable 

	PRR = 0x00;	//power on all peripherals
	SEI();	//enable all interrupts
	timer0_init();
	timer1_init();
}


