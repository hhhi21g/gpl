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

	# var d

	# var e

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

	# d = t0
	STO (R2+20),R5

	# var t2

	# t2 = c * d
	LOD R7,(R2+16)
	LOD R8,(R2+20)
    MUL R7,R8

	# e = t2
	STO (R2+24),R7

	# c = c

	# d = e
	LOD R9,(R2+24)
	STO (R2+20),R9

	# var t3

	# t3 = (a > 0)
	LOD R8,(R2+8)
	LOD R10,0
	SUB R8,R10
	TST R8
	LOD R3,R1+40
	JGZ R3
	LOD R8,0
	LOD R3,R1+24
	JMP R3
	LOD R8,1

	# ifz t3 goto L1
    STO (R2+28),R5
    STO (R2+36),R7
    STO (R2+40),R8
    STO (R2+20),R9
	TST R8
	JEZ L1

	# var t4

	# t4 = a + b
	LOD R11,(R2+8)
    ADD R11,R6

	# c = t4
	STO (R2+16),R11

	# var t5

	# t5 = c + d
	LOD R12,(R2+16)
    ADD R12,R9

	# e = t5
	STO (R2+24),R12

	# goto L2
    STO (R2+44),R11
    STO (R2+48),R12
	JMP L2

	# label L1
L1:

	# var t6

	# t6 = a + b
	LOD R5,(R2+8)
	LOD R6,(R2+12)
    ADD R5,R6

	# d = t6
	STO (R2+20),R5

	# var t7

	# t7 = d + 1
	LOD R7,(R2+20)
    LOD R5,1
    ADD R7,R5

	# e = t7
	STO (R2+24),R7

	# label L2
    STO (R2+52),R5
    STO (R2+56),R7
L2:

	# output c
	LOD R5,(R2+16)
    LOD R15,R5
    OTI

	# output d
	LOD R6,(R2+20)
    LOD R15,R6
    OTI

	# output e
	LOD R7,(R2+24)
    LOD R15,R7
    OTI

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
