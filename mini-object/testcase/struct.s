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

	# var zs

	# input i
	LOD R5,(R2+8)
	ITI
	LOD R5,R15

	# input j
	LOD R6,(R2+12)
	ITI
	LOD R6,R15

	# input k
	LOD R7,(R2+16)
	ITI
	LOD R7,R15

	# var t0

	# t0 = &zs
	LOD R8,(R2+24)
    LOD R8,R2+20

	# var t1

	# t1 = t0 + 0
	STO (R2+24),R8
	LOD R9,0
	ADD R8,R9

	# *t1 = i
	STO (R2+28),R8
	STO (R2+8),R5
    LOD R8,(R2+28)
    STO (R8),R5

	# var t2

	# t2 = &zs
	LOD R10,(R2+32)
    LOD R10,R2+20

	# var t3

	# t3 = t2 + 4
	STO (R2+32),R10
	LOD R11,4
	ADD R10,R11

	# *t3 = j
	STO (R2+36),R10
	STO (R2+12),R6
    LOD R10,(R2+36)
    STO (R10),R6

	# var t4

	# t4 = &zs
	LOD R12,(R2+40)
    LOD R12,R2+20

	# var t5

	# t5 = t4 + 8
	STO (R2+40),R12
	LOD R13,8
	ADD R12,R13

	# *t5 = k
	STO (R2+44),R12
	STO (R2+16),R7
    LOD R12,(R2+44)
    STO (R12),R7

	# ifz 0 goto L2
	TST R9
	JEZ L2

	# output L1
	LOD R14,L1
	LOD R15,R14
	OTS

	# label L2
L2:

	# var t6

	# t6 = &zs
	LOD R5,(R2+48)
    LOD R5,R2+20

	# var t7

	# t7 = 8 + t6
	LOD R6,8
	STO (R2+48),R5
	ADD R6,R5

	# var t8

	# t8 = *t7
	STO (R2+52),R6
	LOD R7,(R2+56)
    LOD R7,(R6)

	# var t9

	# t9 = t8 + 100
	STO (R2+56),R7
	LOD R8,100
	ADD R7,R8

	# i = t9
	STO (R2+60),R7
	STO (R2+8),R7

	# var t10

	# t10 = &zs
	LOD R9,(R2+64)
    LOD R9,R2+20

	# var t11

	# t11 = 4 + t10
	LOD R10,4
	STO (R2+64),R9
	ADD R10,R9

	# var t12

	# t12 = *t11
	STO (R2+68),R10
	LOD R11,(R2+72)
    LOD R11,(R10)

	# var t13

	# t13 = t12 + 200
	STO (R2+72),R11
	LOD R12,200
	ADD R11,R12

	# j = t13
	STO (R2+76),R11
	STO (R2+12),R11

	# var t14

	# t14 = &zs
	LOD R13,(R2+80)
    LOD R13,R2+20

	# var t15

	# t15 = 0 + t14
	LOD R14,0
	STO (R2+80),R13
	ADD R14,R13

	# var t16

	# t16 = *t15
	STO (R2+84),R14
	LOD R15,(R2+88)
    LOD R15,(R14)

	# var t17

	# t17 = t16 + 300
	STO (R2+88),R15
	LOD R5,300
	ADD R15,R5

	# k = t17
	STO (R2+92),R15
	STO (R2+16),R15

	# ifz 0 goto L3
	LOD R5,0
	TST R5
	JEZ L3

	# output L1
	LOD R5,L1
	LOD R15,R5
	OTS

	# label L3
L3:

	# output i
	LOD R5,(R2+8)
	LOD R15,(R2+8)
	OTI

	# output j
	LOD R6,(R2+12)
	LOD R15,(R2+12)
	OTI

	# output k
	LOD R7,(R2+16)
	LOD R15,(R2+16)
	OTI

	# output L1
	LOD R8,L1
	LOD R15,R8
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
