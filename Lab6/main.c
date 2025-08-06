#include "platform.h"
#include "gpio.h"
#include "leds.h"

static int count = 0;
void button_press_isr();

void button_press_isr() {
	gpio_set(P_DBG_ISR, 1);
	count++;
	gpio_set(P_DBG_ISR, 0);
}

int main(void) {
	// Initialise LEDs.
	leds_init();
	
	// Set up debug signals.
	gpio_set_mode(P_DBG_ISR, Output);
	gpio_set_mode(P_DBG_MAIN, Output);
	
	// Set up on-board switch.
	gpio_set_trigger(PD_15, Rising, PullUp);
  gpio_set_callback(PD_15, button_press_isr);
	
	//leds_set(1,1,1);
	while(1)
	{
		gpio_toggle(P_DBG_MAIN);
		leds_set(count & 1, count & 2, count & 4);
	}
}

