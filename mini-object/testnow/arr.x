
# tac list

0x61cbabdf35c0	label main
0x61cbabdf3600	begin
0x61cbabdf1810	var i
0x61cbabdf18e0	var j
0x61cbabdf1b00	vararray arr1[1D]
0x61cbabdf1d70	vararray arr2[2D]
0x61cbabdf2030	vararray arr3[3D]
0x61cbabdf2090	input i
0x61cbabdf22d0	arr1[24] = i
0x61cbabdf2570	var t0
0x61cbabdf25b0	t0 = arr1[24]
0x61cbabdf26e0	var t1
0x61cbabdf2720	t1 = t0 + 6
0x61cbabdf2800	arr2[504] = t1
0x61cbabdf2ba0	var t2
0x61cbabdf2be0	t2 = arr2[504]
0x61cbabdf2d10	var t3
0x61cbabdf2d50	t3 = t2 + 6
0x61cbabdf2e30	arr3[15144] = t3
0x61cbabdf30f0	ifz 0 goto L2
0x61cbabdf2fc0	output L1
0x61cbabdf30b0	label L2
0x61cbabdf3370	var t4
0x61cbabdf33b0	t4 = arr3[15144]
0x61cbabdf3420	j = t4
0x61cbabdf34b0	output j
0x61cbabdf3510	output L1
0x61cbabdf3640	end

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
