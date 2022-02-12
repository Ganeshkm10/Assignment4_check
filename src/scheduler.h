/*
 * scheduler.h
 * This file contains function declarations for scheduler functionality
 *  Created on: 02-Feb-2022
 *      Author: Ganesh KM
 *
 *      Modified on 11-FEB-2022 for Assignment 4
 *
 */

#ifndef SRC_SCHEDULER_H_
#define SRC_SCHEDULER_H_




//#include "irq.h"

/*
 * @description: Function to handle an event when Underflow flag is set
 * @params: None
 * @return: None
 */

typedef enum{
  state_Idle,
  state_wait_for_PowerOn,
  state_wait_for_I2C_WriteComplete,
  state_wait_for_setupvalue,
  state_wait_for_I2C_Read,
}state_t;

typedef enum{
  event_MEASURE_TEMPERATURE,
  event_LETIMER0_COMP1,
  event_I2C_TransferComplete,
  event_timerSetupvalue_complete,
  eventclear
}event;


void schedulerSetEventUF(void);

void schedulerSetEventCOMP1();


/*
 * @description: Function to get the event which is happening currently
 * @params: None
 * @return: event
 */

event getNextEvent();

void schedulerClearEvent();

void statemachine_temperaturemeasurement(event evt);

void schedulerSetEvent_I2C_TransferComplete();

void init_statemachine();


#endif /* SRC_SCHEDULER_H_ */
