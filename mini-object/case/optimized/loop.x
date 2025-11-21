
# tac list

0x55639f763c40	var t2
0x55639f763d40	var t3
0x55639f763ee0	var t4
0x55639f764030	var t5
0x55639f764130	var t6
0x55639f7645d0	var t9
0x55639f764770	var t10
0x55639f7648c0	var t11
0x55639f7649c0	var t12
0x55639f7656f0	label main
0x55639f765730	begin
0x55639f762830	var a
0x55639f762910	var b
0x55639f7629f0	var c
0x55639f762ad0	var d
0x55639f762bb0	var e
0x55639f762c90	var i
0x55639f762d70	var j
0x55639f762e50	var k
0x55639f762eb0	input a
0x55639f762f10	input b
0x55639f762f70	input c
0x55639f7630a0	j = 5
0x55639f763c80	t2 = b * c
0x55639f763d80	t3 = a + t2
0x55639f763f20	t4 = a + c
0x55639f764070	t5 = t4 / b
0x55639f764170	t6 = t3 - t5
0x55639f7647b0	t10 = c - a
0x55639f764900	t11 = t10 / b
0x55639f764a00	t12 = t3 - t11
0x55639f765270	label L1
0x55639f763280	var t0
0x55639f7632c0	t0 = (j > 0)
0x55639f765330	ifz t0 goto L3
0x55639f763530	output j
0x55639f763660	i = 9
0x55639f764e50	label L4
0x55639f7637c0	var t1
0x55639f763800	t1 = (i > 0)
0x55639f764f10	ifz t1 goto L6
0x55639f763a70	output i
0x55639f764280	var t7
0x55639f7642c0	t7 = t6 + 9
0x55639f764300	d = t7
0x55639f7644d0	var t8
0x55639f764b10	var t13
0x55639f764b50	t13 = t12 + 9
0x55639f764b90	e = t13
0x55639f764d90	var t14
0x55639f764dd0	t14 = i - 1
0x55639f764e10	i = t14
0x55639f764e90	label L5
0x55639f764f50	goto L4
0x55639f764ed0	label L6
0x55639f7650d0	var t15
0x55639f765110	t15 = j - 1
0x55639f765150	j = t15
0x55639f765230	output L7
0x55639f7652b0	label L2
0x55639f765370	goto L1
0x55639f7652f0	label L3
0x55639f765450	output L8
0x55639f7654e0	output d
0x55639f765540	output L7
0x55639f7655d0	output e
0x55639f765630	output L8
0x55639f765770	end

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
