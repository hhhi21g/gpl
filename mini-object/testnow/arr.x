
# tac list

0x61c89b7a46d0	label main
0x61c89b7a4710	begin
0x61c89b7a1810	var i
0x61c89b7a18e0	var j
0x61c89b7a1b00	vararray arr1[1D]
0x61c89b7a1d70	vararray arr2[2D]
0x61c89b7a2030	vararray arr3[3D]
0x61c89b7a2090	input i
0x61c89b7a22a0	var t0
0x61c89b7a2760	t0 = 6 * 4
0x61c89b7a27d0	arr1[t0] = i
0x61c89b7a2dc0	var t4
0x61c89b7a2e00	t4 = 6 * 20
0x61c89b7a2e40	t4 = t4 + 6
0x61c89b7a2f20	var t5
0x61c89b7a2f60	t5 = t4 * 4
0x61c89b7a2a40	var t1
0x61c89b7a2a80	t1 = 6 * 4
0x61c89b7a2b60	var t2
0x61c89b7a2ba0	t2 = arr1[t1]
0x61c89b7a2cd0	var t3
0x61c89b7a2d10	t3 = t2 + 6
0x61c89b7a2fd0	arr2[t5] = t3
0x61c89b7a3820	var t10
0x61c89b7a3860	t10 = 6 * 30
0x61c89b7a38a0	t10 = t10 + 6
0x61c89b7a3980	var t11
0x61c89b7a39c0	t11 = t10 * 20
0x61c89b7a3a00	t11 = t11 + 6
0x61c89b7a3ae0	var t12
0x61c89b7a3b20	t12 = t11 * 4
0x61c89b7a3340	var t6
0x61c89b7a3380	t6 = 6 * 20
0x61c89b7a33c0	t6 = t6 + 6
0x61c89b7a34a0	var t7
0x61c89b7a34e0	t7 = t6 * 4
0x61c89b7a35c0	var t8
0x61c89b7a3600	t8 = arr2[t7]
0x61c89b7a3730	var t9
0x61c89b7a3770	t9 = t8 + 6
0x61c89b7a3b90	arr3[t12] = t9
0x61c89b7a3e50	ifz 0 goto L2
0x61c89b7a3d20	output L1
0x61c89b7a3e10	label L2
0x61c89b7a40a0	var t13
0x61c89b7a40e0	t13 = 6 * 30
0x61c89b7a4120	t13 = t13 + 6
0x61c89b7a4200	var t14
0x61c89b7a4240	t14 = t13 * 20
0x61c89b7a4280	t14 = t14 + 6
0x61c89b7a4360	var t15
0x61c89b7a43a0	t15 = t14 * 4
0x61c89b7a4480	var t16
0x61c89b7a44c0	t16 = arr3[t15]
0x61c89b7a4530	j = t16
0x61c89b7a45c0	output j
0x61c89b7a4620	output L1
0x61c89b7a4750	end

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
var t0
t0 = 6 * 4
arr1[t0] = i
var t4
t4 = 6 * 20
t4 = t4 + 6
var t5
t5 = t4 * 4
var t1
t1 = 6 * 4
var t2
t2 = arr1[t1]
var t3
t3 = t2 + 6
arr2[t5] = t3
var t10
t10 = 6 * 30
t10 = t10 + 6
var t11
t11 = t10 * 20
t11 = t11 + 6
var t12
t12 = t11 * 4
var t6
t6 = 6 * 20
t6 = t6 + 6
var t7
t7 = t6 * 4
var t8
t8 = arr2[t7]
var t9
t9 = t8 + 6
arr3[t12] = t9
ifz 0 goto L2
  succ: B3 B2 

[B2]
output L1
  succ: B3 

[B3]
label L2
var t13
t13 = 6 * 30
t13 = t13 + 6
var t14
t14 = t13 * 20
t14 = t14 + 6
var t15
t15 = t14 * 4
var t16
t16 = arr3[t15]
j = t16
output j
output L1
end
  succ: 
