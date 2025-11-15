
# tac list

0x6244563f9750	label main
0x6244563f9790	begin
0x6244563f7830	var i
0x6244563f7910	var j
0x6244563f7b60	vararray arr1[1D]
0x6244563f7e00	vararray arr2[2D]
0x6244563f80f0	vararray arr3[3D]
0x6244563f8150	input i
0x6244563f83b0	arr1[24] = i
0x6244563f8660	var t0
0x6244563f86a0	t0 = arr1[24]
0x6244563f87e0	var t1
0x6244563f8820	t1 = t0 + 6
0x6244563f8910	arr2[504] = t1
0x6244563f8cc0	var t2
0x6244563f8d00	t2 = arr2[504]
0x6244563f8e40	var t3
0x6244563f8e80	t3 = t2 + 6
0x6244563f8f70	arr3[15144] = t3
0x6244563f9260	ifz 0 goto L2
0x6244563f9120	output L1
0x6244563f9220	label L2
0x6244563f94f0	var t4
0x6244563f9530	t4 = arr3[15144]
0x6244563f95a0	j = t4
0x6244563f9630	output j
0x6244563f9690	output L1
0x6244563f97d0	end

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
