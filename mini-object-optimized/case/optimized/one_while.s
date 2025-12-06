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

	# var temp

	# var temp2

	# temp = 56422
	LOD R5,56422
	STO (R2+12),R5

	# i = 0
	LOD R6,0
	STO (R2+8),R6

	# label L1
    STO (R2+12),R5
    STO (R2+8),R6
L1:

	# var t0

	# t0 = (i < 12)
	LOD R5,(R2+8)
    LOD R6,R5
	LOD R3,12
    SUB R6,R3
    TST R6
    JEZ L3
    JGZ L3

	# temp2 = 0
	LOD R6,0
	STO (R2+16),R6

	# var t1

	# t1 = (temp == 7340)
	LOD R7,(R2+12)
    LOD R8,R7
	LOD R3,7340
    SUB R8,R3
    TST R8
    JLZ L5
    JGZ L5

	# var t2

	# t2 = 50636 * i
	LOD R8,50636
    MUL R8,R5

	# var t3

	# t3 = temp - t2
    STO (R2+28),R8
    SUB R7,R8

	# temp2 = t3
	STO (R2+16),R7

	# output L4
	LOD R6,L4
    LOD R15,R6
    OTS

	# label L5
    STO (R2+16),R7
L5:

	# var t4

	# t4 = (temp == 28935)
	LOD R5,(R2+12)
    LOD R9,R5
	LOD R3,28935
    SUB R9,R3
    TST R9
    JLZ L7
    JGZ L7

	# var t5

	# t5 = 2027 * i
	LOD R6,2027
	LOD R7,(R2+8)
    MUL R6,R7

	# var t6

	# t6 = temp - t5
    STO (R2+40),R6
    SUB R5,R6

	# temp2 = t6
	STO (R2+16),R5

	# output L6
	LOD R8,L6
    LOD R15,R8
    OTS

	# label L7
    STO (R2+16),R5
L7:

	# var t7

	# t7 = (temp == 26028)
	LOD R5,(R2+12)
    LOD R10,R5
	LOD R3,26028
    SUB R10,R3
    TST R10
    JLZ L9
    JGZ L9

	# var t8

	# t8 = temp / 70
	LOD R6,70
    DIV R5,R6

	# var t9

	# t9 = t8 + 39976
    STO (R2+52),R5
	LOD R7,39976
    ADD R5,R7

	# temp2 = t9
	STO (R2+16),R5

	# output L8
	LOD R8,L8
    LOD R15,R8
    OTS

	# label L9
    STO (R2+16),R5
L9:

	# var t10

	# t10 = (temp == 56422)
	LOD R5,(R2+12)
    LOD R11,R5
	LOD R3,56422
    SUB R11,R3
    TST R11
    JLZ L11
    JGZ L11

	# var t11

	# t11 = temp / 39
	LOD R6,39
    DIV R5,R6

	# var t12

	# t12 = t11 + 6265
    STO (R2+64),R5
	LOD R7,6265
    ADD R5,R7

	# temp2 = t12
	STO (R2+16),R5

	# output L10
	LOD R8,L10
    LOD R15,R8
    OTS

	# label L11
    STO (R2+16),R5
L11:

	# var t13

	# t13 = (temp == 12188)
	LOD R5,(R2+12)
    LOD R12,R5
	LOD R3,12188
    SUB R12,R3
    TST R12
    JLZ L13
    JGZ L13

	# var t14

	# t14 = 13773 * i
	LOD R6,13773
	LOD R7,(R2+8)
    MUL R6,R7

	# var t15

	# t15 = 27266 - t14
	LOD R8,27266
    STO (R2+76),R6
    SUB R8,R6

	# temp2 = t15
	STO (R2+16),R8

	# output L12
	LOD R9,L12
    LOD R15,R9
    OTS

	# label L13
    STO (R2+16),R8
L13:

	# var t16

	# t16 = (temp == 10943)
	LOD R5,(R2+12)
    LOD R13,R5
	LOD R3,10943
    SUB R13,R3
    TST R13
    JLZ L15
    JGZ L15

	# var t17

	# t17 = 24538 * i
	LOD R6,24538
	LOD R7,(R2+8)
    MUL R6,R7

	# var t18

	# t18 = temp + t17
    STO (R2+88),R6
    ADD R5,R6

	# temp2 = t18
	STO (R2+16),R5

	# output L14
	LOD R8,L14
    LOD R15,R8
    OTS

	# label L15
    STO (R2+16),R5
