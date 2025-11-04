
# tac list

0x5bd1cd94e450	label main
0x5bd1cd94e490	begin
0x5bd1cd94d7f0	var a
0x5bd1cd94d8b0	var pa
0x5bd1cd94d970	var b
0x5bd1cd94da30	var i
0x5bd1cd94daf0	var pi
0x5bd1cd94dbb0	var j
0x5bd1cd94dc10	input a
0x5bd1cd94dc70	input i
0x5bd1cd94df00	ifz 0 goto L2
0x5bd1cd94dde0	output L1
0x5bd1cd94dec0	label L2
0x5bd1cd94df60	pa = &a
0x5bd1cd94dfe0	pi = &i
0x5bd1cd94e060	b = *pa
0x5bd1cd94e0e0	j = *pi
0x5bd1cd94e290	ifz 0 goto L3
0x5bd1cd94e190	output L1
0x5bd1cd94e250	label L3
0x5bd1cd94e2f0	output b
0x5bd1cd94e350	output j
0x5bd1cd94e3b0	output L1
0x5bd1cd94e4d0	end
