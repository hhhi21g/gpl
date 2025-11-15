
# tac list

0x5c0a3c7876e0	label main
0x5c0a3c787720	begin
0x5c0a3c7849f0	var i
0x5c0a3c784ad0	var j
0x5c0a3c784bb0	var k
0x5c0a3c784c90	var zs
0x5c0a3c784cf0	input i
0x5c0a3c784d50	input j
0x5c0a3c784db0	input k
0x5c0a3c7853a0	var t0
0x5c0a3c7853e0	t0 = &zs
0x5c0a3c7854a0	var t1
0x5c0a3c785560	t1 = t0 + 0
0x5c0a3c7855a0	*t1 = i
0x5c0a3c785780	var t2
0x5c0a3c7857c0	t2 = &zs
0x5c0a3c785880	var t3
0x5c0a3c785940	t3 = t2 + 4
0x5c0a3c785980	*t3 = j
0x5c0a3c785b60	var t4
0x5c0a3c785ba0	t4 = &zs
0x5c0a3c785c60	var t5
0x5c0a3c785d20	t5 = t4 + 8
0x5c0a3c785d60	*t5 = k
0x5c0a3c785fd0	ifz 0 goto L2
0x5c0a3c785e90	output L1
0x5c0a3c785f90	label L2
0x5c0a3c786160	var t6
0x5c0a3c7861a0	t6 = &zs
0x5c0a3c786260	var t7
0x5c0a3c7862a0	t7 = t6 + 8
0x5c0a3c786360	var t8
0x5c0a3c7863a0	t8 = *t7
0x5c0a3c786560	var t9
0x5c0a3c7865a0	t9 = t8 + 100
0x5c0a3c7865e0	i = t9
0x5c0a3c786790	var t10
0x5c0a3c7867d0	t10 = &zs
0x5c0a3c786890	var t11
0x5c0a3c7868d0	t11 = t10 + 4
0x5c0a3c786990	var t12
0x5c0a3c7869d0	t12 = *t11
0x5c0a3c786b90	var t13
0x5c0a3c786bd0	t13 = t12 + 200
0x5c0a3c786c10	j = t13
0x5c0a3c786dc0	var t14
0x5c0a3c786e00	t14 = &zs
0x5c0a3c786ec0	var t15
0x5c0a3c786f00	t15 = t14 + 0
0x5c0a3c786fc0	var t16
0x5c0a3c787000	t16 = *t15
0x5c0a3c7871c0	var t17
0x5c0a3c787200	t17 = t16 + 300
0x5c0a3c787240	k = t17
0x5c0a3c787410	ifz 0 goto L3
0x5c0a3c7872f0	output L1
0x5c0a3c7873d0	label L3
0x5c0a3c7874a0	output i
0x5c0a3c787530	output j
0x5c0a3c7875c0	output k
0x5c0a3c787620	output L1
0x5c0a3c787760	end

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
