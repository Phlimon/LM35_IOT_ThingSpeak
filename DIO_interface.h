/****************************************************************************/
/*Author: */
/*File Name:*/
/*Component:*/
/*Version:*/
/****************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*PORT Number*/
#define DIO_PORT_0 0
#define DIO_PORT_1 1
#define DIO_PORT_2 2
#define DIO_PORT_3 3

/*PIN Number*/
#define DIO_PIN_0 0
#define DIO_PIN_1 1
#define DIO_PIN_2 2
#define DIO_PIN_3 3
#define DIO_PIN_4 4
#define DIO_PIN_5 5
#define DIO_PIN_6 6
#define DIO_PIN_7 7

/*Directions*/
#define DIO_INPUT  0
#define DIO_OUTPUT 1

/*Value*/
#define DIO_LOW  0
#define DIO_HIGH 1

/*Null Pointer*/
#define NULL_POINTER ((u8*)0) //casting for the pointer

/*Description:set the direction(INPUT, OUTPUT) for specific port
  Inputs: port number, direction
  Outputs: Error State -> 0 No Error
                       -> 1 Error
*/
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNB, u8 Copy_u8Dir);

/*Description:set the direction(INPUT, OUTPUT) for specific pin
  Inputs: port number, pin number, direction
  Outputs: Error State -> 0 No Error
                       -> 1 Error
*/
u8 DIO_u8SetPinDirection(u8 Copy_u8PortNB, u8 Copyu8PinNB, u8 Copy_u8Dir);

/*Description: set the value(HIGH, LOW) for specific port
  Inputs: port number, value(HIGH, LOW) 0b01100110
  Outputs: Error State -> 0 No Error
                       -> 1 Error
*/
u8 DIO_u8SetPortValue(u8 Copy_u8PortNB, u8 Copy_u8Value);

/*Description: set the value(HIGH, LOW) for specific pin
  Inputs: port number, pin value, value(HIGH, LOW)(0, 1)
  Outputs: Error State -> 0 No Error
                       -> 1 Error
*/
u8 DIO_u8SetPinValue(u8 Copy_u8PortNB, u8 Copyu8PinNB, u8 Copy_u8Value);

/*Description: Read a value (HIGH, LOW) of specific port
  Inputs: port number, address of value(HIGH, LOW) because it is a pointer
  Outputs: Error State -> 0 No Error
                       -> 1 Error
*/
u8 DIO_u8GetPortValue(u8 Copy_u8PortNB, u8 *Copy_u8Value);

/*Description: Read a value (HIGH, LOW) of specific pin
  Inputs: port number, pin number, address of value(HIGH, LOW) because it is a pointer
  Outputs: Error State -> 0 No Error
                       -> 1 Error
*/
u8 DIO_u8GetPinValue(u8 Copy_u8PortNB, u8 Copyu8PinNB, u8 *Copy_u8Value);

#endif /* DIO_INTERFACE_H_ */
