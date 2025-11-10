
# tac list

0x59c0f06515c0	label main
0x59c0f0651600	begin
0x59c0f064f810	var i
0x59c0f064f8e0	var j
0x59c0f064fb00	vararray arr1[1D]
0x59c0f064fd70	vararray arr2[2D]
0x59c0f0650030	vararray arr3[3D]
0x59c0f0650090	input i
0x59c0f06502d0	arr1[24] = i
0x59c0f0650570	var t0
0x59c0f06505b0	t0 = arr1[24]
0x59c0f06506e0	var t1
0x59c0f0650720	t1 = t0 + 6
0x59c0f0650800	arr2[504] = t1
0x59c0f0650ba0	var t2
0x59c0f0650be0	t2 = arr2[504]
0x59c0f0650d10	var t3
0x59c0f0650d50	t3 = t2 + 6
0x59c0f0650e30	arr3[15144] = t3
0x59c0f06510f0	ifz 0 goto L2
0x59c0f0650fc0	output L1
0x59c0f06510b0	label L2
0x59c0f0651370	var t4
0x59c0f06513b0	t4 = arr3[15144]
0x59c0f0651420	j = t4
0x59c0f06514b0	output j
0x59c0f0651510	output L1
0x59c0f0651640	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
vararray arr1[1D]
vararray arr2[2D]
vararray arr3[3D]
input i
arr1[24] = i
var t0
t0 = arr1[24]
var t1
t1 = t0 + 6
arr2[504] = t1
var t2
t2 = arr2[504]
var t3
t3 = t2 + 6
arr3[15144] = t3
ifz 0 goto L2
  succ: B3 B2 

[B2]
output L1
  succ: B3 

[B3]
label L2
var t4
t4 = arr3[15144]
j = t4
output j
output L1
end
  succ: 
