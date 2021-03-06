#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 1;
  if (++blink_count == (200)){
    toggle_red();
    blink_count = 0;
  }
}
