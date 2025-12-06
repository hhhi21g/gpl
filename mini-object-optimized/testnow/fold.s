	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4
	LOD R4,STATIC

	# label main
main:

	# begin

	# var x

	# var y

	# var z

	# var t0

	# y = 14
	LOD R5,14
	STO (R2+12),R5

	# var t1

	# ifz 0 goto L1
    STO (R2+12),R5
	LOD R6,0
	TST R6
	JEZ L1

	# z = 1
	LOD R7,1
	STO (R2+16),R7

	# goto L2
    STO (R2+16),R7
	JMP L2

	# label L1
L1:

	# var t2

	# t2 = y - 14
	LOD R5,(R2+12)
    LOD R6,14
    SUB R5,R6

	# z = t2
	STO (R2+16),R5

	# label L2
    STO (R2+16),R5
L2:

	# z = z

	# output z
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
