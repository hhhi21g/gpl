
# tac list

0x5ae719ea82d0	label main
0x5ae719ea8310	begin
0x5ae719ea59f0	var i
0x5ae719ea5ad0	var j
0x5ae719ea5bb0	var k
0x5ae719ea5c90	var zs
0x5ae719ea5cf0	input i
0x5ae719ea5d50	input j
0x5ae719ea5db0	input k
0x5ae719ea5f90	var t0
0x5ae719ea5fd0	t0 = &zs
0x5ae719ea6090	var t1
0x5ae719ea6150	t1 = t0 + 0
0x5ae719ea6190	*t1 = i
0x5ae719ea6370	var t2
0x5ae719ea63b0	t2 = &zs
0x5ae719ea6470	var t3
0x5ae719ea6530	t3 = t2 + 4
0x5ae719ea6570	*t3 = j
0x5ae719ea6750	var t4
0x5ae719ea6790	t4 = &zs
0x5ae719ea6850	var t5
0x5ae719ea6910	t5 = t4 + 8
0x5ae719ea6950	*t5 = k
0x5ae719ea6bc0	ifz 0 goto L2
0x5ae719ea6a80	output L1
0x5ae719ea6b80	label L2
0x5ae719ea6d50	var t6
0x5ae719ea6d90	t6 = &zs
0x5ae719ea6e50	var t7
0x5ae719ea6e90	t7 = t6 + 8
0x5ae719ea6f50	var t8
0x5ae719ea6f90	t8 = *t7
0x5ae719ea7150	var t9
0x5ae719ea7190	t9 = t8 + 100
0x5ae719ea71d0	i = t9
0x5ae719ea7380	var t10
0x5ae719ea73c0	t10 = &zs
0x5ae719ea7480	var t11
0x5ae719ea74c0	t11 = t10 + 4
0x5ae719ea7580	var t12
0x5ae719ea75c0	t12 = *t11
0x5ae719ea7780	var t13
0x5ae719ea77c0	t13 = t12 + 200
0x5ae719ea7800	j = t13
0x5ae719ea79b0	var t14
0x5ae719ea79f0	t14 = &zs
0x5ae719ea7ab0	var t15
0x5ae719ea7af0	t15 = t14 + 0
0x5ae719ea7bb0	var t16
0x5ae719ea7bf0	t16 = *t15
0x5ae719ea7db0	var t17
0x5ae719ea7df0	t17 = t16 + 300
0x5ae719ea7e30	k = t17
0x5ae719ea8000	ifz 0 goto L3
0x5ae719ea7ee0	output L1
0x5ae719ea7fc0	label L3
0x5ae719ea8090	output i
0x5ae719ea8120	output j
0x5ae719ea81b0	output k
0x5ae719ea8210	output L1
0x5ae719ea8350	end

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
