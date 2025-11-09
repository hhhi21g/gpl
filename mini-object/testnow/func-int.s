	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# var i

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
