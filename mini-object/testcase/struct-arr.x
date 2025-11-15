
# tac list

0x5f0ee8891780	label main
0x5f0ee88917c0	begin
0x5f0ee888be70	var i
0x5f0ee888bf50	var j
0x5f0ee888c030	var a
0x5f0ee888c110	var b
0x5f0ee888c1f0	var c1
0x5f0ee888c450	var t0
0x5f0ee888c490	t0 = &c1
0x5f0ee888c550	var t1
0x5f0ee888c610	t1 = t0 + 0
0x5f0ee888c650	*t1 = 1
0x5f0ee888c9d0	var t2
0x5f0ee888ca10	t2 = &c1
0x5f0ee888cad0	var t3
0x5f0ee888cb90	t3 = t2 + 14
0x5f0ee888cc50	var t4
0x5f0ee888cd10	t4 = t3 + 1108
0x5f0ee888cdd0	var t5
0x5f0ee888ce10	t5 = t4 + 0
0x5f0ee888ce50	*t5 = 2
0x5f0ee888d420	var t6
0x5f0ee888d460	t6 = &c1
0x5f0ee888d520	var t7
0x5f0ee888d560	t7 = t6 + 14
0x5f0ee888d620	var t8
0x5f0ee888d660	t8 = t7 + 1108
0x5f0ee888d720	var t9
0x5f0ee888d760	t9 = t8 + 14
0x5f0ee888d820	var t10
0x5f0ee888d8e0	t10 = t9 + 162
0x5f0ee888d9a0	var t11
0x5f0ee888da60	t11 = t10 + 4
0x5f0ee888db20	var t12
0x5f0ee888db60	t12 = t11 + 1
0x5f0ee888dba0	c*t12 = 'b'
0x5f0ee888e0f0	var t13
0x5f0ee888e130	t13 = &c1
0x5f0ee888e1f0	var t14
0x5f0ee888e230	t14 = t13 + 14
0x5f0ee888e2f0	var t15
0x5f0ee888e330	t15 = t14 + 1108
0x5f0ee888e3f0	var t16
0x5f0ee888e430	t16 = t15 + 14
0x5f0ee888e4f0	var t17
0x5f0ee888e530	t17 = t16 + 162
0x5f0ee888e5f0	var t18
0x5f0ee888e630	t18 = t17 + 4
0x5f0ee888e6f0	var t19
0x5f0ee888e730	t19 = t18 + 0
0x5f0ee888e770	c*t19 = 'a'
0x5f0ee888e9e0	ifz 0 goto L2
0x5f0ee888e8a0	output L1
0x5f0ee888e9a0	label L2
0x5f0ee888eb70	var t20
0x5f0ee888ebb0	t20 = &c1
0x5f0ee888ec70	var t21
0x5f0ee888ecb0	t21 = t20 + 0
0x5f0ee888ed70	var t22
0x5f0ee888edb0	t22 = *t21
0x5f0ee888ee20	i = t22
0x5f0ee888f0f0	var t23
0x5f0ee888f130	t23 = &c1
0x5f0ee888f1f0	var t24
0x5f0ee888f230	t24 = t23 + 14
0x5f0ee888f2f0	var t25
0x5f0ee888f330	t25 = t24 + 1108
0x5f0ee888f3f0	var t26
0x5f0ee888f430	t26 = t25 + 0
0x5f0ee888f4f0	var t27
0x5f0ee888f530	t27 = *t26
0x5f0ee888f5a0	j = t27
0x5f0ee888fa40	var t28
0x5f0ee888fa80	t28 = &c1
0x5f0ee888fb40	var t29
0x5f0ee888fb80	t29 = t28 + 14
0x5f0ee888fc40	var t30
0x5f0ee888fc80	t30 = t29 + 1108
0x5f0ee888fd40	var t31
0x5f0ee888fd80	t31 = t30 + 14
0x5f0ee888fe40	var t32
0x5f0ee888fe80	t32 = t31 + 162
0x5f0ee888ff40	var t33
0x5f0ee888ff80	t33 = t32 + 4
0x5f0ee8890040	var t34
0x5f0ee8890080	t34 = t33 + 0
0x5f0ee8890140	var t35
0x5f0ee8890180	t35 = c*t34
0x5f0ee88901f0	a = t35
0x5f0ee8890690	var t36
0x5f0ee88906d0	t36 = &c1
0x5f0ee8890790	var t37
0x5f0ee88907d0	t37 = t36 + 14
0x5f0ee8890890	var t38
0x5f0ee88908d0	t38 = t37 + 1108
0x5f0ee8890990	var t39
0x5f0ee88909d0	t39 = t38 + 14
0x5f0ee8890a90	var t40
0x5f0ee8890ad0	t40 = t39 + 162
0x5f0ee8890b90	var t41
0x5f0ee8890bd0	t41 = t40 + 4
0x5f0ee8890c90	var t42
0x5f0ee8890cd0	t42 = t41 + 1
0x5f0ee8890d90	var t43
0x5f0ee8890dd0	t43 = c*t42
0x5f0ee8890e40	b = t43
0x5f0ee8891010	ifz 0 goto L3
0x5f0ee8890ef0	output L1
0x5f0ee8890fd0	label L3
0x5f0ee88914b0	output i
0x5f0ee8891540	output j
0x5f0ee88915d0	output a
0x5f0ee8891660	output b
0x5f0ee88916c0	output L1
0x5f0ee8891800	end

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
