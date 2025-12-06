	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4
	LOD R4,STATIC

	# label main
main:

	# begin

	# var i

	# var j

	# var k

	# k = 0
	LOD R5,0
	STO (R2+16),R5

	# label L1
    STO (R2+16),R5
L1:

	# var t0

	# t0 = (k < 10)
	LOD R5,(R2+16)
    LOD R6,R5
	LOD R3,10
    SUB R6,R3
    TST R6
    JEZ L3
    JGZ L3

	# i = 0
	LOD R6,0
	STO (R2+8),R6

	# label L4
    STO (R2+8),R6
L4:

	# var t1

	# t1 = (i < 10)
	LOD R5,(R2+8)
    LOD R7,R5
	LOD R3,10
    SUB R7,R3
    TST R7
    JEZ L6
    JGZ L6

	# var t2

	# t2 = 2 * i
	LOD R6,2
    MUL R6,R5

	# var t3

	# t3 = t2 + 9
    STO (R2+28),R6
	LOD R7,9
    ADD R6,R7

	# j = t3
	STO (R2+12),R6

	# output j
    STO (R2+12),R6
    LOD R15,R6
    OTI

	# output L7
	LOD R8,L7
    LOD R15,R8
    OTS

	# var t4

	# t4 = i + 1
	LOD R9,1
    ADD R5,R9

	# i = t4
	STO (R2+8),R5

	# label L5
    STO (R2+8),R5
L5:

	# goto L4
	JMP L4

	# label L6
L6:

	# var t5

	# t5 = k + 1
	LOD R5,(R2+16)
	LOD R6,1
    ADD R5,R6

	# k = t5
	STO (R2+16),R5

	# label L2
    STO (R2+16),R5
L2:

	# goto L1
	JMP L1

	# label L3
L3:

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L7:
	DBS 10,0
STATIC:
	DBN 0,0
STACK:
