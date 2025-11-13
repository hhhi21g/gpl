
# tac list

0x5f6176ea85c0	label main
0x5f6176ea8600	begin
0x5f6176ea2e50	var c
0x5f6176ea2f20	var i
0x5f6176ea2ff0	var j
0x5f6176ea30c0	var a
0x5f6176ea3190	var b
0x5f6176ea3260	var c1
0x5f6176ea3440	c = 10
0x5f6176ea3610	var t0
0x5f6176ea3650	t0 = &c1
0x5f6176ea3700	var t1
0x5f6176ea37b0	t1 = t0 + 0
0x5f6176ea37f0	*t1 = 1
0x5f6176ea3b50	var t2
0x5f6176ea3b90	t2 = &c1
0x5f6176ea3c40	var t3
0x5f6176ea3cf0	t3 = t2 + 14
0x5f6176ea41b0	var t4
0x5f6176ea4260	t4 = t3 + 1108
0x5f6176ea4310	var t5
0x5f6176ea4350	t5 = t4 + 0
0x5f6176ea4390	*t5 = 2
0x5f6176ea4930	var t6
0x5f6176ea4970	t6 = &c1
0x5f6176ea4a20	var t7
0x5f6176ea4a60	t7 = t6 + 14
0x5f6176ea4b10	var t8
0x5f6176ea4b50	t8 = t7 + 1108
0x5f6176ea4c00	var t9
0x5f6176ea4c40	t9 = t8 + 14
0x5f6176ea4cf0	var t10
0x5f6176ea4da0	t10 = t9 + 162
0x5f6176ea4e50	var t11
0x5f6176ea4f00	t11 = t10 + 4
0x5f6176ea4fb0	var t12
0x5f6176ea4ff0	t12 = t11 + 1
0x5f6176ea5030	c*t12 = 'b'
0x5f6176ea5560	var t13
0x5f6176ea55a0	t13 = &c1
0x5f6176ea5650	var t14
0x5f6176ea5690	t14 = t13 + 14
0x5f6176ea5740	var t15
0x5f6176ea5780	t15 = t14 + 1108
0x5f6176ea5830	var t16
0x5f6176ea5870	t16 = t15 + 14
0x5f6176ea5920	var t17
0x5f6176ea5960	t17 = t16 + 162
0x5f6176ea5a10	var t18
0x5f6176ea5a50	t18 = t17 + 4
0x5f6176ea5b00	var t19
0x5f6176ea5b40	t19 = t18 + 0
0x5f6176ea5b80	c*t19 = 'a'
0x5f6176ea5dd0	ifz 0 goto L2
0x5f6176ea5ca0	output L1
0x5f6176ea5d90	label L2
0x5f6176ea5f50	var t20
0x5f6176ea5f90	t20 = &c1
0x5f6176ea6040	var t21
0x5f6176ea6080	t21 = t20 + 0
0x5f6176ea6130	var t22
0x5f6176ea6170	t22 = *t21
0x5f6176ea61e0	i = t22
0x5f6176ea64a0	var t23
0x5f6176ea64e0	t23 = &c1
0x5f6176ea6590	var t24
0x5f6176ea65d0	t24 = t23 + 14
0x5f6176ea6680	var t25
0x5f6176ea66c0	t25 = t24 + 1108
0x5f6176ea6770	var t26
0x5f6176ea67b0	t26 = t25 + 0
0x5f6176ea6860	var t27
0x5f6176ea68a0	t27 = *t26
0x5f6176ea6910	j = t27
0x5f6176ea6da0	var t28
0x5f6176ea6de0	t28 = &c1
0x5f6176ea6e90	var t29
0x5f6176ea6ed0	t29 = t28 + 14
0x5f6176ea6f80	var t30
0x5f6176ea6fc0	t30 = t29 + 1108
0x5f6176ea7070	var t31
0x5f6176ea70b0	t31 = t30 + 14
0x5f6176ea7160	var t32
0x5f6176ea71a0	t32 = t31 + 162
0x5f6176ea7250	var t33
0x5f6176ea7290	t33 = t32 + 4
0x5f6176ea7340	var t34
0x5f6176ea7380	t34 = t33 + 0
0x5f6176ea7430	var t35
0x5f6176ea7470	t35 = c*t34
0x5f6176ea74e0	a = t35
0x5f6176ea7970	var t36
0x5f6176ea79b0	t36 = &c1
0x5f6176ea7a60	var t37
0x5f6176ea7aa0	t37 = t36 + 14
0x5f6176ea7b50	var t38
0x5f6176ea7b90	t38 = t37 + 1108
0x5f6176ea7c40	var t39
0x5f6176ea7c80	t39 = t38 + 14
0x5f6176ea7d30	var t40
0x5f6176ea7d70	t40 = t39 + 162
0x5f6176ea7e20	var t41
0x5f6176ea7e60	t41 = t40 + 4
0x5f6176ea7f10	var t42
0x5f6176ea7f50	t42 = t41 + 1
0x5f6176ea8000	var t43
0x5f6176ea8040	t43 = c*t42
0x5f6176ea80b0	b = t43
0x5f6176ea8270	ifz 0 goto L3
0x5f6176ea8160	output L1
0x5f6176ea8230	label L3
0x5f6176ea8300	output i
0x5f6176ea8390	output j
0x5f6176ea8420	output a
0x5f6176ea84b0	output b
0x5f6176ea8510	output L1
0x5f6176ea8640	end

[B0]
label main
  succ: B1 

[B1]
begin
var c
var i
var j
var a
var b
var c1
c = 10
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
