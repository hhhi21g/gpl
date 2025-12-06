	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4
	LOD R4,STATIC

	# var t4

	# var t3

	# label main
main:

	# begin

	# var a

	# var b

	# var c

	# var d

	# var e

	# var sumd

	# var sume

	# var i

	# var j

	# var k

	# var t5

	# var t6

	# var t7

	# var t10

	# var t11

	# var t12

	# var t13

	# sumd = 0
	LOD R5,0
	STO (R2+28),R5

	# sume = 0
	LOD R6,0
	STO (R2+32),R6

	# k = 12
	LOD R7,12
	STO (R2+44),R7

	# label L1
    STO (R2+28),R5
    STO (R2+32),R6
    STO (R2+44),R7
L1:

	# var t0

	# t0 = (k > 0)
	LOD R5,(R2+44)
    TST R5
    JEZ L3
    JLZ L3

	# j = 15
	LOD R6,15
	STO (R2+40),R6

	# label L4
    STO (R2+40),R6
L4:

	# var t1

	# t1 = (j > 0)
	LOD R5,(R2+40)
    TST R5
    JEZ L6
    JLZ L6

	# i = 18
	LOD R6,18
	STO (R2+36),R6

	# label L7
    STO (R2+36),R6
L7:

	# var t2

	# t2 = (i > 0)
	LOD R5,(R2+36)
    TST R5
    JEZ L9
    JLZ L9

	# var t8

	# var t9

	# var t14

	# var t15

	# t15 = sumd + 14
	LOD R6,(R2+28)
	LOD R7,14
    ADD R6,R7

	# sumd = t15
	STO (R2+28),R6

	# var t16

	# t16 = sume + 19
	LOD R8,(R2+32)
	LOD R9,19
    ADD R8,R9

	# var t17

	# t17 = t16 + 14
    STO (R2+104),R8
    ADD R8,R7

	# sume = t17
	STO (R2+32),R8

	# var t18

	# t18 = i - 1
	LOD R10,1
    SUB R5,R10

	# i = t18
	STO (R2+36),R5

	# label L8
    STO (R2+36),R5
    STO (R2+28),R6
    STO (R2+32),R8
L8:

	# goto L7
	JMP L7

	# label L9
L9:

	# var t19

	# t19 = j - 1
	LOD R5,(R2+40)
	LOD R6,1
    SUB R5,R6

	# j = t19
	STO (R2+40),R5

	# label L5
    STO (R2+40),R5
L5:

	# goto L4
	JMP L4

	# label L6
L6:

	# var t20

	# t20 = k - 1
	LOD R5,(R2+44)
	LOD R6,1
    SUB R5,R6

	# k = t20
	STO (R2+44),R5

	# label L2
    STO (R2+44),R5
L2:

	# goto L1
	JMP L1

	# label L3
L3:

	# output sumd
	LOD R5,(R2+28)
    LOD R15,R5
    OTI

	# output L10
	LOD R6,L10
    LOD R15,R6
    OTS

	# output sume
	LOD R7,(R2+32)
    LOD R15,R7
    OTI

	# output L11
	LOD R8,L11
    LOD R15,R8
    OTS

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L11:
	DBS 10,0
L10:
	DBS 32,0
STATIC:
	DBN 0,8
STACK:
