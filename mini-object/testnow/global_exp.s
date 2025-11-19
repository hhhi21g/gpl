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

	# var x

	# var y

	# input a
	LOD R5,(R2+8)
	ITI
	LOD R5,R15

	# input b
	LOD R6,(R2+12)
	ITI
	LOD R6,R15

	# var t0

	# t0 = a + b
    STO (R2+8),R5
    STO (R2+12),R6
    ADD R5,R6

	# c = t0
	STO (R2+16),R5

	# var t1

	# t1 = (a > 0)
	LOD R7,(R2+8)
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
    STO (R2+28),R5
    STO (R2+32),R7
	TST R7
	JEZ L1

	# var t2

	# t2 = t0
	LOD R9,R5

	# x = t2
	STO (R2+20),R9

	# goto L2
	JMP L2

	# label L1
L1:

	# var t3

	# t3 = t0
	LOD R6,R5

	# y = t3
	STO (R2+24),R6

	# label L2
L2:

	# output c
	LOD R5,(R2+16)
    LOD R15,R5
    OTI

	# output x
	LOD R6,(R2+20)
    LOD R15,R6
    OTI

	# output y
	LOD R7,(R2+24)
    LOD R15,R7
    OTI

	# return 0
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
