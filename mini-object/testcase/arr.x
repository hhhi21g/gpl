
# tac list

0x5a7827d0ab60	label main
0x5a7827d0aba0	begin
0x5a7827d08830	var i
0x5a7827d08910	var j
0x5a7827d08b60	vararray arr1[1D]
0x5a7827d08e00	vararray arr2[2D]
0x5a7827d090f0	vararray arr3[3D]
0x5a7827d09150	input i
0x5a7827d097c0	arr1[24] = i
0x5a7827d09a70	var t0
0x5a7827d09ab0	t0 = arr1[24]
0x5a7827d09bf0	var t1
0x5a7827d09c30	t1 = t0 + 6
0x5a7827d09d20	arr2[504] = t1
0x5a7827d0a0d0	var t2
0x5a7827d0a110	t2 = arr2[504]
0x5a7827d0a250	var t3
0x5a7827d0a290	t3 = t2 + 6
0x5a7827d0a380	arr3[15144] = t3
0x5a7827d0a670	ifz 0 goto L2
0x5a7827d0a530	output L1
0x5a7827d0a630	label L2
0x5a7827d0a900	var t4
0x5a7827d0a940	t4 = arr3[15144]
0x5a7827d0a9b0	j = t4
0x5a7827d0aa40	output j
0x5a7827d0aaa0	output L1
0x5a7827d0abe0	end

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
