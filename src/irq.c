/*
 * irq.c
 *
 *  Created on: 25-Jan-2022
 *      Author: Ganesh KM
 *      Description: This file contains interrupt handler functions.
 *
 *  Modified on 11-FEB-2022 for Assignment 4
 */

#include<em_letimer.h>
#include"gpio.h"
#include"irq.h"
#include "scheduler.h"
#include"em_core.h"
#include "i2c.h"

#define INCLUDE_LOG_DEBUG 1
#include "log.h"


extern I2C_TransferSeq_TypeDef seq;
extern uint8_t CMD_READ;

uint32_t Log_time=0;

typedef uint32_t CORE_irqState_t;
CORE_irqState_t irqState;

#define CORE_DECLARE_IRQ_STATE        CORE_irqState_t irqState
#define CORE_ENTER_CRITICAL()       irqState = CORE_EnterCritical()
#define CORE_EXIT_CRITICAL()       CORE_ExitCritical(irqState)

/*
 * @description: LETIMER0 Interrupt handler function
 * @params: None
 * @return: None
 */

void LETIMER0_IRQHandler(void)
{
  CORE_ENTER_CRITICAL(); //enter critical section
  uint32_t flags;
  flags = LETIMER_IntGetEnabled(LETIMER0); //getting the flag being set from Interrupt register

  if(flags == LETIMER_IF_UF)
    {
      schedulerSetEventUF();
      Handle_count();

      // gpioLed1SetOff();

      LETIMER_IntClear(LETIMER0,LETIMER_IFC_UF);
    }
  if(flags == LETIMER_IF_COMP1)
      {
      schedulerSetEventCOMP1();
     // gpioLed1SetOn();

        LETIMER_IntClear(LETIMER0,LETIMER_IFC_COMP1);
      }
  CORE_EXIT_CRITICAL();//exit critical section
}

/*
 * @description: I2C0 Interrupt handler function
 * @params: None
 * @return: None
 */

void I2C0_IRQHandler(void)
{
  CORE_ENTER_CRITICAL();
  I2C_TransferReturn_TypeDef transferstatus;

 // sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM1);
  transferstatus = I2C_Transfer(I2C0);

  if(transferstatus == i2cTransferDone)
    {
      schedulerSetEvent_I2C_TransferComplete();
     // LOG_INFO(" I2C transfer is done ");
    }

  if(transferstatus < 0)
    {
     // LOG_ERROR("%d", transferstatus);
    }
  CORE_EXIT_CRITICAL();
 }

void Handle_count(void)
{
  Log_time+=3000;
}

/*
 * @description: Ms calculation function used while logging
 * @params: None
 * @return: None
 */

uint32_t letimerMilliseconds()
{
 return Log_time;
}


