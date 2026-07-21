
# tac list

0x60ffa4864370	label main
0x60ffa48643b0	begin
0x60ffa485ee70	var i
0x60ffa485ef50	var j
0x60ffa485f030	var a
0x60ffa485f110	var b
0x60ffa485f1f0	var c1
0x60ffa485f450	var t0
0x60ffa485f490	t0 = &c1
0x60ffa485f550	var t1
0x60ffa485f610	t1 = t0 + 0
0x60ffa485f650	*t1 = 1
0x60ffa485f9d0	var t2
0x60ffa485fa10	t2 = &c1
0x60ffa485fad0	var t3
0x60ffa485fb90	t3 = t2 + 14
0x60ffa485fc50	var t4
0x60ffa485fd10	t4 = t3 + 1108
0x60ffa485fdd0	var t5
0x60ffa485fe10	t5 = t4 + 0
0x60ffa485fe50	*t5 = 2
0x60ffa4860420	var t6
0x60ffa4860460	t6 = &c1
0x60ffa4860520	var t7
0x60ffa4860560	t7 = t6 + 14
0x60ffa4860620	var t8
0x60ffa4860660	t8 = t7 + 1108
0x60ffa4860720	var t9
0x60ffa4860760	t9 = t8 + 14
0x60ffa4860820	var t10
0x60ffa48608e0	t10 = t9 + 162
0x60ffa48609a0	var t11
0x60ffa4860a60	t11 = t10 + 4
0x60ffa4860b20	var t12
0x60ffa4860b60	t12 = t11 + 1
0x60ffa4860ba0	c*t12 = 'b'
0x60ffa48610f0	var t13
0x60ffa4861130	t13 = &c1
0x60ffa48611f0	var t14
0x60ffa4861230	t14 = t13 + 14
0x60ffa48612f0	var t15
0x60ffa4861330	t15 = t14 + 1108
0x60ffa48613f0	var t16
0x60ffa4861430	t16 = t15 + 14
0x60ffa48614f0	var t17
0x60ffa4861530	t17 = t16 + 162
0x60ffa48615f0	var t18
0x60ffa4861630	t18 = t17 + 4
0x60ffa48616f0	var t19
0x60ffa4861730	t19 = t18 + 0
0x60ffa4861770	c*t19 = 'a'
0x60ffa48619e0	ifz 0 goto L2
0x60ffa48618a0	output L1
0x60ffa48619a0	label L2
0x60ffa4861b70	var t20
0x60ffa4861bb0	t20 = &c1
0x60ffa4861c70	var t21
0x60ffa4861cb0	t21 = t20 + 0
0x60ffa4861d70	var t22
0x60ffa4861db0	t22 = *t21
0x60ffa4861e20	i = t22
0x60ffa48620f0	var t23
0x60ffa4862130	t23 = &c1
0x60ffa48621f0	var t24
0x60ffa4862230	t24 = t23 + 14
0x60ffa48622f0	var t25
0x60ffa4862330	t25 = t24 + 1108
0x60ffa48623f0	var t26
0x60ffa4862430	t26 = t25 + 0
0x60ffa48624f0	var t27
0x60ffa4862530	t27 = *t26
0x60ffa48625a0	j = t27
0x60ffa4862a40	var t28
0x60ffa4862a80	t28 = &c1
0x60ffa4862b40	var t29
0x60ffa4862b80	t29 = t28 + 14
0x60ffa4862c40	var t30
0x60ffa4862c80	t30 = t29 + 1108
0x60ffa4862d40	var t31
0x60ffa4862d80	t31 = t30 + 14
0x60ffa4862e40	var t32
0x60ffa4862e80	t32 = t31 + 162
0x60ffa4862f40	var t33
0x60ffa4862f80	t33 = t32 + 4
0x60ffa4863040	var t34
0x60ffa4863080	t34 = t33 + 0
0x60ffa4863140	var t35
0x60ffa4863180	t35 = c*t34
0x60ffa48631f0	a = t35
0x60ffa4863690	var t36
0x60ffa48636d0	t36 = &c1
0x60ffa4863790	var t37
0x60ffa48637d0	t37 = t36 + 14
0x60ffa4863890	var t38
0x60ffa48638d0	t38 = t37 + 1108
0x60ffa4863990	var t39
0x60ffa48639d0	t39 = t38 + 14
0x60ffa4863a90	var t40
0x60ffa4863ad0	t40 = t39 + 162
0x60ffa4863b90	var t41
0x60ffa4863bd0	t41 = t40 + 4
0x60ffa4863c90	var t42
0x60ffa4863cd0	t42 = t41 + 1
0x60ffa4863d90	var t43
0x60ffa4863dd0	t43 = c*t42
0x60ffa4863e40	b = t43
0x60ffa4864010	ifz 0 goto L3
0x60ffa4863ef0	output L1
0x60ffa4863fd0	label L3
0x60ffa48640a0	output i
0x60ffa4864130	output j
0x60ffa48641c0	output a
0x60ffa4864250	output b
0x60ffa48642b0	output L1
0x60ffa48643f0	end

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
