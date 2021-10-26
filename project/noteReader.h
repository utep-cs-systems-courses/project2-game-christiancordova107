/*Note reader and Player logic
  Remember universal variable secondCount
  Make a pointer to the String that contains the input
  Have a variable that is the gap between the last played note and the note to be play

  while you are reading the input 
    read the current note
    do arithmetic to get cycles to play the frequency
    wait for gap to be over
    call the method to set the period on the buzzer in order to play the note 
*/
#include "frequencyChart.h"

extern int buzzer_Count;

int getCurrentNoteFrequency(char *note);
int getCycle(int frequency);
void playNoteAfterGap(char note[], int gap, int duration);
