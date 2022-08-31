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

static void get_OP1(void);
static void get_OP2(void);
volatile uint8 operand1=0;
volatile uint8 operand2=0;
volatile uint8 operator=0;
volatile uint8 result=0;
volatile uint8 check=0;

int main(void)
{
 	LCD_init();
	KeyPad_init();
	get_OP1();
	if(operand1==-1)
	{
		LCD_Clear();
		main();
	}
	_delay_ms(500);
	get_OP2();
	if(operand2==-1)
	{
		LCD_Clear();
		main();
	}
	_delay_ms(500);

	switch(operator)
	{
	case '+':
		result=operand2+operand1+48;
		break;
	}
	LCD_Clear();
	LCD_displayChar(result);


}


void get_OP1(void)
{
	volatile uint8 temp;

	//get first digit

	temp=KeyPad_getPressedKey();
	if(temp=='+'||temp=='-'||temp=='='||temp=='*'||temp=='/'||temp=='A')  //if first digit is number restart
		{
		operand1=-1;
		return ;
		}
	else
	{
		LCD_displayChar(temp);               //display the first digit
		_delay_ms(500);
		operand1=temp-48;
		temp=KeyPad_getPressedKey();         //take second digit
		LCD_displayChar(temp);               //display second digit
		_delay_ms(500);
		if(temp=='+'||temp=='-'||temp=='*'||temp=='/'||temp=='A')        //if it is an arthimetic operator assign it to global variable and return
		{
			operator=temp;
			return;
		}
		else                            //else add it to the existing number
		{
			operand1=(operand1*10)+temp-48;

			temp=KeyPad_getPressedKey();           //only 2 digits in this calculator so the third must be the operator
			if(temp!='+'||temp!='-'||temp!='*'||temp!='/')    //if last input isnot arthimetic operator then restart
			{
				operand1=-1;
				return;                     //RESTART
			}
			else
			{
				LCD_displayChar(temp);
				_delay_ms(500);
				operator=temp;
			}
		}

	}
}



void get_OP2(void)
{
	volatile uint8 temp;

		//get first digit

		temp=KeyPad_getPressedKey();
		if(temp=='+'||temp=='-'||temp=='='||temp=='*'||temp=='/'||temp=='A')  //if first digit is number restart
			{
			operand2=-1;
			return ;
			}
		else
		{
			LCD_displayChar(temp);
			operand2=temp-48;
			temp=KeyPad_getPressedKey();
			if(temp=='+'||temp=='-'||temp=='*'||temp=='/'||temp=='A')
			{
				operand2=-1;
				return;
			}
			else if(temp=='=')
			{
				return;
			}
			else
			{
				LCD_displayChar(temp);
				operand2=(operand2*10)+temp-48;
				temp=KeyPad_getPressedKey();
				if(temp!='=')
				{
					operand2=-1;
					return;
				}
				else
				{
					LCD_displayChar(temp);
					operator=temp;
				}
			}

		}

}


