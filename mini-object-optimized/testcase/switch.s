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

	# input i
	LOD R5,(R2+8)
	ITI
	LOD R5,R15

	# var t5

	# t5 = (i != 1)
    STO (R2+8),R5
	LOD R6,1
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JEZ R3
	LOD R5,1
	LOD R3,R1+24
	JMP R3
	LOD R5,0

	# ifz t5 goto L2
    STO (R2+16),R5
	TST R5
	JEZ L2

	# var t4

	# t4 = (i != 2)
	LOD R7,(R2+8)
	LOD R8,2
	SUB R7,R8
	TST R7
	LOD R3,R1+40
	JEZ R3
	LOD R7,1
	LOD R3,R1+24
	JMP R3
	LOD R7,0

	# ifz t4 goto L3
    STO (R2+20),R7
	TST R7
	JEZ L3

	# var t3

	# t3 = (i != 3)
	LOD R9,(R2+8)
	LOD R10,3
	SUB R9,R10
	TST R9
	LOD R3,R1+40
	JEZ R3
	LOD R9,1
	LOD R3,R1+24
	JMP R3
	LOD R9,0

	# ifz t3 goto L4
    STO (R2+24),R9
	TST R9
	JEZ L4

	# goto L6
	JMP L6

	# label L4
L4:

	# var t2

	# t2 = i + 3
	LOD R5,(R2+8)
    LOD R6,3
    ADD R5,R6

	# j = t2
    STO (R2+28),R5
   STO (R2+12),R5

	# output j
    LOD R15,(R2+12)
	OTI

	# goto L1
	JMP L1

	# label L3
L3:

	# var t1

	# t1 = i + 2
	LOD R5,(R2+8)
    LOD R6,2
    ADD R5,R6

	# j = t1
    STO (R2+32),R5
   STO (R2+12),R5

	# output j
    LOD R15,(R2+12)
	OTI

	# goto L1
	JMP L1

	# label L2
L2:

	# var t0

	# t0 = i + 1
	LOD R5,(R2+8)
    LOD R6,1
    ADD R5,R6

	# j = t0
    STO (R2+36),R5
   STO (R2+12),R5

	# output j
    LOD R15,(R2+12)
	OTI

	# goto L1
	JMP L1

	# label L6
L6:

	# output L5
	LOD R5,L5
	LOD R15,R5
	OTS

	# goto L1
	JMP L1

	# label L1
L1:

	# output L7
	LOD R5,L7
	LOD R15,R5
	OTS

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L7:
	DBS 10,0
L5:
	DBS 110,111,116,32,49,32,50,32,51,0
STATIC:
	DBN 0,0
STACK:
