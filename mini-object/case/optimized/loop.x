
# tac list

0x61a26ceaec40	var t2
0x61a26ceaed40	var t3
0x61a26ceaeee0	var t4
0x61a26ceaf030	var t5
0x61a26ceaf130	var t6
0x61a26ceaf5d0	var t9
0x61a26ceaf770	var t10
0x61a26ceaf8c0	var t11
0x61a26ceaf9c0	var t12
0x61a26ceb06f0	label main
0x61a26ceb0730	begin
0x61a26cead830	var a
0x61a26cead910	var b
0x61a26cead9f0	var c
0x61a26ceadad0	var d
0x61a26ceadbb0	var e
0x61a26ceadc90	var i
0x61a26ceadd70	var j
0x61a26ceade50	var k
0x61a26ceadeb0	input a
0x61a26ceadf10	input b
0x61a26ceadf70	input c
0x61a26ceae0a0	j = 5
0x61a26ceaec80	t2 = b * c
0x61a26ceaed80	t3 = a + t2
0x61a26ceaef20	t4 = a + c
0x61a26ceaf070	t5 = t4 / b
0x61a26ceaf170	t6 = t3 - t5
0x61a26ceaf7b0	t10 = c - a
0x61a26ceaf900	t11 = t10 / b
0x61a26ceafa00	t12 = t3 - t11
0x61a26ceb0270	label L1
0x61a26ceae280	var t0
0x61a26ceae2c0	t0 = (j > 0)
0x61a26ceb0330	ifz t0 goto L3
0x61a26ceae530	output j
0x61a26ceae660	i = 9
0x61a26ceafe50	label L4
0x61a26ceae7c0	var t1
0x61a26ceae800	t1 = (i > 0)
0x61a26ceaff10	ifz t1 goto L6
0x61a26ceaea70	output i
0x61a26ceaf280	var t7
0x61a26ceaf2c0	t7 = t6 + 9
0x61a26ceaf300	d = t7
0x61a26ceaf4d0	var t8
0x61a26ceafb10	var t13
0x61a26ceafb50	t13 = t12 + 9
0x61a26ceafb90	e = t13
0x61a26ceafd90	var t14
0x61a26ceafdd0	t14 = i - 1
0x61a26ceafe10	i = t14
0x61a26ceafe90	label L5
0x61a26ceaff50	goto L4
0x61a26ceafed0	label L6
0x61a26ceb00d0	var t15
0x61a26ceb0110	t15 = j - 1
0x61a26ceb0150	j = t15
0x61a26ceb0230	output L7
0x61a26ceb02b0	label L2
0x61a26ceb0370	goto L1
0x61a26ceb02f0	label L3
0x61a26ceb0450	output L8
0x61a26ceb04e0	output d
0x61a26ceb0540	output L7
0x61a26ceb05d0	output e
0x61a26ceb0630	output L8
0x61a26ceb0770	end

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
