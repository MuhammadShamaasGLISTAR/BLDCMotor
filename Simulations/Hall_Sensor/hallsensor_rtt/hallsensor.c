/*
 * File: hallsensor.c
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
#include "hallsensor_private.h"

/* Block states (auto storage) */
DW_hallsensor_T hallsensor_DW;

/* Real-time model */
RT_MODEL_hallsensor_T hallsensor_M_;
RT_MODEL_hallsensor_T *const hallsensor_M = &hallsensor_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (hallsensor_M->Timing.TaskCounters.TID[1])++;
  if ((hallsensor_M->Timing.TaskCounters.TID[1]) > 2) {/* Sample time: [5.0E-6s, 0.0s] */
    hallsensor_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model output function */
void hallsensor_output(void)
{
  real_T rtb_PulseGenerator5;
  uint8_T rtb_PulseGenerator;

  /* DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (hallsensor_P.Constant_Value < 256.0) {
    if (hallsensor_P.Constant_Value >= 0.0) {
      rtb_PulseGenerator = (uint8_T)hallsensor_P.Constant_Value;
    } else {
      rtb_PulseGenerator = 0U;
    }
  } else {
    rtb_PulseGenerator = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S12>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S12>/Digital Output' */
  MW_digitalWrite(hallsensor_P.DigitalOutput_p1, rtb_PulseGenerator);

  /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  if (hallsensor_P.Constant1_Value < 256.0) {
    if (hallsensor_P.Constant1_Value >= 0.0) {
      rtb_PulseGenerator = (uint8_T)hallsensor_P.Constant1_Value;
    } else {
      rtb_PulseGenerator = 0U;
    }
  } else {
    rtb_PulseGenerator = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S13>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S13>/Digital Output' */
  MW_digitalWrite(hallsensor_P.DigitalOutput_p1_k, rtb_PulseGenerator);

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  if (hallsensor_P.Constant2_Value < 256.0) {
    if (hallsensor_P.Constant2_Value >= 0.0) {
      rtb_PulseGenerator = (uint8_T)hallsensor_P.Constant2_Value;
    } else {
      rtb_PulseGenerator = 0U;
    }
  } else {
    rtb_PulseGenerator = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S3>/Digital Output' */
  MW_digitalWrite(hallsensor_P.DigitalOutput_p1_f, rtb_PulseGenerator);

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Constant3'
   */
  if (hallsensor_P.Constant3_Value < 256.0) {
    if (hallsensor_P.Constant3_Value >= 0.0) {
      rtb_PulseGenerator = (uint8_T)hallsensor_P.Constant3_Value;
    } else {
      rtb_PulseGenerator = 0U;
    }
  } else {
    rtb_PulseGenerator = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S5>/Digital Output' */
  MW_digitalWrite(hallsensor_P.DigitalOutput_p1_o, rtb_PulseGenerator);

  /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Constant4'
   */
  if (hallsensor_P.Constant4_Value < 256.0) {
    if (hallsensor_P.Constant4_Value >= 0.0) {
      rtb_PulseGenerator = (uint8_T)hallsensor_P.Constant4_Value;
    } else {
      rtb_PulseGenerator = 0U;
    }
  } else {
    rtb_PulseGenerator = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S6>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S6>/Digital Output' */
  MW_digitalWrite(hallsensor_P.DigitalOutput_p1_c, rtb_PulseGenerator);

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  if (hallsensor_P.Constant5_Value < 256.0) {
    if (hallsensor_P.Constant5_Value >= 0.0) {
      rtb_PulseGenerator = (uint8_T)hallsensor_P.Constant5_Value;
    } else {
      rtb_PulseGenerator = 0U;
    }
  } else {
    rtb_PulseGenerator = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S4>/Digital Output' */
  MW_digitalWrite(hallsensor_P.DigitalOutput_p1_l, rtb_PulseGenerator);

  /* DiscretePulseGenerator: '<S1>/Pulse Generator3' */
  rtb_PulseGenerator5 = (hallsensor_DW.clockTickCounter <
    hallsensor_P.PulseGenerator3_Duty) && (hallsensor_DW.clockTickCounter >= 0L)
    ? hallsensor_P.PulseGenerator3_Amp : 0.0;
  if (hallsensor_DW.clockTickCounter >= hallsensor_P.PulseGenerator3_Period -
      1.0) {
    hallsensor_DW.clockTickCounter = 0L;
  } else {
    hallsensor_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator3' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  if (rtb_PulseGenerator5 < 256.0) {
    if (rtb_PulseGenerator5 >= 0.0) {
      rtb_PulseGenerator = (uint8_T)rtb_PulseGenerator5;
    } else {
      rtb_PulseGenerator = 0U;
    }
  } else {
    rtb_PulseGenerator = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' */
  MW_digitalWrite(hallsensor_P.DigitalOutput_p1_b, rtb_PulseGenerator);

  /* DiscretePulseGenerator: '<S1>/Pulse Generator2' */
  rtb_PulseGenerator5 = (hallsensor_DW.clockTickCounter_b <
    hallsensor_P.PulseGenerator2_Duty) && (hallsensor_DW.clockTickCounter_b >=
    0L) ? hallsensor_P.PulseGenerator2_Amp : 0.0;
  if (hallsensor_DW.clockTickCounter_b >= hallsensor_P.PulseGenerator2_Period -
      1.0) {
    hallsensor_DW.clockTickCounter_b = 0L;
  } else {
    hallsensor_DW.clockTickCounter_b++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator2' */

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  if (rtb_PulseGenerator5 < 256.0) {
    if (rtb_PulseGenerator5 >= 0.0) {
      rtb_PulseGenerator = (uint8_T)rtb_PulseGenerator5;
    } else {
      rtb_PulseGenerator = 0U;
    }
  } else {
    rtb_PulseGenerator = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S7>/Digital Output' */
  MW_digitalWrite(hallsensor_P.DigitalOutput_p1_kc, rtb_PulseGenerator);

  /* DiscretePulseGenerator: '<S1>/Pulse Generator6' */
  rtb_PulseGenerator5 = (hallsensor_DW.clockTickCounter_j <
    hallsensor_P.PulseGenerator6_Duty) && (hallsensor_DW.clockTickCounter_j >=
    0L) ? hallsensor_P.PulseGenerator6_Amp : 0.0;
  if (hallsensor_DW.clockTickCounter_j >= hallsensor_P.PulseGenerator6_Period -
      1.0) {
    hallsensor_DW.clockTickCounter_j = 0L;
  } else {
    hallsensor_DW.clockTickCounter_j++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator6' */

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (rtb_PulseGenerator5 < 256.0) {
    if (rtb_PulseGenerator5 >= 0.0) {
      rtb_PulseGenerator = (uint8_T)rtb_PulseGenerator5;
    } else {
      rtb_PulseGenerator = 0U;
    }
  } else {
    rtb_PulseGenerator = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S8>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S8>/Digital Output' */
  MW_digitalWrite(hallsensor_P.DigitalOutput_p1_lx, rtb_PulseGenerator);
  if (hallsensor_M->Timing.TaskCounters.TID[1] == 0) {
    /* DiscretePulseGenerator: '<S1>/Pulse Generator4' */
    rtb_PulseGenerator5 = (hallsensor_DW.clockTickCounter_br <
      hallsensor_P.PulseGenerator4_Duty) && (hallsensor_DW.clockTickCounter_br >=
      0L) ? hallsensor_P.PulseGenerator4_Amp : 0.0;
    if (hallsensor_DW.clockTickCounter_br >= hallsensor_P.PulseGenerator4_Period
        - 1.0) {
      hallsensor_DW.clockTickCounter_br = 0L;
    } else {
      hallsensor_DW.clockTickCounter_br++;
    }

    /* End of DiscretePulseGenerator: '<S1>/Pulse Generator4' */

    /* DataTypeConversion: '<S9>/Data Type Conversion' */
    if (rtb_PulseGenerator5 < 256.0) {
      if (rtb_PulseGenerator5 >= 0.0) {
        rtb_PulseGenerator = (uint8_T)rtb_PulseGenerator5;
      } else {
        rtb_PulseGenerator = 0U;
      }
    } else {
      rtb_PulseGenerator = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S9>/Data Type Conversion' */

    /* S-Function (arduinodigitaloutput_sfcn): '<S9>/Digital Output' */
    MW_digitalWrite(hallsensor_P.DigitalOutput_p1_g, rtb_PulseGenerator);

    /* DiscretePulseGenerator: '<S1>/Pulse Generator1' */
    rtb_PulseGenerator5 = (hallsensor_DW.clockTickCounter_o <
      hallsensor_P.PulseGenerator1_Duty) && (hallsensor_DW.clockTickCounter_o >=
      0L) ? hallsensor_P.PulseGenerator1_Amp : 0.0;
    if (hallsensor_DW.clockTickCounter_o >= hallsensor_P.PulseGenerator1_Period
        - 1.0) {
      hallsensor_DW.clockTickCounter_o = 0L;
    } else {
      hallsensor_DW.clockTickCounter_o++;
    }

    /* End of DiscretePulseGenerator: '<S1>/Pulse Generator1' */

    /* DataTypeConversion: '<S10>/Data Type Conversion' */
    if (rtb_PulseGenerator5 < 256.0) {
      if (rtb_PulseGenerator5 >= 0.0) {
        rtb_PulseGenerator = (uint8_T)rtb_PulseGenerator5;
      } else {
        rtb_PulseGenerator = 0U;
      }
    } else {
      rtb_PulseGenerator = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S10>/Data Type Conversion' */

    /* S-Function (arduinodigitaloutput_sfcn): '<S10>/Digital Output' */
    MW_digitalWrite(hallsensor_P.DigitalOutput_p1_ka, rtb_PulseGenerator);
  }

  /* DiscretePulseGenerator: '<S1>/Pulse Generator5' */
  rtb_PulseGenerator5 = (hallsensor_DW.clockTickCounter_jo <
    hallsensor_P.PulseGenerator5_Duty) && (hallsensor_DW.clockTickCounter_jo >=
    0L) ? hallsensor_P.PulseGenerator5_Amp : 0.0;
  if (hallsensor_DW.clockTickCounter_jo >= hallsensor_P.PulseGenerator5_Period -
      1.0) {
    hallsensor_DW.clockTickCounter_jo = 0L;
  } else {
    hallsensor_DW.clockTickCounter_jo++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator5' */

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (rtb_PulseGenerator5 < 256.0) {
    if (rtb_PulseGenerator5 >= 0.0) {
      rtb_PulseGenerator = (uint8_T)rtb_PulseGenerator5;
    } else {
      rtb_PulseGenerator = 0U;
    }
  } else {
    rtb_PulseGenerator = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S11>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S11>/Digital Output' */
  MW_digitalWrite(hallsensor_P.DigitalOutput_p1_oo, rtb_PulseGenerator);
}

/* Model update function */
void hallsensor_update(void)
{
  rate_scheduler();
}

/* Model initialize function */
void hallsensor_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)hallsensor_M, 0,
                sizeof(RT_MODEL_hallsensor_T));

  /* states (dwork) */
  (void) memset((void *)&hallsensor_DW, 0,
                sizeof(DW_hallsensor_T));

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S12>/Digital Output' */
  MW_pinModeOutput(hallsensor_P.DigitalOutput_p1);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S13>/Digital Output' */
  MW_pinModeOutput(hallsensor_P.DigitalOutput_p1_k);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S3>/Digital Output' */
  MW_pinModeOutput(hallsensor_P.DigitalOutput_p1_f);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S5>/Digital Output' */
  MW_pinModeOutput(hallsensor_P.DigitalOutput_p1_o);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S6>/Digital Output' */
  MW_pinModeOutput(hallsensor_P.DigitalOutput_p1_c);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S4>/Digital Output' */
  MW_pinModeOutput(hallsensor_P.DigitalOutput_p1_l);

  /* Start for DiscretePulseGenerator: '<S1>/Pulse Generator3' */
  hallsensor_DW.clockTickCounter = -2L;

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' */
  MW_pinModeOutput(hallsensor_P.DigitalOutput_p1_b);

  /* Start for DiscretePulseGenerator: '<S1>/Pulse Generator2' */
  hallsensor_DW.clockTickCounter_b = -5L;

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S7>/Digital Output' */
  MW_pinModeOutput(hallsensor_P.DigitalOutput_p1_kc);

  /* Start for DiscretePulseGenerator: '<S1>/Pulse Generator6' */
  hallsensor_DW.clockTickCounter_j = -3L;

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S8>/Digital Output' */
  MW_pinModeOutput(hallsensor_P.DigitalOutput_p1_lx);

  /* Start for DiscretePulseGenerator: '<S1>/Pulse Generator4' */
  hallsensor_DW.clockTickCounter_br = 0L;

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S9>/Digital Output' */
  MW_pinModeOutput(hallsensor_P.DigitalOutput_p1_g);

  /* Start for DiscretePulseGenerator: '<S1>/Pulse Generator1' */
  hallsensor_DW.clockTickCounter_o = -1L;

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S10>/Digital Output' */
  MW_pinModeOutput(hallsensor_P.DigitalOutput_p1_ka);

  /* Start for DiscretePulseGenerator: '<S1>/Pulse Generator5' */
  hallsensor_DW.clockTickCounter_jo = -7L;

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S11>/Digital Output' */
  MW_pinModeOutput(hallsensor_P.DigitalOutput_p1_oo);
}

/* Model terminate function */
void hallsensor_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
