/*
 * File: STMpil.c
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

/* Block signals (default storage) */
B_STMpil_T STMpil_B;

/* Block states (default storage) */
DW_STMpil_T STMpil_DW;

/* External inputs (root inport signals with default storage) */
ExtU_STMpil_T STMpil_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_STMpil_T STMpil_Y;

/* Model step function */
void STMpil_step(void)
{
  real_T numAccum;
  real_T rtb_Integrator;
  real_T rtb_Gain;
  real_T rtb_Add3_ocsa;
  real_T rtb_Add4;
  int32_T rtb_DataTypeConversion2;

  /* Outputs for Atomic SubSystem: '<Root>/STMpil' */
  /* DiscreteTransferFcn: '<S113>/Current filter' */
  numAccum = STMpil_P.Currentfilter_NumCoef * STMpil_DW.Currentfilter_states;

  /* Gain: '<S113>/R3' incorporates:
   *  Memory: '<S113>/it init1'
   */
  rtb_Integrator = STMpil_P.R3_Gain * STMpil_DW.itinit1_PreviousInput;

  /* DataTypeConversion: '<S113>/Data Type Conversion2' incorporates:
   *  Constant: '<S115>/Constant'
   *  DiscreteTransferFcn: '<S113>/Current filter'
   *  RelationalOperator: '<S115>/Compare'
   */
  rtb_DataTypeConversion2 = (numAccum > STMpil_P.Constant_Value);

  /* DiscreteIntegrator: '<S113>/int(i)' incorporates:
   *  Memory: '<S113>/it init'
   */
  if (STMpil_DW.inti_IC_LOADING != 0) {
    STMpil_DW.inti_DSTATE = STMpil_DW.itinit_PreviousInput;
    if (STMpil_DW.inti_DSTATE >= STMpil_P.inti_UpperSat) {
      STMpil_DW.inti_DSTATE = STMpil_P.inti_UpperSat;
    } else {
      if (STMpil_DW.inti_DSTATE <= STMpil_P.inti_LowerSat) {
        STMpil_DW.inti_DSTATE = STMpil_P.inti_LowerSat;
      }
    }
  }

  if ((rtb_DataTypeConversion2 > 0) && (STMpil_DW.inti_PrevResetState <= 0)) {
    STMpil_DW.inti_DSTATE = STMpil_DW.itinit_PreviousInput;
    if (STMpil_DW.inti_DSTATE >= STMpil_P.inti_UpperSat) {
      STMpil_DW.inti_DSTATE = STMpil_P.inti_UpperSat;
    } else {
      if (STMpil_DW.inti_DSTATE <= STMpil_P.inti_LowerSat) {
        STMpil_DW.inti_DSTATE = STMpil_P.inti_LowerSat;
      }
    }
  }

  if (STMpil_DW.inti_DSTATE >= STMpil_P.inti_UpperSat) {
    STMpil_DW.inti_DSTATE = STMpil_P.inti_UpperSat;
  } else {
    if (STMpil_DW.inti_DSTATE <= STMpil_P.inti_LowerSat) {
      STMpil_DW.inti_DSTATE = STMpil_P.inti_LowerSat;
    }
  }

  /* Gain: '<S113>/Gain' incorporates:
   *  DiscreteIntegrator: '<S113>/int(i)'
   */
  rtb_Gain = STMpil_P.Gain_Gain * STMpil_DW.inti_DSTATE;

  /* Fcn: '<S113>/Fcn6' */
  rtb_Add3_ocsa = (((-rtb_Integrator) * 0.999) * 0.1) * 0.9999;

  /* Switch: '<S121>/Switch2' incorporates:
   *  RelationalOperator: '<S121>/LowerRelop1'
   *  RelationalOperator: '<S121>/UpperRelop'
   *  Switch: '<S121>/Switch'
   */
  if (rtb_Gain > rtb_Integrator) {
  } else if (rtb_Gain < rtb_Add3_ocsa) {
    /* Switch: '<S121>/Switch' */
    rtb_Integrator = rtb_Add3_ocsa;
  } else {
    rtb_Integrator = rtb_Gain;
  }

  /* End of Switch: '<S121>/Switch2' */

  /* Gain: '<S113>/R2' incorporates:
   *  Memory: '<S113>/it init1'
   */
  rtb_Add3_ocsa = STMpil_P.R2_Gain * STMpil_DW.itinit1_PreviousInput;

  /* Switch: '<S120>/Switch2' incorporates:
   *  Constant: '<S113>/Constant9'
   *  RelationalOperator: '<S120>/LowerRelop1'
   *  RelationalOperator: '<S120>/UpperRelop'
   *  Switch: '<S120>/Switch'
   */
  if (rtb_Gain > rtb_Add3_ocsa) {
    rtb_Gain = rtb_Add3_ocsa;
  } else {
    if (rtb_Gain < STMpil_P.Constant9_Value) {
      /* Switch: '<S120>/Switch' incorporates:
       *  Constant: '<S113>/Constant9'
       */
      rtb_Gain = STMpil_P.Constant9_Value;
    }
  }

  /* End of Switch: '<S120>/Switch2' */

  /* Switch: '<S113>/Switch7' incorporates:
   *  Fcn: '<S113>/Fcn9'
   *  RelationalOperator: '<S113>/Relational Operator'
   */
  if ((((1.000001 * rtb_Add3_ocsa) * 0.942507068803021) / 0.9999) <= rtb_Gain) {
    rtb_Gain = rtb_Add3_ocsa;
  }

  /* End of Switch: '<S113>/Switch7' */

  /* MultiPortSwitch: '<S117>/Multiport Switch1' incorporates:
   *  Constant: '<S116>/Constant'
   *  Constant: '<S117>/Constant'
   *  Constant: '<S117>/Constant1'
   *  Constant: '<S117>/Constant2'
   *  Constant: '<S117>/Constant3'
   *  Constant: '<S117>/Constant4'
   *  DataTypeConversion: '<S113>/Data Type Conversion1'
   *  DiscreteTransferFcn: '<S113>/Current filter'
   *  Fcn: '<S117>/Charge Lead-Acid'
   *  Fcn: '<S117>/Charge Li-Ion'
   *  Fcn: '<S117>/Charge NiCD'
   *  Fcn: '<S117>/Charge NiMH'
   *  Product: '<S117>/Product'
   *  Product: '<S117>/Product1'
   *  Product: '<S117>/Product2'
   *  Product: '<S117>/Product3'
   *  RelationalOperator: '<S116>/Compare'
   */
  switch ((int32_T)STMpil_P.Battery_BatType) {
   case 1:
    STMpil_Y.SOC = (((-(STMpil_P.Constant4_Value_mb1d * ((real_T)(numAccum <
      STMpil_P.Constant_Value_dbuc)))) * 0.029672835550368391) *
                    (STMpil_P.Constant4_Value_mb1d * numAccum)) *
      (2.1750499999999882 / ((STMpil_P.Constant4_Value_mb1d * rtb_Integrator) +
        0.21750499999999884));
    break;

   case 2:
    /* Product: '<S117>/Product' incorporates:
     *  Constant: '<S117>/Constant1'
     *  Memory: '<S113>/it init1'
     */
    rtb_Add3_ocsa = STMpil_P.Constant1_Value * STMpil_DW.itinit1_PreviousInput;
    STMpil_Y.SOC = ((((-(STMpil_P.Constant1_Value * ((real_T)(numAccum <
      STMpil_P.Constant_Value_dbuc)))) * 0.029672835550368391) *
                     (STMpil_P.Constant1_Value * numAccum)) * rtb_Add3_ocsa) /
      ((STMpil_P.Constant1_Value * rtb_Integrator) + (rtb_Add3_ocsa * 0.1));
    break;

   case 3:
    STMpil_Y.SOC = (((-(STMpil_P.Constant3_Value * ((real_T)(numAccum <
      STMpil_P.Constant_Value_dbuc)))) * 0.029672835550368391) *
                    (STMpil_P.Constant3_Value * numAccum)) * (2.1750499999999882
      / (fabs(STMpil_P.Constant3_Value * rtb_Integrator) + 0.21750499999999884));
    break;

   default:
    STMpil_Y.SOC = (((-(STMpil_P.Constant2_Value * ((real_T)(numAccum <
      STMpil_P.Constant_Value_dbuc)))) * 0.029672835550368391) *
                    (STMpil_P.Constant2_Value * numAccum)) * (2.1750499999999882
      / (fabs(STMpil_P.Constant2_Value * rtb_Integrator) + 0.21750499999999884));
    break;
  }

  /* End of MultiPortSwitch: '<S117>/Multiport Switch1' */

  /* MultiPortSwitch: '<S118>/Multiport Switch1' incorporates:
   *  Constant: '<S118>/Constant'
   *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator'
   *  Fcn: '<S118>/Li-Ion'
   */
  switch ((int32_T)STMpil_P.Battery_BatType) {
   case 1:
    rtb_Integrator = STMpil_DW.DiscreteTimeIntegrator_DSTATE;
    break;

   case 2:
    /* Saturate: '<S118>/Saturation' */
    if (rtb_Gain > STMpil_P.Saturation_UpperSat) {
      rtb_Integrator = STMpil_P.Saturation_UpperSat;
    } else if (rtb_Gain < STMpil_P.Saturation_LowerSat) {
      rtb_Integrator = STMpil_P.Saturation_LowerSat;
    } else {
      rtb_Integrator = rtb_Gain;
    }

    /* End of Saturate: '<S118>/Saturation' */
    rtb_Integrator = 0.21089319159632841 * exp(-15.0 * rtb_Integrator);
    break;

   case 3:
    rtb_Integrator = STMpil_DW.DiscreteTimeIntegrator_DSTATE;
    break;

   default:
    rtb_Integrator = STMpil_DW.DiscreteTimeIntegrator_DSTATE;
    break;
  }

  /* End of MultiPortSwitch: '<S118>/Multiport Switch1' */

  /* Fcn: '<S113>/E_NL' incorporates:
   *  Fcn: '<S113>/E_dyn Discharge'
   *  Memory: '<S113>/it init1'
   */
  rtb_Add3_ocsa = STMpil_DW.itinit1_PreviousInput - rtb_Gain;

  /* Sum: '<S113>/Add3' incorporates:
   *  Constant: '<S113>/Constant'
   *  DiscreteTransferFcn: '<S113>/Current filter'
   *  Fcn: '<S113>/E_NL'
   *  Fcn: '<S113>/E_dyn Discharge'
   *  Fcn: '<S113>/Fcn5'
   *  Memory: '<S113>/it init1'
   *  Sum: '<S113>/Add2'
   */
  rtb_Integrator = STMpil_P.Constant_Value_j1kh + (((((((-0.029672835550368391 *
    STMpil_DW.itinit1_PreviousInput) / rtb_Add3_ocsa) * rtb_Gain) +
    (((((-((real_T)rtb_DataTypeConversion2)) * 0.029672835550368391) * numAccum)
      * STMpil_DW.itinit1_PreviousInput) / rtb_Add3_ocsa)) + STMpil_Y.SOC) +
    rtb_Integrator) + (-0.0 * rtb_Gain));

  /* Switch: '<S119>/Switch2' incorporates:
   *  Constant: '<S113>/Constant1'
   *  Memory: '<S113>/Memory2'
   *  RelationalOperator: '<S119>/LowerRelop1'
   *  RelationalOperator: '<S119>/UpperRelop'
   *  Switch: '<S119>/Switch'
   */
  if (rtb_Integrator > STMpil_P.Constant1_Value_hyh3) {
    STMpil_B.Switch2 = STMpil_P.Constant1_Value_hyh3;
  } else if (rtb_Integrator < STMpil_DW.Memory2_PreviousInput) {
    /* Switch: '<S119>/Switch' incorporates:
     *  Memory: '<S113>/Memory2'
     */
    STMpil_B.Switch2 = STMpil_DW.Memory2_PreviousInput;
  } else {
    STMpil_B.Switch2 = rtb_Integrator;
  }

  /* End of Switch: '<S119>/Switch2' */

  /* S-Function (sfun_spssw_discc): '<S127>/State-Space' incorporates:
   *  Constant: '<S129>/SwitchCurrents'
   *  Inport: '<Root>/In1'
   */

  /* S-Function block: <S127>/State-Space */
  {
    real_T accum;

    /* Circuit has switches */
    int_T *switch_status = (int_T*) STMpil_DW.StateSpace_PWORK.SWITCH_STATUS;
    int_T *switch_status_init = (int_T*)
      STMpil_DW.StateSpace_PWORK.SWITCH_STATUS_INIT;
    int_T *SwitchChange = (int_T*) STMpil_DW.StateSpace_PWORK.SW_CHG;
    int_T *gState = (int_T*) STMpil_DW.StateSpace_PWORK.G_STATE;
    real_T *yswitch = (real_T*)STMpil_DW.StateSpace_PWORK.Y_SWITCH;
    int_T *switchTypes = (int_T*) STMpil_DW.StateSpace_PWORK.SWITCH_TYPES;
    int_T *idxOutSw = (int_T*) STMpil_DW.StateSpace_PWORK.IDX_OUT_SW;
    real_T *DxCol = (real_T*)STMpil_DW.StateSpace_PWORK.DX_COL;
    real_T *tmp2 = (real_T*)STMpil_DW.StateSpace_PWORK.TMP2;
    real_T *BDcol = (real_T*)STMpil_DW.StateSpace_PWORK.BD_COL;
    real_T *tmp1 = (real_T*)STMpil_DW.StateSpace_PWORK.TMP1;
    real_T *uswlast = (real_T*)STMpil_DW.StateSpace_PWORK.USWLAST;
    int_T newState;
    int_T swChanged = 0;
    int loopsToDo = 20;
    real_T temp;

    /* keep an initial copy of switch_status*/
    memcpy(switch_status_init, switch_status, 2 * sizeof(int_T));
    memcpy(uswlast, &STMpil_B.StateSpace_o1[0], 2*sizeof(real_T));
    do {
      if (loopsToDo == 1) {            /* Need to reset some variables: */
        swChanged = 0;

        /* return to the original switch status*/
        {
          int_T i1;
          for (i1=0; i1 < 2; i1++) {
            swChanged = ((SwitchChange[i1] = switch_status_init[i1] -
                          switch_status[i1]) != 0) ? 1 : swChanged;
            switch_status[i1] = switch_status_init[i1];
          }
        }
      } else {
        /*
         * Compute outputs:
         * ---------------
         */
        real_T *Cs = (real_T*)STMpil_DW.StateSpace_PWORK.CS;
        real_T *Ds = (real_T*)STMpil_DW.StateSpace_PWORK.DS;
        accum = 0.0;
        accum += *(Cs++) * STMpil_DW.StateSpace_DSTATE[0];
        accum += *(Cs++) * STMpil_DW.StateSpace_DSTATE[1];
        accum += *(Ds++) * STMpil_P.SwitchCurrents_Value[0];
        accum += *(Ds++) * STMpil_P.SwitchCurrents_Value[1];
        accum += *(Ds++) * STMpil_B.Switch2;
        accum += *(Ds++) * STMpil_U.In1;
        STMpil_B.StateSpace_o1[0] = accum;
        accum = 0.0;
        accum += *(Cs++) * STMpil_DW.StateSpace_DSTATE[0];
        accum += *(Cs++) * STMpil_DW.StateSpace_DSTATE[1];
        accum += *(Ds++) * STMpil_P.SwitchCurrents_Value[0];
        accum += *(Ds++) * STMpil_P.SwitchCurrents_Value[1];
        accum += *(Ds++) * STMpil_B.Switch2;
        accum += *(Ds++) * STMpil_U.In1;
        STMpil_B.StateSpace_o1[1] = accum;
        accum = 0.0;
        accum += *(Cs++) * STMpil_DW.StateSpace_DSTATE[0];
        accum += *(Cs++) * STMpil_DW.StateSpace_DSTATE[1];
        accum += *(Ds++) * STMpil_P.SwitchCurrents_Value[0];
        accum += *(Ds++) * STMpil_P.SwitchCurrents_Value[1];
        accum += *(Ds++) * STMpil_B.Switch2;
        accum += *(Ds++) * STMpil_U.In1;
        STMpil_B.StateSpace_o1[2] = accum;
        swChanged = 0;

        /* Ideal switch */
        newState = gState[0] > 0 ? 1 : 0;
        swChanged = ((SwitchChange[0] = newState - switch_status[0]) != 0) ? 1 :
          swChanged;
        switch_status[0] = newState;   /* Keep new state */

        /* MOSFETs or IGBT/Diode pairs */
        newState = ((STMpil_B.StateSpace_o1[1] > 0.0) && (gState[1] > 0)) ||
          (STMpil_B.StateSpace_o1[1] < 0.0) ? 1 : (((STMpil_B.StateSpace_o1[1] >
          0.0) && gState[1] == 0) ? 0 : switch_status[1]);
        swChanged = ((SwitchChange[1] = newState - switch_status[1]) != 0) ? 1 :
          swChanged;
        switch_status[1] = newState;   /* Keep new state */
      }

      /*
       * Compute new As, Bs, Cs and Ds matrixes:
       * --------------------------------------
       */
      if (swChanged) {
        real_T *As = (real_T*)STMpil_DW.StateSpace_PWORK.AS;
        real_T *Cs = (real_T*)STMpil_DW.StateSpace_PWORK.CS;
        real_T *Bs = (real_T*)STMpil_DW.StateSpace_PWORK.BS;
        real_T *Ds = (real_T*)STMpil_DW.StateSpace_PWORK.DS;
        real_T a1;

        {
          int_T i1;
          for (i1=0; i1 < 2; i1++) {
            if (SwitchChange[i1] != 0) {
              a1 = 1000.0*SwitchChange[i1];
              temp = 1/(1-Ds[i1*5]*a1);
              DxCol[0]= Ds[0 + i1]*temp*a1;
              DxCol[1]= Ds[4 + i1]*temp*a1;
              DxCol[2]= Ds[8 + i1]*temp*a1;
              DxCol[i1] = temp;
              BDcol[0]= Bs[0 + i1]*a1;
              BDcol[1]= Bs[4 + i1]*a1;

              /* Copy row nSw of Cs into tmp1 and zero it out in Cs */
              memcpy(tmp1, &Cs[i1 * 2], 2 * sizeof(real_T));
              memset(&Cs[i1 * 2], '\0', 2 * sizeof(real_T));

              /* Copy row nSw of Ds into tmp2 and zero it out in Ds */
              memcpy(tmp2, &Ds[i1 * 4], 4 * sizeof(real_T));
              memset(&Ds[i1 * 4], '\0', 4 * sizeof(real_T));

              /* Cs = Cs + DxCol * tmp1, Ds = Ds + DxCol * tmp2 *******************/
              a1 = DxCol[0];
              Cs[0 + 0] += a1 * tmp1[0];
              Cs[0 + 1] += a1 * tmp1[1];
              Ds[0 + 0] += a1 * tmp2[0];
              Ds[0 + 1] += a1 * tmp2[1];
              Ds[0 + 2] += a1 * tmp2[2];
              Ds[0 + 3] += a1 * tmp2[3];
              a1 = DxCol[1];
              Cs[2 + 0] += a1 * tmp1[0];
              Cs[2 + 1] += a1 * tmp1[1];
              Ds[4 + 0] += a1 * tmp2[0];
              Ds[4 + 1] += a1 * tmp2[1];
              Ds[4 + 2] += a1 * tmp2[2];
              Ds[4 + 3] += a1 * tmp2[3];
              a1 = DxCol[2];
              Cs[4 + 0] += a1 * tmp1[0];
              Cs[4 + 1] += a1 * tmp1[1];
              Ds[8 + 0] += a1 * tmp2[0];
              Ds[8 + 1] += a1 * tmp2[1];
              Ds[8 + 2] += a1 * tmp2[2];
              Ds[8 + 3] += a1 * tmp2[3];

              /* As = As + BdCol*Cs(nSw,:), Bs = Bs + BdCol*Ds(nSw,:) *************/
              a1 = BDcol[0];
              As[0 + 0] += a1 * Cs[i1 * 2 + 0];
              As[0 + 1] += a1 * Cs[i1 * 2 + 1];
              Bs[0 + 0] += a1 * Ds[i1 * 4 + 0];
              Bs[0 + 1] += a1 * Ds[i1 * 4 + 1];
              Bs[0 + 2] += a1 * Ds[i1 * 4 + 2];
              Bs[0 + 3] += a1 * Ds[i1 * 4 + 3];
              a1 = BDcol[1];
              As[2 + 0] += a1 * Cs[i1 * 2 + 0];
              As[2 + 1] += a1 * Cs[i1 * 2 + 1];
              Bs[4 + 0] += a1 * Ds[i1 * 4 + 0];
              Bs[4 + 1] += a1 * Ds[i1 * 4 + 1];
              Bs[4 + 2] += a1 * Ds[i1 * 4 + 2];
              Bs[4 + 3] += a1 * Ds[i1 * 4 + 3];
            }
          }
        }
      }                                /* if (swChanged) */
    } while (swChanged > 0 && --loopsToDo > 0);

    if (loopsToDo == 0) {
      real_T *Cs = (real_T*)STMpil_DW.StateSpace_PWORK.CS;
      real_T *Ds = (real_T*)STMpil_DW.StateSpace_PWORK.DS;
      accum = 0.0;
      accum += *(Cs++) * STMpil_DW.StateSpace_DSTATE[0];
      accum += *(Cs++) * STMpil_DW.StateSpace_DSTATE[1];
      accum += *(Ds++) * STMpil_P.SwitchCurrents_Value[0];
      accum += *(Ds++) * STMpil_P.SwitchCurrents_Value[1];
      accum += *(Ds++) * STMpil_B.Switch2;
      accum += *(Ds++) * STMpil_U.In1;
      STMpil_B.StateSpace_o1[0] = accum;
      accum = 0.0;
      accum += *(Cs++) * STMpil_DW.StateSpace_DSTATE[0];
      accum += *(Cs++) * STMpil_DW.StateSpace_DSTATE[1];
      accum += *(Ds++) * STMpil_P.SwitchCurrents_Value[0];
      accum += *(Ds++) * STMpil_P.SwitchCurrents_Value[1];
      accum += *(Ds++) * STMpil_B.Switch2;
      accum += *(Ds++) * STMpil_U.In1;
      STMpil_B.StateSpace_o1[1] = accum;
      accum = 0.0;
      accum += *(Cs++) * STMpil_DW.StateSpace_DSTATE[0];
      accum += *(Cs++) * STMpil_DW.StateSpace_DSTATE[1];
      accum += *(Ds++) * STMpil_P.SwitchCurrents_Value[0];
      accum += *(Ds++) * STMpil_P.SwitchCurrents_Value[1];
      accum += *(Ds++) * STMpil_B.Switch2;
      accum += *(Ds++) * STMpil_U.In1;
      STMpil_B.StateSpace_o1[2] = accum;
    }

    /* Output new switches states */
    STMpil_B.StateSpace_o2[0] = (real_T)switch_status[0];
    STMpil_B.StateSpace_o2[1] = (real_T)switch_status[1];
  }

  /* Outport: '<Root>/<Current (A)>' incorporates:
   *  Gain: '<S112>/do not delete this gain'
   */
  STMpil_Y.CurrentA = STMpil_P.donotdeletethisgain_Gain *
    STMpil_B.StateSpace_o1[2];

  /* Sum: '<S113>/Add' incorporates:
   *  Gain: '<S113>/R'
   *  Outport: '<Root>/<Current (A)>'
   */
  STMpil_Y.VoltageV = STMpil_B.Switch2 - (STMpil_P.R_Gain * STMpil_Y.CurrentA);

  /* Outputs for Atomic SubSystem: '<S1>/MyPIL' */
  /* MultiPortSwitch: '<S7>/Output' incorporates:
   *  Constant: '<S7>/Vector'
   *  UnitDelay: '<S104>/Output'
   */
  rtb_Integrator =
    STMpil_P.RepeatingSequenceStair_OutValue[STMpil_DW.Output_DSTATE];

  /* Sum: '<S2>/Add3' incorporates:
   *  Constant: '<S2>/Constant4'
   */
  rtb_Add3_ocsa = STMpil_P.Constant4_Value - STMpil_Y.VoltageV;

  /* Sum: '<S48>/Sum' incorporates:
   *  DiscreteIntegrator: '<S39>/Integrator'
   *  Gain: '<S44>/Proportional Gain'
   */
  numAccum = (STMpil_P.PIDController3_P * rtb_Add3_ocsa) +
    STMpil_DW.Integrator_DSTATE_hwv3;

  /* Saturate: '<S46>/Saturation' */
  if (numAccum > STMpil_P.PIDController3_UpperSaturationL) {
    numAccum = STMpil_P.PIDController3_UpperSaturationL;
  } else {
    if (numAccum < STMpil_P.PIDController3_LowerSaturationL) {
      numAccum = STMpil_P.PIDController3_LowerSaturationL;
    }
  }

  /* End of Saturate: '<S46>/Saturation' */

  /* Sum: '<S2>/Add4' incorporates:
   *  Outport: '<Root>/<Current (A)>'
   */
  rtb_Add4 = numAccum - STMpil_Y.CurrentA;

  /* Sum: '<S96>/Sum' incorporates:
   *  DiscreteIntegrator: '<S87>/Integrator'
   *  Gain: '<S92>/Proportional Gain'
   */
  numAccum = (STMpil_P.PIDController4_P * rtb_Add4) +
    STMpil_DW.Integrator_DSTATE;

  /* Sum: '<S105>/FixPt Sum1' incorporates:
   *  Constant: '<S105>/FixPt Constant'
   *  UnitDelay: '<S104>/Output'
   */
  STMpil_DW.Output_DSTATE = (uint8_T)(((uint32_T)STMpil_DW.Output_DSTATE) +
    STMpil_P.FixPtConstant_Value);

  /* Switch: '<S106>/FixPt Switch' incorporates:
   *  Constant: '<S106>/Constant'
   *  UnitDelay: '<S104>/Output'
   */
  if (STMpil_DW.Output_DSTATE > STMpil_P.LimitedCounter_uplimit) {
    STMpil_DW.Output_DSTATE = STMpil_P.Constant_Value_ip42;
  }

  /* End of Switch: '<S106>/FixPt Switch' */

  /* Update for DiscreteIntegrator: '<S87>/Integrator' incorporates:
   *  Gain: '<S84>/Integral Gain'
   */
  STMpil_DW.Integrator_DSTATE += STMpil_P.Integrator_gainval *
    (STMpil_P.PIDController4_I * rtb_Add4);

  /* Update for DiscreteIntegrator: '<S39>/Integrator' incorporates:
   *  Gain: '<S36>/Integral Gain'
   */
  STMpil_DW.Integrator_DSTATE_hwv3 += STMpil_P.Integrator_gainval_fnnq *
    (STMpil_P.PIDController3_I * rtb_Add3_ocsa);

  /* Saturate: '<S94>/Saturation' */
  if (numAccum > STMpil_P.PIDController4_UpperSaturationL) {
    numAccum = STMpil_P.PIDController4_UpperSaturationL;
  } else {
    if (numAccum < STMpil_P.PIDController4_LowerSaturationL) {
      numAccum = STMpil_P.PIDController4_LowerSaturationL;
    }
  }

  /* End of Saturate: '<S94>/Saturation' */

  /* DataTypeConversion: '<S123>/Data Type Conversion' incorporates:
   *  RelationalOperator: '<S2>/Relational Operator1'
   */
  STMpil_B.DataTypeConversion = (rtb_Integrator <= numAccum);

  /* End of Outputs for SubSystem: '<S1>/MyPIL' */

  /* Fcn: '<S113>/Fcn1' incorporates:
   *  Gain: '<S113>/R4'
   *  Memory: '<S113>/it init1'
   */
  STMpil_Y.SOC = 100.0 * (1.0 - (rtb_Gain / (STMpil_P.R4_Gain *
    STMpil_DW.itinit1_PreviousInput)));

  /* DataTypeConversion: '<S125>/Data Type Conversion' incorporates:
   *  Constant: '<S3>/Constant'
   */
  STMpil_B.DataTypeConversion_ni55 = STMpil_P.Constant_Value_fyee;

  /* Update for Memory: '<S113>/it init1' incorporates:
   *  Constant: '<S113>/Constant12'
   */
  STMpil_DW.itinit1_PreviousInput = STMpil_P.Constant12_Value;

  /* Update for DiscreteTransferFcn: '<S113>/Current filter' incorporates:
   *  Outport: '<Root>/<Current (A)>'
   */
  STMpil_DW.Currentfilter_states = (STMpil_Y.CurrentA -
    (STMpil_P.Currentfilter_DenCoef[1] * STMpil_DW.Currentfilter_states)) /
    STMpil_P.Currentfilter_DenCoef[0];

  /* Update for Memory: '<S113>/it init' incorporates:
   *  Gain: '<S113>/Gain2'
   */
  STMpil_DW.itinit_PreviousInput = STMpil_P.Gain2_Gain * rtb_Gain;

  /* Update for DiscreteIntegrator: '<S113>/int(i)' incorporates:
   *  Outport: '<Root>/<Current (A)>'
   */
  STMpil_DW.inti_IC_LOADING = 0U;
  STMpil_DW.inti_DSTATE += STMpil_P.inti_gainval * STMpil_Y.CurrentA;
  if (STMpil_DW.inti_DSTATE >= STMpil_P.inti_UpperSat) {
    STMpil_DW.inti_DSTATE = STMpil_P.inti_UpperSat;
  } else {
    if (STMpil_DW.inti_DSTATE <= STMpil_P.inti_LowerSat) {
      STMpil_DW.inti_DSTATE = STMpil_P.inti_LowerSat;
    }
  }

  if (rtb_DataTypeConversion2 > 0) {
    STMpil_DW.inti_PrevResetState = 1;
  } else {
    STMpil_DW.inti_PrevResetState = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S113>/int(i)' */

  /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' incorporates:
   *  Abs: '<S118>/Abs'
   *  Constant: '<S122>/Constant'
   *  DataTypeConversion: '<S118>/Data Type Conversion1'
   *  Gain: '<S118>/Gain1'
   *  Gain: '<S118>/Gain4'
   *  Outport: '<Root>/<Current (A)>'
   *  Product: '<S118>/Divide'
   *  RelationalOperator: '<S122>/Compare'
   *  Sum: '<S118>/Add3'
   */
  STMpil_DW.DiscreteTimeIntegrator_DSTATE +=
    STMpil_P.DiscreteTimeIntegrator_gainval * (STMpil_P.Gain1_Gain * (fabs
    (STMpil_Y.CurrentA) * ((STMpil_P.Gain4_Gain * ((real_T)(STMpil_Y.CurrentA <
    STMpil_P.Constant_Value_axhw))) - STMpil_DW.DiscreteTimeIntegrator_DSTATE)));

  /* Update for Memory: '<S113>/Memory2' incorporates:
   *  Gain: '<S113>/R1'
   *  Outport: '<Root>/<Current (A)>'
   */
  STMpil_DW.Memory2_PreviousInput = STMpil_P.R1_Gain * STMpil_Y.CurrentA;

  /* Update for S-Function (sfun_spssw_discc): '<S127>/State-Space' incorporates:
   *  Constant: '<S129>/SwitchCurrents'
   *  Inport: '<Root>/In1'
   */

  /* S-Function block: <S127>/State-Space */
  {
    const real_T *As = (real_T*)STMpil_DW.StateSpace_PWORK.AS;
    const real_T *Bs = (real_T*)STMpil_DW.StateSpace_PWORK.BS;
    real_T *xtmp = (real_T*)STMpil_DW.StateSpace_PWORK.XTMP;
    real_T accum;

    /* Calculate new states... */
    accum = 0.0;
    accum += *(As++) * STMpil_DW.StateSpace_DSTATE[0];
    accum += *(As++) * STMpil_DW.StateSpace_DSTATE[1];
    accum += *(Bs++) * (STMpil_P.SwitchCurrents_Value[0]);
    accum += *(Bs++) * (STMpil_P.SwitchCurrents_Value[1]);
    accum += *(Bs++) * STMpil_B.Switch2;
    accum += *(Bs++) * STMpil_U.In1;
    xtmp[0] = accum;
    accum = 0.0;
    accum += *(As++) * STMpil_DW.StateSpace_DSTATE[0];
    accum += *(As++) * STMpil_DW.StateSpace_DSTATE[1];
    accum += *(Bs++) * (STMpil_P.SwitchCurrents_Value[0]);
    accum += *(Bs++) * (STMpil_P.SwitchCurrents_Value[1]);
    accum += *(Bs++) * STMpil_B.Switch2;
    accum += *(Bs++) * STMpil_U.In1;
    xtmp[1] = accum;
    STMpil_DW.StateSpace_DSTATE[0] = xtmp[0];
    STMpil_DW.StateSpace_DSTATE[1] = xtmp[1];

    {
      int_T *gState = (int_T*)STMpil_DW.StateSpace_PWORK.G_STATE;

      /* Store switch gates values for next step */
      *(gState++) = (int_T) STMpil_B.DataTypeConversion_ni55;
      *(gState++) = (int_T) STMpil_B.DataTypeConversion;
    }
  }

  /* Saturate: '<S113>/Saturation' */
  if (STMpil_Y.SOC > STMpil_P.Saturation_UpperSat_egqb) {
    /* Outport: '<Root>/<SOC (%)>' */
    STMpil_Y.SOC = STMpil_P.Saturation_UpperSat_egqb;
  } else {
    if (STMpil_Y.SOC < STMpil_P.Saturation_LowerSat_dzqb) {
      /* Outport: '<Root>/<SOC (%)>' */
      STMpil_Y.SOC = STMpil_P.Saturation_LowerSat_dzqb;
    }
  }

  /* End of Saturate: '<S113>/Saturation' */
  /* End of Outputs for SubSystem: '<Root>/STMpil' */
}

/* Model initialize function */
void STMpil_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  STMpil_P.Saturation_LowerSat = rtMinusInf;
  STMpil_P.inti_LowerSat = rtMinusInf;

  /* block I/O */
  (void) memset(((void *) &STMpil_B), 0,
                sizeof(B_STMpil_T));

  /* states (dwork) */
  (void) memset((void *)&STMpil_DW, 0,
                sizeof(DW_STMpil_T));

  /* external inputs */
  STMpil_U.In1 = 0.0;

  /* external outputs */
  (void) memset((void *)&STMpil_Y, 0,
                sizeof(ExtY_STMpil_T));

  {
    real_T itinit_PreviousInput_tmp;

    /* SystemInitialize for Atomic SubSystem: '<Root>/STMpil' */
    /* Start for S-Function (sfun_spssw_discc): '<S127>/State-Space' incorporates:
     *  Constant: '<S129>/SwitchCurrents'
     *  Inport: '<Root>/In1'
     */

    /* S-Function block: <S127>/State-Space */
    {
      STMpil_DW.StateSpace_PWORK.AS = (real_T*)calloc(2 * 2, sizeof(real_T));
      STMpil_DW.StateSpace_PWORK.BS = (real_T*)calloc(2 * 4, sizeof(real_T));
      STMpil_DW.StateSpace_PWORK.CS = (real_T*)calloc(3 * 2, sizeof(real_T));
      STMpil_DW.StateSpace_PWORK.DS = (real_T*)calloc(3 * 4, sizeof(real_T));
      STMpil_DW.StateSpace_PWORK.DX_COL = (real_T*)calloc(3, sizeof(real_T));
      STMpil_DW.StateSpace_PWORK.TMP2 = (real_T*)calloc(4, sizeof(real_T));
      STMpil_DW.StateSpace_PWORK.BD_COL = (real_T*)calloc(2, sizeof(real_T));
      STMpil_DW.StateSpace_PWORK.TMP1 = (real_T*)calloc(2, sizeof(real_T));
      STMpil_DW.StateSpace_PWORK.XTMP = (real_T*)calloc(2, sizeof(real_T));
      STMpil_DW.StateSpace_PWORK.SWITCH_STATUS = (int_T*)calloc(2, sizeof(int_T));
      STMpil_DW.StateSpace_PWORK.SW_CHG = (int_T*)calloc(2, sizeof(int_T));
      STMpil_DW.StateSpace_PWORK.G_STATE = (int_T*)calloc(2, sizeof(int_T));
      STMpil_DW.StateSpace_PWORK.Y_SWITCH = (real_T*)calloc(2, sizeof(real_T));
      STMpil_DW.StateSpace_PWORK.SWITCH_TYPES = (int_T*)calloc(2, sizeof(int_T));
      STMpil_DW.StateSpace_PWORK.IDX_OUT_SW = (int_T*)calloc(2, sizeof(int_T));
      STMpil_DW.StateSpace_PWORK.SWITCH_STATUS_INIT = (int_T*)calloc(2, sizeof
        (int_T));
      STMpil_DW.StateSpace_PWORK.USWLAST = (real_T*)calloc(2, sizeof(real_T));
    }

    /* InitializeConditions for Memory: '<S113>/it init1' */
    STMpil_DW.itinit1_PreviousInput = STMpil_P.itinit1_InitialCondition;

    /* InitializeConditions for DiscreteTransferFcn: '<S113>/Current filter' */
    STMpil_DW.Currentfilter_states = STMpil_P.Currentfilter_InitialStates;

    /* InitializeConditions for Memory: '<S113>/it init' incorporates:
     *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator'
     */
    itinit_PreviousInput_tmp = 1.0 - (STMpil_P.Battery_SOC / 100.0);
    STMpil_DW.itinit_PreviousInput = ((itinit_PreviousInput_tmp *
      2.1750499999999882) * 0.942507068803021) * 3600.0;

    /* InitializeConditions for DiscreteIntegrator: '<S113>/int(i)' */
    STMpil_DW.inti_PrevResetState = 2;
    STMpil_DW.inti_IC_LOADING = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
    STMpil_DW.DiscreteTimeIntegrator_DSTATE = 0.21089319159632841 * exp((-15.0 *
      itinit_PreviousInput_tmp) * 2.1750499999999882);

    /* InitializeConditions for Memory: '<S113>/Memory2' */
    STMpil_DW.Memory2_PreviousInput = STMpil_P.Memory2_InitialCondition;

    /* InitializeConditions for S-Function (sfun_spssw_discc): '<S127>/State-Space' incorporates:
     *  Constant: '<S129>/SwitchCurrents'
     *  Inport: '<Root>/In1'
     */
    {
      int32_T i, j;
      real_T *As = (real_T*)STMpil_DW.StateSpace_PWORK.AS;
      real_T *Bs = (real_T*)STMpil_DW.StateSpace_PWORK.BS;
      real_T *Cs = (real_T*)STMpil_DW.StateSpace_PWORK.CS;
      real_T *Ds = (real_T*)STMpil_DW.StateSpace_PWORK.DS;
      real_T *X0 = (real_T*)&STMpil_DW.StateSpace_DSTATE[0];
      for (i = 0; i < 2; i++) {
        X0[i] = (STMpil_P.StateSpace_X0_param[i]);
      }

      /* Copy and transpose A and B */
      for (i=0; i<2; i++) {
        for (j=0; j<2; j++)
          As[i*2 + j] = (STMpil_P.StateSpace_AS_param[i + j*2]);
        for (j=0; j<4; j++)
          Bs[i*4 + j] = (STMpil_P.StateSpace_BS_param[i + j*2]);
      }

      /* Copy and transpose C */
      for (i=0; i<3; i++) {
        for (j=0; j<2; j++)
          Cs[i*2 + j] = (STMpil_P.StateSpace_CS_param[i + j*3]);
      }

      /* Copy and transpose D */
      for (i=0; i<3; i++) {
        for (j=0; j<4; j++)
          Ds[i*4 + j] = (STMpil_P.StateSpace_DS_param[i + j*3]);
      }

      {
        /* Switches work vectors */
        int_T *switch_status = (int_T*) STMpil_DW.StateSpace_PWORK.SWITCH_STATUS;
        int_T *gState = (int_T*)STMpil_DW.StateSpace_PWORK.G_STATE;
        real_T *yswitch = (real_T*)STMpil_DW.StateSpace_PWORK.Y_SWITCH;
        int_T *switchTypes = (int_T*)STMpil_DW.StateSpace_PWORK.SWITCH_TYPES;
        int_T *idxOutSw = (int_T*)STMpil_DW.StateSpace_PWORK.IDX_OUT_SW;
        int_T *switch_status_init = (int_T*)
          STMpil_DW.StateSpace_PWORK.SWITCH_STATUS_INIT;

        /* Initialize work vectors */
        switch_status[0] = 0;
        switch_status_init[0] = 0;
        gState[0] = (int_T) 0.0;
        yswitch[0] = 1/0.001;
        switchTypes[0] = (int_T)1.0;
        idxOutSw[0] = ((int_T)0.0) - 1;
        switch_status[1] = 0;
        switch_status_init[1] = 0;
        gState[1] = (int_T) 0.0;
        yswitch[1] = 1/0.001;
        switchTypes[1] = (int_T)7.0;
        idxOutSw[1] = ((int_T)0.0) - 1;
      }
    }

    /* SystemInitialize for Atomic SubSystem: '<S1>/MyPIL' */
    /* InitializeConditions for UnitDelay: '<S104>/Output' */
    STMpil_DW.Output_DSTATE = STMpil_P.Output_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S87>/Integrator' */
    STMpil_DW.Integrator_DSTATE = STMpil_P.PIDController4_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S39>/Integrator' */
    STMpil_DW.Integrator_DSTATE_hwv3 = STMpil_P.PIDController3_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<S1>/MyPIL' */
    /* End of SystemInitialize for SubSystem: '<Root>/STMpil' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
