## Lab 10 – Serial Communication Performance Analysis ##

This lab examines the timing characteristics of UART serial communication using an Arduino Uno and Arduino Due as transmitters. We capture and analyze the transmitted signals using an oscilloscope or logic analyzer to measure baud rate accuracy, bit timing, and message transmission duration.

**Objectives**
Measure bit duration for UART transmissions and verify against baud rate.

Analyze how message length affects total transmission time.

Explore baud rate scaling and its effect on communication speed.

Understand ASCII encoding in transmitted signals by matching oscilloscope waveforms to expected bit patterns.

**Hardware:**
Arduino Board
Oscilloscope

```
// Transmit a single character repeatedly
void setup() {
  Serial.begin(57600); // 57,600 baud
}

void loop() {
  Serial.write('9');   // Send character '9'
  delay(1000);         // 1 second between transmissions
}
```

```
// Transmit a string continuously
void setup() {
  Serial.begin(115200); // 115,200 baud for faster tests
}

void loop() {
  Serial.print("12345"); // Send a sequence
  delay(500);            // Repeat every 0.5 seconds
}
```

![IMG_2573](https://github.com/user-attachments/assets/9f135687-1894-47f1-9bdd-ffec239cfa05)
![IMG_1743](https://github.com/user-attachments/assets/1bce3f0d-b7e7-4774-b5b2-2926a9ff2531)
