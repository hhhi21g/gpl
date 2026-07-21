
# tac list

0x64ec402e72d0	label main
0x64ec402e7310	begin
0x64ec402e49f0	var i
0x64ec402e4ad0	var j
0x64ec402e4bb0	var k
0x64ec402e4c90	var zs
0x64ec402e4cf0	input i
0x64ec402e4d50	input j
0x64ec402e4db0	input k
0x64ec402e4f90	var t0
0x64ec402e4fd0	t0 = &zs
0x64ec402e5090	var t1
0x64ec402e5150	t1 = t0 + 0
0x64ec402e5190	*t1 = i
0x64ec402e5370	var t2
0x64ec402e53b0	t2 = &zs
0x64ec402e5470	var t3
0x64ec402e5530	t3 = t2 + 4
0x64ec402e5570	*t3 = j
0x64ec402e5750	var t4
0x64ec402e5790	t4 = &zs
0x64ec402e5850	var t5
0x64ec402e5910	t5 = t4 + 8
0x64ec402e5950	*t5 = k
0x64ec402e5bc0	ifz 0 goto L2
0x64ec402e5a80	output L1
0x64ec402e5b80	label L2
0x64ec402e5d50	var t6
0x64ec402e5d90	t6 = &zs
0x64ec402e5e50	var t7
0x64ec402e5e90	t7 = t6 + 8
0x64ec402e5f50	var t8
0x64ec402e5f90	t8 = *t7
0x64ec402e6150	var t9
0x64ec402e6190	t9 = t8 + 100
0x64ec402e61d0	i = t9
0x64ec402e6380	var t10
0x64ec402e63c0	t10 = &zs
0x64ec402e6480	var t11
0x64ec402e64c0	t11 = t10 + 4
0x64ec402e6580	var t12
0x64ec402e65c0	t12 = *t11
0x64ec402e6780	var t13
0x64ec402e67c0	t13 = t12 + 200
0x64ec402e6800	j = t13
0x64ec402e69b0	var t14
0x64ec402e69f0	t14 = &zs
0x64ec402e6ab0	var t15
0x64ec402e6af0	t15 = t14 + 0
0x64ec402e6bb0	var t16
0x64ec402e6bf0	t16 = *t15
0x64ec402e6db0	var t17
0x64ec402e6df0	t17 = t16 + 300
0x64ec402e6e30	k = t17
0x64ec402e7000	ifz 0 goto L3
0x64ec402e6ee0	output L1
0x64ec402e6fc0	label L3
0x64ec402e7090	output i
0x64ec402e7120	output j
0x64ec402e71b0	output k
0x64ec402e7210	output L1
0x64ec402e7350	end

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
