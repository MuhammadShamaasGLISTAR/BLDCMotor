/*
 * File: hallsensor_data.c
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

/* Block parameters (auto storage) */
P_hallsensor_T hallsensor_P = {
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Constant3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Constant4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Constant5'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator3'
                                        */
  6.0,                                 /* Computed Parameter: PulseGenerator3_Period
                                        * Referenced by: '<S1>/Pulse Generator3'
                                        */
  3.0,                                 /* Computed Parameter: PulseGenerator3_Duty
                                        * Referenced by: '<S1>/Pulse Generator3'
                                        */
  3.3333333333333337E-6,               /* Expression: T/3
                                        * Referenced by: '<S1>/Pulse Generator3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  6.0,                                 /* Computed Parameter: PulseGenerator2_Period
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  3.0,                                 /* Computed Parameter: PulseGenerator2_Duty
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  8.3333333333333337E-6,               /* Expression: T/3+T/2
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator6'
                                        */
  6.0,                                 /* Computed Parameter: PulseGenerator6_Period
                                        * Referenced by: '<S1>/Pulse Generator6'
                                        */
  3.0,                                 /* Computed Parameter: PulseGenerator6_Duty
                                        * Referenced by: '<S1>/Pulse Generator6'
                                        */
  6.6666666666666666E-6,               /* Expression: T*(2/3)
                                        * Referenced by: '<S1>/Pulse Generator6'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator4'
                                        */
  2.0,                                 /* Computed Parameter: PulseGenerator4_Period
                                        * Referenced by: '<S1>/Pulse Generator4'
                                        */
  1.0,                                 /* Computed Parameter: PulseGenerator4_Duty
                                        * Referenced by: '<S1>/Pulse Generator4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Pulse Generator4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  2.0,                                 /* Computed Parameter: PulseGenerator1_Period
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  1.0,                                 /* Computed Parameter: PulseGenerator1_Duty
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  5.0E-6,                              /* Expression: T/2
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator5'
                                        */
  6.0,                                 /* Computed Parameter: PulseGenerator5_Period
                                        * Referenced by: '<S1>/Pulse Generator5'
                                        */
  3.0,                                 /* Computed Parameter: PulseGenerator5_Duty
                                        * Referenced by: '<S1>/Pulse Generator5'
                                        */
  1.1666666666666668E-5,               /* Expression: T*(2/3)+T/2
                                        * Referenced by: '<S1>/Pulse Generator5'
                                        */
  8U,                                  /* Computed Parameter: DigitalOutput_p1
                                        * Referenced by: '<S12>/Digital Output'
                                        */
  10U,                                 /* Computed Parameter: DigitalOutput_p1_k
                                        * Referenced by: '<S13>/Digital Output'
                                        */
  12U,                                 /* Computed Parameter: DigitalOutput_p1_f
                                        * Referenced by: '<S3>/Digital Output'
                                        */
  9U,                                  /* Computed Parameter: DigitalOutput_p1_o
                                        * Referenced by: '<S5>/Digital Output'
                                        */
  11U,                                 /* Computed Parameter: DigitalOutput_p1_c
                                        * Referenced by: '<S6>/Digital Output'
                                        */
  13U,                                 /* Computed Parameter: DigitalOutput_p1_l
                                        * Referenced by: '<S4>/Digital Output'
                                        */
  4U,                                  /* Computed Parameter: DigitalOutput_p1_b
                                        * Referenced by: '<S2>/Digital Output'
                                        */
  5U,                                  /* Computed Parameter: DigitalOutput_p1_kc
                                        * Referenced by: '<S7>/Digital Output'
                                        */
  6U,                                  /* Computed Parameter: DigitalOutput_p1_lx
                                        * Referenced by: '<S8>/Digital Output'
                                        */
  2U,                                  /* Computed Parameter: DigitalOutput_p1_g
                                        * Referenced by: '<S9>/Digital Output'
                                        */
  3U,                                  /* Computed Parameter: DigitalOutput_p1_ka
                                        * Referenced by: '<S10>/Digital Output'
                                        */
  7U                                   /* Computed Parameter: DigitalOutput_p1_oo
                                        * Referenced by: '<S11>/Digital Output'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
