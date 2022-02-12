/*
 * i2c.c
 *  Description: This file contains all the I2C related function definitions.
 *  Created on: 02-Feb-2022
 *      Author: Ganesh KM
 *
 *      modified by Ganesh KM on 11-FEB-2022 for Assignment 4
 */

#include "i2c.h"

#define INCLUDE_LOG_DEBUG 1
#include "log.h"
#include "oscillators.h"

typedef struct{
  uint8_t data[2];
  uint16_t BUFFERLEN;
}I2CDATA;

I2CDATA BUFFER;

I2CSPM_Init_TypeDef I2C_Config;


I2C_TransferSeq_TypeDef seq;


uint8_t CMD_READ = 0XF3;
float temp;
uint16_t read_temp;


 /*
  * @description: Function to initialize I2C
  *
  * @params: None
  *
  * @return: None
  */

void Init_I2C()
{
  I2C_Config.port = I2C0,
       I2C_Config.sclPort = gpioPortC;
       I2C_Config.sclPin = 10;
       I2C_Config.sdaPort = gpioPortC;
       I2C_Config.sdaPin = 11;
       I2C_Config.portLocationScl = 14;
       I2C_Config.portLocationSda = 16;
       I2C_Config.i2cRefFreq = 0;
       I2C_Config.i2cMaxFreq = I2C_FREQ_STANDARD_MAX;
       I2C_Config.i2cClhr = i2cClockHLRStandard;

  I2CSPM_Init(&I2C_Config);

}

/*
 * @description: Function for I2C READ functionality
 *
 * @params: pointer to buffer, Length
 *
 * @return: Transferstatus : Tells whether I2C READ is done or not.
 */


I2C_TransferReturn_TypeDef I2C_READ(uint8_t *BUFFER, uint16_t BUFFERLEN)
{

   I2C_TransferReturn_TypeDef transferstatus;

  seq.addr = SI7021_ADDRESS << 1;
  seq.flags = I2C_FLAG_READ;
  seq.buf[0].data = BUFFER;
  seq.buf[0].len = BUFFERLEN;
  NVIC_EnableIRQ( I2C0_IRQn );

   transferstatus = I2C_TransferInit(I2C0, &seq);

 /* if(transferstatus != i2cTransferDone)
    {
       LOG_ERROR("I2CSPM_TRANSFER : I2C BUS READ IS FAILED");
    }*/

   return transferstatus;
}

/*
 * @description: Function for I2C Write functionality
 *
 * @params: pointer to CMD_READ, Length
 *
 * @return: Transferstatus : Tells whether I2C Write is done or not.
 */

I2C_TransferReturn_TypeDef I2C_WRITE(uint16_t CMD_LEN)
{
  I2C_TransferReturn_TypeDef transferstatus;


  seq.addr = SI7021_ADDRESS << 1;
  seq.flags = I2C_FLAG_WRITE;
  seq.buf[0].data = &CMD_READ;
  seq.buf[0].len = CMD_LEN;
  NVIC_EnableIRQ( I2C0_IRQn );


  transferstatus = I2C_TransferInit(I2C0, &seq);

 /*if(transferstatus == i2cTransferInProgress)
  {
      //LOG_ERROR("I2CSPM_TRANSFER in progress : I2C BUS WRITE OF CMD = 0XF3 IS FAILED");
  }
 */
  //NVIC_DisableIRQ(I2C0_IRQn);
return transferstatus;
}

/*
 * @description: Utility function to Get temeperature from SI7021 sensor
 *
 * @params: void
 *
 * @return: void.
 */

void I2C_TemperatureMeasurement()
{

  I2C_TransferReturn_TypeDef status;
  BUFFER.BUFFERLEN = 2;

      status = I2C_READ(BUFFER.data,BUFFER.BUFFERLEN);

      //if(i2cTransferDone == status)
        {
          temp = (( BUFFER.data[0] << 8 ) | (BUFFER.data[1]));  //Temperature calculation as per manual
          read_temp = ( ( 175.72 * (temp) ) / 65536 ) - 46.85;
         //LOG_INFO("transfer is done in I2C READ \n\r");
        }
      if(i2cTransferInProgress == status)
        {
          //LOG_INFO(" transfer in progress in I2C READ \n\r");
        }


      LOG_INFO(" Temperature = %d C ", read_temp);

    //  LOG_INFO( "\n \r buffer DATA written by I2C transfer in Hex values (Only for Debug) is %X %X \n", BUFFER.data[0],BUFFER.data[1] );

      //LOG_INFO( "\n \r buffer DATA is %d %d \n", BUFFER.data[0],BUFFER.data[1] );

}

