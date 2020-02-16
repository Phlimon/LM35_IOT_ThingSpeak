/*
 * TEMP_interface.h
 *
 *  Created on: May 23, 2019
 *      Author: my
 */

#ifndef TEMP_INTERFACE_H_
#define TEMP_INTERFACE_H_

/*Description:convert the ADC reading to Temp reading
  Inputs: ADC Reading, Address of Variable to put Temp Reading
  Outputs: Error State -> 0 No Error
                       -> 1 Error
*/
u8 TEMPREATURE(u16 Copy_u16SensorRead, u16 * Copy_u16ActualTemp);

/*Description:Print Actual Temp on LCD
  Inputs: Actual Temp reading after conversion
  Outputs: Error State -> 0 No Error
                       -> 1 Error
*/
u8 TempLCDPrint(u16 Copy_u16ActualTemp);

#endif /* TEMP_INTERFACE_H_ */
