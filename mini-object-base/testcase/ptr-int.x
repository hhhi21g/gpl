
# tac list

0x5e6e947d9d60	label main
0x5e6e947d9da0	begin
0x5e6e947d8830	var a
0x5e6e947d8910	var pa
0x5e6e947d89f0	var b
0x5e6e947d8ad0	var c
0x5e6e947d8bb0	var d
0x5e6e947d8c90	var ptr
0x5e6e947d8cf0	input a
0x5e6e947d8ef0	var t0
0x5e6e947d8f30	t0 = a + 10
0x5e6e947d8f70	b = t0
0x5e6e947d9170	var t1
0x5e6e947d91b0	t1 = b - 20
0x5e6e947d91f0	c = t1
0x5e6e947d93f0	var t2
0x5e6e947d9430	t2 = c * 30
0x5e6e947d9470	d = t2
0x5e6e947d9500	output a
0x5e6e947d9590	output b
0x5e6e947d9620	output c
0x5e6e947d96b0	output d
0x5e6e947d9790	output L1
0x5e6e947d9810	pa = &a
0x5e6e947d9940	*pa = 111
0x5e6e947d99d0	output a
0x5e6e947d9a80	ptr = pa
0x5e6e947d9bb0	*ptr = 222
0x5e6e947d9c40	output a
0x5e6e947d9ca0	output L1
0x5e6e947d9de0	end

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
