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

	# a = 1
	LOD R5,1
	STO (R2+8),R5

	# a = 2
	LOD R6,2
	STO (R2+8),R6

	# var t0

	# ifz 1 goto L1
    STO (R2+8),R6
	LOD R5,1
	TST R5
	JEZ L1

	# b = a
	STO (R2+12),R6

	# c = b
	STO (R2+16),R6

	# label L1
    STO (R2+16),R6
L1:

	# output c
	LOD R5,(R2+16)
    LOD R15,R5
    OTI

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
