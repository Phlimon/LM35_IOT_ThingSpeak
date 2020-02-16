/*
 * AVR_USART_REG.h
 *
 *  Created on: Oct 11, 2019
 *      Author: my
 */

#ifndef AVR_USART_REG_H_
#define AVR_USART_REG_H_

/*USART I/O Data Register*/
#define UDR (*((u8*) 0x2C))

/*USART Control and Status
 Register A – UCSRA
*/
#define UCSRA (*((u8*) 0x2B))
#define UCSRA_MPCM 0
#define UCSRA_U2X  1
#define UCSRA_PE   2
#define UCSRA_DOR  3
#define UCSRA_FE   4
#define UCSRA_UDRE 5
#define UCSRA_TXC  6
#define UCSRA_RXC  7

/*USART Control and Status
  Register B – UCSRB
*/
#define UCSRB (*((u8*) 0x2A))
#define UCSRB_TXB8  0
#define UCSRB_RXB8  1
#define UCSRB_UCSZ2 2
#define UCSRB_TXEN  3
#define UCSRB_RXEN  4
#define UCSRB_UDRIE 5
#define UCSRB_TXCIE 6
#define UCSRB_RXCIE 7

/*
  USART Control and Status
  Register C – UCSRC  / UBRRH
*/
#define UCSRC (*((u8*) 0x40))
#define UCSRC_UCPOL 0
#define UCSRC_UCSZ0 1
#define UCSRC_UCSZ1 2
#define UCSRC_USBS  3
#define UCSRC_UPM0  4
#define UCSRC_UPM1  5
#define UCSRC_UMSEL 6
#define UCSRC_URSEL 7 /*This bit selects between accessing the UCSRC or the UBRRH Register. It is read as
						one when reading UCSRC. The URSEL must be one when writing the UCSRC.
 	 	 	 	 	  */

/*USART Baud Rate Registers –
  UBRRL and UBRRH
*/
#define UBRRL (*((u8*) 0x29))

#endif /* AVR_USART_REG_H_ */
