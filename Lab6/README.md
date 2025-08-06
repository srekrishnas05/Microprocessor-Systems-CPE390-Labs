### Lab 6: Interrupts, Timing Behavior, & Stack Use ###

This lab introduces external interrupts and how they affect the CPU state, stack, and program timing on the STM32L552ZE microcontroller. It demonstrates how an interrupt service routine (ISR) can react to a hardware button press, update state, and toggle an RGB LED pattern. 
I also used oscilloscopes and debug tools to analyze CPU behavior during ISR execution.

**Learning Objectives**
Write an interrupt-driven program using an ISR and GPIO.

Understand interrupt triggering, NVIC configuration, and ISR execution.

Analyze the stack and register values when an interrupt occurs.

Use a logic analyzer/oscilloscope to examine ISR timing and latency.

Light an RGB LED based on a counter that changes each time a switch is pressed.

Using an oscilloscope or logic analyzer:

ISR latency is measured from switch press to ISR debug line activation.

Observed latency: ~24.8µs

The main program debug line (DBG_Main) drops during ISR execution, confirming CPU handover.

CPU and Stack Analysis
Registers like R0, R14 (LR), and R15 (PC) are inspected during ISR entry.

The Main Stack Pointer (MSP) stores context automatically during ISR entry.

Students analyze memory windows to track how register values are pushed/popped during context switch.

Core Functions Used

```c
void gpio_set(PIN pin, int value);
void leds_init(void);
void leds_set(int red_on, int green_on, int blue_on);
void gpio_set_mode(PIN pin, PinMode mode);
void gpio_set_trigger(PIN pin, TriggerMode trig, PinMode mode);
void gpio_set_callback(PIN pin, void (*callback)(int status));
void gpio_toggle(PIN pin);
