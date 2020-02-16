/*
 * LCD.interface.h
 *
 *  Created on: Apr 5, 2019
 *      Author: my
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_Data_PORT DIO_PORT_2

#define LCD_Control_PORT DIO_PORT_0
#define LCD_RS_PIN DIO_PIN_2
#define LCD_RW_PIN DIO_PIN_3
#define LCD_E_PIN DIO_PIN_4

#define LCD_RS_State DIO_OUTPUT
#define LCD_RW_State DIO_OUTPUT
#define LCD_E_State DIO_OUTPUT

/*Description:this to set a command for LCD like Clear or any order
  Inputs: Command
  Outputs: No output
*/
void LCD_voidControlState(void);

/*Description:
  Inputs:
  Outputs:
*/
void LCD_voidWriteCommand(u8 Copy_u8Command);

/*Description:
  Inputs:
  Outputs:
*/
void LCD_voidWriteData(u8 Copy_u8Data);

/*Description:
  Inputs:
  Outputs:
*/
void LCD_voidIntialization(void);

/*Description:
  Inputs:
  Outputs:
*/
void LCD_u8WriteString(u8 *Copy_u8String, u8 Copy_u8Size);

/*Description:
  Inputs:
  Outputs:
*/
void LCD_u8GoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);

/*Description:
  Inputs:
  Outputs:
*/
void LCD_u8WriteSpecialChar(u8 * SPCHAR);

/*Description:
  Inputs:
  Outputs:
*/
void LCD_voidWriteINT(u16 u16_NB, u8 Position_u8X, u8 Position_u8Y);

/*Description:
  Inputs:
  Outputs:
*/
void LCD_voidClear(void);
#endif /* LCD_INTERFACE_H_ */
