#include "PWM_functions.h"

/* Setup board specific pin muxing */

void App_Setup_Pin(void)
{
    /* Enable SWM clock before altering SWM */
    Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_SWM);

    /* Connect SCT_OUT1 to P0_12 (bottom side of the LCP Board) */
    Chip_SWM_MovablePinAssign(SWM_SCT0_OUT1_O, 12);
    Chip_Clock_DisablePeriphClock(SYSCTL_CLOCK_SWM);
}

/* Percentage to ticks conversion, with float values */

double Chip_SCTPWM_PercentageToTicks_Float(LPC_SCT_T *pSCT, double percent)
{
    return (Chip_SCTPWM_GetTicksPerCycle(pSCT) * percent) / 100;
}

/* Stops and restarts the PWM to changes the frequency, Init and output pins should be already selected */

void Chip_SCTPWM_SetFrequency(int frequency)
{
	Chip_SCTPWM_Stop(SCT_PWM);
	Chip_SCTPWM_SetRate(SCT_PWM, frequency);
	Chip_SCTPWM_SetDutyCycle(SCT_PWM, 1, Chip_SCTPWM_PercentageToTicks_Float(SCT_PWM,50));	// 50% duty cycle
	Chip_SCTPWM_Start(SCT_PWM);
}
