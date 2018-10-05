#include "board.h"
#include "PWM_functions.h"
#include "pitches.h"
#include "speaker.h"

#define TICKRATE_HZ (100) // SysTick rate in Hz

void SysTick_Handler(void)
{
	/* Do nothing */
}

int main(void)
{
	int done = 0;

    SystemCoreClockUpdate();                                        // Generic Initialization
    Board_Init();
    SysTick_Config(SystemCoreClock/TICKRATE_HZ);                    // Enable SysTick Timer

    Chip_SCTPWM_Init(SCT_PWM);                                      // Initialize the SCT
    App_Setup_Pin();                                                // Setup Board specific output pin
    Chip_SCTPWM_SetOutPin(SCT_PWM, SCT_PWM_OUT, SCT_PWM_PIN_OUT);	// Use SCT0_OUT1

    while (!done){

    	Play_Tone(C4,4);
    	Play_Tone(D4,4);
    	Play_Tone(E4,4);
    	Play_Tone(C4,4);

    	Play_Tone(C4,4);
    	Play_Tone(D4,4);
    	Play_Tone(E4,4);
    	Play_Tone(C4,4);

    	Pause(4);

    	Play_Tone(E4,4);
    	Play_Tone(F4,4);
    	Play_Tone(G4,4);

    	Pause (4);

    	Play_Tone(E4,4);
    	Play_Tone(F4,4);
    	Play_Tone(G4,4);

    	Pause (4);

    	Play_Tone(G4,2);
		Play_Tone(A4,2);
		Play_Tone(G4,2);
		Play_Tone(F4,2);
		Play_Tone(E4,4);
		Play_Tone(C4,4);

		Pause (2);

		Play_Tone(G4,2);
		Play_Tone(A4,2);
		Play_Tone(G4,2);
		Play_Tone(F4,2);
		Play_Tone(E4,4);
		Play_Tone(C4,4);

		Pause(4);

		Play_Tone(C4,4);
		Play_Tone(G4,4);
		Play_Tone(C4,4);

		Pause(4);

		Play_Tone(C4,4);
		Play_Tone(G4,4);
		Play_Tone(C4,4);

    	done = 1; // TODO: use a switch to trigger
    }

    return 0;
}
