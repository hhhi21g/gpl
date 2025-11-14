
# tac list

0x5b1e9ddde4d0	label main
0x5b1e9ddde510	begin
0x5b1e9dddb9d0	var i
0x5b1e9dddbaa0	var j
0x5b1e9dddbb70	var k
0x5b1e9dddbc40	var zs
0x5b1e9dddbca0	input i
0x5b1e9dddbd00	input j
0x5b1e9dddbd60	input k
0x5b1e9dddbf30	var t0
0x5b1e9dddbf70	t0 = &zs
0x5b1e9dddc020	var t1
0x5b1e9dddc0d0	t1 = t0 + 0
0x5b1e9dddc110	*t1 = i
0x5b1e9dddc2e0	var t2
0x5b1e9dddc320	t2 = &zs
0x5b1e9dddc3d0	var t3
0x5b1e9dddc480	t3 = t2 + 4
0x5b1e9dddc4c0	*t3 = j
0x5b1e9dddc690	var t4
0x5b1e9dddc6d0	t4 = &zs
0x5b1e9dddc780	var t5
0x5b1e9dddc830	t5 = t4 + 8
0x5b1e9dddc870	*t5 = k
0x5b1e9dddcac0	ifz 0 goto L2
0x5b1e9dddc990	output L1
0x5b1e9dddca80	label L2
0x5b1e9dddcc40	var t6
0x5b1e9dddcc80	t6 = &zs
0x5b1e9dddd140	var t7
0x5b1e9dddd180	t7 = t6 + 8
0x5b1e9dddd230	var t8
0x5b1e9dddd270	t8 = *t7
0x5b1e9dddd410	var t9
0x5b1e9dddd450	t9 = t8 + 100
0x5b1e9dddd490	i = t9
0x5b1e9dddd630	var t10
0x5b1e9dddd670	t10 = &zs
0x5b1e9dddd720	var t11
0x5b1e9dddd760	t11 = t10 + 4
0x5b1e9dddd810	var t12
0x5b1e9dddd850	t12 = *t11
0x5b1e9dddd9f0	var t13
0x5b1e9dddda30	t13 = t12 + 200
0x5b1e9dddda70	j = t13
0x5b1e9ddddc10	var t14
0x5b1e9ddddc50	t14 = &zs
0x5b1e9ddddd00	var t15
0x5b1e9ddddd40	t15 = t14 + 0
0x5b1e9dddddf0	var t16
0x5b1e9dddde30	t16 = *t15
0x5b1e9ddddfd0	var t17
0x5b1e9ddde010	t17 = t16 + 300
0x5b1e9ddde050	k = t17
0x5b1e9ddde210	ifz 0 goto L3
0x5b1e9ddde100	output L1
0x5b1e9ddde1d0	label L3
0x5b1e9ddde2a0	output i
0x5b1e9ddde330	output j
0x5b1e9ddde3c0	output k
0x5b1e9ddde420	output L1
0x5b1e9ddde550	end

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
