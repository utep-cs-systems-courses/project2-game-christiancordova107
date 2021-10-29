#include <msp430.h>
#include "libTimer.h"
#include "main.h"

extern int greenDim;
extern int Green_On_Off_Flag;

void Dim25Green()
{  
  switch(greenDim) {
    
  case 1: Green_On_Off_Flag = 1; greenDim++; break;
  case 2: Green_On_Off_Flag = 0; greenDim++; break;
  case 3: Green_On_Off_Flag = 0; greenDim++; break;
  case 4: Green_On_Off_Flag = 0; greenDim = 1; break;
  }
}
