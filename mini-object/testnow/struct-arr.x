
# tac list

0x60c48ad845c0	label main
0x60c48ad84600	begin
0x60c48ad7ee50	var c
0x60c48ad7ef20	var i
0x60c48ad7eff0	var j
0x60c48ad7f0c0	var a
0x60c48ad7f190	var b
0x60c48ad7f260	var c1
0x60c48ad7f440	c = 10
0x60c48ad7f610	var t0
0x60c48ad7f650	t0 = &c1
0x60c48ad7f700	var t1
0x60c48ad7f7b0	t1 = t0 + 0
0x60c48ad7f7f0	*t1 = 1
0x60c48ad7fb50	var t2
0x60c48ad7fb90	t2 = &c1
0x60c48ad7fc40	var t3
0x60c48ad7fcf0	t3 = t2 + 14
0x60c48ad7fda0	var t4
0x60c48ad7fe50	t4 = t3 + 1108
0x60c48ad7ff00	var t5
0x60c48ad7ff40	t5 = t4 + 0
0x60c48ad7ff80	*t5 = 2
0x60c48ad80520	var t6
0x60c48ad80560	t6 = &c1
0x60c48ad80610	var t7
0x60c48ad80650	t7 = t6 + 14
0x60c48ad80700	var t8
0x60c48ad80740	t8 = t7 + 1108
0x60c48ad807f0	var t9
0x60c48ad80830	t9 = t8 + 14
0x60c48ad808e0	var t10
0x60c48ad80990	t10 = t9 + 162
0x60c48ad80a40	var t11
0x60c48ad80af0	t11 = t10 + 4
0x60c48ad80ba0	var t12
0x60c48ad80be0	t12 = t11 + 1
0x60c48ad80c20	c*t12 = 'b'
0x60c48ad81150	var t13
0x60c48ad81190	t13 = &c1
0x60c48ad81240	var t14
0x60c48ad81280	t14 = t13 + 14
0x60c48ad81330	var t15
0x60c48ad81370	t15 = t14 + 1108
0x60c48ad81420	var t16
0x60c48ad81460	t16 = t15 + 14
0x60c48ad81510	var t17
0x60c48ad81550	t17 = t16 + 162
0x60c48ad81600	var t18
0x60c48ad81640	t18 = t17 + 4
0x60c48ad816f0	var t19
0x60c48ad81730	t19 = t18 + 0
0x60c48ad81770	c*t19 = 'a'
0x60c48ad819c0	ifz 0 goto L2
0x60c48ad81890	output L1
0x60c48ad81980	label L2
0x60c48ad81b40	var t20
0x60c48ad81b80	t20 = &c1
0x60c48ad82040	var t21
0x60c48ad82080	t21 = t20 + 0
0x60c48ad82130	var t22
0x60c48ad82170	t22 = *t21
0x60c48ad821e0	i = t22
0x60c48ad824a0	var t23
0x60c48ad824e0	t23 = &c1
0x60c48ad82590	var t24
0x60c48ad825d0	t24 = t23 + 14
0x60c48ad82680	var t25
0x60c48ad826c0	t25 = t24 + 1108
0x60c48ad82770	var t26
0x60c48ad827b0	t26 = t25 + 0
0x60c48ad82860	var t27
0x60c48ad828a0	t27 = *t26
0x60c48ad82910	j = t27
0x60c48ad82da0	var t28
0x60c48ad82de0	t28 = &c1
0x60c48ad82e90	var t29
0x60c48ad82ed0	t29 = t28 + 14
0x60c48ad82f80	var t30
0x60c48ad82fc0	t30 = t29 + 1108
0x60c48ad83070	var t31
0x60c48ad830b0	t31 = t30 + 14
0x60c48ad83160	var t32
0x60c48ad831a0	t32 = t31 + 162
0x60c48ad83250	var t33
0x60c48ad83290	t33 = t32 + 4
0x60c48ad83340	var t34
0x60c48ad83380	t34 = t33 + 0
0x60c48ad83430	var t35
0x60c48ad83470	t35 = c*t34
0x60c48ad834e0	a = t35
0x60c48ad83970	var t36
0x60c48ad839b0	t36 = &c1
0x60c48ad83a60	var t37
0x60c48ad83aa0	t37 = t36 + 14
0x60c48ad83b50	var t38
0x60c48ad83b90	t38 = t37 + 1108
0x60c48ad83c40	var t39
0x60c48ad83c80	t39 = t38 + 14
0x60c48ad83d30	var t40
0x60c48ad83d70	t40 = t39 + 162
0x60c48ad83e20	var t41
0x60c48ad83e60	t41 = t40 + 4
0x60c48ad83f10	var t42
0x60c48ad83f50	t42 = t41 + 1
0x60c48ad84000	var t43
0x60c48ad84040	t43 = c*t42
0x60c48ad840b0	b = t43
0x60c48ad84270	ifz 0 goto L3
0x60c48ad84160	output L1
0x60c48ad84230	label L3
0x60c48ad84300	output i
0x60c48ad84390	output j
0x60c48ad84420	output a
0x60c48ad844b0	output b
0x60c48ad84510	output L1
0x60c48ad84640	end

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
