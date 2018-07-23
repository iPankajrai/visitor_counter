#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define lcd PORTD
#include<ilibrary/lcd.h>

void main()
{	
	
	DDRA=0b111111111;
	DDRD=0xff;
	DDRB= 0B11111100;
	PORTB=0b00000011;  //pull up
	int count=0;
	while(1)
	{	
		lcd_init();
		lcd_command(0x80);
		lcd_string("VISITORS IN:");
	
		lcd_command(0xc5);
        
		if((PINB & 0b00000001)== 0) 
		{   
			PORTA= 1;  
			while(((PINB & 0b00000010)!=0));
			
		    if((PINB & 0b00000010)==0)
			{   
				PORTA=0x03;
				count++;
		    	lcd_number_infinite(count);	
				while((PINB & 0B00000001)!=0); 
			}	
		 
		}
		 
		 if((PINB & 0b00000010)==0)
		 { 
		 	while(((PINB & 0b00000001)!=0));
		 	if((PINB & 0b00000001)== 0) 
			{
				count--;
				lcd_number_infinite(count);
				
			}	
		
		 }
		
	}
}
