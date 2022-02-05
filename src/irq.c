/*
 * irq.c
 *
 *  Created on: 25-Jan-2022
 *      Author: Ganesh KM
 *      Description: This file contains interrupt handler functions.
 *
 *  Modified on 04-FEB-2022 for Assignment 3
 */

#include<em_letimer.h>
#include"gpio.h"
#include"em_core.h"
#include"irq.h"

typedef uint32_t CORE_irqState_t;
CORE_irqState_t irqState;

#define CORE_DECLARE_IRQ_STATE        CORE_irqState_t irqState
#define CORE_ENTER_CRITICAL()       irqState = CORE_EnterCritical()
#define CORE_EXIT_CRITICAL()       CORE_ExitCritical(irqState)

/*
 * @description: Interrupt handler function
 * @params: None
 * @return: None
 */

void LETIMER0_IRQHandler(void)
{
  CORE_ENTER_CRITICAL(); //enter critical section
  uint32_t flags;
  flags = LETIMER_IntGet(LETIMER0); //getting the flag being set from Interrupt register

  if(flags & LETIMER_IF_UF)
    {
      schedulerSetEventUF();

      // gpioLed1SetOff();

      LETIMER_IntClear(LETIMER0,LETIMER_IFC_UF);
    }
  if(flags & LETIMER_IF_COMP1)
      {

      //gpioLed1SetOn();
        LETIMER_IntClear(LETIMER0,LETIMER_IFC_COMP1);
      }
  CORE_EXIT_CRITICAL();//exit critical section
}
