
# tac list

0x5edd882f66f0	label main
0x5edd882f6730	begin
0x5edd882f3830	var a
0x5edd882f3910	var b
0x5edd882f39f0	var c
0x5edd882f3ad0	var d
0x5edd882f3bb0	var e
0x5edd882f3c90	var i
0x5edd882f3d70	var j
0x5edd882f3e50	var k
0x5edd882f3eb0	input a
0x5edd882f3f10	input b
0x5edd882f3f70	input c
0x5edd882f40a0	j = 5
0x5edd882f6270	label L1
0x5edd882f4280	var t0
0x5edd882f42c0	t0 = (j > 0)
0x5edd882f6330	ifz t0 goto L3
0x5edd882f4530	output j
0x5edd882f4660	i = 9
0x5edd882f5e50	label L4
0x5edd882f47c0	var t1
0x5edd882f4800	t1 = (i > 0)
0x5edd882f5f10	ifz t1 goto L6
0x5edd882f4a70	output i
0x5edd882f4c40	var t2
0x5edd882f4c80	t2 = b * c
0x5edd882f4d40	var t3
0x5edd882f4d80	t3 = a + t2
0x5edd882f4ee0	var t4
0x5edd882f4f20	t4 = a + c
0x5edd882f5030	var t5
0x5edd882f5070	t5 = t4 / b
0x5edd882f5130	var t6
0x5edd882f5170	t6 = t3 - t5
0x5edd882f5280	var t7
0x5edd882f52c0	t7 = t6 + 9
0x5edd882f5300	d = t7
0x5edd882f54d0	var t8
0x5edd882f5510	t8 = b * c
0x5edd882f55d0	var t9
0x5edd882f5610	t9 = a + t8
0x5edd882f5770	var t10
0x5edd882f57b0	t10 = c - a
0x5edd882f58c0	var t11
0x5edd882f5900	t11 = t10 / b
0x5edd882f59c0	var t12
0x5edd882f5a00	t12 = t9 - t11
0x5edd882f5b10	var t13
0x5edd882f5b50	t13 = t12 + 9
0x5edd882f5b90	e = t13
0x5edd882f5d90	var t14
0x5edd882f5dd0	t14 = i - 1
0x5edd882f5e10	i = t14
0x5edd882f5e90	label L5
0x5edd882f5f50	goto L4
0x5edd882f5ed0	label L6
0x5edd882f60d0	var t15
0x5edd882f6110	t15 = j - 1
0x5edd882f6150	j = t15
0x5edd882f6230	output L7
0x5edd882f62b0	label L2
0x5edd882f6370	goto L1
0x5edd882f62f0	label L3
0x5edd882f6450	output L8
0x5edd882f64e0	output d
0x5edd882f6540	output L7
0x5edd882f65d0	output e
0x5edd882f6630	output L8
0x5edd882f6770	end

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
