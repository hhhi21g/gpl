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
	LOD R6,24
    STO (R2+8),R5
    LOD R10,R2+16
	ADD R10,R6
	STO (R10),R5

	# var t0

	# t0 = arr1[24]
	LOD R7,(R2+24856)
    LOD R11,R2+16
	ADD R11,R6
	LOD R7,(R11)

	# var t1

	# t1 = t0 + 6
    STO (R2+24856),R7
    LOD R12,6
    ADD R7,R12

	# arr2[504] = t1
	LOD R8,504
    STO (R2+24860),R7
    LOD R13,R2+56
	ADD R13,R8
	STO (R13),R7

	# var t2

	# t2 = arr2[504]
	LOD R9,(R2+24864)
    LOD R14,R2+56
	ADD R14,R8
	LOD R9,(R14)

	# var t3

	# t3 = t2 + 6
    STO (R2+24864),R9
    LOD R10,6
    ADD R9,R10

	# arr3[15144] = t3
	LOD R10,15144
    STO (R2+24868),R9
    LOD R11,R2+856
	ADD R11,R10
	STO (R11),R9

	# ifz 0 goto L2
	LOD R11,0
	TST R11
	JEZ L2

	# output L1
	LOD R12,L1
	LOD R15,R12
	OTS

	# label L2
L2:

	# var t4

	# t4 = arr3[15144]
	LOD R5,15144
	LOD R6,(R2+24872)
    LOD R12,R2+856
	ADD R12,R5
	LOD R6,(R12)

	# j = t4
    STO (R2+24872),R6
   STO (R2+12),R6

	# output j
    LOD R15,(R2+12)
	OTI

	# output L1
	LOD R7,L1
	LOD R15,R7
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
