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

	# input a
	LOD R5,(R2+8)
	ITI
	LOD R5,R15

	# var t0

	# t0 = a + 110
	STO (R2+8),R5
	LOD R6,110
	ADD R5,R6

	# b = t0
	STO (R2+24),R5

	# var t1

	# t1 = b + 222
	STO (R2+12),R5
	LOD R7,222
	ADD R5,R7

	# c = t1
	STO (R2+28),R5

	# var t2

	# t2 = c * 2
	STO (R2+16),R5
	LOD R8,2
	MUL R5,R8

	# d = t2
	STO (R2+32),R5

	# output b
	LOD R9,(R2+12)
	LOD R15,R9
	OTI

	# output c
	LOD R10,(R2+16)
	LOD R15,R10
	OTI

	# output d
	STO (R2+20),R5
	LOD R15,R5
	OTI

	# output L1
	LOD R11,L1
	LOD R15,R11
	OTS

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L1:
	DBS 10,0
STATIC:
	DBN 0,0
STACK:
