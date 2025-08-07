#include "platform.h"
#include "gpio.h"
#include "stdlib.h"
#include "leds.h"
#include "delay.h"

static int done;

void button_press_isr(int sources) {
	done = 1;
}

int main(void) {
	volatile uint64_t count;
	volatile uint64_t sumcount;
	volatile uint64_t totaltrials;
	volatile uint64_t avg;
	volatile uint64_t trialb;
	volatile uint64_t trialg;
	volatile uint64_t trialr;
	volatile uint64_t col;
	volatile double sumcountb;
	volatile double sumcountg;
	volatile double sumcountr;
	
	// Initialise LEDs.
	leds_init();
	leds_set(0, 0, 0);
		
	// Set up on-board switch.
	//gpio_set_mode(P_SW, PullUp);
	gpio_set_trigger(P_SW, Rising, PullUp);
	gpio_set_callback(P_SW, button_press_isr);
	
	__enable_irq();
	sumcountb = 0;
	sumcountg = 0;
	sumcountr = 0;
	sumcount = 0;
	
	totaltrials = 0;
	while (totaltrials < 10) {
		
		done = 0;
		col = rand() % 2;
		if(col == 0){
			leds_set(0,0,1);}
		else{
			leds_set(0,0,0);}
		
		// Wait from 2 to 7 seconds. You can reduce this after your first testing of the code
		delay_ms((rand() % 2001) + 5000);
		

			
		// reset count so you can see result briefly before next round
		count = 0;
		if (done) {
			
			//trial--;
			// User clicked before the LED turned on!
			// Flash red LED to indicate.
			int j;
			for (j = 0; j < 3; j++) {
				leds_set(1, 0, 0);
				delay_ms(100);
				leds_set(0, 0, 0);
				delay_ms(100);
			}
		} else {
				if (col == 0) {
			leds_set(0, 0, 0);
			trialr++;
			while(!done)				{
				//count++;
				sumcountr++;
				//totaltrials++;
				delay_ms(1);
			}
		}
				if (col == 1) {
			leds_set(0, 0, 1);
			trialg++;
			while(!done)				{
				//count++;
				sumcountg++;
				delay_ms(1);
			}
		}
//				if (col == 2) {
//			leds_set(0, 0, 1);
//		  trialb++;
//			while(!done)				{
//				//count++;
//				sumcountb++;
				
		//	delay_ms(1);
		//	}
		}
			
			totaltrials++;
			//leds_set(0, 0, 0);
		
			__NOP(); // Breakpoint here.
		}
		//sumcount=sumcount+count;
		//avg = sumcount/totaltrials;
		
	//}
		if(trialr>0){
		sumcountr = sumcountr/trialr;}
		if(trialg>0){
		sumcountg = sumcountg/trialg;}
		//if(trialb>0){
		//sumcountb = sumcountb/trialb;}
}
//For part 1, we got an average of 516 in 10 trials
//For part 2, we got averages for Red, Blue, and Green.
// Blue average: 184.333
// Green average: 216.5
// Red average: 322.333
//For part 3, we got an average reaction time of 521.8 while the light was on waiting to turn off.
// Also, we got an average waiting for the light to turn on of 513.8.
// *******************************ARM University Program Copyright © ARM Ltd 2021*************************************   
