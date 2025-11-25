
# tac list

0x59396df1d790	label main
0x59396df1d7d0	begin
0x59396df1c830	var a
0x59396df1c910	var b
0x59396df1c9f0	var c
0x59396df1cad0	var d
0x59396df1cb30	input d
0x59396df1cc60	c = 'c'
0x59396df1cd90	b = 'b'
0x59396df1cdf0	input a
0x59396df1d0c0	ifz 0 goto L2
0x59396df1cfa0	output L1
0x59396df1d080	label L2
0x59396df1d150	output a
0x59396df1d1e0	output b
0x59396df1d270	output c
0x59396df1d300	output d
0x59396df1d360	output L1
0x59396df1d560	var t0
0x59396df1d5a0	t0 = a + 1
0x59396df1d5e0	a = t0
0x59396df1d670	output a
0x59396df1d6d0	output L1
0x59396df1d810	end

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
