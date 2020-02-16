/*
 * ADC_program.c
 *
 *  Created on: May 7, 2019
 *      Author: my
 */

/********************************/
/*Author: PHLIMON               */
/*File Name:ADC_program.c       */
/*Component: ADC                */
/*Version: 1.0                  */
/********************************/

/*Delay*/
#include<avr/delay.h>

/*Types*/
#include "STD_TYPES.h"

/*Dependences*/
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "AVR_ADC_REG.h"

/*Module*/
#include "ADC_interface.h"
#include "DIO_interface.h"

/*Description:
  Inputs:
  Outputs:
*/
void ADC_voidIntialization(void)
{
	//Reference Voltage Configuration
#if Voltage_REF == ADC_AVCC
	SET_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);

#elif Voltage_REF == ADC_AREF
	CLR_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);

#elif Voltage_REF == DC_V_2
	SET_BIT(ADMUX, REFS0);
	SET_BIT(ADMUX, REFS1);

#endif


	//Resolution Configuration
#if Resolution == ADC_ADCL
	CLR_BIT(ADMUX, ADLAR);

#elif Resolution == ADC_ADCH
	SET_BIT(ADMUX, ADLAR);

#endif


	//Prescaler
#if Prescaler == ADC_Prescaler_2
	CLR_BIT(ADCSRA, ADPS0);
	CLR_BIT(ADCSRA, ADPS1);
	CLR_BIT(ADCSRA, ADPS2);

#elif Prescaler == ADC_Prescaler_4
	CLR_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	CLR_BIT(ADCSRA, ADPS2);

#elif Prescaler == ADC_Prescaler_8
	SET_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	CLR_BIT(ADCSRA, ADPS2);

#elif Prescaler == ADC_Prescaler_16
	CLR_BIT(ADCSRA, ADPS0);
	CLR_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);

#elif Prescaler == ADC_Prescaler_32
	SET_BIT(ADCSRA, ADPS0);
	CLR_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);

#elif Prescaler == ADC_Prescaler_64
	CLR_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);

#elif Prescaler == ADC_Prescaler_128
	SET_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);

#endif


	//ADC Enabled of Disabled
#if ADC == ADC_Enable
	SET_BIT(ADCSRA, ADEN);

#else
	CLR_BIT(ADCSRA, ADEN);

#endif


	//ADC Interrupt Enabled of Disabled
#if Interrupt == ADC_Interrupt_Enable
	SET_BIT(ADCSRA, ADIE);

#else
	CLR_BIT(ADCSRA, ADIE);

#endif
}

/*Description:
  Inputs:
  Outputs:
*/
u8 ADC_u8GetADCBlocking(u8 Copy_u8Channel_NB, u16 * Copy_u16Value)
{
	u8 The_Channel, Local_u8Error, Local_u8LowValue;

	if(The_Channel > 31)
	{
		Local_u8Error = 1;
	}

	//the anding is for make the last 3 bits as it is with no change
	//and make the first 5 bits with zeros
	//then the oring for add the value of first 3 bits according to the channel
//	The_Channel = ((ADMUX && 0xE0) | Copy_u8Channel_NB);
	ADMUX &= 0xE0;
	ADMUX |= Copy_u8Channel_NB;

	//Start Conversion
	if(ADC_StConversion == Start)
	{
		SET_BIT(ADCSRA, ADSC);
	}
	else
	{
		CLR_BIT(ADCSRA, ADSC);
	}

	//Wait will it ends the conversion
	while(! GET_BIT(ADCSRA, ADIF))
		{

		}
	SET_BIT(ADCSRA, ADIF);

	/*Get Value*/
	if(ADLAR == ADC_ADCL)
	{
		Local_u8LowValue = ADCL;
		*Copy_u16Value = (Local_u8LowValue) | (ADCH << 8);
	}
	else
	{
		*Copy_u16Value = ADCH;
	}

	return Local_u8Error;
}
