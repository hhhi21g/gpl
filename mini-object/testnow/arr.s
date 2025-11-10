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

	# vararray arr2[2D]
	# declare array arr2 [10][20] elem=int(4B) size=800 bytes

	# vararray arr3[3D]
	# declare array arr3 [10][20][30] elem=int(4B) size=24000 bytes

	# input i
	LOD R5,(R2+8)
	ITI
	LOD R5,R15

	# arr1[24] = i
	STO (R2+8),R5
    LOD R6,R2+40
    STO (R6),R5

	# var t0

	# t0 = arr1[24]
	LOD R6,(R2+24856)
    LOD R7,R2+40
    LOD R6,(R7)

	# var t1

	# t1 = t0 + 6
	STO (R2+24856),R6
	LOD R7,6
	ADD R6,R7

	# arr2[504] = t1
	STO (R2+24860),R6
    LOD R8,R2+560
    STO (R8),R6

	# var t2

	# t2 = arr2[504]
	LOD R8,(R2+24864)
    LOD R9,R2+560
    LOD R8,(R9)

	# var t3

	# t3 = t2 + 6
	STO (R2+24864),R8
	ADD R8,R7

	# arr3[15144] = t3
	STO (R2+24868),R8
    LOD R9,R2+16000
    STO (R9),R8

	# goto L2
	JMP L2

	# output L1
	LOD R9,L1
	LOD R15,R9
	OTS

	# label L2
L2:

	# var t4

	# t4 = arr3[15144]
	LOD R5,(R2+24872)
    LOD R6,R2+16000
    LOD R5,(R6)

	# j = t4
	STO (R2+24872),R5

	# output j
	STO (R2+12),R5
	LOD R15,(R2+12)
	OTI

	# output L1
	LOD R6,L1
	LOD R15,R6
	OTS

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L1:
	DBS 10,0
STATIC:
	DBN 0,0
STACK:
