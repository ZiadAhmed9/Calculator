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

volatile uint32 op1,op2,operation,check;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void calc(uint8 operation,uint32 op1,uint32 op2);		/*this function will calculate result and print it*/
void GET_OP1(void);		/*this function will acquire and display OPERAND1 and the operation*/
void GET_OP2(void);		/*this function will acquire and display OPERAND2*/
//void GET_OPERATION(void);
void restart(void);    /*this function will restart the process*/


/*******************************************************************************
 *                           Main Function                                     *
 *******************************************************************************/

int main(void)
{
	check=0;
	LCD_init();
	KeyPad_init();
	GET_OP1();

	if(check==1)
	{
		main();
	}

//	GET_OPERATION();

	GET_OP2();

	if(check==1)
	{
		main();
	}

	LCD_Clear();

	calc(operation,op1,op2);


	while(1)
	{
		if(KeyPad_getPressedKey()=='A')
		{
			main();
		}



	}
}

void calc(uint8 operation,uint32 op1,uint32 op2)
{
	uint32 result;
	switch(operation)
	{
	case '+' :
		result=op1+op2;
		break;
	case '-' :
		result=op1-op2;
		break;
	case '*' :
		result=op1*op2;
		break;
	case '/' :
		result=op1/op2;
		break;
	}
	if(result>=0&&result<10)
	{
		LCD_integerToString(result);
	}
	else if(result>=10&&result<100)
	{
		LCD_integerToString(result/10);
		LCD_integerToString(result%10);
	}
	else if(result>=100&&result<1000)
	{
		LCD_integerToString(result/100);
		LCD_integerToString((result/10)%10);
		LCD_integerToString(result%10);
	}
	else if(result>=1000&&result<10000)
	{
		LCD_integerToString(result/1000);
		LCD_integerToString((result/100)%10);
		LCD_integerToString((result/10)%10);
		LCD_integerToString(result%10);

	}
	else if(result>=10000&&result<100000)
	{
		LCD_integerToString(result/10000);
		LCD_integerToString((result/1000)%10);
		LCD_integerToString((result/100)%10);
		LCD_integerToString((result/10)%10);
		LCD_integerToString(result%10);

	}

}

void GET_OP1(void)
{
	volatile uint8 key;
	key = KeyPad_getPressedKey(); /* get the pressed key number */
	if(key=='+'||key=='-'||key=='/'||key=='='||key=='A'||key=='*')
	{
		restart();
		return;
	}
	LCD_display_int(key);   /*Display the pressed key*/
	op1=key;
	key = KeyPad_getPressedKey();
	if(key=='+'||key=='-'||key=='/'||key=='*')   /*if the entered digit is an arthimetic operator*/
		{
			_delay_ms(350);
			operation=key;
			return;
		}
	else if(key=='A'||key=='=')
	{
		restart();
		return;
	}
	LCD_display_int(key);
	op1=op1*10+key;
	key = KeyPad_getPressedKey();
	if(key=='+'||key=='-'||key=='/'||key=='*')   /*if the entered digit is an arthimetic operator*/
			{
				_delay_ms(350);
				operation=key;
				return;
			}
	else if(key=='A'||key=='=')
	{
		restart();
		return;
	}
	LCD_display_int(key);
		op1=op1*10+key;
		key = KeyPad_getPressedKey();
		if(key=='+'||key=='-'||key=='/'||key=='*')   /*if the entered digit is an arthimetic operator*/
				{
					_delay_ms(350);
					operation=key;
					return;
				}
}




void GET_OP2(void)
{
	uint8 key;

	key =KeyPad_getPressedKey();
	LCD_Clear();
	if(key=='+'||key=='-'||key=='/'||key=='='||key=='A'||key=='*')
	{
		restart();
		return;
	}
	LCD_display_int(key);   /*Display the pressed key*/
	op2=key;

	key =KeyPad_getPressedKey();
	if(key=='+'||key=='-'||key=='/'||key=='A'||key=='*')
	{
		restart();
		return;
	}
	else if(key=='=')
	{
		return;
	}
	LCD_display_int(key);
	op2=op2*10+key;
	key =KeyPad_getPressedKey();
	if(key=='+'||key=='-'||key=='/'||key=='A'||key=='*')
	{
		restart();
		return;
	}
	else if(key=='=')
	{
		return;
	}
	LCD_display_int(key);
		op2=op2*10+key;
		key =KeyPad_getPressedKey();
		if(key=='+'||key=='-'||key=='/'||key=='A'||key=='*')
		{
			check=1;
			return;
		}
		else if(key=='=')
		{
			return;
		}
}

//void GET_OPERATION(void)
//{
//	uint8 key;
//	key =KeyPad_getPressedKey();
//	LCD_display_int(key);   /*Display the pressed key*/
//	operation=key;
//}

void restart(void)
{
	LCD_Clear();
	check=1;
}


