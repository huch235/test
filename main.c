#include <include.h>
#define key_press 0
#define key_release 1
unsigned char t0_flag=0;

unsigned char key_action(void);

void main(void)
{ 
  init_devices();
  TCNT1=0x0000;
  OCR1A=0x0008;
  TCCR1B|=BIT(CS10); //start timer1
  
  while(1)
  {
    
	/*if(key_action()==key_press)
    {
	    delay_mS(250);
		if(key_action()==key_release)
		  {PORTB^=BIT(PB1);}
	}*/
	  
  }
}

/**********************function********************************/
/*
Description   : detect key action: press OR release(key->PB7,press->Low)
Argument      : 
Return Value  : unsigned char:key_press OR key_release
Note          :  
*/
unsigned char key_action(void)
{   
    unsigned char PINB_PB7;
    PINB_PB7=PINB&BIT(PB7);
    if(PINB_PB7==0)
	{
    	 delay_mS(10);
		 PINB_PB7=PINB&BIT(PB7);
		 if(PINB_PB7==0)
		  {return key_press;} 
	}
	else
	{
    	 delay_mS(10);
		 PINB_PB7=PINB&BIT(PB7);
		 if(PINB_PB7!=0)
		  {return key_release;} 
	}
}