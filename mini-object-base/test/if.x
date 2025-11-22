
# tac list

0x5db4c7a68210	label main
0x5db4c7a68250	begin
0x5db4c7a677d0	var i
0x5db4c7a67870	var j
0x5db4c7a67910	var k
0x5db4c7a67970	input i
0x5db4c7a679d0	input j
0x5db4c7a67b10	var t0
0x5db4c7a67b50	t0 = (i == j)
0x5db4c7a67e50	ifz t0 goto L3
0x5db4c7a67bf0	output L1
0x5db4c7a67e90	goto L4
0x5db4c7a67d50	label L3
0x5db4c7a67c90	output L2
0x5db4c7a67e10	label L4
0x5db4c7a67ff0	var t1
0x5db4c7a68030	t1 = i + j
0x5db4c7a68070	k = t1
0x5db4c7a680d0	output k
0x5db4c7a68170	output L5
0x5db4c7a68290	end
