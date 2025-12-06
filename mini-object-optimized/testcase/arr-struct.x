
# tac list

0x5794b1c05280	label main
0x5794b1c052c0	begin
0x5794b1bfee70	var i
0x5794b1bfef50	var j
0x5794b1bff030	var a
0x5794b1bff110	var b
0x5794b1bff380	vararray cls[1D]
0x5794b1bff690	var t0
0x5794b1bff6d0	t0 = &cls
0x5794b1bff790	var t1
0x5794b1bff910	var t2
0x5794b1bff990	*t2 = 1
0x5794b1bffdc0	var t3
0x5794b1bffe00	t3 = &cls
0x5794b1bffec0	var t4
0x5794b1bfffc0	var t5
0x5794b1c00140	var t6
0x5794b1c002c0	var t7
0x5794b1c00340	*t7 = 2
0x5794b1c009c0	var t8
0x5794b1c00a00	t8 = &cls
0x5794b1c00ac0	var t9
0x5794b1c00bc0	var t10
0x5794b1c00cc0	var t11
0x5794b1c00dc0	var t12
0x5794b1c00ec0	var t13
0x5794b1c01040	var t14
0x5794b1c011c0	var t15
0x5794b1c01240	c*t15 = 'b'
0x5794b1c01840	var t16
0x5794b1c01880	t16 = &cls
0x5794b1c01940	var t17
0x5794b1c01a40	var t18
0x5794b1c01b40	var t19
0x5794b1c01c40	var t20
0x5794b1c01d40	var t21
0x5794b1c01e40	var t22
0x5794b1c01f40	var t23
0x5794b1c01fc0	c*t23 = 'a'
0x5794b1c02230	ifz 0 goto L2
0x5794b1c020f0	output L1
0x5794b1c021f0	label L2
0x5794b1c02470	var t24
0x5794b1c024b0	t24 = &cls
0x5794b1c02570	var t25
0x5794b1c02670	var t26
0x5794b1c02770	var t27
0x5794b1c027b0	t27 = *t26
0x5794b1c02820	i = t27
0x5794b1c02ba0	var t28
0x5794b1c02be0	t28 = &cls
0x5794b1c02ca0	var t29
0x5794b1c02da0	var t30
0x5794b1c02ea0	var t31
0x5794b1c02fa0	var t32
0x5794b1c030a0	var t33
0x5794b1c030e0	t33 = *t32
0x5794b1c03150	j = t33
0x5794b1c036a0	var t34
0x5794b1c036e0	t34 = &cls
0x5794b1c037a0	var t35
0x5794b1c038a0	var t36
0x5794b1c039a0	var t37
0x5794b1c03aa0	var t38
0x5794b1c03ba0	var t39
0x5794b1c03ca0	var t40
0x5794b1c03da0	var t41
0x5794b1c03ea0	var t42
0x5794b1c03ee0	t42 = c*t41
0x5794b1c03f50	a = t42
0x5794b1c044a0	var t43
0x5794b1c044e0	t43 = &cls
0x5794b1c045a0	var t44
0x5794b1c046a0	var t45
0x5794b1c047a0	var t46
0x5794b1c048a0	var t47
0x5794b1c049a0	var t48
0x5794b1c04aa0	var t49
0x5794b1c04ba0	var t50
0x5794b1c04ca0	var t51
0x5794b1c04ce0	t51 = c*t50
0x5794b1c04d50	b = t51
0x5794b1c04f20	ifz 0 goto L3
0x5794b1c04e00	output L1
0x5794b1c04ee0	label L3
0x5794b1c04fb0	output i
0x5794b1c05040	output j
0x5794b1c050d0	output a
0x5794b1c05160	output b
0x5794b1c051c0	output L1
0x5794b1c05300	end

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
*t2 = 1
var t3
t3 = &cls
var t4
var t5
var t6
var t7
*t7 = 2
var t8
t8 = &cls
var t9
var t10
var t11
var t12
var t13
var t14
var t15
c*t15 = 'b'
var t16
t16 = &cls
var t17
var t18
var t19
var t20
var t21
var t22
var t23
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
t27 = *t26
i = t27
var t28
t28 = &cls
var t29
var t30
var t31
var t32
var t33
t33 = *t32
j = t33
var t34
t34 = &cls
var t35
var t36
var t37
var t38
var t39
var t40
var t41
var t42
t42 = c*t41
a = t42
var t43
t43 = &cls
var t44
var t45
var t46
var t47
var t48
var t49
var t50
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
