/*
 * WaterTankSysIden2018.c
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
#include "WaterTankSysIden2018_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double RTWinBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 2;
const double RTWinTimers[4] = {
  0.75, 0.0,
  180.0, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int RTWinBoardCount = 1;
RTWINBOARD RTWinBoards[1] = {
  { "National_Instruments/PCI-MIO-16E-4", 4294967295U, 6, RTWinBoardOptions0 },
};

/* Block signals (auto storage) */
B_WaterTankSysIden2018_T WaterTankSysIden2018_B;

/* Block states (auto storage) */
DW_WaterTankSysIden2018_T WaterTankSysIden2018_DW;

/* Real-time model */
RT_MODEL_WaterTankSysIden2018_T WaterTankSysIden2018_M_;
RT_MODEL_WaterTankSysIden2018_T *const WaterTankSysIden2018_M =
  &WaterTankSysIden2018_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(WaterTankSysIden2018_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(WaterTankSysIden2018_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (WaterTankSysIden2018_M->Timing.TaskCounters.TID[1] == 0) {
    WaterTankSysIden2018_M->Timing.RateInteraction.TID1_2 =
      (WaterTankSysIden2018_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    WaterTankSysIden2018_M->Timing.perTaskSampleHits[5] =
      WaterTankSysIden2018_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (WaterTankSysIden2018_M->Timing.TaskCounters.TID[2])++;
  if ((WaterTankSysIden2018_M->Timing.TaskCounters.TID[2]) > 239) {/* Sample time: [180.0s, 0.0s] */
    WaterTankSysIden2018_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model output function for TID0 */
void WaterTankSysIden2018_output0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_OriginalOutput;
  int32_T j;
  int32_T cff;
  real_T rtb_ActivationGainTANK2;
  real_T u0;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/Rate Transition' */
  if (WaterTankSysIden2018_M->Timing.RateInteraction.TID1_2) {
    WaterTankSysIden2018_B.OffsetFreeInput =
      WaterTankSysIden2018_DW.RateTransition_Buffer0;
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/u_offset'
   */
  WaterTankSysIden2018_B.Sum = WaterTankSysIden2018_P.u_offset_Value +
    WaterTankSysIden2018_B.OffsetFreeInput;

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Gain: '<Root>/Gain'
   *  Step: '<Root>/Step'
   */
  if (WaterTankSysIden2018_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ActivationGainTANK2 = WaterTankSysIden2018_B.Sum;
  } else {
    if (WaterTankSysIden2018_M->Timing.t[0] < WaterTankSysIden2018_P.Step_Time)
    {
      /* Step: '<Root>/Step' */
      rtb_ActivationGainTANK2 = WaterTankSysIden2018_P.Step_Y0;
    } else {
      /* Step: '<Root>/Step' */
      rtb_ActivationGainTANK2 = WaterTankSysIden2018_P.Step_YFinal;
    }

    rtb_ActivationGainTANK2 *= WaterTankSysIden2018_P.Gain_Gain;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Gain: '<Root>/Activation Gain TANK#1' */
  u0 = WaterTankSysIden2018_P.ActivationGainTANK1_Gain * rtb_ActivationGainTANK2;

  /* Saturate: '<Root>/Saturation TANK#1' */
  if (u0 > WaterTankSysIden2018_P.SaturationTANK1_UpperSat) {
    WaterTankSysIden2018_B.ActualInput =
      WaterTankSysIden2018_P.SaturationTANK1_UpperSat;
  } else if (u0 < WaterTankSysIden2018_P.SaturationTANK1_LowerSat) {
    WaterTankSysIden2018_B.ActualInput =
      WaterTankSysIden2018_P.SaturationTANK1_LowerSat;
  } else {
    WaterTankSysIden2018_B.ActualInput = u0;
  }

  /* End of Saturate: '<Root>/Saturation TANK#1' */

  /* Gain: '<Root>/Activation Gain TANK#2' */
  rtb_ActivationGainTANK2 *= WaterTankSysIden2018_P.ActivationGainTANK2_Gain;

  /* Saturate: '<Root>/Saturation TANK#2' */
  if (rtb_ActivationGainTANK2 > WaterTankSysIden2018_P.SaturationTANK2_UpperSat)
  {
    WaterTankSysIden2018_B.SaturationTANK2 =
      WaterTankSysIden2018_P.SaturationTANK2_UpperSat;
  } else if (rtb_ActivationGainTANK2 <
             WaterTankSysIden2018_P.SaturationTANK2_LowerSat) {
    WaterTankSysIden2018_B.SaturationTANK2 =
      WaterTankSysIden2018_P.SaturationTANK2_LowerSat;
  } else {
    WaterTankSysIden2018_B.SaturationTANK2 = rtb_ActivationGainTANK2;
  }

  /* End of Saturate: '<Root>/Saturation TANK#2' */
  /* S-Function Block: <S2>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysIden2018_P.AnalogOutput1_RangeMode;
      parm.rangeidx = WaterTankSysIden2018_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysIden2018_P.AnalogOutput1_Channels,
                     &WaterTankSysIden2018_B.ActualInput, &parm);
    }
  }

  /* S-Function Block: <S2>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysIden2018_P.AnalogOutput2_RangeMode;
      parm.rangeidx = WaterTankSysIden2018_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysIden2018_P.AnalogOutput2_Channels,
                     &WaterTankSysIden2018_B.SaturationTANK2, &parm);
    }
  }

  /* S-Function Block: <S2>/Analog Input1 */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) WaterTankSysIden2018_P.AnalogInput1_RangeMode;
    parm.rangeidx = WaterTankSysIden2018_P.AnalogInput1_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &WaterTankSysIden2018_P.AnalogInput1_Channels,
                   &WaterTankSysIden2018_B.OriginalOutput, &parm);
  }

  /* S-Function Block: <S2>/Analog Input2 */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) WaterTankSysIden2018_P.AnalogInput2_RangeMode;
    parm.rangeidx = WaterTankSysIden2018_P.AnalogInput2_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &WaterTankSysIden2018_P.AnalogInput2_Channels,
                   &rtb_OriginalOutput, &parm);
  }

  /* DiscreteFir: '<S2>/Discrete FIR Filter1' */
  rtb_ActivationGainTANK2 = WaterTankSysIden2018_B.OriginalOutput *
    WaterTankSysIden2018_P.DiscreteFIRFilter1_Coefficients[0];
  cff = 1;
  for (j = WaterTankSysIden2018_DW.DiscreteFIRFilter1_circBuf; j < 4; j++) {
    rtb_ActivationGainTANK2 +=
      WaterTankSysIden2018_DW.DiscreteFIRFilter1_states[j] *
      WaterTankSysIden2018_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < WaterTankSysIden2018_DW.DiscreteFIRFilter1_circBuf; j++) {
    rtb_ActivationGainTANK2 +=
      WaterTankSysIden2018_DW.DiscreteFIRFilter1_states[j] *
      WaterTankSysIden2018_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  WaterTankSysIden2018_B.NoiseReducedOutput = rtb_ActivationGainTANK2;

  /* End of DiscreteFir: '<S2>/Discrete FIR Filter1' */
}

/* Model update function for TID0 */
void WaterTankSysIden2018_update0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* Update for DiscreteFir: '<S2>/Discrete FIR Filter1' */
  /* Update circular buffer index */
  WaterTankSysIden2018_DW.DiscreteFIRFilter1_circBuf--;
  if (WaterTankSysIden2018_DW.DiscreteFIRFilter1_circBuf < 0) {
    WaterTankSysIden2018_DW.DiscreteFIRFilter1_circBuf = 3;
  }

  /* Update circular buffer */
  WaterTankSysIden2018_DW.DiscreteFIRFilter1_states[WaterTankSysIden2018_DW.DiscreteFIRFilter1_circBuf]
    = WaterTankSysIden2018_B.OriginalOutput;

  /* End of Update for DiscreteFir: '<S2>/Discrete FIR Filter1' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++WaterTankSysIden2018_M->Timing.clockTick0)) {
    ++WaterTankSysIden2018_M->Timing.clockTickH0;
  }

  WaterTankSysIden2018_M->Timing.t[0] =
    WaterTankSysIden2018_M->Timing.clockTick0 *
    WaterTankSysIden2018_M->Timing.stepSize0 +
    WaterTankSysIden2018_M->Timing.clockTickH0 *
    WaterTankSysIden2018_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++WaterTankSysIden2018_M->Timing.clockTick1)) {
    ++WaterTankSysIden2018_M->Timing.clockTickH1;
  }

  WaterTankSysIden2018_M->Timing.t[1] =
    WaterTankSysIden2018_M->Timing.clockTick1 *
    WaterTankSysIden2018_M->Timing.stepSize1 +
    WaterTankSysIden2018_M->Timing.clockTickH1 *
    WaterTankSysIden2018_M->Timing.stepSize1 * 4294967296.0;
}

/* Model output function for TID2 */
void WaterTankSysIden2018_output2(void) /* Sample time: [180.0s, 0.0s] */
{
  uint8_T rtb_FixPtSum1;

  /* Sum: '<S4>/FixPt Sum1' incorporates:
   *  Constant: '<S4>/FixPt Constant'
   *  UnitDelay: '<S3>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)((uint32_T)WaterTankSysIden2018_DW.Output_DSTATE +
    WaterTankSysIden2018_P.FixPtConstant_Value);

  /* Switch: '<S5>/FixPt Switch' incorporates:
   *  Constant: '<S5>/Constant'
   */
  if (rtb_FixPtSum1 > WaterTankSysIden2018_P.LimitedCounter_uplimit) {
    WaterTankSysIden2018_B.FixPtSwitch = WaterTankSysIden2018_P.Constant_Value;
  } else {
    WaterTankSysIden2018_B.FixPtSwitch = rtb_FixPtSum1;
  }

  /* End of Switch: '<S5>/FixPt Switch' */

  /* MultiPortSwitch: '<S1>/Output' incorporates:
   *  Constant: '<S1>/Vector'
   *  UnitDelay: '<S3>/Output'
   */
  WaterTankSysIden2018_B.Output =
    WaterTankSysIden2018_P.RepeatingSequenceStair_OutValues[WaterTankSysIden2018_DW.Output_DSTATE];
}

/* Model update function for TID2 */
void WaterTankSysIden2018_update2(void) /* Sample time: [180.0s, 0.0s] */
{
  /* Update for RateTransition: '<Root>/Rate Transition' */
  WaterTankSysIden2018_DW.RateTransition_Buffer0 = WaterTankSysIden2018_B.Output;

  /* Update for UnitDelay: '<S3>/Output' */
  WaterTankSysIden2018_DW.Output_DSTATE = WaterTankSysIden2018_B.FixPtSwitch;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++WaterTankSysIden2018_M->Timing.clockTick2)) {
    ++WaterTankSysIden2018_M->Timing.clockTickH2;
  }

  WaterTankSysIden2018_M->Timing.t[2] =
    WaterTankSysIden2018_M->Timing.clockTick2 *
    WaterTankSysIden2018_M->Timing.stepSize2 +
    WaterTankSysIden2018_M->Timing.clockTickH2 *
    WaterTankSysIden2018_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void WaterTankSysIden2018_output(int_T tid)
{
  switch (tid) {
   case 0 :
    WaterTankSysIden2018_output0();
    break;

   case 2 :
    WaterTankSysIden2018_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void WaterTankSysIden2018_update(int_T tid)
{
  switch (tid) {
   case 0 :
    WaterTankSysIden2018_update0();
    break;

   case 2 :
    WaterTankSysIden2018_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void WaterTankSysIden2018_initialize(void)
{
  /* Start for RateTransition: '<Root>/Rate Transition' */
  WaterTankSysIden2018_B.OffsetFreeInput =
    WaterTankSysIden2018_P.RateTransition_X0;

  /* S-Function Block: <S2>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysIden2018_P.AnalogOutput1_RangeMode;
      parm.rangeidx = WaterTankSysIden2018_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysIden2018_P.AnalogOutput1_Channels,
                     &WaterTankSysIden2018_P.AnalogOutput1_InitialValue, &parm);
    }
  }

  /* S-Function Block: <S2>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysIden2018_P.AnalogOutput2_RangeMode;
      parm.rangeidx = WaterTankSysIden2018_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysIden2018_P.AnalogOutput2_Channels,
                     &WaterTankSysIden2018_P.AnalogOutput2_InitialValue, &parm);
    }
  }

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
  WaterTankSysIden2018_DW.RateTransition_Buffer0 =
    WaterTankSysIden2018_P.RateTransition_X0;

  /* InitializeConditions for DiscreteFir: '<S2>/Discrete FIR Filter1' */
  WaterTankSysIden2018_DW.DiscreteFIRFilter1_circBuf = 0;
  WaterTankSysIden2018_DW.DiscreteFIRFilter1_states[0] =
    WaterTankSysIden2018_P.DiscreteFIRFilter1_InitialStates;
  WaterTankSysIden2018_DW.DiscreteFIRFilter1_states[1] =
    WaterTankSysIden2018_P.DiscreteFIRFilter1_InitialStates;
  WaterTankSysIden2018_DW.DiscreteFIRFilter1_states[2] =
    WaterTankSysIden2018_P.DiscreteFIRFilter1_InitialStates;
  WaterTankSysIden2018_DW.DiscreteFIRFilter1_states[3] =
    WaterTankSysIden2018_P.DiscreteFIRFilter1_InitialStates;

  /* InitializeConditions for UnitDelay: '<S3>/Output' */
  WaterTankSysIden2018_DW.Output_DSTATE =
    WaterTankSysIden2018_P.Output_InitialCondition;
}

/* Model terminate function */
void WaterTankSysIden2018_terminate(void)
{
  /* S-Function Block: <S2>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysIden2018_P.AnalogOutput1_RangeMode;
      parm.rangeidx = WaterTankSysIden2018_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysIden2018_P.AnalogOutput1_Channels,
                     &WaterTankSysIden2018_P.AnalogOutput1_FinalValue, &parm);
    }
  }

  /* S-Function Block: <S2>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysIden2018_P.AnalogOutput2_RangeMode;
      parm.rangeidx = WaterTankSysIden2018_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysIden2018_P.AnalogOutput2_Channels,
                     &WaterTankSysIden2018_P.AnalogOutput2_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  WaterTankSysIden2018_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  WaterTankSysIden2018_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  WaterTankSysIden2018_initialize();
}

void MdlTerminate(void)
{
  WaterTankSysIden2018_terminate();
}

/* Registration function */
RT_MODEL_WaterTankSysIden2018_T *WaterTankSysIden2018(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)WaterTankSysIden2018_M, 0,
                sizeof(RT_MODEL_WaterTankSysIden2018_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&WaterTankSysIden2018_M->solverInfo,
                          &WaterTankSysIden2018_M->Timing.simTimeStep);
    rtsiSetTPtr(&WaterTankSysIden2018_M->solverInfo, &rtmGetTPtr
                (WaterTankSysIden2018_M));
    rtsiSetStepSizePtr(&WaterTankSysIden2018_M->solverInfo,
                       &WaterTankSysIden2018_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&WaterTankSysIden2018_M->solverInfo,
                          (&rtmGetErrorStatus(WaterTankSysIden2018_M)));
    rtsiSetRTModelPtr(&WaterTankSysIden2018_M->solverInfo,
                      WaterTankSysIden2018_M);
  }

  rtsiSetSimTimeStep(&WaterTankSysIden2018_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&WaterTankSysIden2018_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = WaterTankSysIden2018_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    WaterTankSysIden2018_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    WaterTankSysIden2018_M->Timing.sampleTimes =
      (&WaterTankSysIden2018_M->Timing.sampleTimesArray[0]);
    WaterTankSysIden2018_M->Timing.offsetTimes =
      (&WaterTankSysIden2018_M->Timing.offsetTimesArray[0]);

    /* task periods */
    WaterTankSysIden2018_M->Timing.sampleTimes[0] = (0.0);
    WaterTankSysIden2018_M->Timing.sampleTimes[1] = (0.75);
    WaterTankSysIden2018_M->Timing.sampleTimes[2] = (180.0);

    /* task offsets */
    WaterTankSysIden2018_M->Timing.offsetTimes[0] = (0.0);
    WaterTankSysIden2018_M->Timing.offsetTimes[1] = (0.0);
    WaterTankSysIden2018_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(WaterTankSysIden2018_M, &WaterTankSysIden2018_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = WaterTankSysIden2018_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      WaterTankSysIden2018_M->Timing.perTaskSampleHitsArray;
    WaterTankSysIden2018_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    WaterTankSysIden2018_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(WaterTankSysIden2018_M, -1);
  WaterTankSysIden2018_M->Timing.stepSize0 = 0.75;
  WaterTankSysIden2018_M->Timing.stepSize1 = 0.75;
  WaterTankSysIden2018_M->Timing.stepSize2 = 180.0;

  /* External mode info */
  WaterTankSysIden2018_M->Sizes.checksums[0] = (528119185U);
  WaterTankSysIden2018_M->Sizes.checksums[1] = (1058438707U);
  WaterTankSysIden2018_M->Sizes.checksums[2] = (1209150091U);
  WaterTankSysIden2018_M->Sizes.checksums[3] = (1223872453U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    WaterTankSysIden2018_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(WaterTankSysIden2018_M->extModeInfo,
      &WaterTankSysIden2018_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(WaterTankSysIden2018_M->extModeInfo,
                        WaterTankSysIden2018_M->Sizes.checksums);
    rteiSetTPtr(WaterTankSysIden2018_M->extModeInfo, rtmGetTPtr
                (WaterTankSysIden2018_M));
  }

  WaterTankSysIden2018_M->solverInfoPtr = (&WaterTankSysIden2018_M->solverInfo);
  WaterTankSysIden2018_M->Timing.stepSize = (0.75);
  rtsiSetFixedStepSize(&WaterTankSysIden2018_M->solverInfo, 0.75);
  rtsiSetSolverMode(&WaterTankSysIden2018_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  WaterTankSysIden2018_M->ModelData.blockIO = ((void *) &WaterTankSysIden2018_B);
  (void) memset(((void *) &WaterTankSysIden2018_B), 0,
                sizeof(B_WaterTankSysIden2018_T));

  /* parameters */
  WaterTankSysIden2018_M->ModelData.defaultParam = ((real_T *)
    &WaterTankSysIden2018_P);

  /* states (dwork) */
  WaterTankSysIden2018_M->ModelData.dwork = ((void *) &WaterTankSysIden2018_DW);
  (void) memset((void *)&WaterTankSysIden2018_DW, 0,
                sizeof(DW_WaterTankSysIden2018_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    WaterTankSysIden2018_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  WaterTankSysIden2018_M->Sizes.numContStates = (0);/* Number of continuous states */
  WaterTankSysIden2018_M->Sizes.numY = (0);/* Number of model outputs */
  WaterTankSysIden2018_M->Sizes.numU = (0);/* Number of model inputs */
  WaterTankSysIden2018_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  WaterTankSysIden2018_M->Sizes.numSampTimes = (3);/* Number of sample times */
  WaterTankSysIden2018_M->Sizes.numBlocks = (25);/* Number of blocks */
  WaterTankSysIden2018_M->Sizes.numBlockIO = (8);/* Number of block outputs */
  WaterTankSysIden2018_M->Sizes.numBlockPrms = (51);/* Sum of parameter "widths" */
  return WaterTankSysIden2018_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
