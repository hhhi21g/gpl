
# tac list

0x5c2043da6500	label main
0x5c2043da6540	begin
0x5c2043da57f0	var a
0x5c2043da58b0	var b
0x5c2043da5970	var c
0x5c2043da5a30	var d
0x5c2043da5a90	input d
0x5c2043da5ba0	c = 'c'
0x5c2043da5cb0	b = 'b'
0x5c2043da5d10	input a
0x5c2043da5f80	ifz 0 goto L2
0x5c2043da5e80	output L1
0x5c2043da5f40	label L2
0x5c2043da5fe0	output a
0x5c2043da6040	output b
0x5c2043da60a0	output c
0x5c2043da6100	output d
0x5c2043da6160	output L1
0x5c2043da6320	var t0
0x5c2043da6360	t0 = a + 1
0x5c2043da63a0	a = t0
0x5c2043da6400	output a
0x5c2043da6460	output L1
0x5c2043da6580	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var b
var c
var d
input d
c = 'c'
b = 'b'
input a
ifz 0 goto L2
  succ: B3 B2 

[B2]
output L1
  succ: B3 

[B3]
label L2
output a
output b
output c
output d
output L1
var t0
t0 = a + 1
a = t0
output a
output L1
end
  succ: 
