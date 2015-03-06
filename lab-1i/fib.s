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
	push {r4, r5,lr}
	@ index
	mov r2,#0 
	
	mov r3,#-1
	mov r4,#0
	mov r5,#1

.loop:
	
	cmp r2,r0
	itt gt
	movgt r0,r4
	popgt {r4,r5,pc}
	add r4,r3,r5
	mov r3,r5
	mov r5,r4
	add r2,r2,#1
	b .loop

	.size fibonacci, .-fibonacci
	.end
