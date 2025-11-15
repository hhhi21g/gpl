
# tac list

0x605ca0d5ab60	label main
0x605ca0d5aba0	begin
0x605ca0d58830	var i
0x605ca0d58910	var j
0x605ca0d58b60	vararray arr1[1D]
0x605ca0d58e00	vararray arr2[2D]
0x605ca0d590f0	vararray arr3[3D]
0x605ca0d59150	input i
0x605ca0d597c0	arr1[24] = i
0x605ca0d59a70	var t0
0x605ca0d59ab0	t0 = arr1[24]
0x605ca0d59bf0	var t1
0x605ca0d59c30	t1 = t0 + 6
0x605ca0d59d20	arr2[504] = t1
0x605ca0d5a0d0	var t2
0x605ca0d5a110	t2 = arr2[504]
0x605ca0d5a250	var t3
0x605ca0d5a290	t3 = t2 + 6
0x605ca0d5a380	arr3[15144] = t3
0x605ca0d5a670	ifz 0 goto L2
0x605ca0d5a530	output L1
0x605ca0d5a630	label L2
0x605ca0d5a900	var t4
0x605ca0d5a940	t4 = arr3[15144]
0x605ca0d5a9b0	j = t4
0x605ca0d5aa40	output j
0x605ca0d5aaa0	output L1
0x605ca0d5abe0	end

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
