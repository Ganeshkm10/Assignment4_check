/*
 * scheduler.c
 *
 *  Description: This file contains functions to handle Scheduler functionality.
 *  Created on: 02-Feb-2022
 *      Author: Ganesh KM
 *
 */
#include <stdbool.h>
#include"scheduler.h"


static volatile uint32_t UF_flag=0;

/*
 * @description: Function to handle an event when Underflow flag is set
 * @params: None
 * @return: None
 */
void schedulerSetEventUF(void)
{

  UF_flag |= LETIMER_IF_UF;

}
/*
 * @description: Function to get the event which is happening currently
 * @params: None
 * @return: event
 */

uint32_t getNextEvent()
{

  uint32_t event;

 /* while(UF_flag!=1<<i)
    {
      i++;
    } */
  event = UF_flag;
  UF_flag=0;
return event;
}
