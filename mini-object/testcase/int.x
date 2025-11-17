
# tac list

0x5f12d1ca2690	label main
0x5f12d1ca26d0	begin
0x5f12d1ca1830	var a
0x5f12d1ca1910	var b
0x5f12d1ca19f0	var c
0x5f12d1ca1ad0	var d
0x5f12d1ca1b30	input a
0x5f12d1ca1d30	var t0
0x5f12d1ca1d70	t0 = a + 10
0x5f12d1ca1db0	b = t0
0x5f12d1ca1fb0	var t1
0x5f12d1ca1ff0	t1 = b - 20
0x5f12d1ca2030	c = t1
0x5f12d1ca2230	var t2
0x5f12d1ca2270	t2 = c * 30
0x5f12d1ca22b0	d = t2
0x5f12d1ca2340	output a
0x5f12d1ca23d0	output b
0x5f12d1ca2460	output c
0x5f12d1ca24f0	output d
0x5f12d1ca25d0	output L1
0x5f12d1ca2710	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var b
var c
var d
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
end
  succ: 
