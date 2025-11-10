
# tac list

0x641826ab15c0	label main
0x641826ab1600	begin
0x641826aaf810	var i
0x641826aaf8e0	var j
0x641826aafb00	vararray arr1[1D]
0x641826aafd70	vararray arr2[2D]
0x641826ab0030	vararray arr3[3D]
0x641826ab0090	input i
0x641826ab02d0	arr1[24] = i
0x641826ab0570	var t0
0x641826ab05b0	t0 = arr1[24]
0x641826ab06e0	var t1
0x641826ab0720	t1 = t0 + 6
0x641826ab0800	arr2[504] = t1
0x641826ab0ba0	var t2
0x641826ab0be0	t2 = arr2[504]
0x641826ab0d10	var t3
0x641826ab0d50	t3 = t2 + 6
0x641826ab0e30	arr3[15144] = t3
0x641826ab10f0	ifz 0 goto L2
0x641826ab0fc0	output L1
0x641826ab10b0	label L2
0x641826ab1370	var t4
0x641826ab13b0	t4 = arr3[15144]
0x641826ab1420	j = t4
0x641826ab14b0	output j
0x641826ab1510	output L1
0x641826ab1640	end

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
