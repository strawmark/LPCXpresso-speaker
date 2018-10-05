#ifndef __SPEAKER_H__
#define __SPEAKER_H__

void Play_Tone(int note,float duration);
void Pause(float time);

typedef struct note{
	int tone;
	float time;
}note;

#endif
