
# tac list

0x64d3b64d3c40	var t2
0x64d3b64d3d40	var t3
0x64d3b64d3ee0	var t4
0x64d3b64d4030	var t5
0x64d3b64d4130	var t6
0x64d3b64d44d0	var t8
0x64d3b64d45d0	var t9
0x64d3b64d4770	var t10
0x64d3b64d48c0	var t11
0x64d3b64d49c0	var t12
0x64d3b64d5b00	label main
0x64d3b64d5b40	begin
0x64d3b64d2830	var a
0x64d3b64d2910	var b
0x64d3b64d29f0	var c
0x64d3b64d2ad0	var d
0x64d3b64d2bb0	var e
0x64d3b64d2c90	var i
0x64d3b64d2d70	var j
0x64d3b64d2e50	var k
0x64d3b64d2eb0	input a
0x64d3b64d2f10	input b
0x64d3b64d2f70	input c
0x64d3b64d30a0	j = 5
0x64d3b64d3c80	t2 = b * c
0x64d3b64d3d80	t3 = a + t2
0x64d3b64d3f20	t4 = a + c
0x64d3b64d4070	t5 = t4 / b
0x64d3b64d4170	t6 = t3 - t5
0x64d3b64d4510	t8 = b * c
0x64d3b64d4610	t9 = a + t8
0x64d3b64d47b0	t10 = c - a
0x64d3b64d4900	t11 = t10 / b
0x64d3b64d4a00	t12 = t9 - t11
0x64d3b64d5680	label L1
0x64d3b64d3280	var t0
0x64d3b64d32c0	t0 = (j > 0)
0x64d3b64d5740	ifz t0 goto L3
0x64d3b64d3530	output j
0x64d3b64d3660	i = 9
0x64d3b64d5260	label L4
0x64d3b64d37c0	var t1
0x64d3b64d3800	t1 = (i > 0)
0x64d3b64d5320	ifz t1 goto L6
0x64d3b64d3a70	output i
0x64d3b64d4280	var t7
0x64d3b64d42c0	t7 = t6 + 9
0x64d3b64d4300	d = t7
0x64d3b64d4b10	var t13
0x64d3b64d4b50	t13 = t12 + 9
0x64d3b64d4b90	e = t13
0x64d3b64d4d90	var t14
0x64d3b64d4dd0	t14 = i - 1
0x64d3b64d4e10	i = t14
0x64d3b64d52a0	label L5
0x64d3b64d5360	goto L4
0x64d3b64d52e0	label L6
0x64d3b64d54e0	var t15
0x64d3b64d5520	t15 = j - 1
0x64d3b64d5560	j = t15
0x64d3b64d5640	output L7
0x64d3b64d56c0	label L2
0x64d3b64d5780	goto L1
0x64d3b64d5700	label L3
0x64d3b64d5860	output L8
0x64d3b64d58f0	output d
0x64d3b64d5950	output L7
0x64d3b64d59e0	output e
0x64d3b64d5a40	output L8
0x64d3b64d5b80	end

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
var t7
t7 = t6 + 9
d = t7
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
