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

	# t0 = 7
	LOD R5,7

	# a = t0
	STO (R2+20),R5

	# var t1

	# t1 = a * 2
	STO (R2+8),R5
	LOD R6,2
	MUL R5,R6

	# b = t1
	STO (R2+24),R5

	# var t2

	# t2 = b - a
	STO (R2+12),R5
	LOD R7,(R2+8)
	SUB R5,R7

	# c = t2
	STO (R2+28),R5

	# output a
	LOD R15,(R2+8)
	OTI

	# output b
	LOD R8,(R2+12)
	LOD R15,(R2+12)
	OTI

	# output c
	STO (R2+16),R5
	LOD R15,(R2+16)
	OTI

	# output L1
	LOD R9,L1
	LOD R15,R9
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
