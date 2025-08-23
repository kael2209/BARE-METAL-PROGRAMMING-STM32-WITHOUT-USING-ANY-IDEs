#include "main.h"
#include <stdio.h>

#define button_pressed  0
#define button_released	1

int red=0,green=0,blue=0;
int state=0;

uint8_t readButton();

int main(void)
{
	RCC_APB2ENR|=(1<<2);
	GPIOA->CRL&=~(0xF<<0);
	GPIOA->CRL|=(8<<0);
	GPIOA->ODR|=(1<<0);
	
	GPIOA->CRH&=~0xFFFF;
	GPIOA->CRH|=0x1111;
	GPIOA->ODR|=0xF<<8;
	for(;;)
	{
		if ((readButton()== button_pressed)&&(state==0))
		{
			state=1;
			red=1;green=0;blue=0;
		}
		else if ((readButton()!= button_pressed)&&(state==1))
		{
			state=2;
		}
		
		if ((readButton()== button_pressed)&&(state==2))
		{
			state=3;
			red=0;green=1;blue=0;
		}
		else if ((readButton()!= button_pressed)&&(state==3))
		{
			state=4;
		}
		
		if ((readButton()== button_pressed)&&(state==4))
		{
			state=5;
			red=0;green=0;blue=1;
		}
		else if ((readButton()!= button_pressed)&&(state==5))
		{
			state=6;
		}
		
		if ((readButton()== button_pressed)&&(state==6))
		{
			state=7;
			red=1;green=1;blue=0;
		}
		else if ((readButton()!= button_pressed)&&(state==7))
		{
			state=8;
		}
		if ((readButton()== button_pressed)&&(state==8))
		{
			state=9;
			red=1;green=0;blue=1;
		}
		else if ((readButton()!= button_pressed)&&(state==9))
		{
			state=10;
		}
		if ((readButton()== button_pressed)&&(state==10))
		{
			state=11;
			red=0;green=1;blue=1;
		}
		else if ((readButton()!= button_pressed)&&(state==11))
		{
			state=12;
		}
		if ((readButton()== button_pressed)&&(state==12))
		{
			state=13;
			red=1;green=1;blue=1;
		}
		else if ((readButton()!= button_pressed)&&(state==13))
		{
			state=14;
		}
		if ((readButton()== button_pressed)&&(state==14))
		{
			state=15;
			red=0;green=0;blue=0;
		}
		else if ((readButton()!= button_pressed)&&(state==15))
		{
			state=0;
		}
		
		(red) 	? (GPIOA->ODR&=~(1<<8))	:(GPIOA->ODR|=(1<<8));
		(green) ? (GPIOA->ODR&=~(1<<10)):(GPIOA->ODR|=(1<<10));
		(blue) 	? (GPIOA->ODR&=~(1<<11)):(GPIOA->ODR|=(1<<11));
	}
}
uint8_t readButton()
{
	return (GPIOA->IDR&(1<<0))>>0;
}
