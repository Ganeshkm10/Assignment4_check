/*
 * oscillators.c
 *
 *  Created on: 25-Jan-2022
 *      Author: Ganesh KM
 *      Description: This file contains all the CMU module functions configured as per EM modes
 */

#include <stdbool.h>
#include"em_cmu.h"
#include"app.h"

/*
 * @description: Function to initialize Oscillator
 * @params: None
 * @return: None
 */

void initOscillator(){

  CMU_ClockEnable( cmuClock_GPIO, true );

  if(LOWEST_ENERGY_MODE == 3) //enabling ULFRCO for the EM3 mode
    {
      CMU_OscillatorEnable(cmuOsc_ULFRCO, true, true);
      CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_ULFRCO);
      CMU_ClockEnable( cmuClock_LFA, true);
      CMU_ClockEnable(cmuClock_LETIMER0, true);
    }
  else if((LOWEST_ENERGY_MODE == 2) | (LOWEST_ENERGY_MODE == 1) |(LOWEST_ENERGY_MODE == 0)) //enabling LFXO for the all other modes
    {
      CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
      CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
      CMU_ClockEnable( cmuClock_LFA, true);
      CMU_ClockEnable(cmuClock_LETIMER0, true);
      CMU_ClockDivSet(cmuClock_LETIMER0, cmuClkDiv_4);
    }

    //CMU_ClockEnable( cmuClock_HFPER, true );
    //CMU_ClockEnable( cmuClock_I2C0, true );
    //CMU_ClockEnable( cmuClock_LFA, true );
    //CMU_ClockEnable( cmuClock_LETIMER0, true );
}

