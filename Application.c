 /******************************************************************************
 *
 * Module: Application
 *
 * File Name: Application.c
 *
 * Description: Application Layer code
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/
#include "LCD.h"
#include "KEYPAD.h"

uint8 calc(uint8 operation,uint8 op1,uint8 op2);


int main(void)
{

	volatile uint8 key,last_val,op1,op2,operation;
	LCD_init();
	KeyPad_init();

	 key = KeyPad_getPressedKey(); /* get the pressed key number */
	 LCD_display_int(key);   /*Display the pressed key*/
	 op1=key;
	 _delay_ms(300);

	 key =KeyPad_getPressedKey();
	 LCD_display_int(key);   /*Display the pressed key*/
	 operation=key;
	 _delay_ms(300);

	 key =KeyPad_getPressedKey();
	 LCD_display_int(key);   /*Display the pressed key*/
	 op2=key;
	 _delay_ms(300);

	 LCD_Clear();
	 LCD_display_int(calc(operation,op1,op2));

	 while(1)
	    {


	    }
}

uint8 calc(uint8 operation,uint8 op1,uint8 op2)
{
	uint8 result;
	switch(operation)
	{
	case '+' :
		result=op1+op2;


	}
	return result;

}



