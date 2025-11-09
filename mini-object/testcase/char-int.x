
# tac list

0x58a2ff0e9b50	label main
0x58a2ff0e9b90	begin
0x58a2ff0e87f0	var i
0x58a2ff0e88b0	var j
0x58a2ff0e8970	var k
0x58a2ff0e8a30	var l
0x58a2ff0e8af0	var a
0x58a2ff0e8bb0	var b
0x58a2ff0e8c70	var c
0x58a2ff0e8d30	var d
0x58a2ff0e8d90	input d
0x58a2ff0e8ea0	c = 'c'
0x58a2ff0e8fb0	b = 'b'
0x58a2ff0e9010	input a
0x58a2ff0e9280	ifz 0 goto L2
0x58a2ff0e9180	output L1
0x58a2ff0e9240	label L2
0x58a2ff0e92e0	output a
0x58a2ff0e9340	output b
0x58a2ff0e93a0	output c
0x58a2ff0e9400	output d
0x58a2ff0e9460	output L1
0x58a2ff0e9510	i = a
0x58a2ff0e95c0	j = b
0x58a2ff0e9670	k = c
0x58a2ff0e9720	l = d
0x58a2ff0e98d0	ifz 0 goto L3
0x58a2ff0e97d0	output L1
0x58a2ff0e9890	label L3
0x58a2ff0e9930	output i
0x58a2ff0e9990	output j
0x58a2ff0e99f0	output k
0x58a2ff0e9a50	output l
0x58a2ff0e9ab0	output L1
0x58a2ff0e9bd0	end

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
