### Lab 5: CPU Initiliazation & Assembly-C Integration ###

In this README/folder you will find:
1) The contents and learning material of this lab
2) The question & answer sheet for Lab 5
3) Source files and edited Keil environment files

Lab 5.1 – CPU Initiliazation & Assembly-C Integration
This lab introduces low-level embedded systems programming using ARM Assembly in combination with C on the STM32L552ZE microcontroller. The core objective is to build string-processing functions in Assembly, interface them with C, and debug them at the register level.

Learning Objectives
Write assembly subroutines to perform string operations.

Interface assembly code with a C-based main program using ARM calling conventions.

Understand register usage rules (caller vs callee saved).

Use Keil µVision to view processor state (SP, LR, PC).

Debug and trace instructions in the disassembly and memory windows.


Key Concepts
Register conventions: r0–r3 for arguments, r4–r11 must be preserved.

Using BX lr to return from a function.

Capitalizing a string by subtracting 32 from ASCII values.

String copy via manual byte-wise transfer in Assembly.

Memory-mapped inspection of string data.

