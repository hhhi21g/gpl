
# tac list

0x5c0e7f190b00	label main
0x5c0e7f190b40	begin
0x5c0e7f18d830	var a
0x5c0e7f18d910	var b
0x5c0e7f18d9f0	var c
0x5c0e7f18dad0	var d
0x5c0e7f18dbb0	var e
0x5c0e7f18dc90	var i
0x5c0e7f18dd70	var j
0x5c0e7f18de50	var k
0x5c0e7f18deb0	input a
0x5c0e7f18df10	input b
0x5c0e7f18df70	input c
0x5c0e7f18e0a0	j = 5
0x5c0e7f190680	label L1
0x5c0e7f18e280	var t0
0x5c0e7f18e2c0	t0 = (j > 0)
0x5c0e7f190740	ifz t0 goto L3
0x5c0e7f18e530	output j
0x5c0e7f18e660	i = 9
0x5c0e7f190260	label L4
0x5c0e7f18e7c0	var t1
0x5c0e7f18e800	t1 = (i > 0)
0x5c0e7f190320	ifz t1 goto L6
0x5c0e7f18ea70	output i
0x5c0e7f18ec40	var t2
0x5c0e7f18ec80	t2 = b * c
0x5c0e7f18ed40	var t3
0x5c0e7f18ed80	t3 = a + t2
0x5c0e7f18eee0	var t4
0x5c0e7f18ef20	t4 = a + c
0x5c0e7f18f030	var t5
0x5c0e7f18f070	t5 = t4 / b
0x5c0e7f18f130	var t6
0x5c0e7f18f170	t6 = t3 - t5
0x5c0e7f18f280	var t7
0x5c0e7f18f2c0	t7 = t6 + 9
0x5c0e7f18f300	d = t7
0x5c0e7f18f4d0	var t8
0x5c0e7f18f5d0	var t9
0x5c0e7f18f770	var t10
0x5c0e7f18f7b0	t10 = c - a
0x5c0e7f18f8c0	var t11
0x5c0e7f18f900	t11 = t10 / b
0x5c0e7f18f9c0	var t12
0x5c0e7f18fa00	t12 = t3 - t11
0x5c0e7f18fb10	var t13
0x5c0e7f18fb50	t13 = t12 + 9
0x5c0e7f18fb90	e = t13
0x5c0e7f18fd90	var t14
0x5c0e7f18fdd0	t14 = i - 1
0x5c0e7f18fe10	i = t14
0x5c0e7f1902a0	label L5
0x5c0e7f190360	goto L4
0x5c0e7f1902e0	label L6
0x5c0e7f1904e0	var t15
0x5c0e7f190520	t15 = j - 1
0x5c0e7f190560	j = t15
0x5c0e7f190640	output L7
0x5c0e7f1906c0	label L2
0x5c0e7f190780	goto L1
0x5c0e7f190700	label L3
0x5c0e7f190860	output L8
0x5c0e7f1908f0	output d
0x5c0e7f190950	output L7
0x5c0e7f1909e0	output e
0x5c0e7f190a40	output L8
0x5c0e7f190b80	end

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
var t9
var t10
t10 = c - a
var t11
t11 = t10 / b
var t12
t12 = t3 - t11
var t13
t13 = t12 + 9
e = t13
var t14
t14 = i - 1
i = t14
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
