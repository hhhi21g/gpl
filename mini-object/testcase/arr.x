
# tac list

0x61630b5fdb60	label main
0x61630b5fdba0	begin
0x61630b5fb830	var i
0x61630b5fb910	var j
0x61630b5fbb60	vararray arr1[1D]
0x61630b5fbe00	vararray arr2[2D]
0x61630b5fc0f0	vararray arr3[3D]
0x61630b5fc150	input i
0x61630b5fc7c0	arr1[24] = i
0x61630b5fca70	var t0
0x61630b5fcab0	t0 = arr1[24]
0x61630b5fcbf0	var t1
0x61630b5fcc30	t1 = t0 + 6
0x61630b5fcd20	arr2[504] = t1
0x61630b5fd0d0	var t2
0x61630b5fd110	t2 = arr2[504]
0x61630b5fd250	var t3
0x61630b5fd290	t3 = t2 + 6
0x61630b5fd380	arr3[15144] = t3
0x61630b5fd670	ifz 0 goto L2
0x61630b5fd530	output L1
0x61630b5fd630	label L2
0x61630b5fd900	var t4
0x61630b5fd940	t4 = arr3[15144]
0x61630b5fd9b0	j = t4
0x61630b5fda40	output j
0x61630b5fdaa0	output L1
0x61630b5fdbe0	end

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
