
# tac list

0x602485b41370	label main
0x602485b413b0	begin
0x602485b3be70	var i
0x602485b3bf50	var j
0x602485b3c030	var a
0x602485b3c110	var b
0x602485b3c1f0	var c1
0x602485b3c450	var t0
0x602485b3c490	t0 = &c1
0x602485b3c550	var t1
0x602485b3c610	t1 = t0 + 0
0x602485b3c650	*t1 = 1
0x602485b3c9d0	var t2
0x602485b3ca10	t2 = &c1
0x602485b3cad0	var t3
0x602485b3cb90	t3 = t2 + 14
0x602485b3cc50	var t4
0x602485b3cd10	t4 = t3 + 1108
0x602485b3cdd0	var t5
0x602485b3ce10	t5 = t4 + 0
0x602485b3ce50	*t5 = 2
0x602485b3d420	var t6
0x602485b3d460	t6 = &c1
0x602485b3d520	var t7
0x602485b3d560	t7 = t6 + 14
0x602485b3d620	var t8
0x602485b3d660	t8 = t7 + 1108
0x602485b3d720	var t9
0x602485b3d760	t9 = t8 + 14
0x602485b3d820	var t10
0x602485b3d8e0	t10 = t9 + 162
0x602485b3d9a0	var t11
0x602485b3da60	t11 = t10 + 4
0x602485b3db20	var t12
0x602485b3db60	t12 = t11 + 1
0x602485b3dba0	c*t12 = 'b'
0x602485b3e0f0	var t13
0x602485b3e130	t13 = &c1
0x602485b3e1f0	var t14
0x602485b3e230	t14 = t13 + 14
0x602485b3e2f0	var t15
0x602485b3e330	t15 = t14 + 1108
0x602485b3e3f0	var t16
0x602485b3e430	t16 = t15 + 14
0x602485b3e4f0	var t17
0x602485b3e530	t17 = t16 + 162
0x602485b3e5f0	var t18
0x602485b3e630	t18 = t17 + 4
0x602485b3e6f0	var t19
0x602485b3e730	t19 = t18 + 0
0x602485b3e770	c*t19 = 'a'
0x602485b3e9e0	ifz 0 goto L2
0x602485b3e8a0	output L1
0x602485b3e9a0	label L2
0x602485b3eb70	var t20
0x602485b3ebb0	t20 = &c1
0x602485b3ec70	var t21
0x602485b3ecb0	t21 = t20 + 0
0x602485b3ed70	var t22
0x602485b3edb0	t22 = *t21
0x602485b3ee20	i = t22
0x602485b3f0f0	var t23
0x602485b3f130	t23 = &c1
0x602485b3f1f0	var t24
0x602485b3f230	t24 = t23 + 14
0x602485b3f2f0	var t25
0x602485b3f330	t25 = t24 + 1108
0x602485b3f3f0	var t26
0x602485b3f430	t26 = t25 + 0
0x602485b3f4f0	var t27
0x602485b3f530	t27 = *t26
0x602485b3f5a0	j = t27
0x602485b3fa40	var t28
0x602485b3fa80	t28 = &c1
0x602485b3fb40	var t29
0x602485b3fb80	t29 = t28 + 14
0x602485b3fc40	var t30
0x602485b3fc80	t30 = t29 + 1108
0x602485b3fd40	var t31
0x602485b3fd80	t31 = t30 + 14
0x602485b3fe40	var t32
0x602485b3fe80	t32 = t31 + 162
0x602485b3ff40	var t33
0x602485b3ff80	t33 = t32 + 4
0x602485b40040	var t34
0x602485b40080	t34 = t33 + 0
0x602485b40140	var t35
0x602485b40180	t35 = c*t34
0x602485b401f0	a = t35
0x602485b40690	var t36
0x602485b406d0	t36 = &c1
0x602485b40790	var t37
0x602485b407d0	t37 = t36 + 14
0x602485b40890	var t38
0x602485b408d0	t38 = t37 + 1108
0x602485b40990	var t39
0x602485b409d0	t39 = t38 + 14
0x602485b40a90	var t40
0x602485b40ad0	t40 = t39 + 162
0x602485b40b90	var t41
0x602485b40bd0	t41 = t40 + 4
0x602485b40c90	var t42
0x602485b40cd0	t42 = t41 + 1
0x602485b40d90	var t43
0x602485b40dd0	t43 = c*t42
0x602485b40e40	b = t43
0x602485b41010	ifz 0 goto L3
0x602485b40ef0	output L1
0x602485b40fd0	label L3
0x602485b410a0	output i
0x602485b41130	output j
0x602485b411c0	output a
0x602485b41250	output b
0x602485b412b0	output L1
0x602485b413f0	end

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
