/*
 * File: STMpil_data.c
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

#include "STMpil.h"
#include "STMpil_private.h"

/* Block parameters (default storage) */
P_STMpil_T STMpil_P = {
  /* Mask Parameter: Battery_BatType
   * Referenced by:
   *   '<S117>/Constant'
   *   '<S118>/Constant'
   */
  2.0,

  /* Mask Parameter: PIDController4_I
   * Referenced by: '<S84>/Integral Gain'
   */
  -200000.0,

  /* Mask Parameter: PIDController3_I
   * Referenced by: '<S36>/Integral Gain'
   */
  1000.0,

  /* Mask Parameter: PIDController4_InitialCondition
   * Referenced by: '<S87>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController3_InitialCondition
   * Referenced by: '<S39>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController3_LowerSaturationL
   * Referenced by: '<S46>/Saturation'
   */
  0.0,

  /* Mask Parameter: PIDController4_LowerSaturationL
   * Referenced by: '<S94>/Saturation'
   */
  0.0,

  /* Mask Parameter: RepeatingSequenceStair_OutValue
   * Referenced by: '<S7>/Vector'
   */
  { 0.0, 1.0 },

  /* Mask Parameter: PIDController3_P
   * Referenced by: '<S44>/Proportional Gain'
   */
  50.0,

  /* Mask Parameter: PIDController4_P
   * Referenced by: '<S92>/Proportional Gain'
   */
  0.0,

  /* Mask Parameter: Battery_SOC
   * Referenced by:
   *   '<S113>/it init'
   *   '<S118>/Discrete-Time Integrator'
   */
  40.0,

  /* Mask Parameter: PIDController3_UpperSaturationL
   * Referenced by: '<S46>/Saturation'
   */
  22.0,

  /* Mask Parameter: PIDController4_UpperSaturationL
   * Referenced by: '<S94>/Saturation'
   */
  0.95,

  /* Mask Parameter: LimitedCounter_uplimit
   * Referenced by: '<S106>/FixPt Switch'
   */
  1U,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S87>/Integrator'
   */
  0.001,

  /* Expression: 26
   * Referenced by: '<S2>/Constant4'
   */
  26.0,

  /* Computed Parameter: Integrator_gainval_fnnq
   * Referenced by: '<S39>/Integrator'
   */
  0.001,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S117>/Constant2'
   */
  0.0,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S117>/Constant3'
   */
  0.0,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S117>/Constant1'
   */
  1.0,

  /* Computed Parameter: Constant4_Value_mb1d
   * Referenced by: '<S117>/Constant4'
   */
  0.0,

  /* Expression: Batt.Qmax*(1/Batt.lambda)
   * Referenced by: '<S118>/Saturation'
   */
  2.05,

  /* Expression: -inf
   * Referenced by: '<S118>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S123>/0 4'
   */
  0.0,

  /* Expression: 1./Ron
   * Referenced by: '<S123>/1//Rsw'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S125>/0 1'
   */
  0.0,

  /* Expression: 1./Ron
   * Referenced by: '<S125>/1//Rsw'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S115>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S116>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S122>/Constant'
   */
  0.0,

  /* Expression: Batt.Q
   * Referenced by: '<S113>/it init1'
   */
  2.1750499999999882,

  /* Expression: [1-exp(-Ts/(Batt_Tr/3))]
   * Referenced by: '<S113>/Current filter'
   */
  0.0029955044966269995,

  /* Expression: [1 -exp(-Ts/(Batt_Tr/3))]
   * Referenced by: '<S113>/Current filter'
   */
  { 1.0, -0.997004495503373 },

  /* Expression: 0
   * Referenced by: '<S113>/Current filter'
   */
  0.0,

  /* Expression: 0.9999
   * Referenced by: '<S113>/R3'
   */
  0.9999,

  /* Computed Parameter: inti_gainval
   * Referenced by: '<S113>/int(i)'
   */
  0.001,

  /* Expression: Batt.Qmax*3600
   * Referenced by: '<S113>/int(i)'
   */
  7830.1799999999575,

  /* Expression: -inf
   * Referenced by: '<S113>/int(i)'
   */
  0.0,

  /* Expression: 1/3600
   * Referenced by: '<S113>/Gain'
   */
  0.00027777777777777778,

  /* Expression: zeros(2,1)
   * Referenced by: '<S129>/SwitchCurrents'
   */
  { 0.0, 0.0 },

  /* Expression: 2*Batt.E0
   * Referenced by: '<S113>/Constant1'
   */
  7.7918136168073424,

  /* Expression: Batt.E0
   * Referenced by: '<S113>/Constant'
   */
  3.8959068084036712,

  /* Expression: 0.9999
   * Referenced by: '<S113>/R2'
   */
  0.9999,

  /* Expression: 0
   * Referenced by: '<S113>/Constant9'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S118>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S113>/Memory2'
   */
  0.0,

  /* Expression: S.A
   * Referenced by: '<S127>/State-Space'
   */
  { 0.34042995001343307, -1.0963679489036209, 0.63150793856848542,
    0.36891141411001105 },

  /* Expression: S.B
   * Referenced by: '<S127>/State-Space'
   */
  { 668.23626485675675, -551.47307829852127, -668.23626485675675,
    551.47307829852127, 548.18397445181017, 1188.2911580816067,
    0.0066823626485675684, -0.0055147307829852121 },

  /* Expression: S.C
   * Referenced by: '<S127>/State-Space'
   */
  { -0.000668236264856757, 0.000668236264856757, -0.00054818397445181031,
    -0.00031764849309994815, 0.00031764849309994815, 0.00068445570705500552 },

  /* Expression: S.D
   * Referenced by: '<S127>/State-Space'
   */
  { -0.33612284122294878, 0.33612284122294878, -0.27573653914926066,
    0.33612284122294878, -0.33612284122294878, 0.27573653914926066,
    -0.27573653914926055, 0.27573653914926055, 0.59414557904080334,
    0.99999663877158773, 3.3612284122294882E-6, -2.757365391492606E-6 },

  /* Expression: S.x0
   * Referenced by: '<S127>/State-Space'
   */
  { 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S112>/do not delete this gain'
   */
  1.0,

  /* Expression: Batt.R
   * Referenced by: '<S113>/R'
   */
  0.017,

  /* Expression: Batt.A
   * Referenced by: '<S118>/Gain4'
   */
  0.21089319159632841,

  /* Expression: Batt.B/3600
   * Referenced by: '<S118>/Gain1'
   */
  0.0041666666666666666,

  /* Expression: Batt.R
   * Referenced by: '<S113>/R1'
   */
  0.017,

  /* Expression: 0.5
   * Referenced by: '<S123>/Switch'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S125>/Switch'
   */
  0.5,

  /* Expression: 1/Batt.lambda
   * Referenced by: '<S113>/R4'
   */
  0.942507068803021,

  /* Expression: 100
   * Referenced by: '<S113>/Saturation'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S113>/Saturation'
   */
  0.0,

  /* Expression: 3600
   * Referenced by: '<S113>/Gain2'
   */
  3600.0,

  /* Expression: Batt.Q
   * Referenced by: '<S113>/Constant12'
   */
  2.1750499999999882,

  /* Expression: Batt.Ta
   * Referenced by: '<S107>/Ta'
   */
  115.0,

  /* Expression: 1
   * Referenced by: '<S3>/Constant'
   */
  1.0,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S104>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S105>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Constant_Value_ip42
   * Referenced by: '<S106>/Constant'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
