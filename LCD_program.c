/*
 * LCD.program.c
 *
 *  Created on: Apr 5, 2019
 *      Author: my
 */

/********************************/
/*Author: PHLIMON               */
/*File Name:LCD_program.c       */
/*Component: LCD                */
/*Version: 1.0                  */
/********************************/

/*Delay*/
#include<avr/delay.h>

/*Types*/
#include "STD_TYPES.h"

/*Dependences*/
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"

/*Module*/
#include "LCD_interface.h"
#include "DIO_interface.h"

/*Description:this to set a command for LCD like Clear or any order
  Inputs: Command
  Outputs: No output
*/
void LCD_voidControlState(void)
{
	DIO_u8SetPortDirection(LCD_Data_PORT, 255);
	DIO_u8SetPinDirection(LCD_Control_PORT, LCD_E_PIN, LCD_E_State);
	DIO_u8SetPinDirection(LCD_Control_PORT, LCD_RS_PIN, LCD_RS_State);
	DIO_u8SetPinDirection(LCD_Control_PORT, LCD_RW_PIN, LCD_RW_State);
}

/*Description:this to set a command for LCD like Clear or any order
  Inputs: Command
  Outputs: No output
*/
void LCD_voidWriteCommand(u8 Copy_u8Command)
{
	/*Make Sure Enable Pin is LOW*/
	DIO_u8SetPinValue(LCD_Control_PORT, LCD_E_PIN, DIO_LOW);

	/*RS Register Select 0 command and 1 for data*/
	DIO_u8SetPinValue(LCD_Control_PORT, LCD_RS_PIN, DIO_LOW);

	/*RW Register Select 0 Write and 1 for Read*/
	DIO_u8SetPinValue(LCD_Control_PORT, LCD_RW_PIN, DIO_LOW);

	/*Send Command */
	DIO_u8SetPortValue(LCD_Data_PORT, Copy_u8Command);


	/*Enable Sequence*/
	/*Make Enable Pin HIGH*/
	DIO_u8SetPinValue(LCD_Control_PORT, LCD_E_PIN, DIO_HIGH);
	/*Delay for 2 mSec depend on the data sheet of LCD*/
	_delay_ms(2);
	/*Make Enable Pin LOW*/
	DIO_u8SetPinValue(LCD_Control_PORT, LCD_E_PIN, DIO_LOW);
}

/*Description:this to put the data that we need to print
  Inputs: Command
  Outputs: No output
*/
void LCD_voidWriteData(u8 Copy_u8Data)
{
	/*Make Sure Enable Pin is LOW*/
		DIO_u8SetPinValue(LCD_Control_PORT, LCD_E_PIN, DIO_LOW);

		/*RS Register Select 0 command and 1 for data*/
		DIO_u8SetPinValue(LCD_Control_PORT, LCD_RS_PIN, DIO_HIGH);

		/*RW Register Select 0 Write and 1 for Read*/
		DIO_u8SetPinValue(LCD_Control_PORT, LCD_RW_PIN, DIO_LOW);

		/*Send Command */
		DIO_u8SetPortValue(LCD_Data_PORT, Copy_u8Data);


		/*Enable Sequence*/
		/*Make Enable Pin HIGH*/
		DIO_u8SetPinValue(LCD_Control_PORT, LCD_E_PIN, DIO_HIGH);
		/*Delay for 2 mSec depend on the data sheet of LCD*/
		_delay_ms(2);
		/*Make Enable Pin LOW*/
		DIO_u8SetPinValue(LCD_Control_PORT, LCD_E_PIN, DIO_LOW);
}

/*Description:
  Inputs:
  Outputs:
*/
void LCD_voidIntialization(void)
{
	/*the time needed for LCD to be ready (Data Sheet)*/
	_delay_ms(40);
	/*This function to choose how many lines BIT 5 and font BIT 6 choose 5*11 (1) 5*8(0)*/
	LCD_voidWriteCommand(0b00111000);
	/*Delay for make the previous function */
	_delay_ms(1);
	/*function to Disable or Enable the LCD BIT 6 Cursor on off BIT 7 Cursor Blink BIT8*/
	LCD_voidWriteCommand(0b00001100);
	/*Delay for make the previous function */
	_delay_ms(1);
	/*This Function to Clear LCD*/
	LCD_voidWriteCommand(0b00000001);
	/*Delay for make the previous function */
	_delay_ms(2);
}

/*Description: this to write a word or phrase in once
  Inputs:"The Phrase" which it is an array, size of array
  Outputs:
*/
void LCD_u8WriteString(u8 *Copy_u8String, u8 Copy_u8Size)
{
	u8 Local_u8LoopCtr;

	for(Local_u8LoopCtr = 0; Local_u8LoopCtr < Copy_u8Size; Local_u8LoopCtr++)
	{
		LCD_voidWriteData(Copy_u8String[Local_u8LoopCtr]);
	}
}

