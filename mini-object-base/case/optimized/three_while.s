	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

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

	# a = 1
	LOD R5,1
   STO (R2+8),R5

	# b = 2
	LOD R6,2
   STO (R2+12),R6

	# c = 3
	LOD R7,3
   STO (R2+16),R7

	# sumd = 0
	LOD R8,0
   STO (R2+28),R8

	# sume = 0
	LOD R9,0
   STO (R2+32),R9

	# k = 12
	LOD R10,12
   STO (R2+44),R10

	# label L1
L1:

	# var t0

	# t0 = (k > 0)
	LOD R5,(R2+44)
	LOD R6,0
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JGZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t0 goto L3
    STO (R2+48),R5
	TST R5
	JEZ L3

	# j = 15
	LOD R7,15
   STO (R2+40),R7

	# label L4
L4:

	# var t1

	# t1 = (j > 0)
	LOD R5,(R2+40)
	LOD R6,0
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JGZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t1 goto L6
    STO (R2+52),R5
	TST R5
	JEZ L6

	# i = 18
	LOD R7,18
   STO (R2+36),R7

	# label L7
L7:

	# var t2

	# t2 = (i > 0)
	LOD R5,(R2+36)
	LOD R6,0
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JGZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t2 goto L9
    STO (R2+56),R5
	TST R5
	JEZ L9

	# var t3

	# t3 = b * c
	LOD R7,(R2+12)
	LOD R8,(R2+16)
    MUL R7,R8

	# var t4

	# t4 = a + t3
	LOD R9,(R2+8)
    STO (R2+60),R7
    ADD R9,R7

	# var t5

	# t5 = a + c
	LOD R10,(R2+8)
    ADD R10,R8

	# var t6

	# t6 = t5 / b
    STO (R2+68),R10
	LOD R11,(R2+12)
    DIV R10,R11

	# var t7

	# t7 = t4 - t6
    STO (R2+64),R9
    STO (R2+72),R10
    SUB R9,R10

	# var t8

	# t8 = t7 + 9
    STO (R2+76),R9
    LOD R12,9
    ADD R9,R12

	# d = t8
    STO (R2+80),R9
   STO (R2+20),R9

	# var t9

	# t9 = b * c
    MUL R11,R8

	# var t10

	# t10 = a + t9
	LOD R12,(R2+8)
    STO (R2+84),R11
    ADD R12,R11

	# var t11

	# t11 = c - a
	LOD R13,(R2+8)
    SUB R8,R13

	# var t12

	# t12 = t11 / b
    STO (R2+92),R8
	LOD R14,(R2+12)
    DIV R8,R14

	# var t13

	# t13 = t10 - t12
    STO (R2+88),R12
    STO (R2+96),R8
    SUB R12,R8

	# var t14

	# t14 = t13 + 13
    STO (R2+100),R12
    LOD R15,13
    ADD R12,R15

	# e = t14
    STO (R2+104),R12
   STO (R2+24),R12

	# var t15

	# t15 = sumd + d
	LOD R15,(R2+28)
    ADD R15,R9

	# sumd = t15
    STO (R2+108),R15
   STO (R2+28),R15

	# var t16

	# t16 = sume + e
	LOD R5,(R2+32)
    ADD R5,R12

	# var t17

	# t17 = t16 + d
    STO (R2+112),R5
    ADD R5,R9

	# sume = t17
    STO (R2+116),R5
   STO (R2+32),R5

	# var t18

	# t18 = i - 1
	LOD R5,(R2+36)
    LOD R5,1
    LOD R5,1
    SUB R5,R5

	# i = t18
    STO (R2+120),R5
   STO (R2+36),R5

	# label L8
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
    STO (R2+124),R5
   STO (R2+40),R5

	# label L5
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
    STO (R2+128),R5
   STO (R2+44),R5

	# label L2
L2:

	# goto L1
	JMP L1

	# label L3
L3:

	# output sumd
	LOD R5,(R2+28)
    LOD R15,(R2+28)
	OTI

	# output L10
	LOD R6,L10
	LOD R15,R6
	OTS

	# output sume
	LOD R7,(R2+32)
    LOD R15,(R2+32)
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
	DBN 0,0
STACK:
