
# tac list

0x61594f409b50	label main
0x61594f409b90	begin
0x61594f4087f0	var i
0x61594f4088b0	var j
0x61594f408970	var k
0x61594f408a30	var l
0x61594f408af0	var a
0x61594f408bb0	var b
0x61594f408c70	var c
0x61594f408d30	var d
0x61594f408d90	input d
0x61594f408ea0	c = 'c'
0x61594f408fb0	b = 'b'
0x61594f409010	input a
0x61594f409280	ifz 0 goto L2
0x61594f409180	output L1
0x61594f409240	label L2
0x61594f4092e0	output a
0x61594f409340	output b
0x61594f4093a0	output c
0x61594f409400	output d
0x61594f409460	output L1
0x61594f409510	i = a
0x61594f4095c0	j = b
0x61594f409670	k = c
0x61594f409720	l = d
0x61594f4098d0	ifz 0 goto L3
0x61594f4097d0	output L1
0x61594f409890	label L3
0x61594f409930	output i
0x61594f409990	output j
0x61594f4099f0	output k
0x61594f409a50	output l
0x61594f409ab0	output L1
0x61594f409bd0	end

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
