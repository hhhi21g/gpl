
# tac list

0x5bcafa94d790	label main
0x5bcafa94d7d0	begin
0x5bcafa94c830	var a
0x5bcafa94c910	var b
0x5bcafa94c9f0	var c
0x5bcafa94cad0	var d
0x5bcafa94cb30	input d
0x5bcafa94cc60	c = 'c'
0x5bcafa94cd90	b = 'b'
0x5bcafa94cdf0	input a
0x5bcafa94d0c0	ifz 0 goto L2
0x5bcafa94cfa0	output L1
0x5bcafa94d080	label L2
0x5bcafa94d150	output a
0x5bcafa94d1e0	output b
0x5bcafa94d270	output c
0x5bcafa94d300	output d
0x5bcafa94d360	output L1
0x5bcafa94d560	var t0
0x5bcafa94d5a0	t0 = a + 1
0x5bcafa94d5e0	a = t0
0x5bcafa94d670	output a
0x5bcafa94d6d0	output L1
0x5bcafa94d810	end

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
