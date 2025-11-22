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

	# vararray cls[1D]
	# declare array cls [10] elem=int(4B) size=40 bytes

	# var t0

	# t0 = &cls
	LOD R5,(R2+64)
    LOD R5,R2+24

	# var t1

	# t1 = t0 + 0
    STO (R2+64),R5
    LOD R6,0
    ADD R5,R6

	# var t2

	# t2 = t1 + 0
    STO (R2+68),R5
    LOD R6,0
    ADD R5,R6

	# *t2 = 1
    STO (R2+72),R5
	LOD R6,1
    LOD R5,(R2+72)
    STO (R5),R6

	# var t3

	# t3 = &cls
	LOD R7,(R2+76)
    LOD R7,R2+24

	# var t4

	# t4 = t3 + 0
    STO (R2+76),R7
    LOD R8,0
    ADD R7,R8

	# var t5

	# t5 = t4 + 14
    STO (R2+80),R7
    LOD R8,14
    ADD R7,R8

	# var t6

	# t6 = t5 + 1108
    STO (R2+84),R7
    LOD R8,1108
    ADD R7,R8

	# var t7

	# t7 = t6 + 0
    STO (R2+88),R7
    LOD R8,0
    ADD R7,R8

	# *t7 = 2
    STO (R2+92),R7
	LOD R8,2
    LOD R7,(R2+92)
    STO (R7),R8

	# var t8

	# t8 = &cls
	LOD R9,(R2+96)
    LOD R9,R2+24

	# var t9

	# t9 = t8 + 0
    STO (R2+96),R9
    LOD R10,0
    ADD R9,R10

	# var t10

	# t10 = t9 + 14
    STO (R2+100),R9
    LOD R10,14
    ADD R9,R10

	# var t11

	# t11 = t10 + 1108
    STO (R2+104),R9
    LOD R10,1108
    ADD R9,R10

	# var t12

	# t12 = t11 + 14
    STO (R2+108),R9
    LOD R10,14
    ADD R9,R10

	# var t13

	# t13 = t12 + 162
    STO (R2+112),R9
    LOD R10,162
    ADD R9,R10

	# var t14

	# t14 = t13 + 4
    STO (R2+116),R9
    LOD R10,4
    ADD R9,R10

	# var t15

	# t15 = t14 + 1
    STO (R2+120),R9
    LOD R10,1
    ADD R9,R10

	# c*t15 = 'b'
    STO (R2+124),R9
	LOD R10,98
    LOD R9,(R2+124)
    STC (R9),R10

	# var t16

	# t16 = &cls
	LOD R11,(R2+128)
    LOD R11,R2+24

	# var t17

	# t17 = t16 + 0
    STO (R2+128),R11
    LOD R12,0
    ADD R11,R12

	# var t18

	# t18 = t17 + 14
    STO (R2+132),R11
    LOD R12,14
    ADD R11,R12

	# var t19

	# t19 = t18 + 1108
    STO (R2+136),R11
    LOD R12,1108
    ADD R11,R12

	# var t20

	# t20 = t19 + 14
    STO (R2+140),R11
    LOD R12,14
    ADD R11,R12

	# var t21

	# t21 = t20 + 162
    STO (R2+144),R11
    LOD R12,162
    ADD R11,R12

	# var t22

	# t22 = t21 + 4
    STO (R2+148),R11
    LOD R12,4
    ADD R11,R12

	# var t23

	# t23 = t22 + 0
    STO (R2+152),R11
    LOD R12,0
    ADD R11,R12

	# c*t23 = 'a'
    STO (R2+156),R11
	LOD R12,97
    LOD R11,(R2+156)
    STC (R11),R12

	# ifz 0 goto L2
	LOD R13,0
	TST R13
	JEZ L2

	# output L1
	LOD R14,L1
	LOD R15,R14
	OTS

	# label L2
L2:

	# var t24

	# t24 = &cls
	LOD R5,(R2+160)
    LOD R5,R2+24

	# var t25

	# t25 = t24 + 0
    STO (R2+160),R5
    LOD R6,0
    ADD R5,R6

	# var t26

	# t26 = t25 + 0
    STO (R2+164),R5
    LOD R6,0
    ADD R5,R6

	# var t27

	# t27 = *t26
    STO (R2+168),R5
	LOD R6,(R2+172)
    LOD R6,(R5)

	# i = t27
    STO (R2+172),R6
   STO (R2+8),R6

	# var t28

	# t28 = &cls
	LOD R7,(R2+176)
    LOD R7,R2+24

	# var t29

	# t29 = t28 + 0
    STO (R2+176),R7
    LOD R8,0
    ADD R7,R8

	# var t30

	# t30 = t29 + 14
    STO (R2+180),R7
    LOD R8,14
    ADD R7,R8

	# var t31

	# t31 = t30 + 1108
    STO (R2+184),R7
    LOD R8,1108
    ADD R7,R8

	# var t32

	# t32 = t31 + 0
    STO (R2+188),R7
    LOD R8,0
    ADD R7,R8

	# var t33

	# t33 = *t32
    STO (R2+192),R7
	LOD R8,(R2+196)
    LOD R8,(R7)

	# j = t33
    STO (R2+196),R8
   STO (R2+12),R8

	# var t34

	# t34 = &cls
	LOD R9,(R2+200)
    LOD R9,R2+24

	# var t35

	# t35 = t34 + 0
    STO (R2+200),R9
    LOD R10,0
    ADD R9,R10

	# var t36

	# t36 = t35 + 14
    STO (R2+204),R9
    LOD R10,14
    ADD R9,R10

	# var t37

	# t37 = t36 + 1108
    STO (R2+208),R9
    LOD R10,1108
    ADD R9,R10

	# var t38

	# t38 = t37 + 14
    STO (R2+212),R9
    LOD R10,14
    ADD R9,R10

	# var t39

	# t39 = t38 + 162
    STO (R2+216),R9
    LOD R10,162
    ADD R9,R10

	# var t40

	# t40 = t39 + 4
    STO (R2+220),R9
    LOD R10,4
    ADD R9,R10

	# var t41

	# t41 = t40 + 0
    STO (R2+224),R9
    LOD R10,0
    ADD R9,R10

	# var t42

	# t42 = c*t41
	LOD R10,(R2+232)
    STO (R2+228),R9
    LDC R10,(R9)

	# a = t42
   STO (R2+16),R10

	# var t43

	# t43 = &cls
	LOD R11,(R2+236)
    LOD R11,R2+24

	# var t44

	# t44 = t43 + 0
    STO (R2+236),R11
    LOD R12,0
    ADD R11,R12

	# var t45

	# t45 = t44 + 14
    STO (R2+240),R11
    LOD R12,14
    ADD R11,R12

	# var t46

	# t46 = t45 + 1108
    STO (R2+244),R11
    LOD R12,1108
    ADD R11,R12

	# var t47

	# t47 = t46 + 14
    STO (R2+248),R11
    LOD R12,14
    ADD R11,R12

	# var t48

	# t48 = t47 + 162
    STO (R2+252),R11
    LOD R12,162
    ADD R11,R12

	# var t49

	# t49 = t48 + 4
    STO (R2+256),R11
    LOD R12,4
    ADD R11,R12

	# var t50

	# t50 = t49 + 1
    STO (R2+260),R11
    LOD R12,1
    ADD R11,R12

	# var t51

	# t51 = c*t50
	LOD R12,(R2+268)
    STO (R2+264),R11
    LDC R12,(R11)

	# b = t51
   STO (R2+20),R12

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
