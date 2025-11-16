
# tac list

0x5ecf701ee280	label main
0x5ecf701ee2c0	begin
0x5ecf701e7e70	var i
0x5ecf701e7f50	var j
0x5ecf701e8030	var a
0x5ecf701e8110	var b
0x5ecf701e8380	vararray cls[1D]
0x5ecf701e8690	var t0
0x5ecf701e86d0	t0 = &cls
0x5ecf701e8790	var t1
0x5ecf701e8910	var t2
0x5ecf701e8950	t2 = t0
0x5ecf701e8990	*t2 = 1
0x5ecf701e8dc0	var t3
0x5ecf701e8e00	t3 = &cls
0x5ecf701e8ec0	var t4
0x5ecf701e8fc0	var t5
0x5ecf701e9080	t5 = t3 + 14
0x5ecf701e9140	var t6
0x5ecf701e9200	t6 = t5 + 1108
0x5ecf701e92c0	var t7
0x5ecf701e9300	t7 = t6
0x5ecf701e9340	*t7 = 2
0x5ecf701e99c0	var t8
0x5ecf701e9a00	t8 = &cls
0x5ecf701e9ac0	var t9
0x5ecf701e9bc0	var t10
0x5ecf701e9c00	t10 = t8 + 14
0x5ecf701e9cc0	var t11
0x5ecf701e9d00	t11 = t10 + 1108
0x5ecf701e9dc0	var t12
0x5ecf701e9e00	t12 = t11 + 14
0x5ecf701e9ec0	var t13
0x5ecf701e9f80	t13 = t12 + 162
0x5ecf701ea040	var t14
0x5ecf701ea100	t14 = t13 + 4
0x5ecf701ea1c0	var t15
0x5ecf701ea200	t15 = t14 + 1
0x5ecf701ea240	c*t15 = 'b'
0x5ecf701ea840	var t16
0x5ecf701ea880	t16 = &cls
0x5ecf701ea940	var t17
0x5ecf701eaa40	var t18
0x5ecf701eaa80	t18 = t16 + 14
0x5ecf701eab40	var t19
0x5ecf701eab80	t19 = t18 + 1108
0x5ecf701eac40	var t20
0x5ecf701eac80	t20 = t19 + 14
0x5ecf701ead40	var t21
0x5ecf701ead80	t21 = t20 + 162
0x5ecf701eae40	var t22
0x5ecf701eae80	t22 = t21 + 4
0x5ecf701eaf40	var t23
0x5ecf701eaf80	t23 = t22
0x5ecf701eafc0	c*t23 = 'a'
0x5ecf701eb230	ifz 0 goto L2
0x5ecf701eb0f0	output L1
0x5ecf701eb1f0	label L2
0x5ecf701eb470	var t24
0x5ecf701eb4b0	t24 = &cls
0x5ecf701eb570	var t25
0x5ecf701eb670	var t26
0x5ecf701eb770	var t27
0x5ecf701eb7b0	t27 = *t24
0x5ecf701eb820	i = t27
0x5ecf701ebba0	var t28
0x5ecf701ebbe0	t28 = &cls
0x5ecf701ebca0	var t29
0x5ecf701ebda0	var t30
0x5ecf701ebde0	t30 = t28 + 14
0x5ecf701ebea0	var t31
0x5ecf701ebee0	t31 = t30 + 1108
0x5ecf701ebfa0	var t32
0x5ecf701ec0a0	var t33
0x5ecf701ec0e0	t33 = *t31
0x5ecf701ec150	j = t33
0x5ecf701ec6a0	var t34
0x5ecf701ec6e0	t34 = &cls
0x5ecf701ec7a0	var t35
0x5ecf701ec8a0	var t36
0x5ecf701ec8e0	t36 = t34 + 14
0x5ecf701ec9a0	var t37
0x5ecf701ec9e0	t37 = t36 + 1108
0x5ecf701ecaa0	var t38
0x5ecf701ecae0	t38 = t37 + 14
0x5ecf701ecba0	var t39
0x5ecf701ecbe0	t39 = t38 + 162
0x5ecf701ecca0	var t40
0x5ecf701ecce0	t40 = t39 + 4
0x5ecf701ecda0	var t41
0x5ecf701ecea0	var t42
0x5ecf701ecee0	t42 = c*t40
0x5ecf701ecf50	a = t42
0x5ecf701ed4a0	var t43
0x5ecf701ed4e0	t43 = &cls
0x5ecf701ed5a0	var t44
0x5ecf701ed6a0	var t45
0x5ecf701ed6e0	t45 = t43 + 14
0x5ecf701ed7a0	var t46
0x5ecf701ed7e0	t46 = t45 + 1108
0x5ecf701ed8a0	var t47
0x5ecf701ed8e0	t47 = t46 + 14
0x5ecf701ed9a0	var t48
0x5ecf701ed9e0	t48 = t47 + 162
0x5ecf701edaa0	var t49
0x5ecf701edae0	t49 = t48 + 4
0x5ecf701edba0	var t50
0x5ecf701edbe0	t50 = t49 + 1
0x5ecf701edca0	var t51
0x5ecf701edce0	t51 = c*t50
0x5ecf701edd50	b = t51
0x5ecf701edf20	ifz 0 goto L3
0x5ecf701ede00	output L1
0x5ecf701edee0	label L3
0x5ecf701edfb0	output i
0x5ecf701ee040	output j
0x5ecf701ee0d0	output a
0x5ecf701ee160	output b
0x5ecf701ee1c0	output L1
0x5ecf701ee300	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
var a
var b
vararray cls[1D]
var t0
t0 = &cls
var t1
var t2
t2 = t0
*t2 = 1
var t3
t3 = &cls
var t4
var t5
t5 = t3 + 14
var t6
t6 = t5 + 1108
var t7
t7 = t6
*t7 = 2
var t8
t8 = &cls
var t9
var t10
t10 = t8 + 14
var t11
t11 = t10 + 1108
var t12
t12 = t11 + 14
var t13
t13 = t12 + 162
var t14
t14 = t13 + 4
var t15
t15 = t14 + 1
c*t15 = 'b'
var t16
t16 = &cls
var t17
var t18
t18 = t16 + 14
var t19
t19 = t18 + 1108
var t20
t20 = t19 + 14
var t21
t21 = t20 + 162
var t22
t22 = t21 + 4
var t23
t23 = t22
c*t23 = 'a'
ifz 0 goto L2
  succ: B3 B2 

[B2]
output L1
  succ: B3 

[B3]
label L2
var t24
t24 = &cls
var t25
var t26
var t27
t27 = *t24
i = t27
var t28
t28 = &cls
var t29
var t30
t30 = t28 + 14
var t31
t31 = t30 + 1108
var t32
var t33
t33 = *t31
j = t33
var t34
t34 = &cls
var t35
var t36
t36 = t34 + 14
var t37
t37 = t36 + 1108
var t38
t38 = t37 + 14
var t39
t39 = t38 + 162
var t40
t40 = t39 + 4
var t41
var t42
t42 = c*t40
a = t42
var t43
t43 = &cls
var t44
var t45
t45 = t43 + 14
var t46
t46 = t45 + 1108
var t47
t47 = t46 + 14
var t48
t48 = t47 + 162
var t49
t49 = t48 + 4
var t50
t50 = t49 + 1
var t51
t51 = c*t50
b = t51
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
