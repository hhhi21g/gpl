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

	# t0 = a + 10
    STO (R2+8),R5
    LOD R6,10
    ADD R5,R6

	# b = t0
	STO (R2+12),R5

	# var t1

	# t1 = b - 20
	LOD R6,(R2+12)
    LOD R5,20
    SUB R6,R5

	# c = t1
	STO (R2+16),R6

	# var t2

	# t2 = c * 30
	LOD R7,(R2+16)
    LOD R5,30
    MUL R7,R5

	# d = t2
	STO (R2+20),R7

	# output a
	LOD R8,(R2+8)
    LOD R15,R8
    OTI

	# output b
	LOD R9,(R2+12)
    LOD R15,R9
    OTI

	# output c
	LOD R10,(R2+16)
    LOD R15,R10
    OTI

	# output d
	LOD R11,(R2+20)
    LOD R15,R11
    OTI

	# output L1
	LOD R12,L1
    LOD R15,R12
    OTS

	# end
    STO (R2+24),R5
    STO (R2+28),R6
    STO (R2+32),R7
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
