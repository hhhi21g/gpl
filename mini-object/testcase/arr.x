
# tac list

0x559acbc005c0	label main
0x559acbc00600	begin
0x559acbbfe810	var i
0x559acbbfe8e0	var j
0x559acbbfeb00	vararray arr1[1D]
0x559acbbfed70	vararray arr2[2D]
0x559acbbff030	vararray arr3[3D]
0x559acbbff090	input i
0x559acbbff2d0	arr1[24] = i
0x559acbbff570	var t0
0x559acbbff5b0	t0 = arr1[24]
0x559acbbff6e0	var t1
0x559acbbff720	t1 = t0 + 6
0x559acbbff800	arr2[504] = t1
0x559acbbffba0	var t2
0x559acbbffbe0	t2 = arr2[504]
0x559acbbffd10	var t3
0x559acbbffd50	t3 = t2 + 6
0x559acbbffe30	arr3[15144] = t3
0x559acbc000f0	ifz 0 goto L2
0x559acbbfffc0	output L1
0x559acbc000b0	label L2
0x559acbc00370	var t4
0x559acbc003b0	t4 = arr3[15144]
0x559acbc00420	j = t4
0x559acbc004b0	output j
0x559acbc00510	output L1
0x559acbc00640	end

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
