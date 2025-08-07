## Lab 10 – Signal Generator with Timing and Buffering ##

This lab implements a software-based waveform generator using GPIO toggling with precise timer control, designed to run on the STM32 Nucleo-L552ZE-Q. The system outputs a 25Hz square wave and demonstrates two different playback strategies: busy-waiting and interrupt-driven playback, using a circular queue to handle buffering. The output signals are analyzed using a logic analyzer or oscilloscope, and an RGB LED indicates the state of the buffer in real-time.

**Objectives**

Use timers and interrupts to generate a 25Hz square wave with high precision

Compare busy-wait playback vs interrupt-driven playback

Implement a queue-based buffering system to decouple main code from ISR

Add real-time LED visual feedback based on buffer status

Evaluate underflow and overflow scenarios in embedded buffering

--- 

**Playback Modes:**

**Busy-wait Mode:**
The CPU waits between toggles with delay loops.
Precise, but inefficient — CPU is fully blocked.
```
tone_play_with_busy_waiting(40000, 1000); // period, cycles
```

**Interrupt-driven Mode:**
Timer ISR dequeues one sample at a time.
Main thread can enqueue data in advance.
Allows multitasking and reduces timing jitter.
```
tone_play_with_interrupt(40000, 1000); // period, cycles
```


**Buffer Monitoring Logic:**
A circular buffer (size 64–1000 samples) is used to decouple ISR and main loop.

Buffer state is visualized with LEDs:
Red: Empty (underflow)
Blue: Filling (between empty and full)
Green: Full
```
if (queue_full(&play_queue))    leds_set(GREEN);
else if (queue_empty(&play_queue)) leds_set(RED);
else                             leds_set(BLUE);
```
