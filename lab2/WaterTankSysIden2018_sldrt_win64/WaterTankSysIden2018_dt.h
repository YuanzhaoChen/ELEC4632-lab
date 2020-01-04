/*
 * WaterTankSysIden2018_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&WaterTankSysIden2018_B.OffsetFreeInput), 0, 0, 7 },

  { (char_T *)(&WaterTankSysIden2018_B.FixPtSwitch), 3, 0, 1 }
  ,

  { (char_T *)(&WaterTankSysIden2018_DW.DiscreteFIRFilter1_states[0]), 0, 0, 5 },

  { (char_T *)(&WaterTankSysIden2018_DW.AnalogOutput1_PWORK), 11, 0, 6 },

  { (char_T *)(&WaterTankSysIden2018_DW.DiscreteFIRFilter1_circBuf), 6, 0, 1 },

  { (char_T *)(&WaterTankSysIden2018_DW.Output_DSTATE), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&WaterTankSysIden2018_P.AnalogOutput1_FinalValue), 0, 0, 16 },

  { (char_T *)(&WaterTankSysIden2018_P.AnalogOutput1_Channels), 6, 0, 12 },

  { (char_T *)(&WaterTankSysIden2018_P.LimitedCounter_uplimit), 3, 0, 1 },

  { (char_T *)(&WaterTankSysIden2018_P.Gain_Gain), 0, 0, 18 },

  { (char_T *)(&WaterTankSysIden2018_P.Constant_Value), 3, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] WaterTankSysIden2018_dt.h */
