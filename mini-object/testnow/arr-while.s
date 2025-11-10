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

	# j = 0
	LOD R6,0

	# label L1
	STO (R2+8),R5
	STO (R2+12),R6
L1:

	# var t0

	# t0 = (j < 10)
	LOD R5,(R2+12)
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
	STO (R2+56),R5
	TST R5
	JEZ L3

	# var t1

	# t1 = j * 4
	LOD R7,(R2+12)
	LOD R8,4
	MUL R7,R8

	# arr1[t1] = i
	STO (R2+60),R7
	LOD R10,(R2+8)
	LOD R9,R2+16	ADD R9,R7
	STO (R9),R10

	# var t2

	# t2 = i + 1
	LOD R9,1
	ADD R10,R9

	# i = t2
	STO (R2+64),R10

	# var t3

	# t3 = j + 1
	LOD R11,(R2+12)
	ADD R11,R9

	# j = t3
	STO (R2+68),R11

	# label L2
	STO (R2+8),R10
	STO (R2+12),R11
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

	# t4 = (j > 0)
	LOD R5,(R2+12)
	LOD R6,0
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JGZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t4 goto L8
	STO (R2+72),R5
	TST R5
	JEZ L8

	# var t5

	# t5 = j - 1
	LOD R7,(R2+12)
	LOD R8,1
	SUB R7,R8

	# j = t5
	STO (R2+76),R7

	# var t6

	# t6 = j * 4
	STO (R2+12),R7
	LOD R9,4
	MUL R7,R9

	# var t7

	# t7 = arr1[t6]
	STO (R2+80),R7
	LOD R11,(R2+84)
	LOD R10,R2+16	ADD R10,R7
	LOD R11,(R10)

	# i = t7
	STO (R2+84),R11

	# output i
	STO (R2+8),R11
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
