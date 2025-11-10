
# tac list

0x5ae73b334250	label main
0x5ae73b334290	begin
0x5ae73b331810	var i
0x5ae73b3318e0	var j
0x5ae73b331b00	vararray arr1[1D]
0x5ae73b331d70	vararray arr2[2D]
0x5ae73b332030	vararray arr3[3D]
0x5ae73b332090	input i
0x5ae73b3322a0	var t0
0x5ae73b3322e0	t0 = 6 * 1
0x5ae73b332350	arr1[t0] = i
0x5ae73b332940	var t4
0x5ae73b332980	t4 = 6 * 20
0x5ae73b3329c0	t4 = t4 + 6
0x5ae73b332aa0	var t5
0x5ae73b332ae0	t5 = t4 * 1
0x5ae73b3325c0	var t1
0x5ae73b332600	t1 = 6 * 1
0x5ae73b3326e0	var t2
0x5ae73b332720	t2 = arr1[t1]
0x5ae73b332850	var t3
0x5ae73b332890	t3 = t2 + 6
0x5ae73b332b50	arr2[t5] = t3
0x5ae73b3333a0	var t10
0x5ae73b3333e0	t10 = 6 * 30
0x5ae73b333420	t10 = t10 + 6
0x5ae73b333500	var t11
0x5ae73b333540	t11 = t10 * 20
0x5ae73b333580	t11 = t11 + 6
0x5ae73b333660	var t12
0x5ae73b3336a0	t12 = t11 * 1
0x5ae73b332ec0	var t6
0x5ae73b332f00	t6 = 6 * 20
0x5ae73b332f40	t6 = t6 + 6
0x5ae73b333020	var t7
0x5ae73b333060	t7 = t6 * 1
0x5ae73b333140	var t8
0x5ae73b333180	t8 = arr2[t7]
0x5ae73b3332b0	var t9
0x5ae73b3332f0	t9 = t8 + 6
0x5ae73b333710	arr3[t12] = t9
0x5ae73b3339d0	ifz 0 goto L2
0x5ae73b3338a0	output L1
0x5ae73b333990	label L2
0x5ae73b333c20	var t13
0x5ae73b333c60	t13 = 6 * 30
0x5ae73b333ca0	t13 = t13 + 6
0x5ae73b333d80	var t14
0x5ae73b333dc0	t14 = t13 * 20
0x5ae73b333e00	t14 = t14 + 6
0x5ae73b333ee0	var t15
0x5ae73b333f20	t15 = t14 * 1
0x5ae73b334000	var t16
0x5ae73b334040	t16 = arr3[t15]
0x5ae73b3340b0	j = t16
0x5ae73b334140	output j
0x5ae73b3341a0	output L1
0x5ae73b3342d0	end

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
