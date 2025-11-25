
# tac list

0x60307f302370	label main
0x60307f3023b0	begin
0x60307f2fce70	var i
0x60307f2fcf50	var j
0x60307f2fd030	var a
0x60307f2fd110	var b
0x60307f2fd1f0	var c1
0x60307f2fd450	var t0
0x60307f2fd490	t0 = &c1
0x60307f2fd550	var t1
0x60307f2fd610	t1 = t0 + 0
0x60307f2fd650	*t1 = 1
0x60307f2fd9d0	var t2
0x60307f2fda10	t2 = &c1
0x60307f2fdad0	var t3
0x60307f2fdb90	t3 = t2 + 14
0x60307f2fdc50	var t4
0x60307f2fdd10	t4 = t3 + 1108
0x60307f2fddd0	var t5
0x60307f2fde10	t5 = t4 + 0
0x60307f2fde50	*t5 = 2
0x60307f2fe420	var t6
0x60307f2fe460	t6 = &c1
0x60307f2fe520	var t7
0x60307f2fe560	t7 = t6 + 14
0x60307f2fe620	var t8
0x60307f2fe660	t8 = t7 + 1108
0x60307f2fe720	var t9
0x60307f2fe760	t9 = t8 + 14
0x60307f2fe820	var t10
0x60307f2fe8e0	t10 = t9 + 162
0x60307f2fe9a0	var t11
0x60307f2fea60	t11 = t10 + 4
0x60307f2feb20	var t12
0x60307f2feb60	t12 = t11 + 1
0x60307f2feba0	c*t12 = 'b'
0x60307f2ff0f0	var t13
0x60307f2ff130	t13 = &c1
0x60307f2ff1f0	var t14
0x60307f2ff230	t14 = t13 + 14
0x60307f2ff2f0	var t15
0x60307f2ff330	t15 = t14 + 1108
0x60307f2ff3f0	var t16
0x60307f2ff430	t16 = t15 + 14
0x60307f2ff4f0	var t17
0x60307f2ff530	t17 = t16 + 162
0x60307f2ff5f0	var t18
0x60307f2ff630	t18 = t17 + 4
0x60307f2ff6f0	var t19
0x60307f2ff730	t19 = t18 + 0
0x60307f2ff770	c*t19 = 'a'
0x60307f2ff9e0	ifz 0 goto L2
0x60307f2ff8a0	output L1
0x60307f2ff9a0	label L2
0x60307f2ffb70	var t20
0x60307f2ffbb0	t20 = &c1
0x60307f2ffc70	var t21
0x60307f2ffcb0	t21 = t20 + 0
0x60307f2ffd70	var t22
0x60307f2ffdb0	t22 = *t21
0x60307f2ffe20	i = t22
0x60307f3000f0	var t23
0x60307f300130	t23 = &c1
0x60307f3001f0	var t24
0x60307f300230	t24 = t23 + 14
0x60307f3002f0	var t25
0x60307f300330	t25 = t24 + 1108
0x60307f3003f0	var t26
0x60307f300430	t26 = t25 + 0
0x60307f3004f0	var t27
0x60307f300530	t27 = *t26
0x60307f3005a0	j = t27
0x60307f300a40	var t28
0x60307f300a80	t28 = &c1
0x60307f300b40	var t29
0x60307f300b80	t29 = t28 + 14
0x60307f300c40	var t30
0x60307f300c80	t30 = t29 + 1108
0x60307f300d40	var t31
0x60307f300d80	t31 = t30 + 14
0x60307f300e40	var t32
0x60307f300e80	t32 = t31 + 162
0x60307f300f40	var t33
0x60307f300f80	t33 = t32 + 4
0x60307f301040	var t34
0x60307f301080	t34 = t33 + 0
0x60307f301140	var t35
0x60307f301180	t35 = c*t34
0x60307f3011f0	a = t35
0x60307f301690	var t36
0x60307f3016d0	t36 = &c1
0x60307f301790	var t37
0x60307f3017d0	t37 = t36 + 14
0x60307f301890	var t38
0x60307f3018d0	t38 = t37 + 1108
0x60307f301990	var t39
0x60307f3019d0	t39 = t38 + 14
0x60307f301a90	var t40
0x60307f301ad0	t40 = t39 + 162
0x60307f301b90	var t41
0x60307f301bd0	t41 = t40 + 4
0x60307f301c90	var t42
0x60307f301cd0	t42 = t41 + 1
0x60307f301d90	var t43
0x60307f301dd0	t43 = c*t42
0x60307f301e40	b = t43
0x60307f302010	ifz 0 goto L3
0x60307f301ef0	output L1
0x60307f301fd0	label L3
0x60307f3020a0	output i
0x60307f302130	output j
0x60307f3021c0	output a
0x60307f302250	output b
0x60307f3022b0	output L1
0x60307f3023f0	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
var a
var b
var c1
var t0
t0 = &c1
var t1
t1 = t0 + 0
*t1 = 1
var t2
t2 = &c1
var t3
t3 = t2 + 14
var t4
t4 = t3 + 1108
var t5
t5 = t4 + 0
*t5 = 2
var t6
t6 = &c1
var t7
t7 = t6 + 14
var t8
t8 = t7 + 1108
var t9
t9 = t8 + 14
var t10
t10 = t9 + 162
var t11
t11 = t10 + 4
var t12
t12 = t11 + 1
c*t12 = 'b'
var t13
t13 = &c1
var t14
t14 = t13 + 14
var t15
t15 = t14 + 1108
var t16
t16 = t15 + 14
var t17
t17 = t16 + 162
var t18
t18 = t17 + 4
var t19
t19 = t18 + 0
c*t19 = 'a'
ifz 0 goto L2
  succ: B3 B2 

[B2]
output L1
  succ: B3 

[B3]
label L2
var t20
t20 = &c1
var t21
t21 = t20 + 0
var t22
t22 = *t21
i = t22
var t23
t23 = &c1
var t24
t24 = t23 + 14
var t25
t25 = t24 + 1108
var t26
t26 = t25 + 0
var t27
t27 = *t26
j = t27
var t28
t28 = &c1
var t29
t29 = t28 + 14
var t30
t30 = t29 + 1108
var t31
t31 = t30 + 14
var t32
t32 = t31 + 162
var t33
t33 = t32 + 4
var t34
t34 = t33 + 0
var t35
t35 = c*t34
a = t35
var t36
t36 = &c1
var t37
t37 = t36 + 14
var t38
t38 = t37 + 1108
var t39
t39 = t38 + 14
var t40
t40 = t39 + 162
var t41
t41 = t40 + 4
var t42
t42 = t41 + 1
var t43
t43 = c*t42
b = t43
ifz 0 goto L3
  succ: B5 B4 

[B4]
output L1
  succ: B5 

[B5]
label L3
output i
output j
output a
output b
output L1
end
  succ: 
