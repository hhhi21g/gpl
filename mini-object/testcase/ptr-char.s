	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var a

	# var pa

	# var b

	# var c

	# var d

	# var ptr

	# input d
	LOD R5,(R2+24)
	ITC
	LOD R5,R15

	# c = 'c'
	LOD R6,99

	# b = 'b'
	LOD R7,98

	# input a
	LOD R8,(R2+8)
	ITC
	LOD R8,R15

	# ifz 0 goto L2
	STO (R2+24),R5
	STO (R2+20),R6
	STO (R2+16),R7
	STO (R2+8),R8
	LOD R9,0
	TST R9
	JEZ L2

	# output L1
	LOD R10,L1
	LOD R15,R10
	OTS

	# label L2
L2:

	# output a
	LOD R5,(R2+8)
	LOD R15,(R2+8)
	OTC

	# output b
	LOD R6,(R2+16)
	LOD R15,(R2+16)
	OTC

	# output c
	LOD R7,(R2+20)
	LOD R15,(R2+20)
	OTC

	# output d
	LOD R8,(R2+24)
	LOD R15,(R2+24)
	OTC

	# output L1
	LOD R9,L1
	LOD R15,R9
	OTS

	# pa = &a
	LOD R10,(R2+12)
    LOD R10,R2+8

	# *pa = 'A'
	STO (R2+12),R10
	LOD R11,65
    LOD R10,(R2+12)
    STO (R10),R11

	# output a
	LOD R15,(R2+8)
	OTC

	# ptr = pa

	# *ptr = 'B'
	STO (R2+28),R10
	LOD R12,66
    LOD R10,(R2+28)
    STO (R10),R12

	# output a
	LOD R15,(R2+8)
	OTC

	# output L1
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
