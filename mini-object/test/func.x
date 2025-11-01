
# tac list

0x597b1cc07790	var i
0x597b1cc080a0	label main
0x597b1cc080e0	begin
0x597b1cc078b0	var a
0x597b1cc07970	var b
0x597b1cc07a30	var c
0x597b1cc07a90	input a
0x597b1cc07af0	input b
0x597b1cc07c70	var t0
0x597b1cc07cb0	actual b
0x597b1cc07cf0	actual a
0x597b1cc07d50	t0 = call max
0x597b1cc07dc0	c = t0
0x597b1cc07e20	output c
0x597b1cc07ee0	output L1
0x597b1cc07f40	output i
0x597b1cc08000	output L2
0x597b1cc08120	end
0x597b1cc088d0	label max
0x597b1cc08910	begin
0x597b1cc08220	formal x
0x597b1cc082c0	formal y
0x597b1cc08400	var t1
0x597b1cc08440	t1 = (x > y)
0x597b1cc08760	ifz t1 goto L3
0x597b1cc084f0	i = x
0x597b1cc087a0	goto L4
0x597b1cc08660	label L3
0x597b1cc085a0	i = y
0x597b1cc08720	label L4
0x597b1cc08830	return i
0x597b1cc08950	end
