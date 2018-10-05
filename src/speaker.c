#include "board.h"
#include "PWM_functions.h"
#include "pitches.h"
#include "speaker.h"

/* Plays the chosen tone, puts a little pause between each note */

void Play_Tone(int note,float time){
	Chip_SCTPWM_SetFrequency(note); // Play note
	while (time > 0){				// Wait for the input time
		__WFI();
		time=time-0.1;
	}
	Pause(0.2);						// Put a little pause, useful when using the same note after this one
}

/* Halts and waits a given time*/
void Pause(float time){
	Chip_SCTPWM_SetFrequency(0);
	while (time > 0){
		__WFI();
		time=time-0.1;
	}
}
