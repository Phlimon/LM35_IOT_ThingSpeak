/********************************/
/*Author: PHLIMON               */
/*File Name:DIO_program.c       */
/*Component: DIO                */
/*Version: 1.0                  */
/********************************/

/*Types*/
#include "STD_TYPES.h"

/*Dependences*/
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"

/*Module*/
#include "DIO_interface.h"

/*Description:set the direction(INPUT, OUTPUT) for specific port
  Inputs: port number, direction
  Outputs: Error State -> 0 No Error
                       -> 1 Error
*/
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNB, u8 Copy_u8Dir)
{
	/*Local Error Variable*/
	u8 Local_u8Error = 0;

	switch(Copy_u8PortNB)
	{
	case DIO_PORT_0:
		DDRA = Copy_u8Dir;
		break;
	case DIO_PORT_1:
		DDRB = Copy_u8Dir;
		break;
	case DIO_PORT_2:
		DDRC = Copy_u8Dir;
		break;
	case DIO_PORT_3:
		DDRD = Copy_u8Dir;
		break;
	default :
		Local_u8Error = 1;
	}
	return Local_u8Error;
}

/*Description: set the value(HIGH, LOW) for specific port
  Inputs: port number, value(HIGH, LOW) 0b01100110
  Outputs: Error State -> 0 No Error
                       -> 1 Error
*/
u8 DIO_u8SetPortValue(u8 Copy_u8PortNB, u8 Copy_u8Value)
{
	/*Local Error Variable*/
	u8 Local_u8Error = 0;

	switch(Copy_u8PortNB)
	{
	case DIO_PORT_0:
		PORTA = Copy_u8Value;
		break;
	case DIO_PORT_1:
		PORTB = Copy_u8Value;
		break;
	case DIO_PORT_2:
		PORTC = Copy_u8Value;
		break;
	case DIO_PORT_3:
		PORTD = Copy_u8Value;
		break;
	default :
		Local_u8Error = 1;
		break;
	}

	return Local_u8Error;
}

/*Description:set the direction(INPUT, OUTPUT) for specific pin
  Inputs: port number, pin number, direction
  Outputs: Error State -> 0 No Error
                       -> 1 Error
*/
u8 DIO_u8SetPinDirection(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Dir)
{
	u8 Local_u8Error = 0;

	if(Copy_u8PinNB > DIO_PIN_7)
	{
		Local_u8Error = 1;
	}
	else if((Copy_u8Dir!=DIO_INPUT)&&(Copy_u8Dir!=DIO_OUTPUT))
	{
		Local_u8Error = 1;
	}
	else
	{
		switch(Copy_u8PortNB)
		{
		case DIO_PORT_0:
			ASSIGN_BIT(DDRA,Copy_u8PinNB, Copy_u8Dir);
			break;
		case DIO_PORT_1:
			ASSIGN_BIT(DDRB,Copy_u8PinNB, Copy_u8Dir);
			break;
		case DIO_PORT_2:
			ASSIGN_BIT(DDRC,Copy_u8PinNB, Copy_u8Dir);
			break;
		case DIO_PORT_3:
			ASSIGN_BIT(DDRD,Copy_u8PinNB, Copy_u8Dir);
			break;
		default:
			Local_u8Error = 1;
			break;
		}
	}

	return Local_u8Error;
}

/*Description: set the value(HIGH, LOW) for specific pin
  Inputs: port number, pin value, value(HIGH, LOW)(0, 1)
  Outputs: Error State -> 0 No Error
                       -> 1 Error
*/
u8 DIO_u8SetPinValue(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Value)
{
	u8 Local_u8Error = 0;

	if(Copy_u8PinNB > DIO_PIN_7)
	{
		Local_u8Error = 1;
	}
	else if((Copy_u8Value!=DIO_LOW)&&(Copy_u8Value!=DIO_HIGH))
	{
		Local_u8Error = 1;
	}
	else
	{
		switch(Copy_u8PortNB)
		{
		case DIO_PORT_0:
			ASSIGN_BIT(PORTA,Copy_u8PinNB, Copy_u8Value);
			break;
		case DIO_PORT_1:
			ASSIGN_BIT(PORTB,Copy_u8PinNB, Copy_u8Value);
			break;
		case DIO_PORT_2:
			ASSIGN_BIT(PORTC,Copy_u8PinNB, Copy_u8Value);
			break;
		case DIO_PORT_3:
			ASSIGN_BIT(PORTD,Copy_u8PinNB, Copy_u8Value);
			break;
		default:
			Local_u8Error = 1;
			break;
		}
	}

	return Local_u8Error;
}

/*Description: Read a value (HIGH, LOW) of specific port
  Inputs: port number, address of value(HIGH, LOW) because it is a pointer
  Outputs: Error State -> 0 No Error
                       -> 1 Error
*/
u8 DIO_u8GetPortValue(u8 Copy_u8PortNB, u8 *Copy_u8Value)
{
	u8 Local_u8Error;

	if(Copy_u8Value == NULL_POINTER)
	{
		Local_u8Error = 1;
	}
	else
	{
		switch(Copy_u8PortNB)
		{
		case DIO_PORT_0:
			(*Copy_u8Value) = PINA;
			break;
		case DIO_PORT_1:
			(*Copy_u8Value) = PINB;
			break;
		case DIO_PORT_2:
			(*Copy_u8Value) = PINC;
			break;
		case DIO_PORT_3:
			(*Copy_u8Value) = PIND;
			break;
		default:
			Local_u8Error = 1;
			break;
		}
	}
	return Local_u8Error;
}

/*Description: Read a value (HIGH, LOW) of specific pin
  Inputs: port number, pin number, address of value(HIGH, LOW) because it is a pointer
  Outputs: Error State -> 0 No Error
                       -> 1 Error
*/
u8 DIO_u8GetPinValue(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 *Copy_u8Value)
{
	u8 Local_u8Error;

	if(Copy_u8Value == NULL_POINTER)
	{
		Local_u8Error = 1;
	}
	else if(Copy_u8PinNB > DIO_PIN_7)
	{
		Local_u8Error = 1;
	}
	else
	{
		switch(Copy_u8PortNB)
		{
		case DIO_PORT_0:
			(*Copy_u8Value) = GET_BIT(PINA, Copy_u8PinNB);
			break;
		case DIO_PORT_1:
			(*Copy_u8Value) = GET_BIT(PINB, Copy_u8PinNB);
			break;
		case DIO_PORT_2:
			(*Copy_u8Value) = GET_BIT(PINC, Copy_u8PinNB);
			break;
		case DIO_PORT_3:
			(*Copy_u8Value) = GET_BIT(PIND, Copy_u8PinNB);
			break;
		default:
			Local_u8Error = 1;
			break;
		}
	}
	return Local_u8Error;
}
