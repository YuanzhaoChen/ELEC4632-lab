/*
 * WaterTankSysControl2018_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "WaterTankSysControl2018".
 *
 * Model version              : 1.22
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Fri Sep 14 11:14:08 2018
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "WaterTankSysControl2018.h"
#include "WaterTankSysControl2018_private.h"

/* Block parameters (auto storage) */
P_WaterTankSysControl2018_T WaterTankSysControl2018_P = {
  /*  Variable: C_obsrv
   * Referenced by: '<S2>/Gain1'
   */
  { 0.0, 1.0 },
  4.6587246472533073,                  /* Variable: DC_gain
                                        * Referenced by: '<Root>/DC Gain  Compensation'
                                        */

  /*  Variable: G_obsrv
   * Referenced by: '<S2>/Gain2'
   */
  { 0.0, 1.0, -0.27470283025379172, 1.2582230801080165 },

  /*  Variable: H_obsrv
   * Referenced by: '<S2>/Gain'
   */
  { 0.023673477913312424, 0.022913768559220973 },

  /*  Variable: L_ndb2
   * Referenced by: '<S2>/Gain4'
   */
  { -18.088011197352429, -4.9564429361406752 },
  2.0,                                 /* Variable: u_offset
                                        * Referenced by: '<Root>/Constant2'
                                        */
  2.3069661458333335,                  /* Variable: y_offset
                                        * Referenced by:
                                        *   '<Root>/Constant'
                                        *   '<Root>/Constant3'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_FinalValue
                                        * Referenced by: '<S1>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput2_FinalValue
                                        * Referenced by: '<S1>/Analog Output2'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_InitialValue
                                        * Referenced by: '<S1>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput2_InitialValue
                                        * Referenced by: '<S1>/Analog Output2'
                                        */
  10.0,                                /* Mask Parameter: AnalogOutput1_MaxMissedTicks
                                        * Referenced by: '<S1>/Analog Output1'
                                        */
  10.0,                                /* Mask Parameter: AnalogOutput2_MaxMissedTicks
                                        * Referenced by: '<S1>/Analog Output2'
                                        */
  10.0,                                /* Mask Parameter: AnalogInput1_MaxMissedTicks
                                        * Referenced by: '<S1>/Analog Input1'
                                        */
  10.0,                                /* Mask Parameter: AnalogInput2_MaxMissedTicks
                                        * Referenced by: '<S1>/Analog Input2'
                                        */

  /*  Mask Parameter: RepeatingSequenceStair1_OutValues
   * Referenced by: '<S3>/Vector'
   */
  { 0.7, 0.2, -0.5, 0.0 },
  0.0,                                 /* Mask Parameter: AnalogOutput1_YieldWhenWaiting
                                        * Referenced by: '<S1>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput2_YieldWhenWaiting
                                        * Referenced by: '<S1>/Analog Output2'
                                        */
  0.0,                                 /* Mask Parameter: AnalogInput1_YieldWhenWaiting
                                        * Referenced by: '<S1>/Analog Input1'
                                        */
  0.0,                                 /* Mask Parameter: AnalogInput2_YieldWhenWaiting
                                        * Referenced by: '<S1>/Analog Input2'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput1_Channels
                                        * Referenced by: '<S1>/Analog Output1'
                                        */
  1,                                   /* Mask Parameter: AnalogOutput2_Channels
                                        * Referenced by: '<S1>/Analog Output2'
                                        */
  0,                                   /* Mask Parameter: AnalogInput1_Channels
                                        * Referenced by: '<S1>/Analog Input1'
                                        */
  1,                                   /* Mask Parameter: AnalogInput2_Channels
                                        * Referenced by: '<S1>/Analog Input2'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput1_RangeMode
                                        * Referenced by: '<S1>/Analog Output1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput2_RangeMode
                                        * Referenced by: '<S1>/Analog Output2'
                                        */
  0,                                   /* Mask Parameter: AnalogInput1_RangeMode
                                        * Referenced by: '<S1>/Analog Input1'
                                        */
  0,                                   /* Mask Parameter: AnalogInput2_RangeMode
                                        * Referenced by: '<S1>/Analog Input2'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput1_VoltRange
                                        * Referenced by: '<S1>/Analog Output1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput2_VoltRange
                                        * Referenced by: '<S1>/Analog Output2'
                                        */
  0,                                   /* Mask Parameter: AnalogInput1_VoltRange
                                        * Referenced by: '<S1>/Analog Input1'
                                        */
  0,                                   /* Mask Parameter: AnalogInput2_VoltRange
                                        * Referenced by: '<S1>/Analog Input2'
                                        */
  3U,                                  /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S6>/FixPt Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition1'
                                        */

  /*  Expression: [0;0]
   * Referenced by: '<S2>/Delay'
   */
  { 0.0, 0.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Activation Gain TANK#1'
                                        */
  2.5,                                 /* Expression: 2.5
                                        * Referenced by: '<Root>/Saturation TANK#1'
                                        */
  1.5,                                 /* Expression: 1.5
                                        * Referenced by: '<Root>/Saturation TANK#1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Activation Gain TANK#2'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Saturation TANK#2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Saturation TANK#2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Discrete FIR Filter1'
                                        */

  /*  Expression: [0.2 0.2 0.2 0.2 0.2]
   * Referenced by: '<S1>/Discrete FIR Filter1'
   */
  { 0.2, 0.2, 0.2, 0.2, 0.2 },

  /*  Expression: K'
   * Referenced by: '<S2>/Gain3'
   */
  { -0.27470283025379172, 1.2582230801080165 },
  1U,                                  /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S2>/Delay'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S6>/Constant'
                                        */
  1U,                                  /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S5>/FixPt Constant'
                                        */
  0U                                   /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S4>/Output'
                                        */
};
