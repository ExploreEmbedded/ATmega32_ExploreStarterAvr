#include <avr/io.h>

#define LED 5
#define SWITCH 3

int main(void)
{
	
	DDRD |= (1<<LED);               // Configure PD5 as output to connect Led
	DDRD &= ~(1<<SWITCH);           // Configure PD3 as input to connect switch
	PORTD = 0x08;					// Enable The PullUps of PORTC.
	while(1)
	{
		
		while(((PIND)&(1<<SWITCH))==0u)     // Read the switch status and display it on Led
		{
			PORTD |= (1<<LED);
		}
		PORTD &= ~(1<<LED);
	}
	return 0;
}

