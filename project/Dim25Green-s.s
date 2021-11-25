	.text
JT:	.word Default
	.word case1
	.word case2
	.word case3
	.word case4

	.arch msp430g2553
	.p2align 1,0
	
	.extern greenDim
	.extern Green_On_Off_Flag
	.global Dim25Green
Dim25Green:
	mov &greenDim, R12

	cmp #5, R12
	jhs Default		;check if greenDim > 4
	

	add R12, R12
	mov JT(R12), R0

case1:
	mov #1, &Green_On_Off_Flag
	add #1, &greenDim
	jmp Exit

case2:
	mov #0, &Green_On_Off_Flag
	add #1, &greenDim
	jmp Exit

case3:
	mov #0, &Green_On_Off_Flag
	add #1, &greenDim
	jmp Exit

case4:
	mov #0, &Green_On_Off_Flag
	mov #1, &greenDim
	jmp Exit

Default: jmp Exit
	

Exit:	pop r0
