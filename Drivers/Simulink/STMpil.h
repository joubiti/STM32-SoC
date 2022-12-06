/*
 * File: STMpil.h
 *
 * Code generated for Simulink model 'STMpil'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Dec  4 17:34:07 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_STMpil_h_
#define RTW_HEADER_STMpil_h_
#include <math.h>
#include <string.h>
#ifndef STMpil_COMMON_INCLUDES_
# define STMpil_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* STMpil_COMMON_INCLUDES_ */

#include "STMpil_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */

/* Block signals (default storage) */
typedef struct {
  real_T Switch2;                      /* '<S119>/Switch2' */
  real_T StateSpace_o1[3];             /* '<S127>/State-Space' */
  real_T StateSpace_o2[2];             /* '<S127>/State-Space' */
  real_T DataTypeConversion;           /* '<S123>/Data Type Conversion' */
  real_T DataTypeConversion_ni55;      /* '<S125>/Data Type Conversion' */
} B_STMpil_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Currentfilter_states;         /* '<S113>/Current filter' */
  real_T inti_DSTATE;                  /* '<S113>/int(i)' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S118>/Discrete-Time Integrator' */
  real_T StateSpace_DSTATE[2];         /* '<S127>/State-Space' */
  real_T Integrator_DSTATE;            /* '<S87>/Integrator' */
  real_T Integrator_DSTATE_hwv3;       /* '<S39>/Integrator' */
  real_T itinit1_PreviousInput;        /* '<S113>/it init1' */
  real_T itinit_PreviousInput;         /* '<S113>/it init' */
  real_T Memory2_PreviousInput;        /* '<S113>/Memory2' */
  struct {
    void *AS;
    void *BS;
    void *CS;
    void *DS;
    void *DX_COL;
    void *BD_COL;
    void *TMP1;
    void *TMP2;
    void *XTMP;
    void *SWITCH_STATUS;
    void *SWITCH_STATUS_INIT;
    void *SW_CHG;
    void *G_STATE;
    void *USWLAST;
    void *XKM12;
    void *XKP12;
    void *XLAST;
    void *ULAST;
    void *IDX_SW_CHG;
    void *Y_SWITCH;
    void *SWITCH_TYPES;
    void *IDX_OUT_SW;
    void *SWITCH_TOPO_SAVED_IDX;
    void *SWITCH_MAP;
  } StateSpace_PWORK;                  /* '<S127>/State-Space' */

  int_T StateSpace_IWORK[11];          /* '<S127>/State-Space' */
  uint8_T Output_DSTATE;               /* '<S104>/Output' */
  int8_T inti_PrevResetState;          /* '<S113>/int(i)' */
  uint8_T inti_IC_LOADING;             /* '<S113>/int(i)' */
} DW_STMpil_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
} ExtU_STMpil_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T SOC;                          /* '<Root>/<SOC (%)>' */
  real_T CurrentA;                     /* '<Root>/<Current (A)>' */
  real_T VoltageV;                     /* '<Root>/<Voltage (V)>' */
} ExtY_STMpil_T;

