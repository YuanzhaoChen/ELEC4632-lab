/*
 * WaterTankSysControl2018.c
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
#include "WaterTankSysControl2018_dt.h"

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
  105.0, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int RTWinBoardCount = 1;
RTWINBOARD RTWinBoards[1] = {
  { "National_Instruments/PCI-MIO-16E-4", 4294967295U, 6, RTWinBoardOptions0 },
};

/* Block signals (auto storage) */
B_WaterTankSysControl2018_T WaterTankSysControl2018_B;

/* Block states (auto storage) */
DW_WaterTankSysControl2018_T WaterTankSysControl2018_DW;

/* Real-time model */
RT_MODEL_WaterTankSysControl2018_T WaterTankSysControl2018_M_;
RT_MODEL_WaterTankSysControl2018_T *const WaterTankSysControl2018_M =
  &WaterTankSysControl2018_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(WaterTankSysControl2018_M, 1);
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

  /* tid 0 shares data with slower tid rate: 1 */
  WaterTankSysControl2018_M->Timing.RateInteraction.TID0_1 =
    (WaterTankSysControl2018_M->Timing.TaskCounters.TID[1] == 0);

  /* update PerTaskSampleHits matrix for non-inline sfcn */
  WaterTankSysControl2018_M->Timing.perTaskSampleHits[1] =
    WaterTankSysControl2018_M->Timing.RateInteraction.TID0_1;

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (WaterTankSysControl2018_M->Timing.TaskCounters.TID[1])++;
  if ((WaterTankSysControl2018_M->Timing.TaskCounters.TID[1]) > 139) {/* Sample time: [105.0s, 0.0s] */
    WaterTankSysControl2018_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model output function for TID0 */
void WaterTankSysControl2018_output0(void) /* Sample time: [0.75s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_OriginalOutput;
  real_T rtb_SaturationTANK2;
  int32_T j;
  int32_T cff;
  real_T rtb_Sum2;
  real_T rtb_uk;

  {                                    /* Sample time: [0.75s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/Rate Transition1' */
  if (WaterTankSysControl2018_M->Timing.RateInteraction.TID0_1) {
    WaterTankSysControl2018_B.OffsetFreeReferenceSignaly_refk =
      WaterTankSysControl2018_DW.RateTransition1_Buffer0;
  }

  /* End of RateTransition: '<Root>/Rate Transition1' */

  /* Sum: '<Root>/Sum3' incorporates:
   *  Delay: '<S2>/Delay'
   *  Gain: '<Root>/DC Gain  Compensation'
   *  Gain: '<S2>/Gain4'
   */
  rtb_uk = 1.0 / WaterTankSysControl2018_P.DC_gain *
    WaterTankSysControl2018_B.OffsetFreeReferenceSignaly_refk +
    (-WaterTankSysControl2018_P.L_ndb2[0] *
     WaterTankSysControl2018_DW.Delay_DSTATE[0] +
     -WaterTankSysControl2018_P.L_ndb2[1] *
     WaterTankSysControl2018_DW.Delay_DSTATE[1]);

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  rtb_SaturationTANK2 = WaterTankSysControl2018_P.u_offset + rtb_uk;

  /* Gain: '<Root>/Activation Gain TANK#1' */
  rtb_Sum2 = WaterTankSysControl2018_P.ActivationGainTANK1_Gain *
    rtb_SaturationTANK2;

  /* Saturate: '<Root>/Saturation TANK#1' */
  if (rtb_Sum2 > WaterTankSysControl2018_P.SaturationTANK1_UpperSat) {
    WaterTankSysControl2018_B.ActualInput =
      WaterTankSysControl2018_P.SaturationTANK1_UpperSat;
  } else if (rtb_Sum2 < WaterTankSysControl2018_P.SaturationTANK1_LowerSat) {
    WaterTankSysControl2018_B.ActualInput =
      WaterTankSysControl2018_P.SaturationTANK1_LowerSat;
  } else {
    WaterTankSysControl2018_B.ActualInput = rtb_Sum2;
  }

  /* End of Saturate: '<Root>/Saturation TANK#1' */

  /* Gain: '<Root>/Activation Gain TANK#2' */
  rtb_SaturationTANK2 *= WaterTankSysControl2018_P.ActivationGainTANK2_Gain;

  /* Saturate: '<Root>/Saturation TANK#2' */
  if (rtb_SaturationTANK2 > WaterTankSysControl2018_P.SaturationTANK2_UpperSat)
  {
    rtb_SaturationTANK2 = WaterTankSysControl2018_P.SaturationTANK2_UpperSat;
  } else {
    if (rtb_SaturationTANK2 < WaterTankSysControl2018_P.SaturationTANK2_LowerSat)
    {
      rtb_SaturationTANK2 = WaterTankSysControl2018_P.SaturationTANK2_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation TANK#2' */
  /* S-Function Block: <S1>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysControl2018_P.AnalogOutput1_RangeMode;
      parm.rangeidx = WaterTankSysControl2018_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControl2018_P.AnalogOutput1_Channels,
                     &WaterTankSysControl2018_B.ActualInput, &parm);
    }
  }

  /* S-Function Block: <S1>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysControl2018_P.AnalogOutput2_RangeMode;
      parm.rangeidx = WaterTankSysControl2018_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControl2018_P.AnalogOutput2_Channels,
                     &rtb_SaturationTANK2, &parm);
    }
  }

  /* S-Function Block: <S1>/Analog Input1 */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) WaterTankSysControl2018_P.AnalogInput1_RangeMode;
    parm.rangeidx = WaterTankSysControl2018_P.AnalogInput1_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &WaterTankSysControl2018_P.AnalogInput1_Channels,
                   &WaterTankSysControl2018_B.OriginalOutput, &parm);
  }

  /* S-Function Block: <S1>/Analog Input2 */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) WaterTankSysControl2018_P.AnalogInput2_RangeMode;
    parm.rangeidx = WaterTankSysControl2018_P.AnalogInput2_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &WaterTankSysControl2018_P.AnalogInput2_Channels,
                   &rtb_OriginalOutput, &parm);
  }

  /* DiscreteFir: '<S1>/Discrete FIR Filter1' */
  rtb_Sum2 = WaterTankSysControl2018_B.OriginalOutput *
    WaterTankSysControl2018_P.DiscreteFIRFilter1_Coefficients[0];
  cff = 1;
  for (j = WaterTankSysControl2018_DW.DiscreteFIRFilter1_circBuf; j < 4; j++) {
    rtb_Sum2 += WaterTankSysControl2018_DW.DiscreteFIRFilter1_states[j] *
      WaterTankSysControl2018_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < WaterTankSysControl2018_DW.DiscreteFIRFilter1_circBuf; j++) {
    rtb_Sum2 += WaterTankSysControl2018_DW.DiscreteFIRFilter1_states[j] *
      WaterTankSysControl2018_P.DiscreteFIRFilter1_Coefficients[cff];
    cff++;
  }

  WaterTankSysControl2018_B.NoiseReducedOutput = rtb_Sum2;

  /* End of DiscreteFir: '<S1>/Discrete FIR Filter1' */

  /* Sum: '<Root>/Sum4' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  WaterTankSysControl2018_B.ReferenceSignal = WaterTankSysControl2018_P.y_offset
    + WaterTankSysControl2018_B.OffsetFreeReferenceSignaly_refk;

  /* Sum: '<S2>/Sum2' incorporates:
   *  Constant: '<Root>/Constant'
   *  Delay: '<S2>/Delay'
   *  Gain: '<S2>/Gain1'
   *  Sum: '<Root>/Sum5'
   */
  rtb_Sum2 = (WaterTankSysControl2018_B.NoiseReducedOutput -
              WaterTankSysControl2018_P.y_offset) -
    (WaterTankSysControl2018_P.C_obsrv[0] *
     WaterTankSysControl2018_DW.Delay_DSTATE[0] +
     WaterTankSysControl2018_P.C_obsrv[1] *
     WaterTankSysControl2018_DW.Delay_DSTATE[1]);

  /* Sum: '<S2>/Sum1' incorporates:
   *  Delay: '<S2>/Delay'
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/Gain2'
   *  Gain: '<S2>/Gain3'
   */
  WaterTankSysControl2018_B.Sum1[0] = (WaterTankSysControl2018_P.Gain3_Gain[0] *
    rtb_Sum2 + WaterTankSysControl2018_P.H_obsrv[0] * rtb_uk) +
    (WaterTankSysControl2018_P.G_obsrv[0] *
     WaterTankSysControl2018_DW.Delay_DSTATE[0] +
     WaterTankSysControl2018_P.G_obsrv[2] *
     WaterTankSysControl2018_DW.Delay_DSTATE[1]);
  WaterTankSysControl2018_B.Sum1[1] = (WaterTankSysControl2018_P.Gain3_Gain[1] *
    rtb_Sum2 + WaterTankSysControl2018_P.H_obsrv[1] * rtb_uk) +
    (WaterTankSysControl2018_P.G_obsrv[1] *
     WaterTankSysControl2018_DW.Delay_DSTATE[0] +
     WaterTankSysControl2018_P.G_obsrv[3] *
     WaterTankSysControl2018_DW.Delay_DSTATE[1]);
}

