### Lab 7: Interrupt-Based Human Reaction Timer ###

This lab implements a reaction time measurement system using STM32 interrupts. It lights up an LED after a random delay, and waits for the user to press a button. 
The time (measured in loop iterations or delay cycles) between the LED turning on and the user pressing the button is recorded as the reaction time. This demonstrates real-time interrupt handling, timing, and human-in-the-loop systems.

**Learning Objectives**

Develop an embedded system using **external GPIO interrupts**.

Measure **reaction time** by counting delay intervals until an interrupt fires.

Understand how **interrupts interact with main loop execution**.

Collect and average multiple trials, and study how **stimulus changes** affect response.

Analyze how LED color or LED state (on/off) impacts user reaction.

**This Folder Contains**
1) Main.c (Main code file)
2) Instruction PDF
3) ZIP of all files to run code on your own system