L15:

	# var t19

	# t19 = (temp == 21140)
	LOD R5,(R2+12)
    LOD R14,R5
	LOD R3,21140
    SUB R14,R3
    TST R14
    JLZ L17
    JGZ L17

	# var t20

	# t20 = temp / 18
	LOD R6,18
    DIV R5,R6

	# var t21

	# t21 = t20 + 3561
    STO (R2+100),R5
	LOD R7,3561
    ADD R5,R7

	# temp2 = t21
	STO (R2+16),R5

	# output L16
	LOD R8,L16
    LOD R15,R8
    OTS

	# label L17
    STO (R2+16),R5
L17:

	# var t22

	# t22 = (temp == 17810)
	LOD R5,(R2+12)
    LOD R15,R5
	LOD R3,17810
    SUB R15,R3
    TST R15
    JLZ L19
    JGZ L19

	# var t23

	# t23 = 62623 * i
	LOD R6,62623
	LOD R7,(R2+8)
    MUL R6,R7

	# var t24

	# t24 = 16198 - t23
	LOD R8,16198
    STO (R2+112),R6
    SUB R8,R6

	# temp2 = t24
	STO (R2+16),R8

	# output L18
	LOD R9,L18
    LOD R15,R9
    OTS

	# label L19
    STO (R2+16),R8
L19:

	# var t25

	# t25 = (temp == 7711)
	LOD R5,(R2+12)
    LOD R6,R5
	LOD R3,7711
    SUB R6,R3
    TST R6
    JLZ L21
    JGZ L21

	# var t26

	# t26 = 44131 * i
	LOD R6,44131
	LOD R7,(R2+8)
    MUL R6,R7

	# var t27

	# t27 = temp + t26
    STO (R2+124),R6
    ADD R5,R6

	# temp2 = t27
	STO (R2+16),R5

	# output L20
	LOD R8,L20
    LOD R15,R8
    OTS

	# label L21
    STO (R2+16),R5
L21:

	# var t28

	# t28 = (temp == 13607)
	LOD R5,(R2+12)
    LOD R7,R5
	LOD R3,13607
    SUB R7,R3
    TST R7
    JLZ L23
    JGZ L23

	# var t29

	# t29 = temp / 47
	LOD R6,47
    DIV R5,R6

	# var t30

	# t30 = t29 + 9692
    STO (R2+136),R5
	LOD R7,9692
    ADD R5,R7

	# temp2 = t30
	STO (R2+16),R5

	# output L22
	LOD R8,L22
    LOD R15,R8
    OTS

	# label L23
    STO (R2+16),R5
L23:

	# var t31

	# t31 = (temp == 48141)
	LOD R5,(R2+12)
    LOD R8,R5
	LOD R3,48141
    SUB R8,R3
    TST R8
    JLZ L25
    JGZ L25

	# var t32

	# t32 = 55016 * i
	LOD R6,55016
	LOD R7,(R2+8)
    MUL R6,R7

	# var t33

	# t33 = temp + t32
    STO (R2+148),R6
    ADD R5,R6

	# temp2 = t33
	STO (R2+16),R5

	# output L24
	LOD R8,L24
    LOD R15,R8
    OTS

	# label L25
    STO (R2+16),R5
L25:

	# var t34

	# t34 = (temp == 11697)
	LOD R5,(R2+12)
    LOD R9,R5
	LOD R3,11697
    SUB R9,R3
    TST R9
    JLZ L27
    JGZ L27

	# var t35

	# t35 = 62840 * i
	LOD R6,62840
	LOD R7,(R2+8)
    MUL R6,R7

	# var t36

	# t36 = temp + t35
    STO (R2+160),R6
    ADD R5,R6

	# temp2 = t36
	STO (R2+16),R5

	# output L26
	LOD R8,L26
    LOD R15,R8
    OTS

	# label L27
    STO (R2+16),R5
