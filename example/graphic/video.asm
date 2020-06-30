; video routines for DOS
; interface with turbo C for large memory model

	bits 16

	global _add
	global _change_video_mode

segment VIDEO

	; int far add(int a, int b);
	_add:
			push bp
			mov bp, sp
			mov ax, [bp + 6]
			add ax, [bp + 8]
			pop bp
			retf

	; void far change_video_mode(unsigned char mode);
	_change_video_mode:
			push bp
			mov bp, sp
			mov ax, [bp + 6]
			int 10h
			pop bp
			retf
