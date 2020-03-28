/*
 * File: hallsensor.h
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

#ifndef RTW_HEADER_hallsensor_h_
#define RTW_HEADER_hallsensor_h_
#ifndef hallsensor_COMMON_INCLUDES_
# define hallsensor_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* hallsensor_COMMON_INCLUDES_ */

#include "hallsensor_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator3' */
  int32_T clockTickCounter_b;          /* '<S1>/Pulse Generator2' */
  int32_T clockTickCounter_j;          /* '<S1>/Pulse Generator6' */
  int32_T clockTickCounter_br;         /* '<S1>/Pulse Generator4' */
  int32_T clockTickCounter_o;          /* '<S1>/Pulse Generator1' */
  int32_T clockTickCounter_jo;         /* '<S1>/Pulse Generator5' */
} DW_hallsensor_T;

/* Parameters (auto storage) */
struct P_hallsensor_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T PulseGenerator3_Amp;          /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_Period;       /* Computed Parameter: PulseGenerator3_Period
                                        * Referenced by: '<S1>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_Duty;         /* Computed Parameter: PulseGenerator3_Duty
                                        * Referenced by: '<S1>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_PhaseDelay;   /* Expression: T/3
                                        * Referenced by: '<S1>/Pulse Generator3'
                                        */
  real_T PulseGenerator2_Amp;          /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Period;       /* Computed Parameter: PulseGenerator2_Period
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Duty;         /* Computed Parameter: PulseGenerator2_Duty
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_PhaseDelay;   /* Expression: T/3+T/2
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  real_T PulseGenerator6_Amp;          /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator6'
                                        */
  real_T PulseGenerator6_Period;       /* Computed Parameter: PulseGenerator6_Period
                                        * Referenced by: '<S1>/Pulse Generator6'
                                        */
  real_T PulseGenerator6_Duty;         /* Computed Parameter: PulseGenerator6_Duty
                                        * Referenced by: '<S1>/Pulse Generator6'
                                        */
  real_T PulseGenerator6_PhaseDelay;   /* Expression: T*(2/3)
                                        * Referenced by: '<S1>/Pulse Generator6'
                                        */
  real_T PulseGenerator4_Amp;          /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator4'
                                        */
  real_T PulseGenerator4_Period;       /* Computed Parameter: PulseGenerator4_Period
                                        * Referenced by: '<S1>/Pulse Generator4'
                                        */
  real_T PulseGenerator4_Duty;         /* Computed Parameter: PulseGenerator4_Duty
                                        * Referenced by: '<S1>/Pulse Generator4'
                                        */
  real_T PulseGenerator4_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S1>/Pulse Generator4'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;       /* Computed Parameter: PulseGenerator1_Period
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty;         /* Computed Parameter: PulseGenerator1_Duty
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: T/2
                                        * Referenced by: '<S1>/Pulse Generator1'
                                        */
  real_T PulseGenerator5_Amp;          /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator5'
                                        */
  real_T PulseGenerator5_Period;       /* Computed Parameter: PulseGenerator5_Period
                                        * Referenced by: '<S1>/Pulse Generator5'
                                        */
  real_T PulseGenerator5_Duty;         /* Computed Parameter: PulseGenerator5_Duty
                                        * Referenced by: '<S1>/Pulse Generator5'
                                        */
  real_T PulseGenerator5_PhaseDelay;   /* Expression: T*(2/3)+T/2
                                        * Referenced by: '<S1>/Pulse Generator5'
                                        */
  uint32_T DigitalOutput_p1;           /* Computed Parameter: DigitalOutput_p1
                                        * Referenced by: '<S12>/Digital Output'
                                        */
  uint32_T DigitalOutput_p1_k;         /* Computed Parameter: DigitalOutput_p1_k
                                        * Referenced by: '<S13>/Digital Output'
                                        */
  uint32_T DigitalOutput_p1_f;         /* Computed Parameter: DigitalOutput_p1_f
                                        * Referenced by: '<S3>/Digital Output'
                                        */
  uint32_T DigitalOutput_p1_o;         /* Computed Parameter: DigitalOutput_p1_o
                                        * Referenced by: '<S5>/Digital Output'
                                        */
  uint32_T DigitalOutput_p1_c;         /* Computed Parameter: DigitalOutput_p1_c
                                        * Referenced by: '<S6>/Digital Output'
                                        */
  uint32_T DigitalOutput_p1_l;         /* Computed Parameter: DigitalOutput_p1_l
                                        * Referenced by: '<S4>/Digital Output'
                                        */
  uint32_T DigitalOutput_p1_b;         /* Computed Parameter: DigitalOutput_p1_b
                                        * Referenced by: '<S2>/Digital Output'
                                        */
  uint32_T DigitalOutput_p1_kc;        /* Computed Parameter: DigitalOutput_p1_kc
                                        * Referenced by: '<S7>/Digital Output'
                                        */
  uint32_T DigitalOutput_p1_lx;        /* Computed Parameter: DigitalOutput_p1_lx
                                        * Referenced by: '<S8>/Digital Output'
                                        */
  uint32_T DigitalOutput_p1_g;         /* Computed Parameter: DigitalOutput_p1_g
                                        * Referenced by: '<S9>/Digital Output'
                                        */
  uint32_T DigitalOutput_p1_ka;        /* Computed Parameter: DigitalOutput_p1_ka
                                        * Referenced by: '<S10>/Digital Output'
                                        */
  uint32_T DigitalOutput_p1_oo;        /* Computed Parameter: DigitalOutput_p1_oo
                                        * Referenced by: '<S11>/Digital Output'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_hallsensor_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_hallsensor_T hallsensor_P;

/* Block states (auto storage) */
extern DW_hallsensor_T hallsensor_DW;

/* Model entry point functions */
extern void hallsensor_initialize(void);
extern void hallsensor_output(void);
extern void hallsensor_update(void);
extern void hallsensor_terminate(void);

/* Real-time Model object */
extern RT_MODEL_hallsensor_T *const hallsensor_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'hallsensor'
 * '<S1>'   : 'hallsensor/Subsystem'
 * '<S2>'   : 'hallsensor/Subsystem/Digital Output1'
 * '<S3>'   : 'hallsensor/Subsystem/Digital Output10'
 * '<S4>'   : 'hallsensor/Subsystem/Digital Output11'
 * '<S5>'   : 'hallsensor/Subsystem/Digital Output12'
 * '<S6>'   : 'hallsensor/Subsystem/Digital Output13'
 * '<S7>'   : 'hallsensor/Subsystem/Digital Output2'
 * '<S8>'   : 'hallsensor/Subsystem/Digital Output3'
 * '<S9>'   : 'hallsensor/Subsystem/Digital Output4'
 * '<S10>'  : 'hallsensor/Subsystem/Digital Output5'
 * '<S11>'  : 'hallsensor/Subsystem/Digital Output6'
 * '<S12>'  : 'hallsensor/Subsystem/Digital Output8'
 * '<S13>'  : 'hallsensor/Subsystem/Digital Output9'
 */
#endif                                 /* RTW_HEADER_hallsensor_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
