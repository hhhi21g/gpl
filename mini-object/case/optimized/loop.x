
# tac list

0x6177a4f7ac40	var t2
0x6177a4f7c6f0	label main
0x6177a4f7c730	begin
0x6177a4f79830	var a
0x6177a4f79910	var b
0x6177a4f799f0	var c
0x6177a4f79ad0	var d
0x6177a4f79bb0	var e
0x6177a4f79c90	var i
0x6177a4f79d70	var j
0x6177a4f79e50	var k
0x6177a4f7ad40	var t3
0x6177a4f7aee0	var t4
0x6177a4f7b030	var t5
0x6177a4f7b130	var t6
0x6177a4f7b5d0	var t9
0x6177a4f7b770	var t10
0x6177a4f7b8c0	var t11
0x6177a4f7b9c0	var t12
0x6177a4f79eb0	input a
0x6177a4f79f10	input b
0x6177a4f79f70	input c
0x6177a4f7a0a0	j = 5
0x6177a4f7ac80	t2 = b * c
0x6177a4f7ad80	t3 = a + t2
0x6177a4f7af20	t4 = a + c
0x6177a4f7b070	t5 = t4 / b
0x6177a4f7b170	t6 = t3 - t5
0x6177a4f7b7b0	t10 = c - a
0x6177a4f7b900	t11 = t10 / b
0x6177a4f7ba00	t12 = t3 - t11
0x6177a4ffe460	t7 = t6 + 9
0x6177a4ffe4a0	d = t7
0x6177a4ffe4e0	t13 = t12 + 9
0x6177a4ffe520	e = t13
0x6177a4f7c270	label L1
0x6177a4f7a280	var t0
0x6177a4f7a2c0	t0 = (j > 0)
0x6177a4f7c330	ifz t0 goto L3
0x6177a4f7a530	output j
0x6177a4f7a660	i = 9
0x6177a4f7be50	label L4
0x6177a4f7a7c0	var t1
0x6177a4f7a800	t1 = (i > 0)
0x6177a4f7bf10	ifz t1 goto L6
0x6177a4f7aa70	output i
0x6177a4f7b280	var t7
0x6177a4f7b4d0	var t8
0x6177a4f7bb10	var t13
0x6177a4f7bd90	var t14
0x6177a4f7bdd0	t14 = i - 1
0x6177a4f7be10	i = t14
0x6177a4f7be90	label L5
0x6177a4f7bf50	goto L4
0x6177a4f7bed0	label L6
0x6177a4f7c0d0	var t15
0x6177a4f7c110	t15 = j - 1
0x6177a4f7c150	j = t15
0x6177a4f7c230	output L7
0x6177a4f7c2b0	label L2
0x6177a4f7c370	goto L1
0x6177a4f7c2f0	label L3
0x6177a4f7c450	output L8
0x6177a4f7c4e0	output d
0x6177a4f7c540	output L7
0x6177a4f7c5d0	output e
0x6177a4f7c630	output L8
0x6177a4f7c770	end

[B0]
var t2
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
var t3
var t4
var t5
var t6
var t9
var t10
var t11
var t12
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
t7 = t6 + 9
d = t7
t13 = t12 + 9
e = t13
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
var t8
var t13
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
