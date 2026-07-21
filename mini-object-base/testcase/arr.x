
# tac list

0x57ab438e1750	label main
0x57ab438e1790	begin
0x57ab438df830	var i
0x57ab438df910	var j
0x57ab438dfb60	vararray arr1[1D]
0x57ab438dfe00	vararray arr2[2D]
0x57ab438e00f0	vararray arr3[3D]
0x57ab438e0150	input i
0x57ab438e03b0	arr1[24] = i
0x57ab438e0660	var t0
0x57ab438e06a0	t0 = arr1[24]
0x57ab438e07e0	var t1
0x57ab438e0820	t1 = t0 + 6
0x57ab438e0910	arr2[504] = t1
0x57ab438e0cc0	var t2
0x57ab438e0d00	t2 = arr2[504]
0x57ab438e0e40	var t3
0x57ab438e0e80	t3 = t2 + 6
0x57ab438e0f70	arr3[15144] = t3
0x57ab438e1260	ifz 0 goto L2
0x57ab438e1120	output L1
0x57ab438e1220	label L2
0x57ab438e14f0	var t4
0x57ab438e1530	t4 = arr3[15144]
0x57ab438e15a0	j = t4
0x57ab438e1630	output j
0x57ab438e1690	output L1
0x57ab438e17d0	end

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
