#include "noteReader.h"
#include "buzzer.h"

int whenToPlay, whenToStop;
unsigned int playing = 0;

int getCurrentNoteFrequency(char *note) {
  int column;

  if(((*note) == 'A' || (*note) == 'B'))
    return notes[(*note) - 'A'][(*(note+1)) - '0'];
  else
    return notes[(*note) - 'A'][(*(note+1)) - '0' - 1];
}

int getCycle(int frequency) {
  return (2*1000000) / frequency;
}

void playNoteAfterGap(char note[], int gap, int duration) {
    int frequency = getCurrentNoteFrequency(note);
    int cycle = getCycle(frequency);  

    if (!playing) {
      playing = 1;
      whenToPlay = buzzer_Count + gap;
      whenToStop = whenToPlay + duration;
    }
    
    if (buzzer_Count >= whenToPlay) { 
      buzzer_set_period(cycle);
    }
    
    if (buzzer_Count >= whenToStop) {
      buzzer_set_period(100000);
      playing = whenToPlay = whenToStop = 0;
    }
}

