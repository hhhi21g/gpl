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
    LOD R6,0
    ADD R5,R6

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
    LOD R8,14
    ADD R7,R8

	# var t4

	# t4 = 2 * 554
    LOD R8,2
    LOD R8,554
    LOD R8,554
    MUL R8,R8

	# var t5

	# t5 = t3 + t4
    STO (R2+40),R7
    STO (R2+44),R8
    ADD R7,R8

	# var t6

	# t6 = t5 + 0
    STO (R2+48),R7
    LOD R9,0
    ADD R7,R9

	# *t6 = 2
    STO (R2+52),R7
	LOD R9,2
    LOD R7,(R2+52)
    STO (R7),R9

	# var t7

	# t7 = &c1
	LOD R10,(R2+56)
    LOD R10,R2+24

	# var t8

	# t8 = t7 + 14
    STO (R2+56),R10
    LOD R11,14
    ADD R10,R11

	# var t9

	# t9 = 2 * 554
    LOD R11,2
    LOD R11,554
    LOD R11,554
    MUL R11,R11

	# var t10

	# t10 = t8 + t9
    STO (R2+60),R10
    STO (R2+64),R11
    ADD R10,R11

	# var t11

	# t11 = t10 + 14
    STO (R2+68),R10
    LOD R12,14
    ADD R10,R12

	# var t12

	# t12 = 3 * 54
    LOD R12,3
    LOD R12,54
    LOD R12,54
    MUL R12,R12

	# var t13

	# t13 = t11 + t12
    STO (R2+72),R10
    STO (R2+76),R12
    ADD R10,R12

	# var t14

	# t14 = t13 + 4
    STO (R2+80),R10
    LOD R13,4
    ADD R10,R13

	# var t15

	# t15 = 1 * 1
    LOD R13,1
    LOD R13,1
    LOD R13,1
    MUL R13,R13

	# var t16

	# t16 = t14 + t15
    STO (R2+84),R10
    STO (R2+88),R13
    ADD R10,R13

	# *t16 = 'b'
    STO (R2+92),R10
	LOD R14,98
    LOD R10,(R2+92)
    STO (R10),R14

	# var t17

	# t17 = &c1
	LOD R15,(R2+96)
    LOD R15,R2+24

	# var t18

	# t18 = t17 + 14
    STO (R2+96),R15
    LOD R5,14
    ADD R15,R5

	# var t19

	# t19 = 2 * 554
    LOD R5,2
    LOD R5,554
    LOD R5,554
    MUL R5,R5

	# var t20

	# t20 = t18 + t19
    STO (R2+100),R15
    STO (R2+104),R5
    ADD R15,R5

	# var t21

	# t21 = t20 + 14
    STO (R2+108),R15
    LOD R5,14
    ADD R15,R5

	# var t22

	# t22 = 3 * 54
    LOD R5,3
    LOD R5,54
    LOD R5,54
    MUL R5,R5

	# var t23

	# t23 = t21 + t22
    STO (R2+112),R15
    STO (R2+116),R5
    ADD R15,R5

	# var t24

	# t24 = t23 + 4
    STO (R2+120),R15
    LOD R5,4
    ADD R15,R5

	# var t25

	# t25 = 0 * 1
    LOD R5,0
    LOD R5,1
    LOD R5,1
    MUL R5,R5

	# var t26

	# t26 = t24 + t25
    STO (R2+124),R15
    STO (R2+128),R5
    ADD R15,R5

	# *t26 = 'a'
    STO (R2+132),R15
	LOD R5,97
    LOD R15,(R2+132)
    STO (R15),R5

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

	# var t27

	# t27 = &c1
	LOD R5,(R2+136)
    LOD R5,R2+24

	# var t28

	# t28 = t27 + 0
    STO (R2+136),R5
    LOD R6,0
    ADD R5,R6

	# var t29

	# t29 = *t28
    STO (R2+140),R5
	LOD R6,(R2+144)
    LOD R6,(R5)

	# i = t29
    STO (R2+144),R6
   STO (R2+8),R6

	# var t30

	# t30 = &c1
	LOD R7,(R2+148)
    LOD R7,R2+24

	# var t31

	# t31 = t30 + 14
    STO (R2+148),R7
    LOD R8,14
    ADD R7,R8

	# var t32

	# t32 = 2 * 554
    LOD R8,2
    LOD R8,554
    LOD R8,554
    MUL R8,R8

	# var t33

	# t33 = t31 + t32
    STO (R2+152),R7
    STO (R2+156),R8
    ADD R7,R8

	# var t34

	# t34 = t33 + 0
    STO (R2+160),R7
    LOD R9,0
    ADD R7,R9

	# var t35

	# t35 = *t34
    STO (R2+164),R7
	LOD R9,(R2+168)
    LOD R9,(R7)

	# j = t35
    STO (R2+168),R9
   STO (R2+12),R9

	# var t36

	# t36 = &c1
	LOD R10,(R2+172)
    LOD R10,R2+24

	# var t37

	# t37 = t36 + 14
    STO (R2+172),R10
    LOD R11,14
    ADD R10,R11

	# var t38

	# t38 = 2 * 554
    LOD R11,2
    LOD R11,554
    LOD R11,554
    MUL R11,R11

	# var t39

	# t39 = t37 + t38
    STO (R2+176),R10
    STO (R2+180),R11
    ADD R10,R11

	# var t40

	# t40 = t39 + 14
    STO (R2+184),R10
    LOD R12,14
    ADD R10,R12

	# var t41

	# t41 = 3 * 54
    LOD R12,3
    LOD R12,54
    LOD R12,54
    MUL R12,R12

	# var t42

	# t42 = t40 + t41
    STO (R2+188),R10
    STO (R2+192),R12
    ADD R10,R12

	# var t43

	# t43 = t42 + 4
    STO (R2+196),R10
    LOD R13,4
    ADD R10,R13

	# var t44

	# t44 = 0 * 1
    LOD R13,0
    LOD R13,1
    LOD R13,1
    MUL R13,R13

	# var t45

	# t45 = t43 + t44
    STO (R2+200),R10
    STO (R2+204),R13
    ADD R10,R13

	# var t46

	# t46 = *t45
    STO (R2+208),R10
	LOD R14,(R2+212)
    LOD R14,(R10)

	# a = t46
    STO (R2+212),R14
   STO (R2+16),R14

	# var t47

	# t47 = &c1
	LOD R15,(R2+216)
    LOD R15,R2+24

	# var t48

	# t48 = t47 + 14
    STO (R2+216),R15
    LOD R5,14
    ADD R15,R5

	# var t49

	# t49 = 2 * 554
    LOD R5,2
    LOD R5,554
    LOD R5,554
    MUL R5,R5

	# var t50

	# t50 = t48 + t49
    STO (R2+220),R15
    STO (R2+224),R5
    ADD R15,R5

	# var t51

	# t51 = t50 + 14
    STO (R2+228),R15
    LOD R5,14
    ADD R15,R5

	# var t52

	# t52 = 3 * 54
    LOD R5,3
    LOD R5,54
    LOD R5,54
    MUL R5,R5

	# var t53

	# t53 = t51 + t52
    STO (R2+232),R15
    STO (R2+236),R5
    ADD R15,R5

	# var t54

	# t54 = t53 + 4
    STO (R2+240),R15
    LOD R5,4
    ADD R15,R5

	# var t55

	# t55 = 1 * 1
    LOD R5,1
    LOD R5,1
    LOD R5,1
    MUL R5,R5

	# var t56

	# t56 = t54 + t55
    STO (R2+244),R15
    STO (R2+248),R5
    ADD R15,R5

	# var t57

	# t57 = *t56
    STO (R2+252),R15
	LOD R5,(R2+256)
    LOD R5,(R15)

	# b = t57
    STO (R2+256),R5
   STO (R2+20),R5

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
