
# tac list

0x63987f631b00	label main
0x63987f631b40	begin
0x63987f62e830	var a
0x63987f62e910	var b
0x63987f62e9f0	var c
0x63987f62ead0	var d
0x63987f62ebb0	var e
0x63987f62ec90	var i
0x63987f62ed70	var j
0x63987f62ee50	var k
0x63987f62eeb0	input a
0x63987f62ef10	input b
0x63987f62ef70	input c
0x63987f62f0a0	j = 5
0x63987f631680	label L1
0x63987f62f280	var t0
0x63987f62f2c0	t0 = (j > 0)
0x63987f631740	ifz t0 goto L3
0x63987f62f530	output j
0x63987f62f660	i = 9
0x63987f631260	label L4
0x63987f62f7c0	var t1
0x63987f62f800	t1 = (i > 0)
0x63987f631320	ifz t1 goto L6
0x63987f62fa70	output i
0x63987f62fc40	var t2
0x63987f62fc80	t2 = b * c
0x63987f62fd40	var t3
0x63987f62fd80	t3 = a + t2
0x63987f62fee0	var t4
0x63987f62ff20	t4 = a + c
0x63987f630030	var t5
0x63987f630070	t5 = t4 / b
0x63987f630130	var t6
0x63987f630170	t6 = t3 - t5
0x63987f630280	var t7
0x63987f6302c0	t7 = t6 + 9
0x63987f630300	d = t7
0x63987f6304d0	var t8
0x63987f6305d0	var t9
0x63987f630770	var t10
0x63987f6307b0	t10 = c - a
0x63987f6308c0	var t11
0x63987f630900	t11 = t10 / b
0x63987f6309c0	var t12
0x63987f630a00	t12 = t3 - t11
0x63987f630b10	var t13
0x63987f630b50	t13 = t12 + 9
0x63987f630b90	e = t13
0x63987f630d90	var t14
0x63987f630dd0	t14 = i - 1
0x63987f630e10	i = t14
0x63987f6312a0	label L5
0x63987f631360	goto L4
0x63987f6312e0	label L6
0x63987f6314e0	var t15
0x63987f631520	t15 = j - 1
0x63987f631560	j = t15
0x63987f631640	output L7
0x63987f6316c0	label L2
0x63987f631780	goto L1
0x63987f631700	label L3
0x63987f631860	output L8
0x63987f6318f0	output d
0x63987f631950	output L7
0x63987f6319e0	output e
0x63987f631a40	output L8
0x63987f631b80	end

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
