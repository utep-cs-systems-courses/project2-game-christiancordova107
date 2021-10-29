	.arch msp430g2553
	.p2align 1,0
	.text
	
	.extern greenDim
	.extern Green_On_Off_Flag
	.global Dim25Green
Dim25Green:
	cmp #1, &greenDim
	jz case1

	cmp #2, &greenDim
	jz case2

	cmp #3, &greenDim
	jz case3

	cmp #4, &greenDim
	jz case4

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

Exit:	pop r0
