/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'hallsensor'.
 *
 * Model version                  : 1.96
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Fri Mar 13 13:02:59 2020
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "hallsensor.h"
#include "Arduino.h"
#define STEP_SIZE                      (unsigned long) (1)

int_T main(void)
{
  unsigned long oldtime = 0L;
  unsigned long actualtime;
  init();
  hallsensor_initialize();

#ifdef _RTT_USE_SERIAL0_

  Serial_begin(0, 500000);

#endif

#ifdef _RTT_USE_SERIAL1_

  Serial_begin(1, 500000);

#endif

#ifdef _RTT_USE_SERIAL2_

  Serial_begin(2, 500000);

#endif

#ifdef _RTT_USE_SERIAL3_

  Serial_begin(3, 500000);

#endif

  /* The main step loop */
  while (rtmGetErrorStatus(hallsensor_M) == (NULL)) {
    actualtime = micros();
    if ((unsigned long) (actualtime - oldtime) >= STEP_SIZE) {
      oldtime = actualtime;
      hallsensor_output();

      /* Get model outputs here */
      hallsensor_update();
    }
  }

  hallsensor_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
