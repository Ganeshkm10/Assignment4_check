/*
 * scheduler.h
 * This file contains function declarations for scheduler functionality
 *  Created on: 02-Feb-2022
 *      Author: Ganesh KM
 *
 */

#ifndef SRC_SCHEDULER_H_
#define SRC_SCHEDULER_H_

#include "stdio.h"
#include <inttypes.h>
#include<em_letimer.h>

/*
 * @description: Function to handle an event when Underflow flag is set
 * @params: None
 * @return: None
 */

void schedulerSetEventUF(void);


/*
 * @description: Function to get the event which is happening currently
 * @params: None
 * @return: event
 */

uint32_t getNextEvent();






#endif /* SRC_SCHEDULER_H_ */
