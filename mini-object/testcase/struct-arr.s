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

	# var a

	# var b

	# var c1

	# var t0

	# t0 = &c1
	LOD R5,(R2+28)
    LOD R5,R2+24

	# var t1

	# t1 = t0 + 0
    STO (R2+28),R5
    LOD R10,0
    ADD R5,R10

	# *t1 = 1
    STO (R2+32),R5
	LOD R6,1
    LOD R5,(R2+32)
    STO (R5),R6

	# var t2

	# t2 = &c1
	LOD R7,(R2+36)
    LOD R7,R2+24

	# var t3

	# t3 = t2 + 14
    STO (R2+36),R7
    LOD R11,14
    ADD R7,R11

	# var t4

	# t4 = t3 + 1108
    STO (R2+40),R7
    LOD R12,1108
    ADD R7,R12

	# var t5

	# t5 = t4 + 0
    STO (R2+44),R7
    LOD R13,0
    ADD R7,R13

	# *t5 = 2
    STO (R2+48),R7
	LOD R8,2
    LOD R7,(R2+48)
    STO (R7),R8

	# var t6

	# t6 = &c1
	LOD R9,(R2+52)
    LOD R9,R2+24

	# var t7

	# t7 = t6 + 14
    STO (R2+52),R9
    LOD R14,14
    ADD R9,R14

	# var t8

	# t8 = t7 + 1108
    STO (R2+56),R9
    LOD R10,1108
    ADD R9,R10

	# var t9

	# t9 = t8 + 14
    STO (R2+60),R9
    LOD R11,14
    ADD R9,R11

	# var t10

	# t10 = t9 + 162
    STO (R2+64),R9
    LOD R12,162
    ADD R9,R12

	# var t11

	# t11 = t10 + 4
    STO (R2+68),R9
    LOD R13,4
    ADD R9,R13

	# var t12

	# t12 = t11 + 1
    STO (R2+72),R9
    LOD R14,1
    ADD R9,R14

	# c*t12 = 'b'
    STO (R2+76),R9
	LOD R5,98
    LOD R9,(R2+76)
    STC (R9),R5

	# var t13

	# t13 = &c1
	LOD R5,(R2+80)
    LOD R5,R2+24

	# var t14

	# t14 = t13 + 14
    STO (R2+80),R5
    LOD R10,14
    ADD R5,R10

	# var t15

	# t15 = t14 + 1108
    STO (R2+84),R5
    LOD R11,1108
    ADD R5,R11

	# var t16

	# t16 = t15 + 14
    STO (R2+88),R5
    LOD R12,14
    ADD R5,R12

	# var t17

	# t17 = t16 + 162
    STO (R2+92),R5
    LOD R13,162
    ADD R5,R13

	# var t18

	# t18 = t17 + 4
    STO (R2+96),R5
    LOD R14,4
    ADD R5,R14

	# var t19

	# t19 = t18 + 0
    STO (R2+100),R5
    LOD R10,0
    ADD R5,R10

	# c*t19 = 'a'
    STO (R2+104),R5
	LOD R5,97
    LOD R5,(R2+104)
    STC (R5),R5

	# ifz 0 goto L2
	LOD R5,0
	TST R5
	JEZ L2

	# output L1
	LOD R5,L1
	LOD R15,R5
	OTS

	# label L2
L2:

	# var t20

	# t20 = &c1
	LOD R5,(R2+108)
    LOD R5,R2+24

	# var t21

	# t21 = t20 + 0
    STO (R2+108),R5
    LOD R11,0
    ADD R5,R11

	# var t22

	# t22 = *t21
    STO (R2+112),R5
	LOD R6,(R2+116)
    LOD R6,(R5)

	# i = t22
    STO (R2+116),R6
   STO (R2+8),R6

	# var t23

	# t23 = &c1
	LOD R7,(R2+120)
    LOD R7,R2+24

	# var t24

	# t24 = t23 + 14
    STO (R2+120),R7
    LOD R12,14
    ADD R7,R12

	# var t25

	# t25 = t24 + 1108
    STO (R2+124),R7
    LOD R13,1108
    ADD R7,R13

	# var t26

	# t26 = t25 + 0
    STO (R2+128),R7
    LOD R14,0
    ADD R7,R14

	# var t27

	# t27 = *t26
    STO (R2+132),R7
	LOD R8,(R2+136)
    LOD R8,(R7)

	# j = t27
    STO (R2+136),R8
   STO (R2+12),R8

	# var t28

	# t28 = &c1
	LOD R9,(R2+140)
    LOD R9,R2+24

	# var t29

	# t29 = t28 + 14
    STO (R2+140),R9
    LOD R10,14
    ADD R9,R10

	# var t30

	# t30 = t29 + 1108
    STO (R2+144),R9
    LOD R11,1108
    ADD R9,R11

	# var t31

	# t31 = t30 + 14
    STO (R2+148),R9
    LOD R12,14
    ADD R9,R12

	# var t32

	# t32 = t31 + 162
    STO (R2+152),R9
    LOD R13,162
    ADD R9,R13

	# var t33

	# t33 = t32 + 4
    STO (R2+156),R9
    LOD R14,4
    ADD R9,R14

	# var t34

	# t34 = t33 + 0
    STO (R2+160),R9
    LOD R10,0
    ADD R9,R10

	# var t35

	# t35 = c*t34
	LOD R5,(R2+168)
    STO (R2+164),R9
    LDC R5,(R9)

	# a = t35
   STO (R2+16),R5

	# var t36

	# t36 = &c1
	LOD R5,(R2+172)
    LOD R5,R2+24

	# var t37

	# t37 = t36 + 14
    STO (R2+172),R5
    LOD R11,14
    ADD R5,R11

	# var t38

	# t38 = t37 + 1108
    STO (R2+176),R5
    LOD R12,1108
    ADD R5,R12

	# var t39

	# t39 = t38 + 14
    STO (R2+180),R5
    LOD R13,14
    ADD R5,R13

	# var t40

	# t40 = t39 + 162
    STO (R2+184),R5
    LOD R14,162
    ADD R5,R14

	# var t41

	# t41 = t40 + 4
    STO (R2+188),R5
    LOD R10,4
    ADD R5,R10

	# var t42

	# t42 = t41 + 1
    STO (R2+192),R5
    LOD R11,1
    ADD R5,R11

	# var t43

	# t43 = c*t42
	LOD R6,(R2+200)
    STO (R2+196),R5
    LDC R6,(R5)

	# b = t43
   STO (R2+20),R6

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

	# output a
	LOD R7,(R2+16)
    LOD R15,(R2+16)
	OTC

	# output b
	LOD R8,(R2+20)
    LOD R15,(R2+20)
	OTC

	# output L1
	LOD R9,L1
	LOD R15,R9
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
