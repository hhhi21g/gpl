
# tac list

0x57eff9094b00	label main
0x57eff9094b40	begin
0x57eff9091830	var a
0x57eff9091910	var b
0x57eff90919f0	var c
0x57eff9091ad0	var d
0x57eff9091bb0	var e
0x57eff9091c90	var i
0x57eff9091d70	var j
0x57eff9091e50	var k
0x57eff9091eb0	input a
0x57eff9091f10	input b
0x57eff9091f70	input c
0x57eff90920a0	j = 5
0x57eff9094680	label L1
0x57eff9092280	var t0
0x57eff90922c0	t0 = (j > 0)
0x57eff9094740	ifz t0 goto L3
0x57eff9092530	output j
0x57eff9092660	i = 9
0x57eff9094260	label L4
0x57eff90927c0	var t1
0x57eff9092800	t1 = (i > 0)
0x57eff9094320	ifz t1 goto L6
0x57eff9092a70	output i
0x57eff9092c40	var t2
0x57eff9092c80	t2 = b * c
0x57eff9092d40	var t3
0x57eff9092d80	t3 = a + t2
0x57eff9092ee0	var t4
0x57eff9092f20	t4 = a + c
0x57eff9093030	var t5
0x57eff9093070	t5 = t4 / b
0x57eff9093130	var t6
0x57eff9093170	t6 = t3 - t5
0x57eff9093280	var t7
0x57eff90932c0	t7 = t6 + 9
0x57eff9093300	d = t7
0x57eff90934d0	var t8
0x57eff90935d0	var t9
0x57eff9093770	var t10
0x57eff90937b0	t10 = c - a
0x57eff90938c0	var t11
0x57eff9093900	t11 = t10 / b
0x57eff90939c0	var t12
0x57eff9093a00	t12 = t3 - t11
0x57eff9093b10	var t13
0x57eff9093b50	t13 = t12 + 9
0x57eff9093b90	e = t13
0x57eff9093d90	var t14
0x57eff9093dd0	t14 = i - 1
0x57eff9093e10	i = t14
0x57eff90942a0	label L5
0x57eff9094360	goto L4
0x57eff90942e0	label L6
0x57eff90944e0	var t15
0x57eff9094520	t15 = j - 1
0x57eff9094560	j = t15
0x57eff9094640	output L7
0x57eff90946c0	label L2
0x57eff9094780	goto L1
0x57eff9094700	label L3
0x57eff9094860	output L8
0x57eff90948f0	output d
0x57eff9094950	output L7
0x57eff90949e0	output e
0x57eff9094a40	output L8
0x57eff9094b80	end

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
