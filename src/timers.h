/*
 * timers.h
 *
 *  Created on: 25-Jan-2022
 *      Author: Ganesh KM
 *      Description: Header file which contains LETIMER initialization module
 */

#ifndef SRC_TIMERS_H_
#define SRC_TIMERS_H_
#include "stdio.h"
#include <inttypes.h>
#include<em_letimer.h>
//function prototypes

/*
 * @description: Function to initialize LETIMER0
 * @params: None
 * @return: None
 */

void initLETIMER0();

/* TimerWaitUs
 *
 * @description: Function to handle delay based on the LETIMER COUNT register and Compare register.
 *
 * @params: us_wait (micro seconds delay)
 *
 * @return: None
 */

void timerWaitUs_Polled(uint32_t us_wait);

/* TimerWaitUs
 *
 * @description: Function to handle delay based on the LETIMER COUNT register and Compare register.
 *
 * @params: us_wait (micro seconds delay)
 *
 * @return: None
 */

void timerWaitUs_irq(uint32_t ms_wait);


#endif /* SRC_TIMERS_H_ */
