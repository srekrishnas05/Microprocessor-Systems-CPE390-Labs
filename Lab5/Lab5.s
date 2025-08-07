.global _start
_start:
	
	    .syntax unified
    .cpu cortex-m33
    .thumb

    .global my_capitalize
    .type my_capitalize, %function

my_capitalize:
    push {r4, lr}          // Preserve caller-saved registers

cap_loop:
    ldrb  r1, [r0]         // Load byte from string
    cmp   r1, #'a'-1       // Compare to one before 'a'
    bls   cap_skip         // If <=, skip

    cmp   r1, #'z'         // Compare to 'z'
    bhi   cap_skip         // If > 'z', skip

    subs  r1, #32          // Convert to uppercase
    strb  r1, [r0]         // Store back

cap_skip:
    adds  r0, r0, #1       // Move to next char
    cmp   r1, #0           // Null terminator?
    bne   cap_loop

    pop {r4, pc}           // Restore and return