L27:

	# var t37

	# t37 = (temp == 35028)
	LOD R5,(R2+12)
    LOD R10,R5
	LOD R3,35028
    SUB R10,R3
    TST R10
    JLZ L29
    JGZ L29

	# var t38

	# t38 = temp / 178
	LOD R6,178
    DIV R5,R6

	# var t39

	# t39 = t38 + 18141
    STO (R2+172),R5
	LOD R7,18141
    ADD R5,R7

	# temp2 = t39
	STO (R2+16),R5

	# output L28
	LOD R8,L28
    LOD R15,R8
    OTS

	# label L29
    STO (R2+16),R5
L29:

	# var t40

	# t40 = (temp == 24485)
	LOD R5,(R2+12)
    LOD R11,R5
	LOD R3,24485
    SUB R11,R3
    TST R11
    JLZ L31
    JGZ L31

	# var t41

	# t41 = 48033 * i
	LOD R6,48033
	LOD R7,(R2+8)
    MUL R6,R7

	# var t42

	# t42 = temp - t41
    STO (R2+184),R6
    SUB R5,R6

	# temp2 = t42
	STO (R2+16),R5

	# output L30
	LOD R8,L30
    LOD R15,R8
    OTS

	# label L31
    STO (R2+16),R5
L31:

	# var t43

	# t43 = (temp == 9981)
	LOD R5,(R2+12)
    LOD R12,R5
	LOD R3,9981
    SUB R12,R3
    TST R12
    JLZ L32
    JGZ L32

	# var t44

	# t44 = 161 * i
	LOD R6,161
	LOD R7,(R2+8)
    MUL R6,R7

	# var t45

	# t45 = temp - t44
    STO (R2+196),R6
    SUB R5,R6

	# temp2 = t45
	STO (R2+16),R5

	# output L24
	LOD R8,L24
    LOD R15,R8
    OTS

	# label L32
    STO (R2+16),R5
L32:

	# var t46

	# t46 = (temp == 39373)
	LOD R5,(R2+12)
    LOD R13,R5
	LOD R3,39373
    SUB R13,R3
    TST R13
    JLZ L34
    JGZ L34

	# var t47

	# t47 = 6776 * i
	LOD R6,6776
	LOD R7,(R2+8)
    MUL R6,R7

	# var t48

	# t48 = temp - t47
    STO (R2+208),R6
    SUB R5,R6

	# temp2 = t48
	STO (R2+16),R5

	# output L33
	LOD R8,L33
    LOD R15,R8
    OTS

	# label L34
    STO (R2+16),R5
L34:

	# var t49

	# t49 = (temp == 57509)
	LOD R5,(R2+12)
    LOD R14,R5
	LOD R3,57509
    SUB R14,R3
    TST R14
    JLZ L36
    JGZ L36

	# var t50

	# t50 = 17159 * i
	LOD R6,17159
	LOD R7,(R2+8)
    MUL R6,R7

	# var t51

	# t51 = temp - t50
    STO (R2+220),R6
    SUB R5,R6

	# temp2 = t51
	STO (R2+16),R5

	# output L35
	LOD R8,L35
    LOD R15,R8
    OTS

	# label L36
    STO (R2+16),R5
L36:

	# var t52

	# t52 = (temp == 51842)
	LOD R5,(R2+12)
    LOD R15,R5
	LOD R3,51842
    SUB R15,R3
    TST R15
    JLZ L38
    JGZ L38

	# var t53

	# t53 = temp / 102
	LOD R6,102
    DIV R5,R6

	# var t54

	# t54 = t53 + 57001
    STO (R2+232),R5
	LOD R7,57001
    ADD R5,R7

	# temp2 = t54
	STO (R2+16),R5

	# output L37
	LOD R8,L37
    LOD R15,R8
    OTS

	# label L38
    STO (R2+16),R5
L38:

	# var t55

	# t55 = (temp == 40347)
	LOD R5,(R2+12)
    LOD R6,R5
	LOD R3,40347
    SUB R6,R3
    TST R6
    JLZ L40
    JGZ L40

	# var t56

	# t56 = 2568 * i
	LOD R6,2568
	LOD R7,(R2+8)
    MUL R6,R7

	# var t57

	# t57 = 54615 - t56
	LOD R8,54615
    STO (R2+244),R6
    SUB R8,R6

	# temp2 = t57
	STO (R2+16),R8

	# output L39
	LOD R9,L39
    LOD R15,R9
    OTS

	# label L40
    STO (R2+16),R8