/*Description:to change the register AC from DDRAM to CGRAM and accessing to specific location
  Inputs:Position of X and Y
  Outputs:
*/
void LCD_u8GoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8Address;
	/*X position (0-->15) 16 character of LCD + (Y position (0, 1) * 0x40 which the 2nd line began)
	 *+ 128 to add 0b10000000
	*/
	Local_u8Address = Copy_u8XPos + (Copy_u8YPos * 0x40) + 128;

	//Another way
	/*if(Copy_u8YPos == 0)
	{
		Local_u8Address = 0x00 + Copy_u8XPos + 128;
	}
	else if(Copy_u8YPos == 1)
	{
		Local_u8Address = 0x40 + Copy_u8XPos + 128;
	}*/
	LCD_voidWriteCommand(Local_u8Address);
}

/*Description:write or draw what ever you want to show on LCD
  Inputs: array of the draw you want
  Outputs:
*/
void LCD_u8WriteSpecialChar(u8 * SPCHAR)
{
	u8 i;
	LCD_voidWriteCommand(0b01000000);
	for(i = 0; i < 48; i++)
	{
		LCD_voidWriteData(SPCHAR[i]);
	}
}


/*Description: This function to print a Integer number all once
  Inputs:Integer Number, X Position, Y Position
  Outputs:Non
*/
void LCD_voidWriteINT(u16 u16_NB, u8 Position_u8X, u8 Position_u8Y)
{
	u16 temp = 0; //for saving the Integer Number to operate on it without change the original
	/*i for Iteration
	 * NOD number of Digits
	 * NoD for saving number of digits to operate on it without change the original
	 */
	u8 i, NOD = 0, reminder = 0, NoD = 0;

	temp = u16_NB; //saving Integer number in temp

	/*Case of Zero*/
	if(temp == 0)
	{
		LCD_u8GoToXY(Position_u8X, Position_u8Y);
		LCD_voidWriteData(48);
	}

	/*to get the Number of Digits*/
	while(temp != 0)
	{
		temp /= 10;
		NOD++;
	}

	NoD = NOD; //saving number of digits in NoD
	temp = u16_NB; // re-saving the Integer number in temp

	/*to print the Integer number*/
	for(i = 0; i < NoD; i++)
	{
		reminder = temp % 10; //get the once, tens and so on by for loop

		/*geting the value from ASCII Code*/
		switch(reminder)
		{
		case 0:
			if(reminder == 0)
			{
				/*go to the position and print the value of ASCII Code*/
				/*((NoD-=1)+Position_u8X) this to get the ones, tens... position
				 * because we print ones first so we need to write the number
				 * from the right to the left
				 */
				LCD_u8GoToXY(((NOD-=1)+Position_u8X), Position_u8Y);
				LCD_voidWriteData(48);
			}
			break;

		case 1:
			if(reminder == 1)
			{
				LCD_u8GoToXY(((NOD-=1)+Position_u8X), Position_u8Y);
				LCD_voidWriteData(49);
			}
			break;

		case 2:
			if(reminder == 2)
			{
				LCD_u8GoToXY(((NOD-=1)+Position_u8X), Position_u8Y);
				LCD_voidWriteData(50);
			}
			break;

		case 3:
			if(reminder == 3)
			{
				LCD_u8GoToXY(((NOD-=1)+Position_u8X), Position_u8Y);
				LCD_voidWriteData(51);
			}
			break;

		case 4:
			if(reminder == 4)
			{
				LCD_u8GoToXY(((NOD-=1)+Position_u8X), Position_u8Y);
				LCD_voidWriteData(52);
			}
			break;

		case 5:
			if(reminder == 5)
			{
				LCD_u8GoToXY(((NOD-=1)+Position_u8X), Position_u8Y);
				LCD_voidWriteData('5');
			}
			break;

		case 6:
			if(reminder == 6)
			{
				LCD_u8GoToXY(((NOD-=1)+Position_u8X), Position_u8Y);
				LCD_voidWriteData(54);
			}
			break;

		case 7:
			if(reminder == 7)
			{
				LCD_u8GoToXY(((NOD-=1)+Position_u8X), Position_u8Y);
				LCD_voidWriteData(55);
			}
			break;

		case 8:
			if(reminder == 8)
			{
				LCD_u8GoToXY(((NOD-=1)+Position_u8X), Position_u8Y);
				LCD_voidWriteData(56);
			}
			break;

		case 9:
			if(reminder == 9)
			{
				LCD_u8GoToXY(((NOD-=1)+Position_u8X), Position_u8Y);
				LCD_voidWriteData(57);
			}
			break;
		}
		/*deviding temp by 10 to get the tens hundreds thousands and so on every iteration*/
		temp /= 10;
	}
}

void LCD_voidClear(void)
{
	LCD_voidWriteCommand(0b00000001);
	_delay_ms(2);
}
