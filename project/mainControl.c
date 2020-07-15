#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void main(void) 
{  
  configureClocks();
  //buzzer_init();
  //buzzer_set_period(4545);
  switch_init();
  buzzer_init();
  buzzer_set_period(4545);
  led_init();

  or_sr(0x18);  // CPU off, GIE on
} 