L40:

	# var t58

	# t58 = (temp == 8854)
	LOD R5,(R2+12)
    LOD R7,R5
	LOD R3,8854
    SUB R7,R3
    TST R7
    JLZ L42
    JGZ L42

	# var t59

	# t59 = temp / 50
	LOD R6,50
    DIV R5,R6

	# var t60

	# t60 = t59 + 25851
    STO (R2+256),R5
	LOD R7,25851
    ADD R5,R7

	# temp2 = t60
	STO (R2+16),R5

	# output L41
	LOD R8,L41
    LOD R15,R8
    OTS

	# label L42
    STO (R2+16),R5
L42:

	# var t61

	# t61 = (temp == 10116)
	LOD R5,(R2+12)
    LOD R8,R5
	LOD R3,10116
    SUB R8,R3
    TST R8
    JLZ L44
    JGZ L44

	# var t62

	# t62 = temp / 53
	LOD R6,53
    DIV R5,R6

	# var t63

	# t63 = t62 + 13417
    STO (R2+268),R5
	LOD R7,13417
    ADD R5,R7

	# temp2 = t63
	STO (R2+16),R5

	# output L43
	LOD R8,L43
    LOD R15,R8
    OTS

	# label L44
    STO (R2+16),R5
L44:

	# var t64

	# t64 = (temp == 20947)
	LOD R5,(R2+12)
    LOD R9,R5
	LOD R3,20947
    SUB R9,R3
    TST R9
    JLZ L46
    JGZ L46

	# var t65

	# t65 = 43689 * i
	LOD R6,43689
	LOD R7,(R2+8)
    MUL R6,R7

	# var t66

	# t66 = 64044 - t65
	LOD R8,64044
    STO (R2+280),R6
    SUB R8,R6

	# temp2 = t66
	STO (R2+16),R8

	# output L45
	LOD R9,L45
    LOD R15,R9
    OTS

	# label L46
    STO (R2+16),R8
L46:

	# var t67

	# t67 = (temp == 21250)
	LOD R5,(R2+12)
    LOD R10,R5
	LOD R3,21250
    SUB R10,R3
    TST R10
    JLZ L48
    JGZ L48

	# var t68

	# t68 = 29723 * i
	LOD R6,29723
	LOD R7,(R2+8)
    MUL R6,R7

	# var t69

	# t69 = temp - t68
    STO (R2+292),R6
    SUB R5,R6

	# temp2 = t69
	STO (R2+16),R5

	# output L47
	LOD R8,L47
    LOD R15,R8
    OTS

	# label L48
    STO (R2+16),R5
L48:

	# var t70

	# t70 = (temp == 16416)
	LOD R5,(R2+12)
    LOD R11,R5
	LOD R3,16416
    SUB R11,R3
    TST R11
    JLZ L50
    JGZ L50

	# var t71

	# t71 = 41523 * i
	LOD R6,41523
	LOD R7,(R2+8)
    MUL R6,R7

	# var t72

	# t72 = temp - t71
    STO (R2+304),R6
    SUB R5,R6

	# temp2 = t72
	STO (R2+16),R5

	# output L49
	LOD R8,L49
    LOD R15,R8
    OTS

	# label L50
    STO (R2+16),R5
L50:

	# var t73

	# t73 = (temp == 13204)
	LOD R5,(R2+12)
    LOD R12,R5
	LOD R3,13204
    SUB R12,R3
    TST R12
    JLZ L52
    JGZ L52

	# var t74

	# t74 = temp / 193
	LOD R6,193
    DIV R5,R6

	# var t75

	# t75 = t74 + 53788
    STO (R2+316),R5
	LOD R7,53788
    ADD R5,R7

	# temp2 = t75
	STO (R2+16),R5

	# output L51
	LOD R8,L51
    LOD R15,R8
    OTS

	# label L52
    STO (R2+16),R5
L52:

	# var t76

	# t76 = (temp == 47597)
	LOD R5,(R2+12)
    LOD R13,R5
	LOD R3,47597
    SUB R13,R3
    TST R13
    JLZ L54
    JGZ L54

	# var t77

	# t77 = 59581 * i
	LOD R6,59581
	LOD R7,(R2+8)
    MUL R6,R7

	# var t78

	# t78 = temp + t77
    STO (R2+328),R6
    ADD R5,R6

	# temp2 = t78
	STO (R2+16),R5

	# output L53
	LOD R8,L53
    LOD R15,R8
    OTS

	# label L54
    STO (R2+16),R5
