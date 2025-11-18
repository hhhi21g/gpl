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

	# a = 1
	LOD R5,1
	STO (R2+8),R5

	# b = 2
	LOD R6,2
	STO (R2+12),R6

	# var t0

	# t0 = (a > b)
    STO (R2+8),R5
    STO (R2+12),R6
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JGZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t0 goto L1
    STO (R2+20),R5
	TST R5
	JEZ L1

	# var t1

	# t1 = a + 1
	LOD R7,(R2+8)
    LOD R5,1
    ADD R7,R5

	# c = t1
	STO (R2+16),R7

	# goto L2
    STO (R2+24),R7
	JMP L2

	# label L1
L1:

	# var t2

	# t2 = b + 1
	LOD R5,(R2+12)
    LOD R6,1
    ADD R5,R6

	# c = t2
	STO (R2+16),R5

	# label L2
    STO (R2+28),R5
L2:

	# var t3

	# t3 = c + 3
	LOD R5,(R2+16)
    LOD R6,3
    ADD R5,R6

	# a = t3
	STO (R2+8),R5

	# end
    STO (R2+32),R5
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
STATIC:
	DBN 0,0
STACK:
