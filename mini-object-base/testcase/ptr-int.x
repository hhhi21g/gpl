
# tac list

0x57ce62475d60	label main
0x57ce62475da0	begin
0x57ce62474830	var a
0x57ce62474910	var pa
0x57ce624749f0	var b
0x57ce62474ad0	var c
0x57ce62474bb0	var d
0x57ce62474c90	var ptr
0x57ce62474cf0	input a
0x57ce62474ef0	var t0
0x57ce62474f30	t0 = a + 10
0x57ce62474f70	b = t0
0x57ce62475170	var t1
0x57ce624751b0	t1 = b - 20
0x57ce624751f0	c = t1
0x57ce624753f0	var t2
0x57ce62475430	t2 = c * 30
0x57ce62475470	d = t2
0x57ce62475500	output a
0x57ce62475590	output b
0x57ce62475620	output c
0x57ce624756b0	output d
0x57ce62475790	output L1
0x57ce62475810	pa = &a
0x57ce62475940	*pa = 111
0x57ce624759d0	output a
0x57ce62475a80	ptr = pa
0x57ce62475bb0	*ptr = 222
0x57ce62475c40	output a
0x57ce62475ca0	output L1
0x57ce62475de0	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var pa
var b
var c
var d
var ptr
input a
var t0
t0 = a + 10
b = t0
var t1
t1 = b - 20
c = t1
var t2
t2 = c * 30
d = t2
output a
output b
output c
output d
output L1
pa = &a
*pa = 111
output a
ptr = pa
*ptr = 222
output a
output L1
end
  succ: 
