#include <stdlib.h>
#include <stdio.h>
#include "noteReader.c"

void updateNote();

char MarioSong[] = "E4E4E4C4E4G4G3";
int stop = (sizeof(MarioSong) / sizeof(MarioSong[0]));
char *p = MarioSong;
char currentNote[2] = "E4";
short state = 1;


void playCurrentNote()
{
  
  switch (state) {
  case 1: 
    playNoteAfterGap(currentNote, 0, 40);
    if(!playing) {
      state++;
      updateNote();
    }
    break;
  case 2:
    playNoteAfterGap(currentNote, 10, 40);
    if(!playing) {
      state++;
      updateNote();
    }
    break;
  case 3:
    playNoteAfterGap(currentNote, 30, 40);
    if(!playing) {
      state++;
      updateNote();
    }
    break;
  case 4:
    playNoteAfterGap(currentNote, 30, 40);
    if(!playing) {
      state++;
      updateNote();
    }
    break;
  case 5:
    playNoteAfterGap(currentNote, 30, 40);
    if(!playing) {
      state++;
      updateNote();
    }
    break;
  case 6:
    playNoteAfterGap(currentNote, 20, 40);
    if(!playing) {
      state++;
      updateNote();
    }
    break;
  case 7:
    playNoteAfterGap(currentNote, 20, 40);
    if(!playing) {
      state++;
      updateNote();
    }
    break;
  case 8:
    playNoteAfterGap(currentNote, 60, 40);
    if(!playing) {
      state = 1;
      currentNote[0] = 'E';
      currentNote[0] = '4';
      p = MarioSong;
    }
    break;
  default:
    break;
  }
}

void updateNote()
{
  if(p <= MarioSong + stop) {
     currentNote[0] = *p;
     currentNote[1] = *(p+1);
     p += 2;
  }
}
