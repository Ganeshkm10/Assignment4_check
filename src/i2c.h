/*
 * i2c.h
 *  This file contains I2C function declarations.
 *  Created on: 02-Feb-2022
 *      Author: Ganesh KM
 *
 *       modified by Ganesh KM on 11-FEB-2022 for Assignment 4
 */

#ifndef SRC_I2C_H_
#define SRC_I2C_H_

#include "sl_i2cspm.h"

#include "gpio.h"






#define SI7021_ADDRESS 0x40



/*
  * @description: Function to initialize I2C
  *
  * @params: None
  *
  * @return: None
  */

void Init_I2C();

/*
 * @description: Function for I2C READ functionality
 *
 * @params: pointer to buffer, Length
 *
 * @return: Transferstatus : Tells whether I2C READ is done or not.
 */

I2C_TransferReturn_TypeDef I2C_READ(uint8_t *BUFFER, uint16_t BUFFERLEN);

/*
 * @description: Function for I2C Write functionality
 *
 * @params: pointer to CMD_READ, Length
 *
 * @return: Transferstatus : Tells whether I2C Write is done or not.
 */

I2C_TransferReturn_TypeDef I2C_WRITE(uint16_t CMD_LEN);

/*
 * @description: Utility function to Get temeperature from SI7021 sensor
 *
 * @params: void
 *
 * @return: void.
 */

void I2C_TemperatureMeasurement();



#endif /* SRC_I2C_H_ */
