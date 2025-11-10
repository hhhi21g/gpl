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

	# vararray arr1[1D]
	# declare array arr1 [10] elem=int(4B) size=40 bytes

	# input i
	LOD R5,(R2+8)
	ITI
	LOD R5,R15

	# label L1
	STO (R2+8),R5
L1:

	# var t0

	# var t8

	# var t1

	# arr1[0] = i
	LOD R6,0
	LOD R7,(R2+8)
	LOD R5,R2+16	ADD R5,R6
	STO (R5),R7

	# var t2

	# t2 = i + 1
	LOD R5,1
	ADD R7,R5

	# i = t2
	STO (R2+68),R7

	# var t3

	# label L2
	STO (R2+8),R7
L2:

	# goto L1
	JMP L1

	# label L3
L3:

	# goto L5
	JMP L5

	# output L4
	LOD R5,L4
	LOD R15,R5
	OTS

	# label L5
L5:

	# label L6
L6:

	# var t4

	# var t9

	# var t5

	# var t6

	# var t7

	# t7 = arr1[0]
	LOD R6,0
	LOD R7,(R2+92)
	LOD R5,R2+16	ADD R5,R6
	LOD R7,(R5)

	# i = t7
	STO (R2+92),R7

	# output i
	STO (R2+8),R7
	LOD R15,(R2+8)
	OTI

	# label L7
L7:

	# goto L6
	JMP L6

	# label L8
L8:

	# output L4
	LOD R5,L4
	LOD R15,R5
	OTS

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L4:
	DBS 10,0
STATIC:
	DBN 0,0
STACK:
