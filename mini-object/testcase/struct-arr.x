
# tac list

0x57bddffc2780	label main
0x57bddffc27c0	begin
0x57bddffbce70	var i
0x57bddffbcf50	var j
0x57bddffbd030	var a
0x57bddffbd110	var b
0x57bddffbd1f0	var c1
0x57bddffbd450	var t0
0x57bddffbd490	t0 = &c1
0x57bddffbd550	var t1
0x57bddffbd610	t1 = t0 + 0
0x57bddffbd650	*t1 = 1
0x57bddffbd9d0	var t2
0x57bddffbda10	t2 = &c1
0x57bddffbdad0	var t3
0x57bddffbdb90	t3 = t2 + 14
0x57bddffbdc50	var t4
0x57bddffbdd10	t4 = t3 + 1108
0x57bddffbddd0	var t5
0x57bddffbde10	t5 = t4 + 0
0x57bddffbde50	*t5 = 2
0x57bddffbe420	var t6
0x57bddffbe460	t6 = &c1
0x57bddffbe520	var t7
0x57bddffbe560	t7 = t6 + 14
0x57bddffbe620	var t8
0x57bddffbe660	t8 = t7 + 1108
0x57bddffbe720	var t9
0x57bddffbe760	t9 = t8 + 14
0x57bddffbe820	var t10
0x57bddffbe8e0	t10 = t9 + 162
0x57bddffbe9a0	var t11
0x57bddffbea60	t11 = t10 + 4
0x57bddffbeb20	var t12
0x57bddffbeb60	t12 = t11 + 1
0x57bddffbeba0	c*t12 = 'b'
0x57bddffbf0f0	var t13
0x57bddffbf130	t13 = &c1
0x57bddffbf1f0	var t14
0x57bddffbf230	t14 = t13 + 14
0x57bddffbf2f0	var t15
0x57bddffbf330	t15 = t14 + 1108
0x57bddffbf3f0	var t16
0x57bddffbf430	t16 = t15 + 14
0x57bddffbf4f0	var t17
0x57bddffbf530	t17 = t16 + 162
0x57bddffbf5f0	var t18
0x57bddffbf630	t18 = t17 + 4
0x57bddffbf6f0	var t19
0x57bddffbf730	t19 = t18 + 0
0x57bddffbf770	c*t19 = 'a'
0x57bddffbf9e0	ifz 0 goto L2
0x57bddffbf8a0	output L1
0x57bddffbf9a0	label L2
0x57bddffbfb70	var t20
0x57bddffbfbb0	t20 = &c1
0x57bddffc0080	var t21
0x57bddffc00c0	t21 = t20 + 0
0x57bddffc0180	var t22
0x57bddffc01c0	t22 = *t21
0x57bddffc0230	i = t22
0x57bddffc0500	var t23
0x57bddffc0540	t23 = &c1
0x57bddffc0600	var t24
0x57bddffc0640	t24 = t23 + 14
0x57bddffc0700	var t25
0x57bddffc0740	t25 = t24 + 1108
0x57bddffc0800	var t26
0x57bddffc0840	t26 = t25 + 0
0x57bddffc0900	var t27
0x57bddffc0940	t27 = *t26
0x57bddffc09b0	j = t27
0x57bddffc0e50	var t28
0x57bddffc0e90	t28 = &c1
0x57bddffc0f50	var t29
0x57bddffc0f90	t29 = t28 + 14
0x57bddffc1050	var t30
0x57bddffc1090	t30 = t29 + 1108
0x57bddffc1150	var t31
0x57bddffc1190	t31 = t30 + 14
0x57bddffc1250	var t32
0x57bddffc1290	t32 = t31 + 162
0x57bddffc1350	var t33
0x57bddffc1390	t33 = t32 + 4
0x57bddffc1450	var t34
0x57bddffc1490	t34 = t33 + 0
0x57bddffc1550	var t35
0x57bddffc1590	t35 = c*t34
0x57bddffc1600	a = t35
0x57bddffc1aa0	var t36
0x57bddffc1ae0	t36 = &c1
0x57bddffc1ba0	var t37
0x57bddffc1be0	t37 = t36 + 14
0x57bddffc1ca0	var t38
0x57bddffc1ce0	t38 = t37 + 1108
0x57bddffc1da0	var t39
0x57bddffc1de0	t39 = t38 + 14
0x57bddffc1ea0	var t40
0x57bddffc1ee0	t40 = t39 + 162
0x57bddffc1fa0	var t41
0x57bddffc1fe0	t41 = t40 + 4
0x57bddffc20a0	var t42
0x57bddffc20e0	t42 = t41 + 1
0x57bddffc21a0	var t43
0x57bddffc21e0	t43 = c*t42
0x57bddffc2250	b = t43
0x57bddffc2420	ifz 0 goto L3
0x57bddffc2300	output L1
0x57bddffc23e0	label L3
0x57bddffc24b0	output i
0x57bddffc2540	output j
0x57bddffc25d0	output a
0x57bddffc2660	output b
0x57bddffc26c0	output L1
0x57bddffc2800	end

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
