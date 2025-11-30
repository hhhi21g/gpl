	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4
	LOD R4,STATIC

	# var t2

	# label main
main:

	# begin

	# var a

	# var b

	# var c

	# var d

	# var e

	# var i

	# var j

	# var k

	# var t3

	# var t4

	# var t5

	# var t6

	# var t9

	# var t10

	# var t11

	# var t12

	# input a
	LOD R5,(R2+8)
	ITI
	LOD R5,R15

	# input b
	LOD R6,(R2+12)
	ITI
	LOD R6,R15

	# input c
	LOD R7,(R2+16)
	ITI
	LOD R7,R15

	# j = 5
	LOD R8,5
	STO (R2+32),R8

	# t2 = b * c
    STO (R2+12),R6
    STO (R2+16),R7
    MUL R6,R7

	# t3 = a + t2
    STO (R2+8),R5
	STO (R4+0),R6
    ADD R5,R6

	# t4 = a + c
	LOD R9,(R2+8)
    ADD R9,R7

	# t5 = t4 / b
    STO (R2+44),R9
	LOD R10,(R2+12)
    DIV R9,R10

	# t6 = t3 - t5
    STO (R2+40),R5
    STO (R2+48),R9
    SUB R5,R9

	# t10 = c - a
	LOD R11,(R2+8)
    SUB R7,R11

	# t11 = t10 / b
    STO (R2+60),R7
    DIV R7,R10

	# t12 = t3 - t11
	LOD R12,(R2+40)
    STO (R2+64),R7
    SUB R12,R7

	# t7 = t6 + 9
    STO (R2+52),R5
    LOD R13,9
    ADD R5,R13

	# d = t7
	STO (R2+20),R5

	# t13 = t12 + 9
    STO (R2+68),R12
    LOD R13,9
    ADD R12,R13

	# e = t13
	STO (R2+24),R12

	# label L1
    STO (R2-1),R5
    STO (R2+32),R8
    STO (R2-1),R12
L1:

	# var t0

	# t0 = (j > 0)
	LOD R5,(R2+32)
    TST R5
    JEZ L3
    JLZ L3

	# output j
    LOD R15,R5
    OTI

	# i = 9
	LOD R6,9
	STO (R2+28),R6

	# label L4
    STO (R2+28),R6
L4:

	# var t1

	# t1 = (i > 0)
	LOD R5,(R2+28)
    TST R5
    JEZ L6
    JLZ L6

	# output i
    LOD R15,R5
    OTI

	# var t7

	# var t8

	# var t13

	# var t14

	# t14 = i - 1
    LOD R6,1
    SUB R5,R6

	# i = t14
	STO (R2+28),R5

	# label L5
    STO (R2+28),R5
L5:

	# goto L4
	JMP L4

	# label L6
L6:

	# var t15

	# t15 = j - 1
	LOD R5,(R2+32)
    LOD R6,1
    SUB R5,R6

	# j = t15
	STO (R2+32),R5

	# output L7
	LOD R6,L7
    LOD R15,R6
    OTS

	# label L2
    STO (R2+32),R5
L2:

	# goto L1
	JMP L1

	# label L3
L3:

	# output L8
	LOD R5,L8
    LOD R15,R5
    OTS

	# output d
	LOD R6,(R2+20)
    LOD R15,R6
    OTI

	# output L7
	LOD R7,L7
    LOD R15,R7
    OTS

	# output e
	LOD R8,(R2+24)
    LOD R15,R8
    OTI

	# output L8
    LOD R15,R5
    OTS

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L8:
	DBS 10,0
L7:
	DBS 32,0
STATIC:
	DBN 0,4
STACK:
