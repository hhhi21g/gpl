
# tac list

0x629eafb104d0	label main
0x629eafb10510	begin
0x629eafb0d9d0	var i
0x629eafb0daa0	var j
0x629eafb0db70	var k
0x629eafb0dc40	var zs
0x629eafb0dca0	input i
0x629eafb0dd00	input j
0x629eafb0dd60	input k
0x629eafb0e340	var t0
0x629eafb0e380	t0 = &zs
0x629eafb0e430	var t1
0x629eafb0e4e0	t1 = t0 + 0
0x629eafb0e520	*t1 = i
0x629eafb0e6f0	var t2
0x629eafb0e730	t2 = &zs
0x629eafb0e7e0	var t3
0x629eafb0e890	t3 = t2 + 4
0x629eafb0e8d0	*t3 = j
0x629eafb0eaa0	var t4
0x629eafb0eae0	t4 = &zs
0x629eafb0eb90	var t5
0x629eafb0ec40	t5 = t4 + 8
0x629eafb0ec80	*t5 = k
0x629eafb0eed0	ifz 0 goto L2
0x629eafb0eda0	output L1
0x629eafb0ee90	label L2
0x629eafb0f050	var t6
0x629eafb0f090	t6 = &zs
0x629eafb0f140	var t7
0x629eafb0f180	t7 = t6 + 8
0x629eafb0f230	var t8
0x629eafb0f270	t8 = *t7
0x629eafb0f410	var t9
0x629eafb0f450	t9 = t8 + 100
0x629eafb0f490	i = t9
0x629eafb0f630	var t10
0x629eafb0f670	t10 = &zs
0x629eafb0f720	var t11
0x629eafb0f760	t11 = t10 + 4
0x629eafb0f810	var t12
0x629eafb0f850	t12 = *t11
0x629eafb0f9f0	var t13
0x629eafb0fa30	t13 = t12 + 200
0x629eafb0fa70	j = t13
0x629eafb0fc10	var t14
0x629eafb0fc50	t14 = &zs
0x629eafb0fd00	var t15
0x629eafb0fd40	t15 = t14 + 0
0x629eafb0fdf0	var t16
0x629eafb0fe30	t16 = *t15
0x629eafb0ffd0	var t17
0x629eafb10010	t17 = t16 + 300
0x629eafb10050	k = t17
0x629eafb10210	ifz 0 goto L3
0x629eafb10100	output L1
0x629eafb101d0	label L3
0x629eafb102a0	output i
0x629eafb10330	output j
0x629eafb103c0	output k
0x629eafb10420	output L1
0x629eafb10550	end

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
