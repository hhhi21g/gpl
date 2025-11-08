
# tac list

0x646b60df5500	label main
0x646b60df5540	begin
0x646b60df47f0	var a
0x646b60df48b0	var b
0x646b60df4970	var c
0x646b60df4a30	var d
0x646b60df4a90	input d
0x646b60df4ba0	c = 'c'
0x646b60df4cb0	b = 'b'
0x646b60df4d10	input a
0x646b60df4f80	ifz 0 goto L2
0x646b60df4e80	output L1
0x646b60df4f40	label L2
0x646b60df4fe0	output a
0x646b60df5040	output b
0x646b60df50a0	output c
0x646b60df5100	output d
0x646b60df5160	output L1
0x646b60df5320	var t0
0x646b60df5360	t0 = a + 1
0x646b60df53a0	a = t0
0x646b60df5400	output a
0x646b60df5460	output L1
0x646b60df5580	end

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