/* Model update function for TID0 */
void WaterTankSysControl2018_update0(void) /* Sample time: [0.75s, 0.0s] */
{
  /* Update for Delay: '<S2>/Delay' */
  WaterTankSysControl2018_DW.Delay_DSTATE[0] = WaterTankSysControl2018_B.Sum1[0];
  WaterTankSysControl2018_DW.Delay_DSTATE[1] = WaterTankSysControl2018_B.Sum1[1];

  /* Update for DiscreteFir: '<S1>/Discrete FIR Filter1' */
  /* Update circular buffer index */
  WaterTankSysControl2018_DW.DiscreteFIRFilter1_circBuf--;
  if (WaterTankSysControl2018_DW.DiscreteFIRFilter1_circBuf < 0) {
    WaterTankSysControl2018_DW.DiscreteFIRFilter1_circBuf = 3;
  }

  /* Update circular buffer */
  WaterTankSysControl2018_DW.DiscreteFIRFilter1_states[WaterTankSysControl2018_DW.DiscreteFIRFilter1_circBuf]
    = WaterTankSysControl2018_B.OriginalOutput;

  /* End of Update for DiscreteFir: '<S1>/Discrete FIR Filter1' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++WaterTankSysControl2018_M->Timing.clockTick0)) {
    ++WaterTankSysControl2018_M->Timing.clockTickH0;
  }

  WaterTankSysControl2018_M->Timing.t[0] =
    WaterTankSysControl2018_M->Timing.clockTick0 *
    WaterTankSysControl2018_M->Timing.stepSize0 +
    WaterTankSysControl2018_M->Timing.clockTickH0 *
    WaterTankSysControl2018_M->Timing.stepSize0 * 4294967296.0;
}

/* Model output function for TID1 */
void WaterTankSysControl2018_output1(void) /* Sample time: [105.0s, 0.0s] */
{
  uint8_T rtb_FixPtSum1;

  /* Sum: '<S5>/FixPt Sum1' incorporates:
   *  Constant: '<S5>/FixPt Constant'
   *  UnitDelay: '<S4>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)((uint32_T)WaterTankSysControl2018_DW.Output_DSTATE +
    WaterTankSysControl2018_P.FixPtConstant_Value);

  /* Switch: '<S6>/FixPt Switch' incorporates:
   *  Constant: '<S6>/Constant'
   */
  if (rtb_FixPtSum1 > WaterTankSysControl2018_P.LimitedCounter_uplimit) {
    WaterTankSysControl2018_B.FixPtSwitch =
      WaterTankSysControl2018_P.Constant_Value;
  } else {
    WaterTankSysControl2018_B.FixPtSwitch = rtb_FixPtSum1;
  }

  /* End of Switch: '<S6>/FixPt Switch' */

  /* MultiPortSwitch: '<S3>/Output' incorporates:
   *  Constant: '<S3>/Vector'
   *  UnitDelay: '<S4>/Output'
   */
  WaterTankSysControl2018_B.Output =
    WaterTankSysControl2018_P.RepeatingSequenceStair1_OutValues[WaterTankSysControl2018_DW.Output_DSTATE];
}

/* Model update function for TID1 */
void WaterTankSysControl2018_update1(void) /* Sample time: [105.0s, 0.0s] */
{
  /* Update for RateTransition: '<Root>/Rate Transition1' */
  WaterTankSysControl2018_DW.RateTransition1_Buffer0 =
    WaterTankSysControl2018_B.Output;

  /* Update for UnitDelay: '<S4>/Output' */
  WaterTankSysControl2018_DW.Output_DSTATE =
    WaterTankSysControl2018_B.FixPtSwitch;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++WaterTankSysControl2018_M->Timing.clockTick1)) {
    ++WaterTankSysControl2018_M->Timing.clockTickH1;
  }

  WaterTankSysControl2018_M->Timing.t[1] =
    WaterTankSysControl2018_M->Timing.clockTick1 *
    WaterTankSysControl2018_M->Timing.stepSize1 +
    WaterTankSysControl2018_M->Timing.clockTickH1 *
    WaterTankSysControl2018_M->Timing.stepSize1 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void WaterTankSysControl2018_output(int_T tid)
{
  switch (tid) {
   case 0 :
    WaterTankSysControl2018_output0();
    break;

   case 1 :
    WaterTankSysControl2018_output1();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void WaterTankSysControl2018_update(int_T tid)
{
  switch (tid) {
   case 0 :
    WaterTankSysControl2018_update0();
    break;

   case 1 :
    WaterTankSysControl2018_update1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void WaterTankSysControl2018_initialize(void)
{
  /* Start for RateTransition: '<Root>/Rate Transition1' */
  WaterTankSysControl2018_B.OffsetFreeReferenceSignaly_refk =
    WaterTankSysControl2018_P.RateTransition1_X0;

  /* S-Function Block: <S1>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysControl2018_P.AnalogOutput1_RangeMode;
      parm.rangeidx = WaterTankSysControl2018_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControl2018_P.AnalogOutput1_Channels,
                     &WaterTankSysControl2018_P.AnalogOutput1_InitialValue,
                     &parm);
    }
  }

  /* S-Function Block: <S1>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysControl2018_P.AnalogOutput2_RangeMode;
      parm.rangeidx = WaterTankSysControl2018_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControl2018_P.AnalogOutput2_Channels,
                     &WaterTankSysControl2018_P.AnalogOutput2_InitialValue,
                     &parm);
    }
  }

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition1' */
  WaterTankSysControl2018_DW.RateTransition1_Buffer0 =
    WaterTankSysControl2018_P.RateTransition1_X0;

  /* InitializeConditions for Delay: '<S2>/Delay' */
  WaterTankSysControl2018_DW.Delay_DSTATE[0] =
    WaterTankSysControl2018_P.Delay_InitialCondition[0];
  WaterTankSysControl2018_DW.Delay_DSTATE[1] =
    WaterTankSysControl2018_P.Delay_InitialCondition[1];

  /* InitializeConditions for DiscreteFir: '<S1>/Discrete FIR Filter1' */
  WaterTankSysControl2018_DW.DiscreteFIRFilter1_circBuf = 0;
  WaterTankSysControl2018_DW.DiscreteFIRFilter1_states[0] =
    WaterTankSysControl2018_P.DiscreteFIRFilter1_InitialStates;
  WaterTankSysControl2018_DW.DiscreteFIRFilter1_states[1] =
    WaterTankSysControl2018_P.DiscreteFIRFilter1_InitialStates;
  WaterTankSysControl2018_DW.DiscreteFIRFilter1_states[2] =
    WaterTankSysControl2018_P.DiscreteFIRFilter1_InitialStates;
  WaterTankSysControl2018_DW.DiscreteFIRFilter1_states[3] =
    WaterTankSysControl2018_P.DiscreteFIRFilter1_InitialStates;

  /* InitializeConditions for UnitDelay: '<S4>/Output' */
  WaterTankSysControl2018_DW.Output_DSTATE =
    WaterTankSysControl2018_P.Output_InitialCondition;
}

/* Model terminate function */
void WaterTankSysControl2018_terminate(void)
{
  /* S-Function Block: <S1>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysControl2018_P.AnalogOutput1_RangeMode;
      parm.rangeidx = WaterTankSysControl2018_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControl2018_P.AnalogOutput1_Channels,
                     &WaterTankSysControl2018_P.AnalogOutput1_FinalValue, &parm);
    }
  }

  /* S-Function Block: <S1>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) WaterTankSysControl2018_P.AnalogOutput2_RangeMode;
      parm.rangeidx = WaterTankSysControl2018_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &WaterTankSysControl2018_P.AnalogOutput2_Channels,
                     &WaterTankSysControl2018_P.AnalogOutput2_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  WaterTankSysControl2018_output(tid);
}

void MdlUpdate(int_T tid)
{
  WaterTankSysControl2018_update(tid);
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
  WaterTankSysControl2018_initialize();
}

void MdlTerminate(void)
{
  WaterTankSysControl2018_terminate();
}

/* Registration function */
RT_MODEL_WaterTankSysControl2018_T *WaterTankSysControl2018(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)WaterTankSysControl2018_M, 0,
                sizeof(RT_MODEL_WaterTankSysControl2018_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = WaterTankSysControl2018_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    WaterTankSysControl2018_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    WaterTankSysControl2018_M->Timing.sampleTimes =
      (&WaterTankSysControl2018_M->Timing.sampleTimesArray[0]);
    WaterTankSysControl2018_M->Timing.offsetTimes =
      (&WaterTankSysControl2018_M->Timing.offsetTimesArray[0]);

    /* task periods */
    WaterTankSysControl2018_M->Timing.sampleTimes[0] = (0.75);
    WaterTankSysControl2018_M->Timing.sampleTimes[1] = (105.0);

    /* task offsets */
    WaterTankSysControl2018_M->Timing.offsetTimes[0] = (0.0);
    WaterTankSysControl2018_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(WaterTankSysControl2018_M,
             &WaterTankSysControl2018_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = WaterTankSysControl2018_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      WaterTankSysControl2018_M->Timing.perTaskSampleHitsArray;
    WaterTankSysControl2018_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    WaterTankSysControl2018_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(WaterTankSysControl2018_M, 525.0);
  WaterTankSysControl2018_M->Timing.stepSize0 = 0.75;
  WaterTankSysControl2018_M->Timing.stepSize1 = 105.0;

  /* External mode info */
  WaterTankSysControl2018_M->Sizes.checksums[0] = (1378430764U);
  WaterTankSysControl2018_M->Sizes.checksums[1] = (147328259U);
  WaterTankSysControl2018_M->Sizes.checksums[2] = (504286106U);
  WaterTankSysControl2018_M->Sizes.checksums[3] = (182940256U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    WaterTankSysControl2018_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(WaterTankSysControl2018_M->extModeInfo,
      &WaterTankSysControl2018_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(WaterTankSysControl2018_M->extModeInfo,
                        WaterTankSysControl2018_M->Sizes.checksums);
    rteiSetTPtr(WaterTankSysControl2018_M->extModeInfo, rtmGetTPtr
                (WaterTankSysControl2018_M));
  }

  WaterTankSysControl2018_M->solverInfoPtr =
    (&WaterTankSysControl2018_M->solverInfo);
  WaterTankSysControl2018_M->Timing.stepSize = (0.75);
  rtsiSetFixedStepSize(&WaterTankSysControl2018_M->solverInfo, 0.75);
  rtsiSetSolverMode(&WaterTankSysControl2018_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  WaterTankSysControl2018_M->ModelData.blockIO = ((void *)
    &WaterTankSysControl2018_B);
  (void) memset(((void *) &WaterTankSysControl2018_B), 0,
                sizeof(B_WaterTankSysControl2018_T));

  /* parameters */
  WaterTankSysControl2018_M->ModelData.defaultParam = ((real_T *)
    &WaterTankSysControl2018_P);

  /* states (dwork) */
  WaterTankSysControl2018_M->ModelData.dwork = ((void *)
    &WaterTankSysControl2018_DW);
  (void) memset((void *)&WaterTankSysControl2018_DW, 0,
                sizeof(DW_WaterTankSysControl2018_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    WaterTankSysControl2018_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  WaterTankSysControl2018_M->Sizes.numContStates = (0);/* Number of continuous states */
  WaterTankSysControl2018_M->Sizes.numY = (0);/* Number of model outputs */
  WaterTankSysControl2018_M->Sizes.numU = (0);/* Number of model inputs */
  WaterTankSysControl2018_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  WaterTankSysControl2018_M->Sizes.numSampTimes = (2);/* Number of sample times */
  WaterTankSysControl2018_M->Sizes.numBlocks = (35);/* Number of blocks */
  WaterTankSysControl2018_M->Sizes.numBlockIO = (8);/* Number of block outputs */
  WaterTankSysControl2018_M->Sizes.numBlockPrms = (63);/* Sum of parameter "widths" */
  return WaterTankSysControl2018_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
