
# tac list

0x635fe4537870	label main
0x635fe45378b0	begin
0x635fe4533840	var a
0x635fe4533920	var b
0x635fe4533a00	var c
0x635fe4533ae0	var d
0x635fe4533bc0	var e
0x635fe4533ca0	var sumd
0x635fe4533d80	var sume
0x635fe4533e60	var i
0x635fe4533f40	var j
0x635fe4534020	var k
0x635fe4534150	a = 1
0x635fe4534280	b = 2
0x635fe45343b0	c = 3
0x635fe45344e0	sumd = 0
0x635fe4534590	sume = 0
0x635fe45346c0	k = 12
0x635fe45373d0	label L1
0x635fe4534820	var t0
0x635fe4534860	t0 = (k > 0)
0x635fe4537490	ifz t0 goto L3
0x635fe4534b70	j = 15
0x635fe4537090	label L4
0x635fe4534cd0	var t1
0x635fe4534d10	t1 = (j > 0)
0x635fe4537150	ifz t1 goto L6
0x635fe4535020	i = 18
0x635fe4536d50	label L7
0x635fe4535180	var t2
0x635fe45351c0	t2 = (i > 0)
0x635fe4536e10	ifz t2 goto L9
0x635fe4535570	var t3
0x635fe45355b0	t3 = b * c
0x635fe4535670	var t4
0x635fe45356b0	t4 = a + t3
0x635fe4535810	var t5
0x635fe4535850	t5 = a + c
0x635fe4535960	var t6
0x635fe45359a0	t6 = t5 / b
0x635fe4535a60	var t7
0x635fe4535aa0	t7 = t4 - t6
0x635fe4535c30	var t8
0x635fe4535c70	t8 = t7 + 9
0x635fe4535cb0	d = t8
0x635fe4535e80	var t9
0x635fe4535ec0	t9 = b * c
0x635fe4535f80	var t10
0x635fe4535fc0	t10 = a + t9
0x635fe4536120	var t11
0x635fe4536160	t11 = c - a
0x635fe4536270	var t12
0x635fe45362b0	t12 = t11 / b
0x635fe4536370	var t13
0x635fe45363b0	t13 = t10 - t12
0x635fe4536540	var t14
0x635fe4536580	t14 = t13 + 13
0x635fe45365c0	e = t14
0x635fe4536740	var t15
0x635fe4536780	t15 = sumd + d
0x635fe45367c0	sumd = t15
0x635fe4536940	var t16
0x635fe4536980	t16 = sume + e
0x635fe4536a90	var t17
0x635fe4536ad0	t17 = t16 + d
0x635fe4536b10	sume = t17
0x635fe4536c90	var t18
0x635fe4536cd0	t18 = i - 1
0x635fe4536d10	i = t18
0x635fe4536d90	label L8
0x635fe4536e50	goto L7
0x635fe4536dd0	label L9
0x635fe4536fd0	var t19
0x635fe4537010	t19 = j - 1
0x635fe4537050	j = t19
0x635fe45370d0	label L5
0x635fe4537190	goto L4
0x635fe4537110	label L6
0x635fe4537310	var t20
0x635fe4537350	t20 = k - 1
0x635fe4537390	k = t20
0x635fe4537410	label L2
0x635fe45374d0	goto L1
0x635fe4537450	label L3
0x635fe4537560	output sumd
0x635fe4537640	output L10
0x635fe45376d0	output sume
0x635fe45377b0	output L11
0x635fe45378f0	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var b
var c
var d
var e
var sumd
var sume
var i
var j
var k
a = 1
b = 2
c = 3
sumd = 0
sume = 0
k = 12
  succ: B2 

[B2]
label L1
var t0
t0 = (k > 0)
ifz t0 goto L3
  succ: B10 B3 

[B3]
j = 15
  succ: B4 

[B4]
label L4
var t1
t1 = (j > 0)
ifz t1 goto L6
  succ: B9 B5 

[B5]
i = 18
  succ: B6 

[B6]
label L7
var t2
t2 = (i > 0)
ifz t2 goto L9
  succ: B8 B7 

[B7]
var t3
t3 = b * c
var t4
t4 = a + t3
var t5
t5 = a + c
var t6
t6 = t5 / b
var t7
t7 = t4 - t6
var t8
t8 = t7 + 9
d = t8
var t9
t9 = b * c
var t10
t10 = a + t9
var t11
t11 = c - a
var t12
t12 = t11 / b
var t13
t13 = t10 - t12
var t14
t14 = t13 + 13
e = t14
var t15
t15 = sumd + d
sumd = t15
var t16
t16 = sume + e
var t17
t17 = t16 + d
sume = t17
var t18
t18 = i - 1
i = t18
label L8
goto L7
  succ: B6 

[B8]
label L9
var t19
t19 = j - 1
j = t19
label L5
goto L4
  succ: B4 

[B9]
label L6
var t20
t20 = k - 1
k = t20
label L2
goto L1
  succ: B2 

[B10]
label L3
output sumd
output L10
output sume
output L11
end
  succ: 
