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

	# a = 5
	LOD R5,5

	# var t0

	# t0 = a * 3
	STO (R2+8),R5
	LOD R6,3
	MUL R5,R6

	# b = t0
	STO (R2+20),R5

	# c = 98
	LOD R7,98

	# a = 0
	LOD R8,0

	# output a
	STO (R2+8),R8
	LOD R15,R8
	OTI

	# output L1
	LOD R9,L1
	LOD R15,R9
	OTS

	# output b
	STO (R2+12),R5
	LOD R15,R5
	OTI

	# output L1
	LOD R15,R9
	OTS

	# output c
	STO (R2+16),R7
	LOD R15,R7
	OTC

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L1:
	DBS 32,0
STATIC:
	DBN 0,0
STACK:
