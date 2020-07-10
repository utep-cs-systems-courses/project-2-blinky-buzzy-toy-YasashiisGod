#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char switch_state_down, switch_state_changed; /* effectively boolean */

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & BUTTONS);	/* if switch up, sense down */
  P2IES &= (p2val | ~BUTTONS);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= BUTTONS;		/* enables resistors for switches */
  P2IE = BUTTONS;		/* enable interrupts from switches */
  P2OUT |= BUTTONS;		/* pull-ups for switches */
  P2DIR &= ~BUTTONS;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
  buzzer_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  switch_state_down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  switch_state_changed = 1;
  led_update();
  buzzer_update();
}
