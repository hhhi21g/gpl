
# tac list

0x57adc63d91e0	label main
0x57adc63d9220	begin
0x57adc63d7810	var i
0x57adc63d78e0	var j
0x57adc63d79b0	var k
0x57adc63d7a80	var l
0x57adc63d7b50	var a
0x57adc63d7c20	var b
0x57adc63d7cf0	var c
0x57adc63d7dc0	var d
0x57adc63d7e20	input d
0x57adc63d7f40	c = 'c'
0x57adc63d8060	b = 'b'
0x57adc63d80c0	input a
0x57adc63d8360	ifz 0 goto L2
0x57adc63d8250	output L1
0x57adc63d8320	label L2
0x57adc63d8800	output a
0x57adc63d8890	output b
0x57adc63d8920	output c
0x57adc63d89b0	output d
0x57adc63d8a10	output L1
0x57adc63d8ac0	i = a
0x57adc63d8b70	j = b
0x57adc63d8c20	k = c
0x57adc63d8cd0	l = d
0x57adc63d8e90	ifz 0 goto L3
0x57adc63d8d80	output L1
0x57adc63d8e50	label L3
0x57adc63d8f20	output i
0x57adc63d8fb0	output j
0x57adc63d9040	output k
0x57adc63d90d0	output l
0x57adc63d9130	output L1
0x57adc63d9260	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
var k
var l
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
i = a
j = b
k = c
l = d
ifz 0 goto L3
  succ: B5 B4 

[B4]
output L1
  succ: B5 

[B5]
label L3
output i
output j
output k
output l
output L1
end
  succ: 
