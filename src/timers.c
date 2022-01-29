/*
 * timers.c
 *
 *  Created on: 25-Jan-2022
 *      Author: Ganesh KM
 *      Description: This file contains source code for initialization of LETIMER0
 *      Note : To change the LED ON period and LETIMER PERIOD , change the values in the #defines.
 */

#include<em_letimer.h>
#include<core_cm4.h>
#include"app.h"
#include"timers.h"


/*
 * configurable parameters such as LED ON time and period in ms.
 *
 */
#define LETIMER_PERIOD_MS 2250   //VALUES ARE IN Milliseconds
#define LED_ON_PERIOD_MS 175     //VALUES ARE IN Milliseconds


/*
 * defines for LFXO Values
 */
#define PRESCALAR_VALUE 4
#define ACTUAL_CLK_FREQ 32768/PRESCALAR_VALUE
#define VALUE_TO_LOAD (LETIMER_PERIOD_MS*ACTUAL_CLK_FREQ)/1000
#define VALUE_TO_LOAD_COMP1 (LED_ON_PERIOD_MS * ACTUAL_CLK_FREQ )/1000 //#define VALUE_TO_LOAD_COMP1 1434

/*
 * defines for ULFRCO Values
 */
#define ACTUAL_CLK_FREQ_ULFRCO 1000
#define VALUE_TO_LOAD_ULFRCO (LETIMER_PERIOD_MS*ACTUAL_CLK_FREQ_ULFRCO)/1000
#define VALUE_TO_LOAD_COMP1_ULFRCO (LED_ON_PERIOD_MS * ACTUAL_CLK_FREQ_ULFRCO)/1000

/*
 * @description: Function to initialize LETIMER0
 * @params: None
 * @return: None
 */


void initLETIMER0()
{
  const LETIMER_Init_TypeDef letimer_init =
  {
  .enable =    true,
  .debugRun =  true,
  .comp0Top =  true,
  .bufTop =   false,
  .out0Pol = 0,
  .out1Pol = 0,
  .ufoa0 =  _LETIMER_CTRL_UFOA0_NONE,
  .ufoa1=  _LETIMER_CTRL_UFOA0_PULSE,
  .repMode = _LETIMER_CTRL_REPMODE_FREE
  };

  LETIMER_Init(LETIMER0,&letimer_init);

  LETIMER_IntEnable(LETIMER0,LETIMER_IEN_UF);
  LETIMER_IntEnable(LETIMER0,LETIMER_IEN_COMP1);

   NVIC_EnableIRQ(LETIMER0_IRQn);
   LETIMER_Enable(LETIMER0,true);

//Switching COMP values and load values according to energy modes.
   if(LOWEST_ENERGY_MODE == 3)
     {
       LETIMER_CompareSet(LETIMER0,0,VALUE_TO_LOAD_ULFRCO);
       LETIMER_CompareSet(LETIMER0,1,VALUE_TO_LOAD_COMP1_ULFRCO);
     }
   else if((LOWEST_ENERGY_MODE == 2) | (LOWEST_ENERGY_MODE == 1) |(LOWEST_ENERGY_MODE == 0))
     {
       LETIMER_CompareSet(LETIMER0,0,VALUE_TO_LOAD);
       LETIMER_CompareSet(LETIMER0,1,VALUE_TO_LOAD_COMP1);
     }


/*COMP0TOP  in  LETIMERn_CTRL  is  set,  the  value  of  LETIMERn_COMP0  acts  as  the  top  value  of
  the timer, and LETIMERn_COMP0 is loaded into LETIMERn_CNT on timer underflow. Otherwise the
  timer wraps around to 0xFFFF. The underflow interrupt flag UF in LETIMERn_IF is set when the timer
  reaches zero. */
}


