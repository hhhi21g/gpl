	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var a

	# var b

	# var c

	# var t0

	# t0 = b + c
	LOD R5,(R2+12)
	LOD R6,(R2+16)
    ADD R5,R6

	# a = t0
	STO (R2+8),R5

	# var t1

	# t1 = (b > 0)
	LOD R7,(R2+12)
	LOD R8,0
	SUB R7,R8
	TST R7
	LOD R3,R1+40
	JGZ R3
	LOD R7,0
	LOD R3,R1+24
	JMP R3
	LOD R7,1

	# ifz t1 goto L1
    STO (R2+20),R5
    STO (R2+24),R7
	TST R7
	JEZ L1

	# b = 1
	LOD R9,1
	STO (R2+12),R9

	# label L1
    STO (R2+12),R9
L1:

	# var t2

	# t2 = b + c
	LOD R5,(R2+12)
	LOD R6,(R2+16)
    ADD R5,R6

	# a = t2
	STO (R2+8),R5

	# return 0
    STO (R2+28),R5
	LOD R5,0
    LOD R15,R5
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
STATIC:
	DBN 0,0
STACK:
