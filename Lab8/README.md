### Lab 8 – Digital Sound Synthesizer Using GPIO and Speaker ###

This lab demonstrates real-time audio generation using GPIO pins on the STM32L552ZE board. The user can dynamically adjust tone frequency and duration using hardware buttons, and waveforms are visualized using an oscilloscope. It also includes modifications in ARM Assembly.

🎯 Objectives

Generate square and rectangular waveforms using GPIO

Use buttons to interactively change tone frequency and duration

Interface a speaker circuit with capacitor and resistor filtering

Replace waveform logic with optimized ARM Assembly code

Visualize digital waveforms via oscilloscope

---

**Hardware Requirements**

STM32 Nucleo-L552ZE-Q

Speaker: 8Ω or similar, connected via GPIO

Buttons: 3x momentary switches

Resistor: 330Ω (recommended to reduce volume)

Capacitor: 1µF (DC blocking)

Measurement: Oscilloscope or Logic Analyzer

---

**Key Functions:**
```c
void delay_us(unsigned int us);
void play_tone(unsigned int duration_ms);
void update_buttons(void);
void gpio_setup(void);
