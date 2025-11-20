
# tac list

0x63dfd4a99c40	var t2
0x63dfd4a99d40	var t3
0x63dfd4a99ee0	var t4
0x63dfd4a9a030	var t5
0x63dfd4a9a130	var t6
0x63dfd4a9a5d0	var t9
0x63dfd4a9a770	var t10
0x63dfd4a9a8c0	var t11
0x63dfd4a9a9c0	var t12
0x63dfd4a9b6f0	label main
0x63dfd4a9b730	begin
0x63dfd4a98830	var a
0x63dfd4a98910	var b
0x63dfd4a989f0	var c
0x63dfd4a98ad0	var d
0x63dfd4a98bb0	var e
0x63dfd4a98c90	var i
0x63dfd4a98d70	var j
0x63dfd4a98e50	var k
0x63dfd4a98eb0	input a
0x63dfd4a98f10	input b
0x63dfd4a98f70	input c
0x63dfd4a990a0	j = 5
0x63dfd4a99c80	t2 = b * c
0x63dfd4a99d80	t3 = a + t2
0x63dfd4a99f20	t4 = a + c
0x63dfd4a9a070	t5 = t4 / b
0x63dfd4a9a170	t6 = t3 - t5
0x63dfd4a9a7b0	t10 = c - a
0x63dfd4a9a900	t11 = t10 / b
0x63dfd4a9aa00	t12 = t3 - t11
0x63dfd4a9b270	label L1
0x63dfd4a99280	var t0
0x63dfd4a992c0	t0 = (j > 0)
0x63dfd4a9b330	ifz t0 goto L3
0x63dfd4a99530	output j
0x63dfd4a99660	i = 9
0x63dfd4a9ae50	label L4
0x63dfd4a997c0	var t1
0x63dfd4a99800	t1 = (i > 0)
0x63dfd4a9af10	ifz t1 goto L6
0x63dfd4a99a70	output i
0x63dfd4a9a280	var t7
0x63dfd4a9a2c0	t7 = t6 + 9
0x63dfd4a9a300	d = t7
0x63dfd4a9a4d0	var t8
0x63dfd4a9ab10	var t13
0x63dfd4a9ab50	t13 = t12 + 9
0x63dfd4a9ab90	e = t13
0x63dfd4a9ad90	var t14
0x63dfd4a9add0	t14 = i - 1
0x63dfd4a9ae10	i = t14
0x63dfd4a9ae90	label L5
0x63dfd4a9af50	goto L4
0x63dfd4a9aed0	label L6
0x63dfd4a9b0d0	var t15
0x63dfd4a9b110	t15 = j - 1
0x63dfd4a9b150	j = t15
0x63dfd4a9b230	output L7
0x63dfd4a9b2b0	label L2
0x63dfd4a9b370	goto L1
0x63dfd4a9b2f0	label L3
0x63dfd4a9b450	output L8
0x63dfd4a9b4e0	output d
0x63dfd4a9b540	output L7
0x63dfd4a9b5d0	output e
0x63dfd4a9b630	output L8
0x63dfd4a9b770	end

[B0]
var t2
var t3
var t4
var t5
var t6
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
t10 = c - a
t11 = t10 / b
t12 = t3 - t11
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
var t8
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
