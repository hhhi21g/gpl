
# tac list

0x626ce720e060	label main
0x626ce720e0a0	begin
0x626ce720c810	var a
0x626ce720c8e0	var pa
0x626ce720c9b0	var b
0x626ce720ca80	var c
0x626ce720cb50	var d
0x626ce720cc20	var ptr
0x626ce720cc80	input a
0x626ce720d270	var t0
0x626ce720d2b0	t0 = a + 10
0x626ce720d2f0	b = t0
0x626ce720d4d0	var t1
0x626ce720d510	t1 = b - 20
0x626ce720d550	c = t1
0x626ce720d730	var t2
0x626ce720d770	t2 = c * 30
0x626ce720d7b0	d = t2
0x626ce720d840	output a
0x626ce720d8d0	output b
0x626ce720d960	output c
0x626ce720d9f0	output d
0x626ce720dac0	output L1
0x626ce720db40	pa = &a
0x626ce720dc60	*pa = 111
0x626ce720dcf0	output a
0x626ce720dda0	ptr = pa
0x626ce720dec0	*ptr = 222
0x626ce720df50	output a
0x626ce720dfb0	output L1
0x626ce720e0e0	end

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
