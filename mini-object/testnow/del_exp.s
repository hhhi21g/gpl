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

	# b = 1
	LOD R6,1
	STO (R2+12),R6

	# var t0

	# ifz 0 goto L1
    STO (R2+8),R5
    STO (R2+12),R6
	LOD R7,0
	TST R7
	JEZ L1

	# var t1

	# t1 = b + 1
    LOD R5,1
    ADD R6,R5

	# c = t1
	STO (R2+16),R6

	# goto L2
    STO (R2+24),R6
	JMP L2

	# label L1
L1:

	# c = 2
	LOD R5,2
	STO (R2+16),R5

	# label L2
    STO (R2+16),R5
L2:

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
