
# tac list

0x5d8f1a59a6e0	label main
0x5d8f1a59a720	begin
0x5d8f1a5979f0	var i
0x5d8f1a597ad0	var j
0x5d8f1a597bb0	var k
0x5d8f1a597c90	var zs
0x5d8f1a597cf0	input i
0x5d8f1a597d50	input j
0x5d8f1a597db0	input k
0x5d8f1a5983a0	var t0
0x5d8f1a5983e0	t0 = &zs
0x5d8f1a5984a0	var t1
0x5d8f1a598560	t1 = t0 + 0
0x5d8f1a5985a0	*t1 = i
0x5d8f1a598780	var t2
0x5d8f1a5987c0	t2 = &zs
0x5d8f1a598880	var t3
0x5d8f1a598940	t3 = t2 + 4
0x5d8f1a598980	*t3 = j
0x5d8f1a598b60	var t4
0x5d8f1a598ba0	t4 = &zs
0x5d8f1a598c60	var t5
0x5d8f1a598d20	t5 = t4 + 8
0x5d8f1a598d60	*t5 = k
0x5d8f1a598fd0	ifz 0 goto L2
0x5d8f1a598e90	output L1
0x5d8f1a598f90	label L2
0x5d8f1a599160	var t6
0x5d8f1a5991a0	t6 = &zs
0x5d8f1a599260	var t7
0x5d8f1a5992a0	t7 = t6 + 8
0x5d8f1a599360	var t8
0x5d8f1a5993a0	t8 = *t7
0x5d8f1a599560	var t9
0x5d8f1a5995a0	t9 = t8 + 100
0x5d8f1a5995e0	i = t9
0x5d8f1a599790	var t10
0x5d8f1a5997d0	t10 = &zs
0x5d8f1a599890	var t11
0x5d8f1a5998d0	t11 = t10 + 4
0x5d8f1a599990	var t12
0x5d8f1a5999d0	t12 = *t11
0x5d8f1a599b90	var t13
0x5d8f1a599bd0	t13 = t12 + 200
0x5d8f1a599c10	j = t13
0x5d8f1a599dc0	var t14
0x5d8f1a599e00	t14 = &zs
0x5d8f1a599ec0	var t15
0x5d8f1a599f00	t15 = t14 + 0
0x5d8f1a599fc0	var t16
0x5d8f1a59a000	t16 = *t15
0x5d8f1a59a1c0	var t17
0x5d8f1a59a200	t17 = t16 + 300
0x5d8f1a59a240	k = t17
0x5d8f1a59a410	ifz 0 goto L3
0x5d8f1a59a2f0	output L1
0x5d8f1a59a3d0	label L3
0x5d8f1a59a4a0	output i
0x5d8f1a59a530	output j
0x5d8f1a59a5c0	output k
0x5d8f1a59a620	output L1
0x5d8f1a59a760	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
var k
var zs
input i
input j
input k
var t0
t0 = &zs
var t1
t1 = t0 + 0
*t1 = i
var t2
t2 = &zs
var t3
t3 = t2 + 4
*t3 = j
var t4
t4 = &zs
var t5
t5 = t4 + 8
*t5 = k
ifz 0 goto L2
  succ: B3 B2 

[B2]
output L1
  succ: B3 

[B3]
label L2
var t6
t6 = &zs
var t7
t7 = t6 + 8
var t8
t8 = *t7
var t9
t9 = t8 + 100
i = t9
var t10
t10 = &zs
var t11
t11 = t10 + 4
var t12
t12 = *t11
var t13
t13 = t12 + 200
j = t13
var t14
t14 = &zs
var t15
t15 = t14 + 0
var t16
t16 = *t15
var t17
t17 = t16 + 300
k = t17
ifz 0 goto L3
  succ: B5 B4 

[B4]
output L1
  succ: B5 

[B5]
label L3
output i
output j
output k
output L1
end
  succ: 
