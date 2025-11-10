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

	# t0 = 6 * 4
	LOD R6,6
	LOD R7,4
	MUL R6,R7

	# arr1[t0] = i
	STO (R2+24856),R6
	STO (R2+8),R5
	LOD R8,R2+16	ADD R8,R6
	STO (R8),R5

	# var t4

	# t4 = 6 * 20
	LOD R8,6
	LOD R9,20
	MUL R8,R9

	# t4 = t4 + 6
	STO (R2+24860),R8
	LOD R10,6
	ADD R8,R10

	# var t5

	# t5 = t4 * 4
	STO (R2+24860),R8
	MUL R8,R7

	# var t1

	# t1 = 6 * 4
	MUL R10,R7

	# var t2

	# t2 = arr1[t1]
	STO (R2+24868),R10
	LOD R12,(R2+24872)
	LOD R11,R2+16	ADD R11,R10
	LOD R12,(R11)

	# var t3

	# t3 = t2 + 6
	STO (R2+24872),R12
	LOD R11,6
	ADD R12,R11

	# arr2[t5] = t3
	STO (R2+24864),R8
	STO (R2+24876),R12
	LOD R13,R2+56	ADD R13,R8
	STO (R13),R12

	# var t10

	# t10 = 6 * 30
	LOD R13,30
	MUL R11,R13

	# t10 = t10 + 6
	STO (R2+24880),R11
	LOD R14,6
	ADD R11,R14

	# var t11

	# t11 = t10 * 20
	STO (R2+24880),R11
	MUL R11,R9

	# t11 = t11 + 6
	STO (R2+24884),R11
	ADD R11,R14

	# var t12

	# t12 = t11 * 4
	STO (R2+24884),R11
	MUL R11,R7

	# var t6

	# t6 = 6 * 20
	MUL R14,R9

	# t6 = t6 + 6
	STO (R2+24892),R14
	LOD R15,6
	ADD R14,R15

	# var t7

	# t7 = t6 * 4
	STO (R2+24892),R14
	MUL R14,R7

	# var t8

	# t8 = arr2[t7]
	STO (R2+24896),R14
	LOD R5,(R2+24900)
	LOD R5,R2+56	ADD R5,R14
	LOD R5,(R5)

	# var t9

	# t9 = t8 + 6
	LOD R5,(R2+24900)
	ADD R5,R15

	# arr3[t12] = t9
	STO (R2+24888),R11
	STO (R2+24904),R5
	LOD R6,R2+856	ADD R6,R11
	STO (R6),R5

	# goto L2
	JMP L2

	# output L1
	LOD R6,L1
	LOD R15,R6
	OTS

	# label L2
L2:

	# var t13

	# t13 = 6 * 30
	LOD R5,6
	LOD R6,30
	MUL R5,R6

	# t13 = t13 + 6
	STO (R2+24908),R5
	LOD R7,6
	ADD R5,R7

	# var t14

	# t14 = t13 * 20
	STO (R2+24908),R5
	LOD R8,20
	MUL R5,R8

	# t14 = t14 + 6
	STO (R2+24912),R5
	ADD R5,R7

	# var t15

	# t15 = t14 * 4
	STO (R2+24912),R5
	LOD R9,4
	MUL R5,R9

	# var t16

	# t16 = arr3[t15]
	STO (R2+24916),R5
	LOD R11,(R2+24920)
	LOD R10,R2+856	ADD R10,R5
	LOD R11,(R10)

	# j = t16
	STO (R2+24920),R11

	# output j
	STO (R2+12),R11
	LOD R15,(R2+12)
	OTI

	# output L1
	LOD R10,L1
	LOD R15,R10
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
