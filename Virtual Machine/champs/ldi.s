.name "ldi"
.comment "test ldi"

#	fork %:state
	ld %13, r2
	ld 13, r3
	ldi r2, r3, r4
	ldi r2, %14, r5
	ldi %15, r5, r6
	ldi %16, %17, r7
	ldi -10, r7, r8
	ldi -10, %18, r9
	st r1, 200
	st r2, 200
	st r3, 200
	st r4, 200
	st r5, 200
	st r6, 200
	st r7, 200
	st r8, 200
	st r9, 200
	sti r1, r1, r2
	sti r3, %200, r1
	sti r4, -7, r1
	sti r5, r1, %-9999
	sti r6, %-24, %200
	sti r7, -7, %193
