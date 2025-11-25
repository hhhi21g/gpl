
# tac list

0x5ac7f8f00ed0	label main
0x5ac7f8f00f10	begin
0x5ac7f8eff830	var i
0x5ac7f8eff910	var j
0x5ac7f8eff9f0	var k
0x5ac7f8effad0	var l
0x5ac7f8effbb0	var a
0x5ac7f8effc90	var b
0x5ac7f8effd70	var c
0x5ac7f8effe50	var d
0x5ac7f8effeb0	input d
0x5ac7f8efffe0	c = 'c'
0x5ac7f8f00110	b = 'b'
0x5ac7f8f00170	input a
0x5ac7f8f00440	ifz 0 goto L2
0x5ac7f8f00320	output L1
0x5ac7f8f00400	label L2
0x5ac7f8f004d0	output a
0x5ac7f8f00560	output b
0x5ac7f8f005f0	output c
0x5ac7f8f00680	output d
0x5ac7f8f006e0	output L1
0x5ac7f8f00790	i = a
0x5ac7f8f00840	j = b
0x5ac7f8f008f0	k = c
0x5ac7f8f009a0	l = d
0x5ac7f8f00b70	ifz 0 goto L3
0x5ac7f8f00a50	output L1
0x5ac7f8f00b30	label L3
0x5ac7f8f00c00	output i
0x5ac7f8f00c90	output j
0x5ac7f8f00d20	output k
0x5ac7f8f00db0	output l
0x5ac7f8f00e10	output L1
0x5ac7f8f00f50	end

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
