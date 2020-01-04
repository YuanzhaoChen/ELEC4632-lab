/*
 * WaterTankSysIden2018_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "WaterTankSysIden2018".
 *
 * Model version              : 1.35
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Fri Aug 17 09:56:26 2018
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "WaterTankSysIden2018.h"
#include "WaterTankSysIden2018_private.h"

/* Block parameters (auto storage) */
P_WaterTankSysIden2018_T WaterTankSysIden2018_P = {
  0.0,                                 /* Mask Parameter: AnalogOutput1_FinalValue
                                        * Referenced by: '<S2>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput2_FinalValue
                                        * Referenced by: '<S2>/Analog Output2'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput1_InitialValue
                                        * Referenced by: '<S2>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput2_InitialValue
                                        * Referenced by: '<S2>/Analog Output2'
                                        */
  10.0,                                /* Mask Parameter: AnalogOutput1_MaxMissedTicks
                                        * Referenced by: '<S2>/Analog Output1'
                                        */
  10.0,                                /* Mask Parameter: AnalogOutput2_MaxMissedTicks
                                        * Referenced by: '<S2>/Analog Output2'
                                        */
  10.0,                                /* Mask Parameter: AnalogInput1_MaxMissedTicks
                                        * Referenced by: '<S2>/Analog Input1'
                                        */
  10.0,                                /* Mask Parameter: AnalogInput2_MaxMissedTicks
                                        * Referenced by: '<S2>/Analog Input2'
                                        */

  /*  Mask Parameter: RepeatingSequenceStair_OutValues
   * Referenced by: '<S1>/Vector'
   */
  { -0.4, 0.2, -0.3, 0.0 },
  0.0,                                 /* Mask Parameter: AnalogOutput1_YieldWhenWaiting
                                        * Referenced by: '<S2>/Analog Output1'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput2_YieldWhenWaiting
                                        * Referenced by: '<S2>/Analog Output2'
                                        */
  0.0,                                 /* Mask Parameter: AnalogInput1_YieldWhenWaiting
                                        * Referenced by: '<S2>/Analog Input1'
                                        */
  0.0,                                 /* Mask Parameter: AnalogInput2_YieldWhenWaiting
                                        * Referenced by: '<S2>/Analog Input2'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput1_Channels
                                        * Referenced by: '<S2>/Analog Output1'
                                        */
  1,                                   /* Mask Parameter: AnalogOutput2_Channels
                                        * Referenced by: '<S2>/Analog Output2'
                                        */
  0,                                   /* Mask Parameter: AnalogInput1_Channels
                                        * Referenced by: '<S2>/Analog Input1'
                                        */
  1,                                   /* Mask Parameter: AnalogInput2_Channels
                                        * Referenced by: '<S2>/Analog Input2'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput1_RangeMode
                                        * Referenced by: '<S2>/Analog Output1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput2_RangeMode
                                        * Referenced by: '<S2>/Analog Output2'
                                        */
  0,                                   /* Mask Parameter: AnalogInput1_RangeMode
                                        * Referenced by: '<S2>/Analog Input1'
                                        */
  0,                                   /* Mask Parameter: AnalogInput2_RangeMode
                                        * Referenced by: '<S2>/Analog Input2'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput1_VoltRange
                                        * Referenced by: '<S2>/Analog Output1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput2_VoltRange
                                        * Referenced by: '<S2>/Analog Output2'
                                        */
  0,                                   /* Mask Parameter: AnalogInput1_VoltRange
                                        * Referenced by: '<S2>/Analog Input1'
                                        */
  0,                                   /* Mask Parameter: AnalogInput2_VoltRange
                                        * Referenced by: '<S2>/Analog Input2'
                                        */
  3U,                                  /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S5>/FixPt Switch'
                                        */
  2.5,                                 /* Expression: 2.5
                                        * Referenced by: '<Root>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/u_offset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Activation Gain TANK#1'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<Root>/Saturation TANK#1'
                                        */
  0.0,                                 /* Expression: 0
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
                                        * Referenced by: '<S2>/Discrete FIR Filter1'
                                        */

  /*  Expression: [0.2 0.2 0.2 0.2 0.2]
   * Referenced by: '<S2>/Discrete FIR Filter1'
   */
  { 0.2, 0.2, 0.2, 0.2, 0.2 },
  0U,                                  /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S5>/Constant'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  1U,                                  /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S4>/FixPt Constant'
                                        */
  0U                                   /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S3>/Output'
                                        */
};
