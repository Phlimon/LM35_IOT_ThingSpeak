/*
 * ADC_interface.h
 *
 *  Created on: May 7, 2019
 *      Author: my
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

// Voltage Reference
#define Voltage_REF ADC_AVCC
#define ADC_AVCC 0
#define ADC_AREF 1
#define ADC_V_2  2

//Resolution
#define Resolution ADC_ADCH   //0 for ADCL Right Adjustment, 1 for ADCH Left Adjustment
#define ADC_ADCL 0
#define ADC_ADCH 1

//Prescaler
//Prescaler is the Clock For ADC
#define Prescaler ADC_Prescaler_2
#define ADC_Prescaler_2		2
#define ADC_Prescaler_4  	4
#define ADC_Prescaler_8		8
#define ADC_Prescaler_16	16
#define ADC_Prescaler_32	32
#define ADC_Prescaler_64	64
#define ADC_Prescaler_128	128

//ADC Enable or Disable
#define ADC ADC_Enable
#define ADC_Enable  1
#define ADC_Disable 0

//ADC Interrupt Enable or Disable
#define Interrupt ADC_Interrupt_Enable
#define ADC_Interrupt_Enable 1
#define ADC_Interrupt_Diable 0

//Channels
#define Channel_0 0
#define Channel_1 1
#define Channel_2 2
#define Channel_3 3
#define Channel_4 4
#define Channel_5 5
#define Channel_6 6
#define Channel_7 7
#define Channel_8 8
#define Channel_9 9
#define Channel_10 10
#define Channel_11 11
#define Channel_12 12
#define Channel_13 13
#define Channel_14 14
#define Channel_15 15
#define Channel_16 16
#define Channel_17 17
#define Channel_18 18
#define Channel_19 19
#define Channel_20 20
#define Channel_21 21
#define Channel_22 22
#define Channel_23 23
#define Channel_24 24
#define Channel_25 25
#define Channel_26 26
#define Channel_27 27
#define Channel_28 28
#define Channel_29 29
#define Channel_30 30
#define Channel_31 31

//Start Conversion
#define ADC_StConversion Start
#define Start 1
#define Stop  0

/*Description:
  Inputs:
  Outputs:
*/
void ADC_voidIntialization(void);

/*Description:
  Inputs:
  Outputs:
*/
u8 ADC_u8GetADCBlocking(u8 Copy_u8Channel_NB, u16 * Copy_u16Value);

#endif /* ADC_INTERFACE_H_ */
