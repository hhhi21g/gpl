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

	# var t0

	# t0 = 6
	LOD R6,6

	# arr1[t0] = i
	STO (R2+24856),R6
	STO (R2+8),R5
	ADD R7,R6
	STO (R7),R5

	# var t4

	# t4 = 120
	LOD R8,120

	# t4 = t4 + 6
	STO (R2+24860),R8
	LOD R9,6
	ADD R8,R9

	# var t5

	# t5 = t4 * 1
	STO (R2+24860),R8
	LOD R10,1
	MUL R8,R10

	# var t1

	# t1 = 6

	# var t2

	# t2 = arr1[t1]
	STO (R2+24868),R9
	LOD R11,(R2+24872)
	ADD R7,R9
	LOD R11,(R7)

	# var t3

	# t3 = t2 + 6
	STO (R2+24872),R11
	LOD R12,6
	ADD R11,R12

	# arr2[t5] = t3
	STO (R2+24864),R8
	STO (R2+24876),R11
	ADD R13,R8
	STO (R13),R11

	# var t10

	# t10 = 180
	LOD R14,180

	# t10 = t10 + 6
	STO (R2+24880),R14
	ADD R14,R12

	# var t11

	# t11 = t10 * 20
	STO (R2+24880),R14
	LOD R15,20
	MUL R14,R15

	# t11 = t11 + 6
	STO (R2+24884),R14
	ADD R14,R12

	# var t12

	# t12 = t11 * 1
	STO (R2+24884),R14
	MUL R14,R10

	# var t6

	# t6 = 120
	LOD R5,120

	# t6 = t6 + 6
	STO (R2+24892),R5
	ADD R5,R12

	# var t7

	# t7 = t6 * 1
	STO (R2+24892),R5
	MUL R5,R10

	# var t8

	# t8 = arr2[t7]
	STO (R2+24896),R5
	LOD R5,(R2+24900)
	ADD R13,R5
	LOD R5,(R13)

	# var t9

	# t9 = t8 + 6
	STO (R2+24900),R5
	ADD R5,R12

	# arr3[t12] = t9
	STO (R2+24888),R14
	STO (R2+24904),R5
	ADD R6,R14
	STO (R6),R5

	# goto L2
	JMP L2

	# output L1
	LOD R5,L1
	LOD R15,R5
	OTS

	# label L2
L2:

	# var t13

	# t13 = 180
	LOD R5,180

	# t13 = t13 + 6
	STO (R2+24908),R5
	LOD R6,6
	ADD R5,R6

	# var t14

	# t14 = t13 * 20
	STO (R2+24908),R5
	LOD R7,20
	MUL R5,R7

	# t14 = t14 + 6
	STO (R2+24912),R5
	ADD R5,R6

	# var t15

	# t15 = t14 * 1
	STO (R2+24912),R5
	LOD R8,1
	MUL R5,R8

	# var t16

	# t16 = arr3[t15]
	STO (R2+24916),R5
	LOD R10,(R2+24920)
	ADD R9,R5
	LOD R10,(R9)

	# j = t16
	STO (R2+24920),R10

	# output j
	STO (R2+12),R10
	LOD R15,(R2+12)
	OTI

	# output L1
	LOD R11,L1
	LOD R15,R11
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
