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

	# input i
	LOD R5,(R2+8)
	ITI
	LOD R5,R15

	# input j
	LOD R6,(R2+12)
	ITI
	LOD R6,R15

	# var t0

	# t0 = (i == j)

	# output L1
	LOD R7,L1
    LOD R15,R7
    OTS

	# goto L4
    STO (R2+8),R5
    STO (R2+12),R6
	JMP L4

	# label L3
L3:

	# output L2
	LOD R5,L2
    LOD R15,R5
    OTS

	# label L4
L4:

	# var t1

	# t1 = i + j
	LOD R5,(R2+8)
	LOD R6,(R2+12)
    ADD R5,R6

	# k = t1
	STO (R2+16),R5

	# output k
    STO (R2+16),R5
    LOD R15,R5
    OTI

	# output L5
	LOD R7,L5
    LOD R15,R7
    OTS

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L5:
	DBS 10,0
L2:
	DBS 110,111,116,32,101,113,117,97,108,10,0
L1:
	DBS 101,113,117,97,108,10,0
STATIC:
	DBN 0,0
STACK:
