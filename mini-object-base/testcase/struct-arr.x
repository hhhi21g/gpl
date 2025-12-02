
# tac list

0x6249db97c370	label main
0x6249db97c3b0	begin
0x6249db976e70	var i
0x6249db976f50	var j
0x6249db977030	var a
0x6249db977110	var b
0x6249db9771f0	var c1
0x6249db977450	var t0
0x6249db977490	t0 = &c1
0x6249db977550	var t1
0x6249db977610	t1 = t0 + 0
0x6249db977650	*t1 = 1
0x6249db9779d0	var t2
0x6249db977a10	t2 = &c1
0x6249db977ad0	var t3
0x6249db977b90	t3 = t2 + 14
0x6249db977c50	var t4
0x6249db977d10	t4 = t3 + 1108
0x6249db977dd0	var t5
0x6249db977e10	t5 = t4 + 0
0x6249db977e50	*t5 = 2
0x6249db978420	var t6
0x6249db978460	t6 = &c1
0x6249db978520	var t7
0x6249db978560	t7 = t6 + 14
0x6249db978620	var t8
0x6249db978660	t8 = t7 + 1108
0x6249db978720	var t9
0x6249db978760	t9 = t8 + 14
0x6249db978820	var t10
0x6249db9788e0	t10 = t9 + 162
0x6249db9789a0	var t11
0x6249db978a60	t11 = t10 + 4
0x6249db978b20	var t12
0x6249db978b60	t12 = t11 + 1
0x6249db978ba0	c*t12 = 'b'
0x6249db9790f0	var t13
0x6249db979130	t13 = &c1
0x6249db9791f0	var t14
0x6249db979230	t14 = t13 + 14
0x6249db9792f0	var t15
0x6249db979330	t15 = t14 + 1108
0x6249db9793f0	var t16
0x6249db979430	t16 = t15 + 14
0x6249db9794f0	var t17
0x6249db979530	t17 = t16 + 162
0x6249db9795f0	var t18
0x6249db979630	t18 = t17 + 4
0x6249db9796f0	var t19
0x6249db979730	t19 = t18 + 0
0x6249db979770	c*t19 = 'a'
0x6249db9799e0	ifz 0 goto L2
0x6249db9798a0	output L1
0x6249db9799a0	label L2
0x6249db979b70	var t20
0x6249db979bb0	t20 = &c1
0x6249db979c70	var t21
0x6249db979cb0	t21 = t20 + 0
0x6249db979d70	var t22
0x6249db979db0	t22 = *t21
0x6249db979e20	i = t22
0x6249db97a0f0	var t23
0x6249db97a130	t23 = &c1
0x6249db97a1f0	var t24
0x6249db97a230	t24 = t23 + 14
0x6249db97a2f0	var t25
0x6249db97a330	t25 = t24 + 1108
0x6249db97a3f0	var t26
0x6249db97a430	t26 = t25 + 0
0x6249db97a4f0	var t27
0x6249db97a530	t27 = *t26
0x6249db97a5a0	j = t27
0x6249db97aa40	var t28
0x6249db97aa80	t28 = &c1
0x6249db97ab40	var t29
0x6249db97ab80	t29 = t28 + 14
0x6249db97ac40	var t30
0x6249db97ac80	t30 = t29 + 1108
0x6249db97ad40	var t31
0x6249db97ad80	t31 = t30 + 14
0x6249db97ae40	var t32
0x6249db97ae80	t32 = t31 + 162
0x6249db97af40	var t33
0x6249db97af80	t33 = t32 + 4
0x6249db97b040	var t34
0x6249db97b080	t34 = t33 + 0
0x6249db97b140	var t35
0x6249db97b180	t35 = c*t34
0x6249db97b1f0	a = t35
0x6249db97b690	var t36
0x6249db97b6d0	t36 = &c1
0x6249db97b790	var t37
0x6249db97b7d0	t37 = t36 + 14
0x6249db97b890	var t38
0x6249db97b8d0	t38 = t37 + 1108
0x6249db97b990	var t39
0x6249db97b9d0	t39 = t38 + 14
0x6249db97ba90	var t40
0x6249db97bad0	t40 = t39 + 162
0x6249db97bb90	var t41
0x6249db97bbd0	t41 = t40 + 4
0x6249db97bc90	var t42
0x6249db97bcd0	t42 = t41 + 1
0x6249db97bd90	var t43
0x6249db97bdd0	t43 = c*t42
0x6249db97be40	b = t43
0x6249db97c010	ifz 0 goto L3
0x6249db97bef0	output L1
0x6249db97bfd0	label L3
0x6249db97c0a0	output i
0x6249db97c130	output j
0x6249db97c1c0	output a
0x6249db97c250	output b
0x6249db97c2b0	output L1
0x6249db97c3f0	end

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
