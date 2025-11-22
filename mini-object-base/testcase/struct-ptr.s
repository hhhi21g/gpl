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

	# var pi

	# var a

	# var b

	# var pc

	# var c1

	# var t2

	# t2 = &c1
	LOD R5,(R2+36)
    LOD R5,R2+32

	# var t3

	# t3 = t2 + 14
    STO (R2+36),R5
    LOD R6,14
    ADD R5,R6

	# var t4

	# t4 = t3 + 1108
    STO (R2+40),R5
    LOD R6,1108
    ADD R5,R6

	# var t5

	# t5 = t4 + 14
    STO (R2+44),R5
    LOD R6,14
    ADD R5,R6

	# var t6

	# t6 = t5 + 162
    STO (R2+48),R5
    LOD R6,162
    ADD R5,R6

	# var t7

	# t7 = t6 + 0
    STO (R2+52),R5
    LOD R6,0
    ADD R5,R6

	# var t0

	# t0 = &c1
    LOD R6,R2+32

	# var t1

	# t1 = t0 + 0
    STO (R2+60),R6
    LOD R7,0
    ADD R6,R7

	# *t7 = t1
    STO (R2+56),R5
    STO (R2+64),R6
    LOD R5,(R2+56)
    STO (R5),R6

	# var t8

	# t8 = &c1
	LOD R7,(R2+68)
    LOD R7,R2+32

	# var t9

	# t9 = t8 + 14
    STO (R2+68),R7
    LOD R8,14
    ADD R7,R8

	# var t10

	# t10 = t9 + 1108
    STO (R2+72),R7
    LOD R8,1108
    ADD R7,R8

	# var t11

	# t11 = t10 + 14
    STO (R2+76),R7
    LOD R8,14
    ADD R7,R8

	# var t12

	# t12 = t11 + 162
    STO (R2+80),R7
    LOD R8,162
    ADD R7,R8

	# var t13

	# t13 = t12 + 0
    STO (R2+84),R7
    LOD R8,0
    ADD R7,R8

	# var t14

	# t14 = *t13
    STO (R2+88),R7
	LOD R8,(R2+92)
    LOD R8,(R7)

	# pi = t14
    STO (R2+92),R8
   STO (R2+16),R8

	# *pi = 999
	LOD R9,999
    LOD R8,(R2+16)
    STO (R8),R9

	# var t15

	# t15 = &c1
	LOD R10,(R2+96)
    LOD R10,R2+32

	# var t16

	# t16 = t15 + 0
    STO (R2+96),R10
    LOD R11,0
    ADD R10,R11

	# var t17

	# t17 = *t16
    STO (R2+100),R10
	LOD R11,(R2+104)
    LOD R11,(R10)

	# i = t17
    STO (R2+104),R11
   STO (R2+8),R11

	# output i
    LOD R15,(R2+8)
	OTI

	# output L1
	LOD R12,L1
	LOD R15,R12
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
