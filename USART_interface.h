/*
 * USART_interface.h
 *
 *  Created on: Oct 11, 2019
 *      Author: my
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#define High 1
#define Low  0

#define Enable  1
#define Disable 0

/*Receive Interrupt*/
#define RX_Interrupt HIGH

/*Transmit Interrupt*/
#define TX_Interrupt HIGH

/*Data Register Empty Interrupt*/
#define DataRegEmptyInterrupt HIGH

/*Transmitting Enabling*/
#define Transmitting Enable

/*Receiving Enabling*/
#define Reciving Enable

/*Double the USART Transmission Speed (Choose Baud Rate)*/
#define Double_Transmission_Speed  LOW

/*Multi-Processor Communication Mode*/
#define Multi_Processor LOW

/*Choosing the baud rate*/
#define UBRLL_Value 51

void USART_voidIntialization();

u8 USART_u8SendChar(u8 Copy_u8Char);

u8 USART_u8ReceiveChar(void);

#endif /* USART_INTERFACE_H_ */
