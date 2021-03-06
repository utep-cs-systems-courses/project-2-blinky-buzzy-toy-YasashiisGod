#include <msp430.h>
#include "switches.h"

/* Switch on P1 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & BUTTONS) {	      /* did a button cause this interrupt? */
    P2IFG &= ~BUTTONS;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}

