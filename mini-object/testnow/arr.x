
# tac list

0x560fd43a5250	label main
0x560fd43a5290	begin
0x560fd43a2810	var i
0x560fd43a28e0	var j
0x560fd43a2b00	vararray arr1[1D]
0x560fd43a2d70	vararray arr2[2D]
0x560fd43a3030	vararray arr3[3D]
0x560fd43a3090	input i
0x560fd43a32a0	var t0
0x560fd43a32e0	t0 = 6 * 1
0x560fd43a3350	arr1[t0] = i
0x560fd43a3940	var t4
0x560fd43a3980	t4 = 6 * 20
0x560fd43a39c0	t4 = t4 + 6
0x560fd43a3aa0	var t5
0x560fd43a3ae0	t5 = t4 * 1
0x560fd43a35c0	var t1
0x560fd43a3600	t1 = 6 * 1
0x560fd43a36e0	var t2
0x560fd43a3720	t2 = arr1[t1]
0x560fd43a3850	var t3
0x560fd43a3890	t3 = t2 + 6
0x560fd43a3b50	arr2[t5] = t3
0x560fd43a43a0	var t10
0x560fd43a43e0	t10 = 6 * 30
0x560fd43a4420	t10 = t10 + 6
0x560fd43a4500	var t11
0x560fd43a4540	t11 = t10 * 20
0x560fd43a4580	t11 = t11 + 6
0x560fd43a4660	var t12
0x560fd43a46a0	t12 = t11 * 1
0x560fd43a3ec0	var t6
0x560fd43a3f00	t6 = 6 * 20
0x560fd43a3f40	t6 = t6 + 6
0x560fd43a4020	var t7
0x560fd43a4060	t7 = t6 * 1
0x560fd43a4140	var t8
0x560fd43a4180	t8 = arr2[t7]
0x560fd43a42b0	var t9
0x560fd43a42f0	t9 = t8 + 6
0x560fd43a4710	arr3[t12] = t9
0x560fd43a49d0	ifz 0 goto L2
0x560fd43a48a0	output L1
0x560fd43a4990	label L2
0x560fd43a4c20	var t13
0x560fd43a4c60	t13 = 6 * 30
0x560fd43a4ca0	t13 = t13 + 6
0x560fd43a4d80	var t14
0x560fd43a4dc0	t14 = t13 * 20
0x560fd43a4e00	t14 = t14 + 6
0x560fd43a4ee0	var t15
0x560fd43a4f20	t15 = t14 * 1
0x560fd43a5000	var t16
0x560fd43a5040	t16 = arr3[t15]
0x560fd43a50b0	j = t16
0x560fd43a5140	output j
0x560fd43a51a0	output L1
0x560fd43a52d0	end

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
t0 = 6 * 1
arr1[t0] = i
var t4
t4 = 6 * 20
t4 = t4 + 6
var t5
t5 = t4 * 1
var t1
t1 = 6 * 1
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
t12 = t11 * 1
var t6
t6 = 6 * 20
t6 = t6 + 6
var t7
t7 = t6 * 1
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
t15 = t14 * 1
var t16
t16 = arr3[t15]
j = t16
output j
output L1
end
  succ: 
