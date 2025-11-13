	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var c

	# var i

	# var j

	# var a

	# var b

	# var c1

	# c = 10
	LOD R5,10
   STO (R2+8),R5

	# var t0

	# t0 = &c1
	LOD R6,(R2+32)
    LOD R6,R2+28

	# var t1

	# t1 = t0 + 0
    STO (R2+32),R6
    LOD R7,0
    ADD R6,R7

	# var t1

	# *t1 = 1
    STO (R2+40),R6
	LOD R7,1
    LOD R6,(R2+40)
    STO (R6),R7

	# var t2

	# t2 = &c1
	LOD R8,(R2+44)
    LOD R8,R2+28

	# var t3

	# t3 = t2 + 14
    STO (R2+44),R8
    LOD R9,14
    ADD R8,R9

	# var t3

	# var t4

	# t4 = t3 + 1108
    STO (R2+52),R8
    LOD R9,1108
    ADD R8,R9

	# var t5

	# t5 = t4 + 0
    STO (R2+56),R8
    LOD R9,0
    ADD R8,R9

	# var t5

	# *t5 = 2
    STO (R2+64),R8
	LOD R9,2
    LOD R8,(R2+64)
    STO (R8),R9

	# var t6

	# t6 = &c1
	LOD R10,(R2+68)
    LOD R10,R2+28

	# var t7

	# t7 = t6 + 14
    STO (R2+68),R10
    LOD R11,14
    ADD R10,R11

	# var t7

	# var t8

	# t8 = t7 + 1108
    STO (R2+76),R10
    LOD R11,1108
    ADD R10,R11

	# var t9

	# t9 = t8 + 14
    STO (R2+80),R10
    LOD R11,14
    ADD R10,R11

	# var t9

	# var t10

	# t10 = t9 + 162
    STO (R2+88),R10
    LOD R11,162
    ADD R10,R11

	# var t11

	# t11 = t10 + 4
    STO (R2+92),R10
    LOD R11,4
    ADD R10,R11

	# var t11

	# var t12

	# t12 = t11 + 1
    STO (R2+100),R10
    LOD R11,1
    ADD R10,R11

	# *t12 = 'b'
    STO (R2+104),R10
	LOD R11,98
    LOD R10,(R2+104)
    STO (R10),R11

	# var t13

	# t13 = &c1
	LOD R12,(R2+108)
    LOD R12,R2+28

	# var t14

	# t14 = t13 + 14
    STO (R2+108),R12
    LOD R13,14
    ADD R12,R13

	# var t14

	# var t15

	# t15 = t14 + 1108
    STO (R2+116),R12
    LOD R13,1108
    ADD R12,R13

	# var t16

	# t16 = t15 + 14
    STO (R2+120),R12
    LOD R13,14
    ADD R12,R13

	# var t16

	# var t17

	# t17 = t16 + 162
    STO (R2+128),R12
    LOD R13,162
    ADD R12,R13

	# var t18

	# t18 = t17 + 4
    STO (R2+132),R12
    LOD R13,4
    ADD R12,R13

	# var t18

	# var t19

	# t19 = t18 + 0
    STO (R2+140),R12
    LOD R13,0
    ADD R12,R13

	# *t19 = 'a'
    STO (R2+144),R12
	LOD R13,97
    LOD R12,(R2+144)
    STO (R12),R13

	# ifz 0 goto L2
	LOD R14,0
	TST R14
	JEZ L2

	# output L1
	LOD R15,L1
	LOD R15,R15
	OTS

	# label L2
L2:

	# var t20

	# t20 = &c1
	LOD R5,(R2+148)
    LOD R5,R2+28

	# var t21

	# t21 = t20 + 0
    STO (R2+148),R5
    LOD R6,0
    ADD R5,R6

	# var t21

	# var t22

	# t22 = *t21
    STO (R2+156),R5
	LOD R6,(R2+160)
    LOD R6,(R5)

	# i = t22
    STO (R2+160),R6
   STO (R2+12),R6

	# var t23

	# t23 = &c1
	LOD R7,(R2+164)
    LOD R7,R2+28

	# var t24

	# t24 = t23 + 14
    STO (R2+164),R7
    LOD R8,14
    ADD R7,R8

	# var t24

	# var t25

	# t25 = t24 + 1108
    STO (R2+172),R7
    LOD R8,1108
    ADD R7,R8

	# var t26

	# t26 = t25 + 0
    STO (R2+176),R7
    LOD R8,0
    ADD R7,R8

	# var t26

	# var t27

	# t27 = *t26
    STO (R2+184),R7
	LOD R8,(R2+188)
    LOD R8,(R7)

	# j = t27
    STO (R2+188),R8
   STO (R2+16),R8

	# var t28

	# t28 = &c1
	LOD R9,(R2+192)
    LOD R9,R2+28

	# var t29

	# t29 = t28 + 14
    STO (R2+192),R9
    LOD R10,14
    ADD R9,R10

	# var t29

	# var t30

	# t30 = t29 + 1108
    STO (R2+200),R9
    LOD R10,1108
    ADD R9,R10

	# var t31

	# t31 = t30 + 14
    STO (R2+204),R9
    LOD R10,14
    ADD R9,R10

	# var t31

	# var t32

	# t32 = t31 + 162
    STO (R2+212),R9
    LOD R10,162
    ADD R9,R10

	# var t33

	# t33 = t32 + 4
    STO (R2+216),R9
    LOD R10,4
    ADD R9,R10

	# var t33

	# var t34

	# t34 = t33 + 0
    STO (R2+224),R9
    LOD R10,0
    ADD R9,R10

	# var t35

	# t35 = *t34
    STO (R2+228),R9
	LOD R10,(R2+232)
    LOD R10,(R9)

	# a = t35
    STO (R2+232),R10
   STO (R2+20),R10

	# var t36

	# t36 = &c1
	LOD R11,(R2+236)
    LOD R11,R2+28

	# var t37

	# t37 = t36 + 14
    STO (R2+236),R11
    LOD R12,14
    ADD R11,R12

	# var t37

	# var t38

	# t38 = t37 + 1108
    STO (R2+244),R11
    LOD R12,1108
    ADD R11,R12

	# var t39

	# t39 = t38 + 14
    STO (R2+248),R11
    LOD R12,14
    ADD R11,R12

	# var t39

	# var t40

	# t40 = t39 + 162
    STO (R2+256),R11
    LOD R12,162
    ADD R11,R12

	# var t41

	# t41 = t40 + 4
    STO (R2+260),R11
    LOD R12,4
    ADD R11,R12

	# var t41

	# var t42

	# t42 = t41 + 1
    STO (R2+268),R11
    LOD R12,1
    ADD R11,R12

	# var t43

	# t43 = *t42
    STO (R2+272),R11
	LOD R12,(R2+276)
    LOD R12,(R11)

	# b = t43
    STO (R2+276),R12
   STO (R2+24),R12

	# ifz 0 goto L3
	LOD R13,0
	TST R13
	JEZ L3

	# output L1
	LOD R14,L1
	LOD R15,R14
	OTS

	# label L3
L3:

	# output i
	LOD R5,(R2+12)
    LOD R15,(R2+12)
	OTI

	# output j
	LOD R6,(R2+16)
    LOD R15,(R2+16)
	OTI

	# output a
	LOD R7,(R2+20)
    LOD R15,(R2+20)
	OTC

	# output b
	LOD R8,(R2+24)
    LOD R15,(R2+24)
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
