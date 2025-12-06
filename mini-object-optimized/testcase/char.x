
# tac list

0x5922898c0790	label main
0x5922898c07d0	begin
0x5922898bf830	var a
0x5922898bf910	var b
0x5922898bf9f0	var c
0x5922898bfad0	var d
0x5922898bfb30	input d
0x5922898bfc60	c = 'c'
0x5922898bfd90	b = 'b'
0x5922898bfdf0	input a
0x5922898c00c0	ifz 0 goto L2
0x5922898bffa0	output L1
0x5922898c0080	label L2
0x5922898c0150	output a
0x5922898c01e0	output b
0x5922898c0270	output c
0x5922898c0300	output d
0x5922898c0360	output L1
0x5922898c0560	var t0
0x5922898c05a0	t0 = a + 1
0x5922898c05e0	a = t0
0x5922898c0670	output a
0x5922898c06d0	output L1
0x5922898c0810	end

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
