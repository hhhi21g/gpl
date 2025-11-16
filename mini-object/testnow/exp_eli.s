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
    STO (R2+28),R5
   STO (R2+16),R5

	# var t1

	# d = t0
   STO (R2+20),R7

	# var t2

	# t2 = c * d
    MUL R5,R7

	# e = t2
    STO (R2+36),R5
   STO (R2+24),R5

	# c = c
	LOD R8,(R2+16)
   STO (R2+16),R8

	# d = e
   STO (R2+20),R5

	# var t3

	# t3 = (a > 0)
	LOD R7,(R2+8)
	LOD R9,0
	SUB R7,R9
	TST R7
	LOD R3,R1+40
	JGZ R3
	LOD R7,0
	LOD R3,R1+24
	JMP R3
	LOD R7,1

	# ifz t3 goto L1
    STO (R2+40),R7
	TST R7
	JEZ L1

	# var t4

	# t4 = a + b
	LOD R10,(R2+8)
    ADD R10,R6

	# c = t4
    STO (R2+44),R10
   STO (R2+16),R10

	# var t5

	# t5 = c + d
    ADD R10,R5

	# e = t5
    STO (R2+48),R10
   STO (R2+24),R10

	# goto L2
	JMP L2

	# label L1
L1:

	# var t6

	# t6 = a + b
	LOD R5,(R2+8)
	LOD R6,(R2+12)
    ADD R5,R6

	# d = t6
    STO (R2+52),R5
   STO (R2+20),R5

	# var t7

	# t7 = d + 1
    LOD R6,1
    ADD R5,R6

	# e = t7
    STO (R2+56),R5
   STO (R2+24),R5

	# label L2
L2:

	# output c
	LOD R5,(R2+16)
    LOD R15,(R2+16)
	OTI

	# output d
	LOD R6,(R2+20)
    LOD R15,(R2+20)
	OTI

	# output e
	LOD R7,(R2+24)
    LOD R15,(R2+24)
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
