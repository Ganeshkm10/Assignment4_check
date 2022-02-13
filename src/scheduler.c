/*
 * scheduler.c
 *
 *  Description: This file contains functions to handle Scheduler functionality.
 *  Created on: 02-Feb-2022
 *      Author: Ganesh KM
 *
 *      Modified on 11-FEB-2022 for Assignment 4
 *
 */

#include <stdbool.h>
#include "em_core.h"

#include"scheduler.h"
#include "gpio.h"
#include "timers.h"
#include "oscillators.h"
#include "i2c.h"
#include "irq.h"

#define INCLUDE_LOG_DEBUG 1
#include "log.h"



//uint8_t CMD_READ_1 = 0XF3;
/*I2C_TransferSeq_TypeDef seq;
uint16_t SI7021_ADDRESS = 0x40;
uint8_t CMD_READ = 0XF3;*/
/*#include"em_core.h"



#define CORE_DECLARE_IRQ_STATE        CORE_irqState_t irqState
#define CORE_ENTER_CRITICAL()       irqState = CORE_EnterCritical()
#define CORE_EXIT_CRITICAL()       CORE_ExitCritical(irqState)*/

//typedef uint32_t CORE_irqState_t;
//CORE_irqState_t irqState;
//static volatile uint32_t Event_flag=0;

volatile event _EVENT;
 state_t CURRENT_STATE;
 state_t NEXT_STATE;

/*
 * @description: Function to handle an event when Underflow flag is set
 * @params: None
 * @return: None
 */
void schedulerSetEventUF(void)
{
  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();
  //UF_flag |= LETIMER_IF_UF;

  _EVENT = event_MEASURE_TEMPERATURE;

  // gpioLed1SetOn();
 CORE_EXIT_CRITICAL() ;
}

/*
 * @description: Function to handle an event when I2C transfer flag is set
 * @params: None
 * @return: None
 */

void schedulerSetEvent_I2C_TransferComplete()
{
  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();
  _EVENT = event_I2C_TransferComplete;
 // LOG_INFO("Entering I2C transfer scheduler");
  CORE_EXIT_CRITICAL() ;
}

/*
 * @description: Function to handle an event when COMP1 is set
 * @params: None
 * @return: None
 */

void schedulerSetEventCOMP1()
{
  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();
  _EVENT = event_LETIMER0_COMP1;

  //gpioLed1SetOff();
  CORE_EXIT_CRITICAL() ;
}


/*
 * @description: Function to get the event which is happening currently
 * @params: None
 * @return: event
 */

event getNextEvent()
{
  event CurrentEvent;

  CurrentEvent = _EVENT;
  schedulerClearEvent();

return CurrentEvent ;
}

/*
 * @description: Function to CLEAR THE scheduler event
 * @params: None
 * @return: event
 */

void schedulerClearEvent()
{
  //CORE_ENTER_CRITICAL();
    _EVENT = eventclear;
    //LOG_INFO("Entering clear event scheduler");
  //  CORE_EXIT_CRITICAL() ;
}

/*
 * @description: Function to set the statemachine to IDLE state
 * @params: None
 * @return: event
 */

void init_statemachine()
{
  CURRENT_STATE = state_Idle;
}


/*
 * @description: Statemachine to handle the series of temperature measuement according to the events
 *
 * @params: evt ( enum :EVENT)
 *
 * @return: none
 *
 */


void statemachine_temperaturemeasurement(event evt)
{
  volatile event Event_to_consider = evt;


      switch(CURRENT_STATE)
      {

        case state_Idle:
          {
             if(Event_to_consider == eventclear)
               {
                 NEXT_STATE = state_Idle;
               }
             if(Event_to_consider == event_MEASURE_TEMPERATURE)

               {
                 Init_I2C();
                 gpioSi7021Enable();

                 timerWaitUs_irq(80);
                 NEXT_STATE = state_wait_for_PowerOn;
               }
            break;
          }

        case state_wait_for_PowerOn:
          {

            if(Event_to_consider == event_LETIMER0_COMP1)
              {

                sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM1);
                 I2C_WRITE(1);
                    NEXT_STATE = state_wait_for_I2C_WriteComplete;

              }
           break;
          }

        case state_wait_for_I2C_WriteComplete:
          {
            //if(Event_to_consider == event_I2C_TransferComplete)
              sl_power_manager_remove_em_requirement(SL_POWER_MANAGER_EM1);
                timerWaitUs_irq(11);
                NEXT_STATE = state_wait_for_setupvalue;

                   break;
          }

        case state_wait_for_setupvalue:
          {
           // if(Event_to_consider == event_LETIMER0_COMP1)
              {
                NEXT_STATE = state_wait_for_I2C_Read;
                _EVENT = event_timerSetupvalue_complete;
                sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM1);
              }

             break;
          }

        case state_wait_for_I2C_Read:
          {
              I2C_TemperatureMeasurement();
              gpioSi7021Disable();
              sl_power_manager_remove_em_requirement(SL_POWER_MANAGER_EM1);
              NEXT_STATE = state_Idle;

            break;
          }
        default:
          {
            LOG_WARN("Unknown state in State machine");
          }

      }

 if(CURRENT_STATE != NEXT_STATE)
   {
     CURRENT_STATE = NEXT_STATE;
   }


}




