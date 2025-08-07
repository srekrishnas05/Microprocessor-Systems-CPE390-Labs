## Lab 9 – Infrared Proximity Sensor with RGB LED Feedback ##

This lab implements a contactless object detection system using an IR emitter-detector pair and an ADC input on the STM32L552ZE board. By measuring changes in reflected infrared light, the system estimates how close an object is and dynamically lights an RGB LED to indicate proximity.

The design simulates basic features of automated distance sensors used in robotics and consumer electronics.

---

**Objectives**

Build and calibrate a proximity sensor using IR reflection

Measure light intensity using the STM32 ADC

Visualize object distance with an RGB LED

Minimize noise through differential ADC sampling

Calibrate LED thresholds based on proximity zones


**Hardware Used:**

STM32 Nucleo-L552ZE-Q

IR LED (D1)

IR Phototransistor (Q1)

RGB LED  

Resistors

Breadboard & wires

Oscilloscope

---

The difference between the two readings is used to determine if an object is reflecting IR light into the phototransistor. The RGB LED indicates the result:

| Distance (cm) | LED Color |
|---------------|-----------|
| >20 cm        | Green     |
| 16–20 cm      | Blue      |
| 12–16 cm      | Yellow    |
| 8–12 cm       | Red       |
| 4–8 cm        | Magenta   |
| 0–4 cm        | White     |


**Core Functions**
```c
int measure_ir();             // Takes 20+ samples w/ LED ON and OFF, computes difference
void pick_leds(int delta);    // Maps delta to RGB color output
void gpio_setup();            // Initializes LED + IR pins
void delay(int us);           // Adds delay for phototransistor response
