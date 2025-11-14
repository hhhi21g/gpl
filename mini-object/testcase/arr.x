
# tac list

0x60c87c990b60	label main
0x60c87c990ba0	begin
0x60c87c98e830	var i
0x60c87c98e910	var j
0x60c87c98eb60	vararray arr1[1D]
0x60c87c98ee00	vararray arr2[2D]
0x60c87c98f0f0	vararray arr3[3D]
0x60c87c98f150	input i
0x60c87c98f7c0	arr1[24] = i
0x60c87c98fa70	var t0
0x60c87c98fab0	t0 = arr1[24]
0x60c87c98fbf0	var t1
0x60c87c98fc30	t1 = t0 + 6
0x60c87c98fd20	arr2[504] = t1
0x60c87c9900d0	var t2
0x60c87c990110	t2 = arr2[504]
0x60c87c990250	var t3
0x60c87c990290	t3 = t2 + 6
0x60c87c990380	arr3[15144] = t3
0x60c87c990670	ifz 0 goto L2
0x60c87c990530	output L1
0x60c87c990630	label L2
0x60c87c990900	var t4
0x60c87c990940	t4 = arr3[15144]
0x60c87c9909b0	j = t4
0x60c87c990a40	output j
0x60c87c990aa0	output L1
0x60c87c990be0	end

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
