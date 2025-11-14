
# tac list

0x5d955f9c16e0	label main
0x5d955f9c1720	begin
0x5d955f9be9f0	var i
0x5d955f9bead0	var j
0x5d955f9bebb0	var k
0x5d955f9bec90	var zs
0x5d955f9becf0	input i
0x5d955f9bed50	input j
0x5d955f9bedb0	input k
0x5d955f9bf3a0	var t0
0x5d955f9bf3e0	t0 = &zs
0x5d955f9bf4a0	var t1
0x5d955f9bf560	t1 = t0 + 0
0x5d955f9bf5a0	*t1 = i
0x5d955f9bf780	var t2
0x5d955f9bf7c0	t2 = &zs
0x5d955f9bf880	var t3
0x5d955f9bf940	t3 = t2 + 4
0x5d955f9bf980	*t3 = j
0x5d955f9bfb60	var t4
0x5d955f9bfba0	t4 = &zs
0x5d955f9bfc60	var t5
0x5d955f9bfd20	t5 = t4 + 8
0x5d955f9bfd60	*t5 = k
0x5d955f9bffd0	ifz 0 goto L2
0x5d955f9bfe90	output L1
0x5d955f9bff90	label L2
0x5d955f9c0160	var t6
0x5d955f9c01a0	t6 = &zs
0x5d955f9c0260	var t7
0x5d955f9c02a0	t7 = t6 + 8
0x5d955f9c0360	var t8
0x5d955f9c03a0	t8 = *t7
0x5d955f9c0560	var t9
0x5d955f9c05a0	t9 = t8 + 100
0x5d955f9c05e0	i = t9
0x5d955f9c0790	var t10
0x5d955f9c07d0	t10 = &zs
0x5d955f9c0890	var t11
0x5d955f9c08d0	t11 = t10 + 4
0x5d955f9c0990	var t12
0x5d955f9c09d0	t12 = *t11
0x5d955f9c0b90	var t13
0x5d955f9c0bd0	t13 = t12 + 200
0x5d955f9c0c10	j = t13
0x5d955f9c0dc0	var t14
0x5d955f9c0e00	t14 = &zs
0x5d955f9c0ec0	var t15
0x5d955f9c0f00	t15 = t14 + 0
0x5d955f9c0fc0	var t16
0x5d955f9c1000	t16 = *t15
0x5d955f9c11c0	var t17
0x5d955f9c1200	t17 = t16 + 300
0x5d955f9c1240	k = t17
0x5d955f9c1410	ifz 0 goto L3
0x5d955f9c12f0	output L1
0x5d955f9c13d0	label L3
0x5d955f9c14a0	output i
0x5d955f9c1530	output j
0x5d955f9c15c0	output k
0x5d955f9c1620	output L1
0x5d955f9c1760	end

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
