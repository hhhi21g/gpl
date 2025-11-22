	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4
	LOD R4,STATIC

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

	# var t2

	# *t2 = 1
	LOD R6,(R2+72)
	LOD R7,1
    LOD R6,(R2+72)
    STO (R6),R7

	# var t3

	# t3 = &cls
	LOD R8,(R2+76)
    LOD R8,R2+24

	# var t4

	# var t5

	# var t6

	# var t7

	# *t7 = 2
	LOD R9,(R2+92)
	LOD R10,2
    LOD R9,(R2+92)
    STO (R9),R10

	# var t8

	# t8 = &cls
	LOD R11,(R2+96)
    LOD R11,R2+24

	# var t9

	# var t10

	# var t11

	# var t12

	# var t13

	# var t14

	# var t15

	# c*t15 = 'b'
	LOD R12,(R2+124)
	LOD R13,98
    LOD R12,(R2+124)
    STC (R12),R13

	# var t16

	# t16 = &cls
	LOD R14,(R2+128)
    LOD R14,R2+24

	# var t17

	# var t18

	# var t19

	# var t20

	# var t21

	# var t22

	# var t23

	# c*t23 = 'a'
	LOD R15,(R2+156)
	LOD R6,97
    LOD R15,(R2+156)
    STC (R15),R6

	# ifz 0 goto L2
    STO (R2+64),R5
    STO (R2+76),R8
    STO (R2+96),R11
    STO (R2+128),R14
	LOD R5,0
	TST R5
	JEZ L2

	# output L1
	LOD R5,L1
    LOD R15,R5
    OTS

	# label L2
L2:

	# var t24

	# t24 = &cls
	LOD R5,(R2+160)
    LOD R5,R2+24

	# var t25

	# var t26

	# var t27

	# t27 = *t26
	LOD R6,(R2+168)
	LOD R7,(R2+172)
    LOD R7,(R6)

	# i = t27
	STO (R2+8),R7

	# var t28

	# t28 = &cls
	LOD R8,(R2+176)
    LOD R8,R2+24

	# var t29

	# var t30

	# var t31

	# var t32

	# var t33

	# t33 = *t32
	LOD R9,(R2+192)
	LOD R10,(R2+196)
    LOD R10,(R9)

	# j = t33
	STO (R2+12),R10

	# var t34

	# t34 = &cls
	LOD R11,(R2+200)
    LOD R11,R2+24

	# var t35

	# var t36

	# var t37

	# var t38

	# var t39

	# var t40

	# var t41

	# var t42

	# t42 = c*t41
	LOD R12,(R2+232)
	LOD R13,(R2+228)
    LDC R12,(R13)

	# a = t42
	STO (R2+16),R12

	# var t43

	# t43 = &cls
	LOD R14,(R2+236)
    LOD R14,R2+24

	# var t44

	# var t45

	# var t46

	# var t47

	# var t48

	# var t49

	# var t50

	# var t51

	# t51 = c*t50
	LOD R15,(R2+268)
	LOD R6,(R2+264)
    LDC R15,(R6)

	# b = t51
	STO (R2+20),R15

	# ifz 0 goto L3
    STO (R2+160),R5
    STO (R2+8),R7
    STO (R2+176),R8
    STO (R2+12),R10
    STO (R2+200),R11
    STO (R2+16),R12
    STO (R2+236),R14
    STO (R2+20),R15
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
    LOD R15,R5
    OTI

	# output j
	LOD R6,(R2+12)
    LOD R15,R6
    OTI

	# output a
	LOD R7,(R2+16)
    LOD R15,R7
    OTC

	# output b
	LOD R8,(R2+20)
    LOD R15,R8
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
