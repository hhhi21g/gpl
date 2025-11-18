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

	# t0 = b + c
	LOD R5,(R2+12)
	LOD R6,(R2+16)
    ADD R5,R6

	# a = t0
	STO (R2+8),R5

	# b = 10
	LOD R7,10
	STO (R2+12),R7

	# var t1

	# t1 = a + b
	LOD R8,(R2+8)
    STO (R2+12),R7
    ADD R8,R7

	# c = t1
	STO (R2+16),R8

	# return 0
    STO (R2+20),R5
    STO (R2+24),R8
	LOD R5,0
    LOD R15,R5
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

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
