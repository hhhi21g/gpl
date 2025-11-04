
# tac list

0x583e999f17f0	label main
0x583e999f1830	begin
0x583e999f07f0	var a
0x583e999f08b0	var pa
0x583e999f0970	var b
0x583e999f0a30	var c
0x583e999f0af0	var d
0x583e999f0bb0	var ptr
0x583e999f0c10	input d
0x583e999f0d20	c = 'c'
0x583e999f0e30	b = 'b'
0x583e999f0e90	input a
0x583e999f1100	ifz 0 goto L2
0x583e999f1000	output L1
0x583e999f10c0	label L2
0x583e999f1160	output a
0x583e999f11c0	output b
0x583e999f1220	output c
0x583e999f1280	output d
0x583e999f12e0	output L1
0x583e999f1360	pa = &a
0x583e999f1470	*pa = 'A'
0x583e999f14d0	output a
0x583e999f1580	ptr = pa
0x583e999f1690	*ptr = 'B'
0x583e999f16f0	output a
0x583e999f1750	output L1
0x583e999f1870	end
