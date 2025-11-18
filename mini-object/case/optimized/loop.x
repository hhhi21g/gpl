
# tac list

0x57bfa0815b00	label main
0x57bfa0815b40	begin
0x57bfa0812830	var a
0x57bfa0812910	var b
0x57bfa08129f0	var c
0x57bfa0812ad0	var d
0x57bfa0812bb0	var e
0x57bfa0812c90	var i
0x57bfa0812d70	var j
0x57bfa0812e50	var k
0x57bfa0812eb0	input a
0x57bfa0812f10	input b
0x57bfa0812f70	input c
0x57bfa08130a0	j = 5
0x57bfa0815680	label L1
0x57bfa0813280	var t0
0x57bfa08132c0	t0 = (j > 0)
0x57bfa0815740	ifz t0 goto L3
0x57bfa0813530	output j
0x57bfa0813660	i = 9
0x57bfa0815260	label L4
0x57bfa08137c0	var t1
0x57bfa0813800	t1 = (i > 0)
0x57bfa0815320	ifz t1 goto L6
0x57bfa0813a70	output i
0x57bfa0813c40	var t2
0x57bfa0813c80	t2 = b * c
0x57bfa0813d40	var t3
0x57bfa0813d80	t3 = a + t2
0x57bfa0813ee0	var t4
0x57bfa0813f20	t4 = a + c
0x57bfa0814030	var t5
0x57bfa0814070	t5 = t4 / b
0x57bfa0814130	var t6
0x57bfa0814170	t6 = t3 - t5
0x57bfa0814280	var t7
0x57bfa08142c0	t7 = t6 + 9
0x57bfa0814300	d = t7
0x57bfa08144d0	var t8
0x57bfa0814510	t8 = b * c
0x57bfa08145d0	var t9
0x57bfa0814610	t9 = a + t8
0x57bfa0814770	var t10
0x57bfa08147b0	t10 = c - a
0x57bfa08148c0	var t11
0x57bfa0814900	t11 = t10 / b
0x57bfa08149c0	var t12
0x57bfa0814a00	t12 = t9 - t11
0x57bfa0814b10	var t13
0x57bfa0814b50	t13 = t12 + 9
0x57bfa0814b90	e = t13
0x57bfa0814d90	var t14
0x57bfa0814dd0	t14 = i - 1
0x57bfa0814e10	i = t14
0x57bfa08152a0	label L5
0x57bfa0815360	goto L4
0x57bfa08152e0	label L6
0x57bfa08154e0	var t15
0x57bfa0815520	t15 = j - 1
0x57bfa0815560	j = t15
0x57bfa0815640	output L7
0x57bfa08156c0	label L2
0x57bfa0815780	goto L1
0x57bfa0815700	label L3
0x57bfa0815860	output L8
0x57bfa08158f0	output d
0x57bfa0815950	output L7
0x57bfa08159e0	output e
0x57bfa0815a40	output L8
0x57bfa0815b80	end

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
