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

void calc(uint8 operation,uint8 op1,uint8 op2);
void GET_OP1(void);
void GET_OP2(void);
//void GET_OPERATION(void);
void restart(void);

volatile uint8 op1,op2,operation,check;

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



	}
}

void calc(uint8 operation,uint8 op1,uint8 op2)
{
	uint8 result;
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
		LCD_display_int(result);
	}
	else if(result>=10&&result<100)
	{
		LCD_display_int(result/10);
		LCD_display_int(result%10);
	}

}

void GET_OP1(void)
{
	volatile int key;
	key = KeyPad_getPressedKey(); /* get the pressed key number */
	if(key=='+'||key=='-'||key=='/'||key=='='||key=='A'||key=='*')
	{
		LCD_Clear();
		check=1;
		return;
	}
	LCD_display_int(key);   /*Display the pressed key*/
	op1=key;
	key = KeyPad_getPressedKey();
	if(key=='+'||key=='-'||key=='/'||key=='*')   /*if the entered digit is an arthimetic operator*/
		{
			LCD_display_int(key);   /*Display the pressed key*/
			operation=key;
			return;
		}
	else if(key=='A'||key=='=')
	{
		check=1;
		return;
	}
	else
	{
	op1=(op1*10)+key;
	key = KeyPad_getPressedKey();
	if(key=='+'||key=='-'||key=='/'||key=='*')   /*if the entered digit is an arthimetic operator*/
			{
				LCD_display_int(key);   /*Display the pressed key*/
				operation=key;
				return;
			}
	}


}

void GET_OP2(void)
{
	uint8 key;
	key =KeyPad_getPressedKey();
	if(key=='+'||key=='-'||key=='/'||key=='='||key=='A'||key=='*')
	{
		restart();
		return;
	}
	LCD_display_int(key);   /*Display the pressed key*/
	op2=key;
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


