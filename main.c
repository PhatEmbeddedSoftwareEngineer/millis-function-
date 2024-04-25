#include "function_millis.h"

int main(void)
{
	unsigned long now=0;
	SetSystem72Mhz();
	ConfigureTimer3();
	RCC->APB2ENR |= (1<<4); // gpioA 
	GPIOC->CRH = 0x44344444; // PC13
	while(1)
	{
		if(millis()-now>=1000)
		{
			now=millis();
			GPIOC->ODR ^= (1<<13);
		}
		
	}
}

