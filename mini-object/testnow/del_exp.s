	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var a

	# a = 1
	LOD R5,1
	STO (R2+8),R5

	# ifz 0 goto L1
    STO (R2+8),R5
	LOD R6,0
	TST R6
	JEZ L1

	# a = 2
	LOD R7,2
	STO (R2+8),R7

	# label L1
    STO (R2+8),R7
L1:

	# a = 3
	LOD R5,3
	STO (R2+8),R5

	# output a
    STO (R2+8),R5
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
