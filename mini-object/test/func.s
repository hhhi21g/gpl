	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# var i

	# label main
main:

	# begin

	# var a

	# var b

	# var c

	# input a
	LOD R5,(R2+8)
	ITI
	LOD R5,R15

	# input b
	LOD R6,(R2+12)
	ITI
	LOD R6,R15

	# var t0

	# actual b
	STO (R2+12),R6
	STO (R2+24),R6

	# actual a
	STO (R2+8),R5
	STO (R2+28),R5

	# t0 = call max
	STO (R2+32),R2
	LOD R4,R1+32
	STO (R2+36),R4
	LOD R2,R2+32
	JMP max
	LOD R5,(R2+20)
	LOD R5,R4

	# c = t0
	STO (R2+20),R5

	# output c
	STO (R2+16),R5
	LOD R15,R5
	OTI

	# output L1
	LOD R6,L1
	LOD R15,R6
	OTS

	# output i
	LOD R4,STATIC
	LOD R7,(R4+0)
	LOD R15,R7
	OTI

	# output L2
	LOD R8,L2
	LOD R15,R8
	OTS

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# label max
max:

	# begin

	# formal x

	# formal y

	# var t1

	# t1 = (x > y)
	LOD R5,(R2-4)
	LOD R6,(R2-8)
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JGZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# ifz t1 goto L3
	STO (R2+8),R5
	TST R5
	JEZ L3

	# i = x
	LOD R7,(R2-4)

	# goto L4
	LOD R4,STATIC
	STO (R4+0),R7
	JMP L4

	# label L3
L3:

	# i = y
	LOD R5,(R2-8)

	# label L4
	LOD R4,STATIC
	STO (R4+0),R5
L4:

	# return i
	LOD R4,STATIC
	LOD R4,(R4+0)
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# tail
EXIT:
	END
L2:
	DBS 10,0
L1:
	DBS 32,0
STATIC:
	DBN 0,4
STACK:
