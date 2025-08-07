#include "platform.h"
#include "gpio.h"
#include "delay.h"
#include "switches.h"

static int period = 140;
static int duration_ms;

void update_buttons(void) {
	static int lastButtonsPressed[2] = { 0 };
	int buttonsPressed[2];
	// Remember previous state of the up and down buttons so that
	// we don't interpret a single button press multiple times.
	
buttonsPressed[0] = switch_get(P_SW_UP);
buttonsPressed[1] = switch_get(P_SW_DN);
	
	
	buttonsPressed[1] = switch_get(P_SW_DN);
	if (buttonsPressed[0] && !lastButtonsPressed[0]) {
//		__asm(
//    "MOV      r0,#0xc0 \n\t\
//		MOVT     r0,#0x2000 \n\t\
//		LDR      r1,[r0,#0] \n\t\
//		ADDS     r1,r1,#0x64 \n\t\
//		STR      r1,[r0,#0] \n\t\
//		LDR      r0,[r0,#0] \n\t\
//		MOV      r1,#0x3E9 \n\t\
//		CMP      r0,r1 \n\t\
//		BLT      END \n\t\
//		MOV      r1,#0xc0 \n\t\
//		MOVT     r1,#0x2000 \n\t\
//		MOV      r0,#0x3E8 \n\t\
//		STR      r0,[r1,#0] \n\t\
//		"
// 		"END: \n\t");
		duration_ms += 100;
		if (duration_ms > 1000) {
			duration_ms = 1000;
		}
	}
	if (buttonsPressed[1] && !lastButtonsPressed[1]) {
		duration_ms -= 100;
		if (duration_ms < 100) {
			duration_ms = 100;
		}
	}
	lastButtonsPressed[0] = buttonsPressed[0];
	lastButtonsPressed[1] = buttonsPressed[1];
}

void play_tone(int duration_ms) {
	unsigned int i;
	unsigned int cycles = 2 * (duration_ms * 1000) / period;
	for (i = 0; i < cycles; i++) {
		gpio_toggle(P_SPEAKER);
		if (i % 2 == 0){
		delay_us(period / 1);
		}
		else{
			delay_us(period / 3);
		}
	}
}

int main(void) {
	switches_init();
	gpio_set_mode(P_SPEAKER, Output);
	
	while (1) {
		// Play if the centre button is pressed.
		if (switch_get(P_SW_CR)) {
			// Play for ~50 ms.
			play_tone(duration_ms);
		}
		update_buttons();
	}
}

// *******************************ARM University Program Copyright © ARM Ltd 2021*************************************   
