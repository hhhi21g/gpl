	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var x

	# var y

	# var z

	# x = 7
	LOD R5,7
   STO (R2+8),R5

	# var t0

	# y = 14
	LOD R6,14
   STO (R2+12),R6

	# var t1

	# ifz 0 goto L1
	LOD R7,0
	TST R7
	JEZ L1

	# z = 1
	LOD R8,1
   STO (R2+16),R8

	# goto L2
	JMP L2

	# label L1
L1:

	# var t2

	# t2 = y - 14
	LOD R5,(R2+12)
    LOD R6,14
    SUB R5,R6

	# z = t2
    STO (R2+28),R5
   STO (R2+16),R5

	# label L2
L2:

	# z = z
	LOD R5,(R2+16)
   STO (R2+16),R5

	# output z
    LOD R15,(R2+16)
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
