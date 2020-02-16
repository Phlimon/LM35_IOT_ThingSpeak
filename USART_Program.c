/*
 * USART_Program.c
 *
 *  Created on: Oct 11, 2019
 *      Author: my
 */

/*Delay*/
#include<avr/delay.h>

/*Types*/
#include "STD_TYPES.h"

/*Dependences*/
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "AVR_USART_REG.h"

/*Module*/
#include "DIO_interface.h"
#include "USART_interface.h"

void USART_voidIntialization()
{
	u8 UCSRC_Value = 0;

	//Enable Transmitter
	#if Transmitting == Enable
	SET_BIT(UCSRB, UCSRB_TXEN);

	#elif Transmitting == Disable
	CLR_BIT(UCSRB, UCSRB_TXEN);

	#endif

	//Enable Receiver
	#if Reciving == Enable
	SET_BIT(UCSRB, UCSRB_RXEN);

	#elif Reciving == Disable
	CLR_BIT(UCSRB, UCSRB_RXEN);

	#endif

	//Choose UCSRC
	SET_BIT(UCSRC_Value, UCSRC_URSEL);

	//Choose Asynchronous
	CLR_BIT(UCSRC_Value, UCSRC_UMSEL);

	//Choose 1 bit for Stop Bit
	CLR_BIT(UCSRC_Value, UCSRC_USBS);

	//Choose the number of bits (8 Bits)
	CLR_BIT(UCSRB, UCSRB_UCSZ2);
	SET_BIT(UCSRC_Value, UCSRC_UCSZ0);
	SET_BIT(UCSRC_Value, UCSRC_UCSZ1);

	//Choose speed 9600
	#if Double_Transmission_Speed == LOW
	CLR_BIT(UCSRA, UCSRA_U2X);

	#elif Double_Transmission_Speed == HIGH
	SET_BIT(UCSRA, UCSRA_U2X);

	#endif

	UBRRL = UBRLL_Value;

	/*Choosing Multi-Processor or No*/
	#if Multi_Processor == LOW
	CLR_BIT(UCSRA, UCSRA_MPCM);

	#elif Multi_Processor == HIGH
	SET_BIT(UCSRA, UCSRA_MPCM);

	#endif

	/*Interrupt For Transmitting*/
	#if TX_Interrupt == HIGH
	SET_BIT(UCSRB, UCSRB_TXCIE);

	#elif TX_Interrupt == LOW
	CLR_BIT(UCSRB, UCSRB_TXCIE);

	#endif

	/*Interrupt For Receiving*/
	#if RX_Interrupt == HIGH
	SET_BIT(UCSRB, UCSRB_RXCIE);

	#elif RX_Interrupt == LOW
	CLR_BIT(UCSRB, UCSRB_RXCIE);

	#endif

	/*USART Data Register Empty Interrupt*/
	#if DataRegEmptyInterrupt == HIGH
	SET_BIT(UCSRB, UCSRB_UDRIE);

	#elif DataRegEmptyInterrupt == LOW
	CLR_BIT(UCSRB, UCSRB_UDRIE);

	#endif

	/*Put The Value in the Register*/
	UCSRC = UCSRC_Value;
}

u8 USART_u8SendChar(u8 Copy_u8Char)
{
	while(!(GET_BIT(UCSRA, UCSRA_UDRE)));

	/*Assign the Value to the register*/
	UDR = Copy_u8Char;

	return 0;
}

//u8 USART_u8ReceiveChar(u8 * Copy_u8Data)
u8 USART_u8ReceiveChar(void)
{
	while(!(GET_BIT(UCSRA, UCSRA_RXC)));
	//While(((GET_BIT(UCSRA, UCSRA_RXC)) == 0);
	//*Copy_u8Data = UDR;

	//SET_BIT(UCSRA, UCSRA_RXC);

	return UDR;
}


//SHould change pointer data type to char
void USART_u8SendString(u8 * Copy_u8STR)
{
	u8 i = 0;

	while(Copy_u8STR[i] != '\0') //'\0' means the end of the array
	{
		USART_u8SendChar(Copy_u8STR[i]);
		i++;
	}
}

void USART_u8ReciveString(u8 * arrOfString)
{
	u8 i = 0;

	while(arrOfString[i] != '\0')
	//for(i = 0; i < 16; i++)
	{
		arrOfString[i] = USART_u8ReceiveChar();
	}
}
