	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# var i

	# label main
main:

	# begin

	# var a

	# var b

	# var c

	# input a
	LOD R5,(R2+8)
	ITI
	LOD R5,R15

	# input b
	LOD R6,(R2+12)
	ITI
	LOD R6,R15

	# var t0

	# actual a
	STO (R2+8),R5
	STO (R2+24),R5

	# actual b
	STO (R2+12),R6
	STO (R2+28),R6

	# t0 = call max
	STO (R2+32),R2
	LOD R4,R1+32
	STO (R2+36),R4
	LOD R2,R2+32
	JMP max
	LOD R5,(R2+20)
	LOD R5,R4

	# c = t0
	STO (R2+20),R5

	# output c
	STO (R2+16),R5
	LOD R15,(R2+16)
	OTI

	# output L1
	LOD R6,L1
	LOD R15,R6
	OTS

	# var t1

	# t1 = i + 1
	LOD R4,STATIC
	LOD R7,(R4+0)
	LOD R8,1
	ADD R7,R8

	# i = t1
	STO (R2+24),R7

	# output i
	LOD R4,STATIC
	STO (R4+0),R7
	LOD R15,(R2+0)
	OTI

	# output L2
	LOD R9,L2
	LOD R15,R9
	OTS

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L2:
	DBS 10,0
L1:
	DBS 32,0
STATIC:
	DBN 0,4
STACK:
