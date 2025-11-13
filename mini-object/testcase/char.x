
# tac list

0x5a1c44e0bad0	label main
0x5a1c44e0bb10	begin
0x5a1c44e0a810	var a
0x5a1c44e0a8e0	var b
0x5a1c44e0a9b0	var c
0x5a1c44e0aa80	var d
0x5a1c44e0aae0	input d
0x5a1c44e0ac00	c = 'c'
0x5a1c44e0ad20	b = 'b'
0x5a1c44e0ad80	input a
0x5a1c44e0b020	ifz 0 goto L2
0x5a1c44e0af10	output L1
0x5a1c44e0afe0	label L2
0x5a1c44e0b4c0	output a
0x5a1c44e0b550	output b
0x5a1c44e0b5e0	output c
0x5a1c44e0b670	output d
0x5a1c44e0b6d0	output L1
0x5a1c44e0b8b0	var t0
0x5a1c44e0b8f0	t0 = a + 1
0x5a1c44e0b930	a = t0
0x5a1c44e0b9c0	output a
0x5a1c44e0ba20	output L1
0x5a1c44e0bb50	end

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
