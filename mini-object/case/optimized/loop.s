	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# var t2

	# var t3

	# var t4

	# var t5

	# var t6

	# var t8

	# var t9

	# var t10

	# var t11

	# var t12

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
	LOD R9,(R2+12)
    STO (R2+16),R7
    MUL R9,R7

	# t3 = a + t2
	LOD R10,(R2+8)
	LOD R4,STATIC
	STO (R4+0),R9
    ADD R10,R9

	# t4 = a + c
	LOD R11,(R2+8)
    ADD R11,R7

	# t5 = t4 / b
    STO (R2+12),R6
    DIV R12,R6

	# t6 = t3 - t5
	LOD R4,STATIC
	STO (R4+12),R12
    SUB R13,R12

	# t8 = b * c
	LOD R14,(R2+12)
    MUL R14,R7

	# t9 = a + t8
	LOD R15,(R2+8)
	LOD R4,STATIC
	STO (R4+20),R14
    ADD R15,R14

	# t10 = c - a
	LOD R6,(R2+16)
    STO (R2+8),R5
    SUB R6,R5

	# t11 = t10 / b
	LOD R5,(R2+12)
    LOD R7,R5
    DIV R5,R7

	# t12 = t9 - t11
	LOD R4,STATIC
	STO (R4+32),R5
    SUB R7,R5

	# label L1
	LOD R4,STATIC
	STO (R4+28),R6
	LOD R4,STATIC
	STO (R4+36),R7
	LOD R4,STATIC
	STO (R4+4),R10
	LOD R4,STATIC
	STO (R4+8),R11
	LOD R4,STATIC
	STO (R4+16),R13
	LOD R4,STATIC
	STO (R4+24),R15
L1:

	# var t0

	# t0 = (j > 0)
	LOD R5,(R2+32)
    LOD R6,0
    SUB R5,R6
    TST R5
    JGZ L2000
    LOD R5,0
    JMP L2001
L2000:
    LOD R5,1
L2001:

	# ifz t0 goto L3
	TST R5
	JEZ L3

	# output j
	LOD R6,(R2+32)
    LOD R15,R6
    OTI

	# i = 9
	LOD R7,9
    STO (R2+28),R7

	# label L4
L4:

	# var t1

	# t1 = (i > 0)
	LOD R5,(R2+28)
    LOD R6,0
    SUB R5,R6
    TST R5
    JGZ L2002
    LOD R5,0
    JMP L2004
L2002:
    LOD R5,1
L2004:

	# ifz t1 goto L6
	TST R5
	JEZ L6

	# output i
	LOD R6,(R2+28)
    LOD R15,R6
    OTI

	# var t7

	# t7 = t6 + 9
    LOD R8,9
    ADD R7,R8

	# d = t7
    STO (R2+20),R7

	# var t13

	# t13 = t12 + 9
    LOD R9,9
    ADD R8,R9

	# e = t13
    STO (R2+24),R8

	# var t14

	# t14 = i - 1
	LOD R9,(R2+28)
    LOD R10,1
    SUB R9,R10

	# i = t14
    STO (R2+28),R9

	# output L7
	LOD R10,L7
    LOD R15,R10
    OTS

	# output d
	LOD R11,(R2+20)
    LOD R15,R11
    OTI

	# output L7
    LOD R15,R10
    OTS

	# output e
	LOD R12,(R2+24)
    LOD R15,R12
    OTI

	# output L8
	LOD R13,L8
    LOD R15,R13
    OTS

	# label L5
    STO (R2+48),R7
    STO (R2+52),R8
    STO (R2+56),R9
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
    STO (R2+60),R5
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
	DBN 0,40
STACK:
