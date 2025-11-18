	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

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
	LOD R6,10
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JLZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t0 goto L3
    STO (R2+20),R5
	TST R5
	JEZ L3

	# i = 0
	LOD R7,0
	STO (R2+8),R7

	# label L4
    STO (R2+8),R7
L4:

	# var t1

	# t1 = (i < 10)
	LOD R5,(R2+8)
	LOD R6,10
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JLZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t1 goto L6
    STO (R2+24),R5
	TST R5
	JEZ L6

	# var t2

	# t2 = 2 * i
    LOD R5,2
	LOD R7,(R2+8)
    MUL R5,R7

	# var t3

	# t3 = t2 + 9
    STO (R2+28),R5
    LOD R6,9
    ADD R5,R6

	# j = t3
	STO (R2+12),R5

	# output j
	LOD R8,(R2+12)
    LOD R15,R8
    OTI

	# output L7
	LOD R9,L7
    LOD R15,R9
    OTS

	# var t4

	# t4 = i + 1
    LOD R5,1
    ADD R7,R5

	# i = t4
	STO (R2+8),R7

	# label L5
    STO (R2+32),R5
    STO (R2+36),R7
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
    STO (R2+40),R5
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
