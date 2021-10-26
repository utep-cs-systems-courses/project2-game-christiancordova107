#include <msp430.h>
#include "libTimer.h"
#include "main.h"
#include "MarioSong.c"

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (LED_RED | LED_GREEN)

#define SW1 BIT0                /* switch1 is p1.3 */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4)		/* only 1 switch on this board */

int buzzer_Count = 0;
int led_Count = 0;
int greenState, greenDim;
int redState, redDim;
int state_toy = 0;

void switch_init() {
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
}

void led_init() {
  P1DIR |= LEDS;
  P1OUT &= ~LEDS;		/* leds initially off */
}

void wdt_init() {
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
}

void main(void) 
{  
  switch_init();
  led_init();
  wdt_init();
  buzzer_init();  
  or_sr(0x18);  // CPU off, GIE on
} 

static int sw1Down;
static int sw2Down;
static int sw3Down;
static int sw4Down;

void
switch_interrupt_handler()
{
  char p2val = P2IN;		/* switch is in P1 */

/* update switch interrupt sense to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */

  sw1Down = (p2val & SW1)? 0:1;
  sw2Down = (p2val & SW2)? 0:1;
  sw3Down = (p2val & SW3)? 0:1;
  sw4Down = (p2val & SW4)? 0:1;
  
}

/* Switch on P1 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  led_Count++;
  buzzer_Count++;

  //while switch 1 is being pressed play the song and turn green on
  if(sw1Down) {
      playCurrentNote();
  }
  else {
    buzzer_set_period(100000);
  }

  if(sw2Down) {
    if (state_toy == 0) {
      state_toy = 1;
      greenState = 0;
      redState = 0;
      greenDim = 1;
      redDim = 1;
      P1OUT |= LEDS;
    }

    else if(state_toy == 1) {
      greenState++;
    }
  }
  
  if(sw3Down) {
    if(state_toy == 1) {
      redState++;
    }
  }

  if(sw4Down) {
    state_toy = 0;
    P1OUT &= ~LEDS;
  }
  
  if(state_toy  == 1) {
    if(greenState == 0)
      P1OUT |= LED_GREEN;
  if(greenState == 1) 
    Dim75Green();
  else if(greenState == 2) 
    Dim50Green();
  else if(greenState == 3)
    Dim25Green();
  else {
    //greenState = 0;
    //P1OUT |= LED_GREEN;
  }
  }
  
  if(state_toy == 1) {
    if(redState == 0)
      P1OUT |= LED_RED;
    else if(redState == 1) 
      Dim75Red();
    else if(redState == 2) 
      Dim50Red();
    else if(redState == 3) 
      Dim25Red();
    else {
    //redState = 0;
    //P1OUT |= LED_RED;
  }
  }
}

void Dim25Green()
{
  
  switch(greenDim) {
    
  case 1: P1OUT |= LED_GREEN; greenDim++; break;
  case 2: P1OUT &= ~LED_GREEN; greenDim++; break;
  case 3: P1OUT &= ~LED_GREEN; greenDim++; break;
  case 4: P1OUT &= ~LED_GREEN; greenDim = 1; break;
  }
}

void Dim50Green()
{  
  switch(greenDim) {
    
  case 1: P1OUT |= LED_GREEN; greenDim++; break;
  case 2: P1OUT |= LED_GREEN; greenDim++; break;
  case 3: P1OUT &= ~LED_GREEN; greenDim++; break;
  case 4: P1OUT &= ~LED_GREEN; greenDim = 1; break;
  }
}

void Dim75Green()
{ 
  switch(greenDim) {
    
  case 1: P1OUT |= LED_GREEN; greenDim++; break;
  case 2: P1OUT |= LED_GREEN; greenDim++; break;
  case 3: P1OUT |= LED_GREEN; greenDim++; break;
  case 4: P1OUT &= ~LED_GREEN; greenDim = 1; break;
  }
}

void Dim25Red()
{  
  switch(redDim) {
    
  case 1: P1OUT |= LED_RED; redDim++; break;
  case 2: P1OUT &= ~LED_RED; redDim++; break;
  case 3: P1OUT &= ~LED_RED; redDim++; break;
  case 4: P1OUT &= ~LED_RED; redDim = 1; break;
  }
}

void Dim50Red()
{  
  switch(redDim) {
    
  case 1: P1OUT |= LED_RED; redDim++; break;
  case 2: P1OUT |= LED_RED; redDim++; break;
  case 3: P1OUT &= ~LED_RED; redDim++; break;
  case 4: P1OUT &= ~LED_RED; redDim = 1; break;
  }
}

void Dim75Red()
{  
  switch(redDim) {
    
  case 1: P1OUT |= LED_RED; redDim++; break;
  case 2: P1OUT |= LED_RED; redDim++; break;
  case 3: P1OUT |= LED_RED; redDim++; break;
  case 4: P1OUT &= ~LED_RED; redDim = 1; break;
  }
}

  
