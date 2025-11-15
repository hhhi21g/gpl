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

	# var t0

	# t0 = 3 + 4
    LOD R5,3
    LOD R5,4
    LOD R5,4
    ADD R5,R5

	# x = t0
    STO (R2+20),R5
   STO (R2+8),R5

	# var t1

	# t1 = x * 2
    LOD R6,2
    MUL R5,R6

	# y = t1
    STO (R2+24),R5
   STO (R2+12),R5

	# var t2

	# t2 = (y > 20)
	LOD R6,20
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JGZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t2 goto L1
    STO (R2+28),R5
	TST R5
	JEZ L1

	# var t3

	# t3 = y - 14
	LOD R7,(R2+12)
    LOD R8,14
    SUB R7,R8

	# z = t3
    STO (R2+32),R7
   STO (R2+16),R7

	# goto L2
	JMP L2

	# label L1
L1:

	# z = 0
	LOD R5,0
   STO (R2+16),R5

	# label L2
L2:

	# var t4

	# t4 = z + 0
	LOD R5,(R2+16)
    LOD R6,0
    ADD R5,R6

	# z = t4
    STO (R2+36),R5
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
