
# tac list

0x6550941e5b60	label main
0x6550941e5ba0	begin
0x6550941e3830	var i
0x6550941e3910	var j
0x6550941e3b60	vararray arr1[1D]
0x6550941e3e00	vararray arr2[2D]
0x6550941e40f0	vararray arr3[3D]
0x6550941e4150	input i
0x6550941e47c0	arr1[24] = i
0x6550941e4a70	var t0
0x6550941e4ab0	t0 = arr1[24]
0x6550941e4bf0	var t1
0x6550941e4c30	t1 = t0 + 6
0x6550941e4d20	arr2[504] = t1
0x6550941e50d0	var t2
0x6550941e5110	t2 = arr2[504]
0x6550941e5250	var t3
0x6550941e5290	t3 = t2 + 6
0x6550941e5380	arr3[15144] = t3
0x6550941e5670	ifz 0 goto L2
0x6550941e5530	output L1
0x6550941e5630	label L2
0x6550941e5900	var t4
0x6550941e5940	t4 = arr3[15144]
0x6550941e59b0	j = t4
0x6550941e5a40	output j
0x6550941e5aa0	output L1
0x6550941e5be0	end

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
