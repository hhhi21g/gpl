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

	# input a
	LOD R5,(R2+8)
	ITI
	LOD R5,R15

	# var t0

	# t0 = a + 10
	STO (R2+8),R5
	LOD R6,10
	ADD R5,R6

	# b = t0
	STO (R2+32),R5

	# var t1

	# t1 = b - 20
	STO (R2+16),R5
	LOD R7,20
	SUB R5,R7

	# c = t1
	STO (R2+36),R5

	# var t2

	# t2 = c * 30
	STO (R2+20),R5
	LOD R8,30
	MUL R5,R8

	# d = t2
	STO (R2+40),R5

	# output a
	LOD R9,(R2+8)
	LOD R15,(R2+8)
	OTI

	# output b
	LOD R10,(R2+16)
	LOD R15,(R2+16)
	OTI

	# output c
	LOD R11,(R2+20)
	LOD R15,(R2+20)
	OTI

	# output d
	STO (R2+24),R5
	LOD R15,(R2+24)
	OTI

	# output L1
	LOD R12,L1
	LOD R15,R12
	OTS

	# pa = &a
	LOD R13,(R2+12)
    LOD R13,R2+8

	# *pa = 111
	STO (R2+12),R13
	LOD R14,111
    LOD R13,(R2+12)
    STO (R13),R14

	# output a
	LOD R15,(R2+8)
	OTI

	# ptr = pa

	# *ptr = 222
	STO (R2+28),R13
	LOD R15,222
    LOD R13,(R2+28)
    STO (R13),R15

	# output a
	LOD R15,(R2+8)
	OTI

	# output L1
	LOD R15,R12
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
