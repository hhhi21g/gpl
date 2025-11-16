
# tac list

0x5853927f9b00	label main
0x5853927f9b40	begin
0x5853927f6830	var a
0x5853927f6910	var b
0x5853927f69f0	var c
0x5853927f6ad0	var d
0x5853927f6bb0	var e
0x5853927f6c90	var i
0x5853927f6d70	var j
0x5853927f6e50	var k
0x5853927f6eb0	input a
0x5853927f6f10	input b
0x5853927f6f70	input c
0x5853927f70a0	j = 5
0x5853927f9680	label L1
0x5853927f7280	var t0
0x5853927f72c0	t0 = (j > 0)
0x5853927f9740	ifz t0 goto L3
0x5853927f7530	output j
0x5853927f7660	i = 9
0x5853927f9260	label L4
0x5853927f77c0	var t1
0x5853927f7800	t1 = (i > 0)
0x5853927f9320	ifz t1 goto L6
0x5853927f7a70	output i
0x5853927f7c40	var t2
0x5853927f7c80	t2 = b * c
0x5853927f7d40	var t3
0x5853927f7d80	t3 = a + t2
0x5853927f7ee0	var t4
0x5853927f7f20	t4 = a + c
0x5853927f8030	var t5
0x5853927f8070	t5 = t4 / b
0x5853927f8130	var t6
0x5853927f8170	t6 = t3 - t5
0x5853927f8280	var t7
0x5853927f82c0	t7 = t6 + 9
0x5853927f8300	d = t7
0x5853927f84d0	var t8
0x5853927f8510	t8 = b * c
0x5853927f85d0	var t9
0x5853927f8610	t9 = a + t8
0x5853927f8770	var t10
0x5853927f87b0	t10 = c - a
0x5853927f88c0	var t11
0x5853927f8900	t11 = t10 / b
0x5853927f89c0	var t12
0x5853927f8a00	t12 = t9 - t11
0x5853927f8b10	var t13
0x5853927f8b50	t13 = t12 + 9
0x5853927f8b90	e = t13
0x5853927f8d90	var t14
0x5853927f8dd0	t14 = i - 1
0x5853927f8e10	i = t14
0x5853927f92a0	label L5
0x5853927f9360	goto L4
0x5853927f92e0	label L6
0x5853927f94e0	var t15
0x5853927f9520	t15 = j - 1
0x5853927f9560	j = t15
0x5853927f9640	output L7
0x5853927f96c0	label L2
0x5853927f9780	goto L1
0x5853927f9700	label L3
0x5853927f9860	output L8
0x5853927f98f0	output d
0x5853927f9950	output L7
0x5853927f99e0	output e
0x5853927f9a40	output L8
0x5853927f9b80	end

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
var i
var j
var k
input a
input b
input c
j = 5
  succ: B2 

[B2]
label L1
var t0
t0 = (j > 0)
ifz t0 goto L3
  succ: B7 B3 

[B3]
output j
i = 9
  succ: B4 

[B4]
label L4
var t1
t1 = (i > 0)
ifz t1 goto L6
  succ: B6 B5 

[B5]
output i
var t2
t2 = b * c
var t3
t3 = a + t2
var t4
t4 = a + c
var t5
t5 = t4 / b
var t6
t6 = t3 - t5
var t7
t7 = t6 + 9
d = t7
var t8
t8 = b * c
var t9
t9 = a + t8
var t10
t10 = c - a
var t11
t11 = t10 / b
var t12
t12 = t9 - t11
var t13
t13 = t12 + 9
e = t13
var t14
t14 = i - 1
i = t14
label L5
goto L4
  succ: B4 

[B6]
label L6
var t15
t15 = j - 1
j = t15
output L7
label L2
goto L1
  succ: B2 

[B7]
label L3
output L8
output d
output L7
output e
output L8
end
  succ: 
