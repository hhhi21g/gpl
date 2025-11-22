
# tac list

0x5f3a3ab27b00	label main
0x5f3a3ab27b40	begin
0x5f3a3ab24830	var a
0x5f3a3ab24910	var b
0x5f3a3ab249f0	var c
0x5f3a3ab24ad0	var d
0x5f3a3ab24bb0	var e
0x5f3a3ab24c90	var i
0x5f3a3ab24d70	var j
0x5f3a3ab24e50	var k
0x5f3a3ab24eb0	input a
0x5f3a3ab24f10	input b
0x5f3a3ab24f70	input c
0x5f3a3ab250a0	j = 5
0x5f3a3ab27680	label L1
0x5f3a3ab25280	var t0
0x5f3a3ab252c0	t0 = (j > 0)
0x5f3a3ab27740	ifz t0 goto L3
0x5f3a3ab25530	output j
0x5f3a3ab25660	i = 9
0x5f3a3ab27260	label L4
0x5f3a3ab257c0	var t1
0x5f3a3ab25800	t1 = (i > 0)
0x5f3a3ab27320	ifz t1 goto L6
0x5f3a3ab25a70	output i
0x5f3a3ab25c40	var t2
0x5f3a3ab25c80	t2 = b * c
0x5f3a3ab25d40	var t3
0x5f3a3ab25d80	t3 = a + t2
0x5f3a3ab25ee0	var t4
0x5f3a3ab25f20	t4 = a + c
0x5f3a3ab26030	var t5
0x5f3a3ab26070	t5 = t4 / b
0x5f3a3ab26130	var t6
0x5f3a3ab26170	t6 = t3 - t5
0x5f3a3ab26280	var t7
0x5f3a3ab262c0	t7 = t6 + 9
0x5f3a3ab26300	d = t7
0x5f3a3ab264d0	var t8
0x5f3a3ab26510	t8 = b * c
0x5f3a3ab265d0	var t9
0x5f3a3ab26610	t9 = a + t8
0x5f3a3ab26770	var t10
0x5f3a3ab267b0	t10 = c - a
0x5f3a3ab268c0	var t11
0x5f3a3ab26900	t11 = t10 / b
0x5f3a3ab269c0	var t12
0x5f3a3ab26a00	t12 = t9 - t11
0x5f3a3ab26b10	var t13
0x5f3a3ab26b50	t13 = t12 + 9
0x5f3a3ab26b90	e = t13
0x5f3a3ab26d90	var t14
0x5f3a3ab26dd0	t14 = i - 1
0x5f3a3ab26e10	i = t14
0x5f3a3ab272a0	label L5
0x5f3a3ab27360	goto L4
0x5f3a3ab272e0	label L6
0x5f3a3ab274e0	var t15
0x5f3a3ab27520	t15 = j - 1
0x5f3a3ab27560	j = t15
0x5f3a3ab27640	output L7
0x5f3a3ab276c0	label L2
0x5f3a3ab27780	goto L1
0x5f3a3ab27700	label L3
0x5f3a3ab27860	output L8
0x5f3a3ab278f0	output d
0x5f3a3ab27950	output L7
0x5f3a3ab279e0	output e
0x5f3a3ab27a40	output L8
0x5f3a3ab27b80	end

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
