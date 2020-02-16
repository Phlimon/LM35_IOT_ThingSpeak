/*
 * AVR_EXTI_REG.h
 *
 *  Created on: Apr 20, 2019
 *      Author: my
 */

#ifndef AVR_EXTI_REG_H_
#define AVR_EXTI_REG_H_

#define MCUCR (*((u8*) 0x55))

#define MCUCR_ISC00 0
#define MCUCR_ISC01 1

#define MCUCR_ISC10 2
#define MCUCR_ISC11 3

#define MCUCSR (*((u8*) 0x54))

#define MCUCSR_ISC2 6

#define GICR (*((u8*) 0x5B))

#define GICR_INT0 6
#define GICR_INT1 7
#define GICR_INT2 5

#define GIFR (*((u8*) 0x5A))

#define GIFR_INTF0 6
#define GIFR_INTF1 7
#define GIFR_INTF2 5

#define SREG (*((u8*) 0x5F))

#define SREG_I 7

#endif /* AVR_EXTI_REG_H_ */