L54:

	# var t79

	# t79 = (temp == 45195)
	LOD R5,(R2+12)
    LOD R14,R5
	LOD R3,45195
    SUB R14,R3
    TST R14
    JLZ L56
    JGZ L56

	# var t80

	# t80 = 22361 * i
	LOD R6,22361
	LOD R7,(R2+8)
    MUL R6,R7

	# var t81

	# t81 = temp - t80
    STO (R2+340),R6
    SUB R5,R6

	# temp2 = t81
	STO (R2+16),R5

	# output L55
	LOD R8,L55
    LOD R15,R8
    OTS

	# label L56
    STO (R2+16),R5
L56:

	# var t82

	# t82 = (temp == 6032)
	LOD R5,(R2+12)
    LOD R15,R5
	LOD R3,6032
    SUB R15,R3
    TST R15
    JLZ L57
    JGZ L57

	# var t83

	# t83 = 1021 * i
	LOD R6,1021
	LOD R7,(R2+8)
    MUL R6,R7

	# var t84

	# t84 = temp + t83
    STO (R2+352),R6
    ADD R5,R6

	# temp2 = t84
	STO (R2+16),R5

	# output L24
	LOD R8,L24
    LOD R15,R8
    OTS

	# label L57
    STO (R2+16),R5
L57:

	# var t85

	# t85 = (temp == 17276)
	LOD R5,(R2+12)
    LOD R6,R5
	LOD R3,17276
    SUB R6,R3
    TST R6
    JLZ L59
    JGZ L59

	# var t86

	# t86 = 21834 * i
	LOD R6,21834
	LOD R7,(R2+8)
    MUL R6,R7

	# var t87

	# t87 = 18047 - t86
	LOD R8,18047
    STO (R2+364),R6
    SUB R8,R6

	# temp2 = t87
	STO (R2+16),R8

	# output L58
	LOD R9,L58
    LOD R15,R9
    OTS

	# label L59
    STO (R2+16),R8
L59:

	# var t88

	# t88 = (temp == 34923)
	LOD R5,(R2+12)
    LOD R7,R5
	LOD R3,34923
    SUB R7,R3
    TST R7
    JLZ L61
    JGZ L61

	# var t89

	# t89 = 32482 * i
	LOD R6,32482
	LOD R7,(R2+8)
    MUL R6,R7

	# var t90

	# t90 = temp - t89
    STO (R2+376),R6
    SUB R5,R6

	# temp2 = t90
	STO (R2+16),R5

	# output L60
	LOD R8,L60
    LOD R15,R8
    OTS

	# label L61
    STO (R2+16),R5
L61:

	# temp = temp2
	LOD R5,(R2+16)
	STO (R2+12),R5

	# var t91

	# t91 = i + 1
	LOD R6,(R2+8)
	LOD R7,1
    ADD R6,R7

	# i = t91
	STO (R2+8),R6

	# label L2
    STO (R2+12),R5
    STO (R2+8),R6
L2:

	# goto L1
	JMP L1

	# label L3
L3:

	# output L62
	LOD R5,L62
    LOD R15,R5
    OTS

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L62:
	DBS 10,0
L60:
	DBS 103,0
L58:
	DBS 118,0
L55:
	DBS 106,0
L53:
	DBS 119,0
L51:
	DBS 112,0
L49:
	DBS 108,0
L47:
	DBS 116,0
L45:
	DBS 114,0
L43:
	DBS 105,0
L41:
	DBS 102,0
L39:
	DBS 110,0
L37:
	DBS 122,0
L35:
	DBS 101,0
L33:
	DBS 121,0
L30:
	DBS 99,0
L28:
	DBS 111,0
L26:
	DBS 120,0
L24:
	DBS 32,0
L22:
	DBS 115,0
L20:
	DBS 97,0
L18:
	DBS 113,0
L16:
	DBS 98,0
L14:
	DBS 100,0
L12:
	DBS 104,0
L10:
	DBS 109,0
L8:
	DBS 117,0
L6:
	DBS 33,0
L4:
	DBS 107,0
STATIC:
	DBN 0,0
STACK:
