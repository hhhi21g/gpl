
# tac list

0x5b052a9f2c40	var t2
0x5b052a9f2d40	var t3
0x5b052a9f2ee0	var t4
0x5b052a9f3030	var t5
0x5b052a9f3130	var t6
0x5b052a9f34d0	var t8
0x5b052a9f35d0	var t9
0x5b052a9f3770	var t10
0x5b052a9f38c0	var t11
0x5b052a9f39c0	var t12
0x5b052a9f4d40	label main
0x5b052a9f4d80	begin
0x5b052a9f1830	var a
0x5b052a9f1910	var b
0x5b052a9f19f0	var c
0x5b052a9f1ad0	var d
0x5b052a9f1bb0	var e
0x5b052a9f1c90	var i
0x5b052a9f1d70	var j
0x5b052a9f1e50	var k
0x5b052a9f1eb0	input a
0x5b052a9f1f10	input b
0x5b052a9f1f70	input c
0x5b052a9f20a0	j = 5
0x5b052a9f2c80	t2 = b * c
0x5b052a9f2d80	t3 = a + t2
0x5b052a9f2f20	t4 = a + c
0x5b052a9f3070	t5 = t4 / b
0x5b052a9f3170	t6 = t3 - t5
0x5b052a9f3510	t8 = b * c
0x5b052a9f3610	t9 = a + t8
0x5b052a9f37b0	t10 = c - a
0x5b052a9f3900	t11 = t10 / b
0x5b052a9f3a00	t12 = t9 - t11
0x5b052a9f4940	label L1
0x5b052a9f2280	var t0
0x5b052a9f22c0	t0 = (j > 0)
0x5b052a9f4a00	ifz t0 goto L3
0x5b052a9f2530	output j
0x5b052a9f2660	i = 9
0x5b052a9f45a0	label L4
0x5b052a9f27c0	var t1
0x5b052a9f2800	t1 = (i > 0)
0x5b052a9f4660	ifz t1 goto L6
0x5b052a9f2a70	output i
0x5b052a9f3280	var t7
0x5b052a9f32c0	t7 = t6 + 9
0x5b052a9f3300	d = t7
0x5b052a9f3b10	var t13
0x5b052a9f3b50	t13 = t12 + 9
0x5b052a9f3b90	e = t13
0x5b052a9f3d90	var t14
0x5b052a9f3dd0	t14 = i - 1
0x5b052a9f3e10	i = t14
0x5b052a9f3ef0	output L7
0x5b052a9f3f80	output d
0x5b052a9f3fe0	output L7
0x5b052a9f4070	output e
0x5b052a9f4150	output L8
0x5b052a9f45e0	label L5
0x5b052a9f46a0	goto L4
0x5b052a9f4620	label L6
0x5b052a9f4820	var t15
0x5b052a9f4860	t15 = j - 1
0x5b052a9f48a0	j = t15
0x5b052a9f4900	output L7
0x5b052a9f4980	label L2
0x5b052a9f4a40	goto L1
0x5b052a9f49c0	label L3
0x5b052a9f4aa0	output L8
0x5b052a9f4b30	output d
0x5b052a9f4b90	output L7
0x5b052a9f4c20	output e
0x5b052a9f4c80	output L8
0x5b052a9f4dc0	end

[B0]
var t2
var t3
var t4
var t5
var t6
var t8
var t9
var t10
var t11
var t12
  succ: B1 

[B1]
label main
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
t2 = b * c
t3 = a + t2
t4 = a + c
t5 = t4 / b
t6 = t3 - t5
t8 = b * c
t9 = a + t8
t10 = c - a
t11 = t10 / b
t12 = t9 - t11
  succ: B2 

[B2]
label L1
var t0
t0 = (j > 0)
ifz t0 goto L3
  succ: B9 B3 

[B3]
output j
i = 9
  succ: B4 

[B4]
label L4
var t1
t1 = (i > 0)
ifz t1 goto L6
  succ: B7 B5 

[B5]
output i
var t7
t7 = t6 + 9
d = t7
var t13
t13 = t12 + 9
e = t13
var t14
t14 = i - 1
i = t14
output L7
output d
output L7
output e
output L8
  succ: B6 

[B6]
label L5
goto L4
  succ: B4 

[B7]
label L6
var t15
t15 = j - 1
j = t15
output L7
  succ: B8 

[B8]
label L2
goto L1
  succ: B2 

[B9]
label L3
output L8
output d
output L7
output e
output L8
end
  succ: 
