
# tac list

0x6476d74deb00	label main
0x6476d74deb40	begin
0x6476d74db830	var a
0x6476d74db910	var b
0x6476d74db9f0	var c
0x6476d74dbad0	var d
0x6476d74dbbb0	var e
0x6476d74dbc90	var i
0x6476d74dbd70	var j
0x6476d74dbe50	var k
0x6476d74dbeb0	input a
0x6476d74dbf10	input b
0x6476d74dbf70	input c
0x6476d74dc0a0	j = 5
0x6476d74de680	label L1
0x6476d74dc280	var t0
0x6476d74dc2c0	t0 = (j > 0)
0x6476d74de740	ifz t0 goto L3
0x6476d74dc530	output j
0x6476d74dc660	i = 9
0x6476d74de260	label L4
0x6476d74dc7c0	var t1
0x6476d74dc800	t1 = (i > 0)
0x6476d74de320	ifz t1 goto L6
0x6476d74dca70	output i
0x6476d74dcc40	var t2
0x6476d74dcc80	t2 = b * c
0x6476d74dcd40	var t3
0x6476d74dcd80	t3 = a + t2
0x6476d74dcee0	var t4
0x6476d74dcf20	t4 = a + c
0x6476d74dd030	var t5
0x6476d74dd070	t5 = t4 / b
0x6476d74dd130	var t6
0x6476d74dd170	t6 = t3 - t5
0x6476d74dd280	var t7
0x6476d74dd2c0	t7 = t6 + 9
0x6476d74dd300	d = t7
0x6476d74dd4d0	var t8
0x6476d74dd510	t8 = b * c
0x6476d74dd5d0	var t9
0x6476d74dd610	t9 = a + t8
0x6476d74dd770	var t10
0x6476d74dd7b0	t10 = c - a
0x6476d74dd8c0	var t11
0x6476d74dd900	t11 = t10 / b
0x6476d74dd9c0	var t12
0x6476d74dda00	t12 = t9 - t11
0x6476d74ddb10	var t13
0x6476d74ddb50	t13 = t12 + 9
0x6476d74ddb90	e = t13
0x6476d74ddd90	var t14
0x6476d74dddd0	t14 = i - 1
0x6476d74dde10	i = t14
0x6476d74de2a0	label L5
0x6476d74de360	goto L4
0x6476d74de2e0	label L6
0x6476d74de4e0	var t15
0x6476d74de520	t15 = j - 1
0x6476d74de560	j = t15
0x6476d74de640	output L7
0x6476d74de6c0	label L2
0x6476d74de780	goto L1
0x6476d74de700	label L3
0x6476d74de860	output L8
0x6476d74de8f0	output d
0x6476d74de950	output L7
0x6476d74de9e0	output e
0x6476d74dea40	output L8
0x6476d74deb80	end

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
