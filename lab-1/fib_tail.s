	.syntax unified
	.arch armv7-a
	.text
	.align 2
	.thumb
	.thumb_func

	.global fibonacci
	.type fibonacci, function

fibonacci:
	@ ADD/MODIFY CODE BELOW
	@ PROLOG
	push {r5, r6, lr} // remove r3 because it is used for holding argument values to the subroutine
	mov r6, r0
        cmp r6, #0
	it le
	ble .L3

	cmp r6 ,#1
	it eq
	beq .L4

	mov r5, r2
	add r2, r1, r2
	mov r1, r5
	sub r0, r6, #1
	bl fibonacci
	pop {r5, r6, pc}		@EPILOG

	@ END CODE MODIFICATION
.L3:
	mov r0, r1			
	pop {r5, r6, pc}		@ EPILOG

.L4:
	mov r0, r2			
	pop {r5, r6, pc}		@ EPILOG

	.size fibonacci, .-fibonacci
	.end
