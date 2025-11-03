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
    LOD R5,(R2+32)
    STO (R2+16),R5

	# var t1

	# t1 = b - 20
	LOD R7,(R2+16)
	LOD R8,20
	SUB R7,R8

	# c = t1
    LOD R5,(R2+36)
    STO (R2+20),R5

	# var t2

	# t2 = c * 30
	LOD R9,(R2+20)
	LOD R10,30
	MUL R9,R10

	# d = t2
    LOD R5,(R2+40)
    STO (R2+24),R5

	# output a
	LOD R11,(R2+8)
	LOD R15,R11
	OTI

	# output b
	LOD R12,(R2+16)
	LOD R15,R12
	OTI

	# output c
	LOD R13,(R2+20)
	LOD R15,R13
	OTI

	# output d
	LOD R14,(R2+24)
	LOD R15,R14
	OTI

	# output L1
	LOD R15,L1
	LOD R15,R15
	OTS

	# pa = &a
	LOD R6,(R2+12)
    LOD R6,R2+8

	# *pa = 111
    LOD R5,(R2+12)
	LOD R8,111
    STO (R5),R8

	# output a
	LOD R15,R11
	OTI

	# ptr = pa
    LOD R5,(R2+12)
    STO (R2+28),R5

	# *ptr = 222
    LOD R5,(R2+28)
	LOD R8,222
    STO (R5),R8

	# output a
	LOD R15,R11
	OTI

	# output L1
	LOD R15,R15
	OTS

	# end
	STO (R2+32),R5
	STO (R2+12),R6
	STO (R2+36),R7
	STO (R2+40),R9
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