/* Parameters (default storage) */
struct P_STMpil_T_ {
  real_T Battery_BatType;              /* Mask Parameter: Battery_BatType
                                        * Referenced by:
                                        *   '<S117>/Constant'
                                        *   '<S118>/Constant'
                                        */
  real_T PIDController4_I;             /* Mask Parameter: PIDController4_I
                                        * Referenced by: '<S84>/Integral Gain'
                                        */
  real_T PIDController3_I;             /* Mask Parameter: PIDController3_I
                                        * Referenced by: '<S36>/Integral Gain'
                                        */
  real_T PIDController4_InitialCondition;
                              /* Mask Parameter: PIDController4_InitialCondition
                               * Referenced by: '<S87>/Integrator'
                               */
  real_T PIDController3_InitialCondition;
                              /* Mask Parameter: PIDController3_InitialCondition
                               * Referenced by: '<S39>/Integrator'
                               */
  real_T PIDController3_LowerSaturationL;
                              /* Mask Parameter: PIDController3_LowerSaturationL
                               * Referenced by: '<S46>/Saturation'
                               */
  real_T PIDController4_LowerSaturationL;
                              /* Mask Parameter: PIDController4_LowerSaturationL
                               * Referenced by: '<S94>/Saturation'
                               */
  real_T RepeatingSequenceStair_OutValue[2];
                              /* Mask Parameter: RepeatingSequenceStair_OutValue
                               * Referenced by: '<S7>/Vector'
                               */
  real_T PIDController3_P;             /* Mask Parameter: PIDController3_P
                                        * Referenced by: '<S44>/Proportional Gain'
                                        */
  real_T PIDController4_P;             /* Mask Parameter: PIDController4_P
                                        * Referenced by: '<S92>/Proportional Gain'
                                        */
  real_T Battery_SOC;                  /* Mask Parameter: Battery_SOC
                                        * Referenced by:
                                        *   '<S113>/it init'
                                        *   '<S118>/Discrete-Time Integrator'
                                        */
  real_T PIDController3_UpperSaturationL;
                              /* Mask Parameter: PIDController3_UpperSaturationL
                               * Referenced by: '<S46>/Saturation'
                               */
  real_T PIDController4_UpperSaturationL;
                              /* Mask Parameter: PIDController4_UpperSaturationL
                               * Referenced by: '<S94>/Saturation'
                               */
  uint8_T LimitedCounter_uplimit;      /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S106>/FixPt Switch'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S87>/Integrator'
                                        */
  real_T Constant4_Value;              /* Expression: 26
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Integrator_gainval_fnnq; /* Computed Parameter: Integrator_gainval_fnnq
                                   * Referenced by: '<S39>/Integrator'
                                   */
  real_T Constant2_Value;              /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S117>/Constant2'
                                        */
  real_T Constant3_Value;              /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S117>/Constant3'
                                        */
  real_T Constant1_Value;              /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S117>/Constant1'
                                        */
  real_T Constant4_Value_mb1d;       /* Computed Parameter: Constant4_Value_mb1d
                                      * Referenced by: '<S117>/Constant4'
                                      */
  real_T Saturation_UpperSat;          /* Expression: Batt.Qmax*(1/Batt.lambda)
                                        * Referenced by: '<S118>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -inf
                                        * Referenced by: '<S118>/Saturation'
                                        */
  real_T u4_Value;                     /* Expression: 0
                                        * Referenced by: '<S123>/0 4'
                                        */
  real_T uRsw_Gain;                    /* Expression: 1./Ron
                                        * Referenced by: '<S123>/1//Rsw'
                                        */
  real_T u1_Value;                     /* Expression: 0
                                        * Referenced by: '<S125>/0 1'
                                        */
  real_T uRsw_Gain_o03j;               /* Expression: 1./Ron
                                        * Referenced by: '<S125>/1//Rsw'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S115>/Constant'
                                        */
  real_T Constant_Value_dbuc;          /* Expression: 0
                                        * Referenced by: '<S116>/Constant'
                                        */
  real_T Constant_Value_axhw;          /* Expression: 0
                                        * Referenced by: '<S122>/Constant'
                                        */
  real_T itinit1_InitialCondition;     /* Expression: Batt.Q
                                        * Referenced by: '<S113>/it init1'
                                        */
  real_T Currentfilter_NumCoef;        /* Expression: [1-exp(-Ts/(Batt_Tr/3))]
                                        * Referenced by: '<S113>/Current filter'
                                        */
  real_T Currentfilter_DenCoef[2];     /* Expression: [1 -exp(-Ts/(Batt_Tr/3))]
                                        * Referenced by: '<S113>/Current filter'
                                        */
  real_T Currentfilter_InitialStates;  /* Expression: 0
                                        * Referenced by: '<S113>/Current filter'
                                        */
  real_T R3_Gain;                      /* Expression: 0.9999
                                        * Referenced by: '<S113>/R3'
                                        */
  real_T inti_gainval;                 /* Computed Parameter: inti_gainval
                                        * Referenced by: '<S113>/int(i)'
                                        */
  real_T inti_UpperSat;                /* Expression: Batt.Qmax*3600
                                        * Referenced by: '<S113>/int(i)'
                                        */
  real_T inti_LowerSat;                /* Expression: -inf
                                        * Referenced by: '<S113>/int(i)'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/3600
                                        * Referenced by: '<S113>/Gain'
                                        */
  real_T SwitchCurrents_Value[2];      /* Expression: zeros(2,1)
                                        * Referenced by: '<S129>/SwitchCurrents'
                                        */
  real_T Constant1_Value_hyh3;         /* Expression: 2*Batt.E0
                                        * Referenced by: '<S113>/Constant1'
                                        */
  real_T Constant_Value_j1kh;          /* Expression: Batt.E0
                                        * Referenced by: '<S113>/Constant'
                                        */
  real_T R2_Gain;                      /* Expression: 0.9999
                                        * Referenced by: '<S113>/R2'
                                        */
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<S113>/Constant9'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S118>/Discrete-Time Integrator'
                            */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S113>/Memory2'
                                        */
  real_T StateSpace_AS_param[4];       /* Expression: S.A
                                        * Referenced by: '<S127>/State-Space'
                                        */
  real_T StateSpace_BS_param[8];       /* Expression: S.B
                                        * Referenced by: '<S127>/State-Space'
                                        */
  real_T StateSpace_CS_param[6];       /* Expression: S.C
                                        * Referenced by: '<S127>/State-Space'
                                        */
  real_T StateSpace_DS_param[12];      /* Expression: S.D
                                        * Referenced by: '<S127>/State-Space'
                                        */
  real_T StateSpace_X0_param[2];       /* Expression: S.x0
                                        * Referenced by: '<S127>/State-Space'
                                        */
  real_T donotdeletethisgain_Gain;     /* Expression: 1
                                        * Referenced by: '<S112>/do not delete this gain'
                                        */
  real_T R_Gain;                       /* Expression: Batt.R
                                        * Referenced by: '<S113>/R'
                                        */
  real_T Gain4_Gain;                   /* Expression: Batt.A
                                        * Referenced by: '<S118>/Gain4'
                                        */
  real_T Gain1_Gain;                   /* Expression: Batt.B/3600
                                        * Referenced by: '<S118>/Gain1'
                                        */
  real_T R1_Gain;                      /* Expression: Batt.R
                                        * Referenced by: '<S113>/R1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S123>/Switch'
                                        */
  real_T Switch_Threshold_anv1;        /* Expression: 0.5
                                        * Referenced by: '<S125>/Switch'
                                        */
  real_T R4_Gain;                      /* Expression: 1/Batt.lambda
                                        * Referenced by: '<S113>/R4'
                                        */
  real_T Saturation_UpperSat_egqb;     /* Expression: 100
                                        * Referenced by: '<S113>/Saturation'
                                        */
  real_T Saturation_LowerSat_dzqb;     /* Expression: 0
                                        * Referenced by: '<S113>/Saturation'
                                        */
  real_T Gain2_Gain;                   /* Expression: 3600
                                        * Referenced by: '<S113>/Gain2'
                                        */
  real_T Constant12_Value;             /* Expression: Batt.Q
                                        * Referenced by: '<S113>/Constant12'
                                        */
  real_T Ta_Value;                     /* Expression: Batt.Ta
                                        * Referenced by: '<S107>/Ta'
                                        */
  real_T Constant_Value_fyee;          /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  uint8_T Output_InitialCondition;/* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S104>/Output'
                                   */
  uint8_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S105>/FixPt Constant'
                                       */
  uint8_T Constant_Value_ip42;        /* Computed Parameter: Constant_Value_ip42
                                       * Referenced by: '<S106>/Constant'
                                       */
};

