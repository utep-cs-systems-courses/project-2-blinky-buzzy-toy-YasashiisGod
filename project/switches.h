#ifndef switches_included
#define switches_included

#define SW1 BIT0           		/* switch1 is p1.3 */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

#define BUTTONS (SW1 | SW2 | SW3 | SW4)	/* Initialized all the buttons */

void switch_init();
void switch_interrupt_handler();

extern char switch1_state_down, switch2_state_down, switch3_state_down, switch4_state_down, switch_state_changed; /* effectively boolean */

#endif // included
