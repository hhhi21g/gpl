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

	# var _t0

	# _t0 = &c1
	LOD R4,STATIC
	LOD R5,(R4+0)
    LOD R6,R2
    LOD R7,24
    LOD R5,R6
    ADD R5,R7

	# var _t1

	# _t1 = _t0 + 0
	LOD R4,STATIC
	STO (R4+0),R5
    LOD R8,0
    ADD R5,R8

	# *_t1 = 1
	LOD R4,STATIC
	STO (R4+0),R5
	LOD R9,1
    LOD R5,(R2+0)
    STO (R5),R9

	# var _t2

	# _t2 = &c1
	LOD R4,STATIC
	LOD R10,(R4+0)
    LOD R11,R2
    LOD R12,24
    LOD R10,R11
    ADD R10,R12

	# var _t3

	# _t3 = _t2 + 14
	LOD R4,STATIC
	STO (R4+0),R10
    LOD R13,14
    ADD R10,R13

	# var _t4

	# _t4 = 2 * 554
    LOD R14,2
    LOD R15,554
    MUL R14,R15

	# var _t5

	# _t5 = _t3 + _t4
	LOD R4,STATIC
	STO (R4+0),R10
	LOD R4,STATIC
	STO (R4+0),R14
    ADD R10,R14

	# var _t6

	# _t6 = _t5 + 0
	LOD R4,STATIC
	STO (R4+0),R10
    LOD R5,0
    ADD R10,R5

	# *_t6 = 2
	LOD R4,STATIC
	STO (R4+0),R10
	LOD R5,2
    LOD R10,(R2+0)
    STO (R10),R5

	# var _t7

	# _t7 = &c1
	LOD R4,STATIC
	LOD R5,(R4+0)
    LOD R5,R2
    LOD R5,24
    LOD R5,R5
    ADD R5,R5

	# var _t8

	# _t8 = _t7 + 14
	LOD R4,STATIC
	STO (R4+0),R5
    LOD R5,14
    LOD R5,14
    ADD R5,R5

	# var _t9

	# _t9 = 2 * 554
    LOD R5,2
    LOD R5,554
    LOD R5,554
    MUL R5,R5

	# var _t10

	# _t10 = _t8 + _t9
	LOD R4,STATIC
	LOD R6,(R4+0)
	LOD R4,STATIC
	STO (R4+0),R5
    ADD R6,R5

	# var _t11

	# _t11 = _t10 + 14
	LOD R4,STATIC
	STO (R4+0),R6
    LOD R5,14
    ADD R6,R5

	# var _t12

	# _t12 = 3 * 54
    LOD R5,3
    LOD R5,54
    LOD R5,54
    MUL R5,R5

	# var _t13

	# _t13 = _t11 + _t12
	LOD R4,STATIC
	STO (R4+0),R6
	LOD R4,STATIC
	STO (R4+0),R5
    ADD R6,R5

	# var _t14

	# _t14 = _t13 + 4
	LOD R4,STATIC
	STO (R4+0),R6
    LOD R5,4
    ADD R6,R5

	# var _t15

	# _t15 = 1 * 1
    LOD R5,1
    LOD R5,1
    LOD R5,1
    MUL R5,R5

	# var _t16

	# _t16 = _t14 + _t15
	LOD R4,STATIC
	STO (R4+0),R6
	LOD R4,STATIC
	STO (R4+0),R5
    ADD R6,R5

	# *_t16 = 'b'
	LOD R4,STATIC
	STO (R4+0),R6
	LOD R5,98
    LOD R6,(R2+0)
    STO (R6),R5

	# var _t17

	# _t17 = &c1
	LOD R4,STATIC
	LOD R5,(R4+0)
    LOD R5,R2
    LOD R5,24
    LOD R5,R5
    ADD R5,R5

	# var _t18

	# _t18 = _t17 + 14
	LOD R4,STATIC
	STO (R4+0),R5
    LOD R5,14
    LOD R5,14
    ADD R5,R5

	# var _t19

	# _t19 = 2 * 554
    LOD R5,2
    LOD R5,554
    LOD R5,554
    MUL R5,R5

	# var _t20

	# _t20 = _t18 + _t19
	LOD R4,STATIC
	LOD R6,(R4+0)
	LOD R4,STATIC
	STO (R4+0),R5
    ADD R6,R5

	# var _t21

	# _t21 = _t20 + 14
	LOD R4,STATIC
	STO (R4+0),R6
    LOD R5,14
    ADD R6,R5

	# var _t22

	# _t22 = 3 * 54
    LOD R5,3
    LOD R5,54
    LOD R5,54
    MUL R5,R5

	# var _t23

	# _t23 = _t21 + _t22
	LOD R4,STATIC
	STO (R4+0),R6
	LOD R4,STATIC
	STO (R4+0),R5
    ADD R6,R5

	# var _t24

	# _t24 = _t23 + 4
	LOD R4,STATIC
	STO (R4+0),R6
    LOD R5,4
    ADD R6,R5

	# var _t25

	# _t25 = 0 * 1
    LOD R5,0
    LOD R5,1
    LOD R5,1
    MUL R5,R5

	# var _t26

	# _t26 = _t24 + _t25
	LOD R4,STATIC
	STO (R4+0),R6
	LOD R4,STATIC
	STO (R4+0),R5
    ADD R6,R5

	# *_t26 = 'a'
	LOD R4,STATIC
	STO (R4+0),R6
	LOD R5,97
    LOD R6,(R2+0)
    STO (R6),R5

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

	# var _t27

	# _t27 = &c1
	LOD R4,STATIC
	LOD R5,(R4+0)
    LOD R6,R2
    LOD R7,24
    LOD R5,R6
    ADD R5,R7

	# var _t28

	# _t28 = _t27 + 0
	LOD R4,STATIC
	STO (R4+0),R5
    LOD R8,0
    ADD R5,R8

	# var _t29

	# _t29 = *_t28
	LOD R4,STATIC
	STO (R4+0),R5
	LOD R4,STATIC
	LOD R9,(R4+0)
    LOD R9,(R5)

	# i = _t29
	LOD R4,STATIC
	STO (R4+0),R9
   STO (R2+8),R9

	# var _t30

	# _t30 = &c1
	LOD R4,STATIC
	LOD R10,(R4+0)
    LOD R11,R2
    LOD R12,24
    LOD R10,R11
    ADD R10,R12

	# var _t31

	# _t31 = _t30 + 14
	LOD R4,STATIC
	STO (R4+0),R10
    LOD R13,14
    ADD R10,R13

	# var _t32

	# _t32 = 2 * 554
    LOD R14,2
    LOD R15,554
    MUL R14,R15

	# var _t33

	# _t33 = _t31 + _t32
	LOD R4,STATIC
	STO (R4+0),R10
	LOD R4,STATIC
	STO (R4+0),R14
    ADD R10,R14

	# var _t34

	# _t34 = _t33 + 0
	LOD R4,STATIC
	STO (R4+0),R10
    LOD R5,0
    ADD R10,R5

	# var _t35

	# _t35 = *_t34
	LOD R4,STATIC
	STO (R4+0),R10
	LOD R4,STATIC
	LOD R5,(R4+0)
    LOD R5,(R10)

	# j = _t35
	LOD R4,STATIC
	STO (R4+0),R5
   STO (R2+12),R5

	# var _t36

	# _t36 = &c1
	LOD R4,STATIC
	LOD R5,(R4+0)
    LOD R5,R2
    LOD R5,24
    LOD R5,R5
    ADD R5,R5

	# var _t37

	# _t37 = _t36 + 14
	LOD R4,STATIC
	STO (R4+0),R5
    LOD R5,14
    LOD R5,14
    ADD R5,R5

	# var _t38

	# _t38 = 2 * 554
    LOD R5,2
    LOD R5,554
    LOD R5,554
    MUL R5,R5

	# var _t39

	# _t39 = _t37 + _t38
	LOD R4,STATIC
	LOD R6,(R4+0)
	LOD R4,STATIC
	STO (R4+0),R5
    ADD R6,R5

	# var _t40

	# _t40 = _t39 + 14
	LOD R4,STATIC
	STO (R4+0),R6
    LOD R5,14
    ADD R6,R5

	# var _t41

	# _t41 = 3 * 54
    LOD R5,3
    LOD R5,54
    LOD R5,54
    MUL R5,R5

	# var _t42

	# _t42 = _t40 + _t41
	LOD R4,STATIC
	STO (R4+0),R6
	LOD R4,STATIC
	STO (R4+0),R5
    ADD R6,R5

	# var _t43

	# _t43 = _t42 + 4
	LOD R4,STATIC
	STO (R4+0),R6
    LOD R5,4
    ADD R6,R5

	# var _t44

	# _t44 = 0 * 1
    LOD R5,0
    LOD R5,1
    LOD R5,1
    MUL R5,R5

	# var _t45

	# _t45 = _t43 + _t44
	LOD R4,STATIC
	STO (R4+0),R6
	LOD R4,STATIC
	STO (R4+0),R5
    ADD R6,R5

	# var _t46

	# _t46 = *_t45
	LOD R4,STATIC
	STO (R4+0),R6
	LOD R4,STATIC
	LOD R5,(R4+0)
    LOD R5,(R6)

	# a = _t46
	LOD R4,STATIC
	STO (R4+0),R5
   STO (R2+16),R5

	# var _t47

	# _t47 = &c1
	LOD R4,STATIC
	LOD R5,(R4+0)
    LOD R5,R2
    LOD R5,24
    LOD R5,R5
    ADD R5,R5

	# var _t48

	# _t48 = _t47 + 14
	LOD R4,STATIC
	STO (R4+0),R5
    LOD R5,14
    LOD R5,14
    ADD R5,R5

	# var _t49

	# _t49 = 2 * 554
    LOD R5,2
    LOD R5,554
    LOD R5,554
    MUL R5,R5

	# var _t50

	# _t50 = _t48 + _t49
	LOD R4,STATIC
	LOD R6,(R4+0)
	LOD R4,STATIC
	STO (R4+0),R5
    ADD R6,R5

	# var _t51

	# _t51 = _t50 + 14
	LOD R4,STATIC
	STO (R4+0),R6
    LOD R5,14
    ADD R6,R5

	# var _t52

	# _t52 = 3 * 54
    LOD R5,3
    LOD R5,54
    LOD R5,54
    MUL R5,R5

	# var _t53

	# _t53 = _t51 + _t52
	LOD R4,STATIC
	STO (R4+0),R6
	LOD R4,STATIC
	STO (R4+0),R5
    ADD R6,R5

	# var _t54

	# _t54 = _t53 + 4
	LOD R4,STATIC
	STO (R4+0),R6
    LOD R5,4
    ADD R6,R5

	# var _t55

	# _t55 = 1 * 1
    LOD R5,1
    LOD R5,1
    LOD R5,1
    MUL R5,R5

	# var _t56

	# _t56 = _t54 + _t55
	LOD R4,STATIC
	STO (R4+0),R6
	LOD R4,STATIC
	STO (R4+0),R5
    ADD R6,R5

	# var _t57

	# _t57 = *_t56
	LOD R4,STATIC
	STO (R4+0),R6
	LOD R4,STATIC
	LOD R5,(R4+0)
    LOD R5,(R6)

	# b = _t57
	LOD R4,STATIC
	STO (R4+0),R5
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
