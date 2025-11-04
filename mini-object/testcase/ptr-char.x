
# tac list

0x58233eec17f0	label main
0x58233eec1830	begin
0x58233eec07f0	var a
0x58233eec08b0	var pa
0x58233eec0970	var b
0x58233eec0a30	var c
0x58233eec0af0	var d
0x58233eec0bb0	var ptr
0x58233eec0c10	input d
0x58233eec0d20	c = 'c'
0x58233eec0e30	b = 'b'
0x58233eec0e90	input a
0x58233eec1100	ifz 0 goto L2
0x58233eec1000	output L1
0x58233eec10c0	label L2
0x58233eec1160	output a
0x58233eec11c0	output b
0x58233eec1220	output c
0x58233eec1280	output d
0x58233eec12e0	output L1
0x58233eec1360	pa = &a
0x58233eec1470	*pa = 'A'
0x58233eec14d0	output a
0x58233eec1580	ptr = pa
0x58233eec1690	*ptr = 'B'
0x58233eec16f0	output a
0x58233eec1750	output L1
0x58233eec1870	end
