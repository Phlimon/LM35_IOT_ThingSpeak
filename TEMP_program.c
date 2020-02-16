/*
 * TEMP_program.c
 *
 *  Created on: May 23, 2019
 *      Author: my
 */

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
#include "TEMP_interface.h"

/*Description:convert the ADC reading to Temp reading
  Inputs: ADC Reading, Address of Variable to put Temp Reading
  Outputs: Error State -> 0 No Error
                       -> 1 Error
*/
u8 TEMPREATURE(u16 Copy_u16SensorRead, u16 * Copy_u16ActualTemp)
{
	u16 Local_u16Actual;

	/*Convert the Value to Digital*/
	Local_u16Actual = ((Copy_u16SensorRead * 500) / 256);
	Local_u16Actual += (Copy_u16SensorRead * 53)/1000;

	*Copy_u16ActualTemp = Local_u16Actual;
	return 0;
}

/*Description:Print Actual Temp on LCD
  Inputs: Actual Temp reading after conversion
  Outputs: Error State -> 0 No Error
                       -> 1 Error
*/
u8 TempLCDPrint(u16 Copy_u16ActualTemp)
{
	static u16 Local_u16OldTemp;

	/*Write the celisuse Symbole C*/
	LCD_u8GoToXY(9, 1);
	LCD_u8WriteString("C", 1);

	/*Checking to reduce the instability on LCD*/
	if(Local_u16OldTemp != Copy_u16ActualTemp)
	{
		/*Write TEMP: on LCD*/
		LCD_u8GoToXY(0, 0);
		LCD_u8WriteString("TEMP:", 5);

		/*Clear the place to write the new Value*/
		LCD_u8GoToXY(7, 1);
		LCD_u8WriteString("     ", 5);

		/*Write the value of temp*/;
		LCD_voidWriteINT(Copy_u16ActualTemp, 6, 1);
		Local_u16OldTemp = Copy_u16ActualTemp;
	}

	return 0;
}

