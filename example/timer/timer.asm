;	timer.asm

		bits 16

	global _install_fast_clock

; http://www.intel-assembler.it/portale/5/high-precision-timer-clock/source-code-fast-timer-8259-c-asm.asp
_install_fast_clock:
		cli
		mov al, 36h
		out 43h, al
		mov al, 0h
		out 40h, al
		mov al, 4h
		out 40h, al
		sti
		retf
