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

	# var t1

	# var t2

	# b = 15
	LOD R5,15

	# var t3

	# c = 98
	LOD R6,98

	# var t4

	# var t5

	# a = 0
	LOD R7,0

	# output a
	STO (R2+8),R7
	LOD R15,R7
	OTI

	# output L1
	LOD R8,L1
	LOD R15,R8
	OTS

	# output b
	STO (R2+12),R5
	LOD R15,R5
	OTI

	# output L1
	LOD R15,R8
	OTS

	# output c
	STO (R2+16),R6
	LOD R15,R6
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
