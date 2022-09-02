 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: KEYPAD.h
 *
 * Description: Keypad Module Header File
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "DIO.h"


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
//In this project I Will use port B as output from MCU and Port D as input to MCU

#define N_col 4
#define N_row 4
#define KEYPAD_PORT_OUT 'B'
#define KEYPAD_PORT_IN 'A'
#define KEYPAD_PORT_Dir 'B'



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
	Function Name        : KeyPad_getPressedKey
	Function Returns     : unsigned char of the value of the pressed key
	Function Arguments   : void
	Function Description : Checks the keypad for inputs and reads its values
*/
uint8 KeyPad_getPressedKey(void);

void KeyPad_init(void);


#endif /* KEYPAD_H_ */