/* Block parameters (default storage) */
extern P_STMpil_T STMpil_P;

/* Block signals (default storage) */
extern B_STMpil_T STMpil_B;

/* Block states (default storage) */
extern DW_STMpil_T STMpil_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_STMpil_T STMpil_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_STMpil_T STMpil_Y;

/* Model entry point functions */
extern void STMpil_initialize(void);
extern void STMpil_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('batterycharger/STMpil')    - opens subsystem batterycharger/STMpil
 * hilite_system('batterycharger/STMpil/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'batterycharger'
 * '<S1>'   : 'batterycharger/STMpil'
 * '<S2>'   : 'batterycharger/STMpil/MyPIL'
 * '<S3>'   : 'batterycharger/STMpil/Plant'
 * '<S4>'   : 'batterycharger/STMpil/powergui'
 * '<S5>'   : 'batterycharger/STMpil/MyPIL/PID Controller3'
 * '<S6>'   : 'batterycharger/STMpil/MyPIL/PID Controller4'
 * '<S7>'   : 'batterycharger/STMpil/MyPIL/Repeating Sequence Stair'
 * '<S8>'   : 'batterycharger/STMpil/MyPIL/PID Controller3/Anti-windup'
 * '<S9>'   : 'batterycharger/STMpil/MyPIL/PID Controller3/D Gain'
 * '<S10>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Filter'
 * '<S11>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Filter ICs'
 * '<S12>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/I Gain'
 * '<S13>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Ideal P Gain'
 * '<S14>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Ideal P Gain Fdbk'
 * '<S15>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Integrator'
 * '<S16>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Integrator ICs'
 * '<S17>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/N Copy'
 * '<S18>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/N Gain'
 * '<S19>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/P Copy'
 * '<S20>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Parallel P Gain'
 * '<S21>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Reset Signal'
 * '<S22>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Saturation'
 * '<S23>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Saturation Fdbk'
 * '<S24>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Sum'
 * '<S25>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Sum Fdbk'
 * '<S26>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Tracking Mode'
 * '<S27>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Tracking Mode Sum'
 * '<S28>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Tsamp - Integral'
 * '<S29>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Tsamp - Ngain'
 * '<S30>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/postSat Signal'
 * '<S31>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/preSat Signal'
 * '<S32>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Anti-windup/Passthrough'
 * '<S33>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/D Gain/Disabled'
 * '<S34>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Filter/Disabled'
 * '<S35>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Filter ICs/Disabled'
 * '<S36>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/I Gain/Internal Parameters'
 * '<S37>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Ideal P Gain/Passthrough'
 * '<S38>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S39>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Integrator/Discrete'
 * '<S40>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Integrator ICs/Internal IC'
 * '<S41>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S42>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/N Gain/Disabled'
 * '<S43>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/P Copy/Disabled'
 * '<S44>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S45>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Reset Signal/Disabled'
 * '<S46>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Saturation/Enabled'
 * '<S47>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Saturation Fdbk/Disabled'
 * '<S48>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Sum/Sum_PI'
 * '<S49>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Sum Fdbk/Disabled'
 * '<S50>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Tracking Mode/Disabled'
 * '<S51>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S52>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S53>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S54>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/postSat Signal/Forward_Path'
 * '<S55>'  : 'batterycharger/STMpil/MyPIL/PID Controller3/preSat Signal/Forward_Path'
 * '<S56>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Anti-windup'
 * '<S57>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/D Gain'
 * '<S58>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Filter'
 * '<S59>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Filter ICs'
 * '<S60>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/I Gain'
 * '<S61>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Ideal P Gain'
 * '<S62>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Ideal P Gain Fdbk'
 * '<S63>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Integrator'
 * '<S64>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Integrator ICs'
 * '<S65>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/N Copy'
 * '<S66>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/N Gain'
 * '<S67>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/P Copy'
 * '<S68>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Parallel P Gain'
 * '<S69>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Reset Signal'
 * '<S70>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Saturation'
 * '<S71>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Saturation Fdbk'
 * '<S72>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Sum'
 * '<S73>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Sum Fdbk'
 * '<S74>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Tracking Mode'
 * '<S75>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Tracking Mode Sum'
 * '<S76>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Tsamp - Integral'
 * '<S77>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Tsamp - Ngain'
 * '<S78>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/postSat Signal'
 * '<S79>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/preSat Signal'
 * '<S80>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Anti-windup/Passthrough'
 * '<S81>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/D Gain/Disabled'
 * '<S82>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Filter/Disabled'
 * '<S83>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Filter ICs/Disabled'
 * '<S84>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/I Gain/Internal Parameters'
 * '<S85>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Ideal P Gain/Passthrough'
 * '<S86>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Ideal P Gain Fdbk/Disabled'
 * '<S87>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Integrator/Discrete'
 * '<S88>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Integrator ICs/Internal IC'
 * '<S89>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/N Copy/Disabled wSignal Specification'
 * '<S90>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/N Gain/Disabled'
 * '<S91>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/P Copy/Disabled'
 * '<S92>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Parallel P Gain/Internal Parameters'
 * '<S93>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Reset Signal/Disabled'
 * '<S94>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Saturation/Enabled'
 * '<S95>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Saturation Fdbk/Disabled'
 * '<S96>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Sum/Sum_PI'
 * '<S97>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Sum Fdbk/Disabled'
 * '<S98>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Tracking Mode/Disabled'
 * '<S99>'  : 'batterycharger/STMpil/MyPIL/PID Controller4/Tracking Mode Sum/Passthrough'
 * '<S100>' : 'batterycharger/STMpil/MyPIL/PID Controller4/Tsamp - Integral/Passthrough'
 * '<S101>' : 'batterycharger/STMpil/MyPIL/PID Controller4/Tsamp - Ngain/Passthrough'
 * '<S102>' : 'batterycharger/STMpil/MyPIL/PID Controller4/postSat Signal/Forward_Path'
 * '<S103>' : 'batterycharger/STMpil/MyPIL/PID Controller4/preSat Signal/Forward_Path'
 * '<S104>' : 'batterycharger/STMpil/MyPIL/Repeating Sequence Stair/LimitedCounter'
 * '<S105>' : 'batterycharger/STMpil/MyPIL/Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S106>' : 'batterycharger/STMpil/MyPIL/Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 * '<S107>' : 'batterycharger/STMpil/Plant/Battery'
 * '<S108>' : 'batterycharger/STMpil/Plant/Controlled Voltage Source'
 * '<S109>' : 'batterycharger/STMpil/Plant/IGBT//Diode'
 * '<S110>' : 'batterycharger/STMpil/Plant/Ideal Switch'
 * '<S111>' : 'batterycharger/STMpil/Plant/Battery/Controlled Voltage Source'
 * '<S112>' : 'batterycharger/STMpil/Plant/Battery/Current Measurement'
 * '<S113>' : 'batterycharger/STMpil/Plant/Battery/Model'
 * '<S114>' : 'batterycharger/STMpil/Plant/Battery/Current Measurement/Model'
 * '<S115>' : 'batterycharger/STMpil/Plant/Battery/Model/Compare To Zero'
 * '<S116>' : 'batterycharger/STMpil/Plant/Battery/Model/Compare To Zero2'
 * '<S117>' : 'batterycharger/STMpil/Plant/Battery/Model/E_dyn Charge'
 * '<S118>' : 'batterycharger/STMpil/Plant/Battery/Model/Exp'
 * '<S119>' : 'batterycharger/STMpil/Plant/Battery/Model/Saturation Dynamic'
 * '<S120>' : 'batterycharger/STMpil/Plant/Battery/Model/Saturation Dynamic1'
 * '<S121>' : 'batterycharger/STMpil/Plant/Battery/Model/Saturation Dynamic2'
 * '<S122>' : 'batterycharger/STMpil/Plant/Battery/Model/Exp/Compare To Zero2'
 * '<S123>' : 'batterycharger/STMpil/Plant/IGBT//Diode/Model'
 * '<S124>' : 'batterycharger/STMpil/Plant/IGBT//Diode/Model/Measurement list'
 * '<S125>' : 'batterycharger/STMpil/Plant/Ideal Switch/Model'
 * '<S126>' : 'batterycharger/STMpil/Plant/Ideal Switch/Model/Measurement list'
 * '<S127>' : 'batterycharger/STMpil/powergui/EquivalentModel1'
 * '<S128>' : 'batterycharger/STMpil/powergui/EquivalentModel1/Gates'
 * '<S129>' : 'batterycharger/STMpil/powergui/EquivalentModel1/Sources'
 * '<S130>' : 'batterycharger/STMpil/powergui/EquivalentModel1/Status'
 * '<S131>' : 'batterycharger/STMpil/powergui/EquivalentModel1/Yout'
 */

/*-
 * Requirements for '<Root>': STMpil
 */
#endif                                 /* RTW_HEADER_STMpil_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
