
# tac list

0x5f56c2668c40	var t2
0x5f56c2668d40	var t3
0x5f56c2668ee0	var t4
0x5f56c2669030	var t5
0x5f56c2669130	var t6
0x5f56c26695d0	var t9
0x5f56c2669770	var t10
0x5f56c26698c0	var t11
0x5f56c26699c0	var t12
0x5f56c266a6f0	label main
0x5f56c266a730	begin
0x5f56c2667830	var a
0x5f56c2667910	var b
0x5f56c26679f0	var c
0x5f56c2667ad0	var d
0x5f56c2667bb0	var e
0x5f56c2667c90	var i
0x5f56c2667d70	var j
0x5f56c2667e50	var k
0x5f56c2667eb0	input a
0x5f56c2667f10	input b
0x5f56c2667f70	input c
0x5f56c26680a0	j = 5
0x5f56c2668c80	t2 = b * c
0x5f56c2668d80	t3 = a + t2
0x5f56c2668f20	t4 = a + c
0x5f56c2669070	t5 = t4 / b
0x5f56c2669170	t6 = t3 - t5
0x5f56c26697b0	t10 = c - a
0x5f56c2669900	t11 = t10 / b
0x5f56c2669a00	t12 = t3 - t11
0x5f56c26ec460	t7 = t6 + 9
0x5f56c26ec4a0	d = t7
0x5f56c26ec4e0	t13 = t12 + 9
0x5f56c26ec520	e = t13
0x5f56c266a270	label L1
0x5f56c2668280	var t0
0x5f56c26682c0	t0 = (j > 0)
0x5f56c266a330	ifz t0 goto L3
0x5f56c2668530	output j
0x5f56c2668660	i = 9
0x5f56c2669e50	label L4
0x5f56c26687c0	var t1
0x5f56c2668800	t1 = (i > 0)
0x5f56c2669f10	ifz t1 goto L6
0x5f56c2668a70	output i
0x5f56c2669280	var t7
0x5f56c26694d0	var t8
0x5f56c2669b10	var t13
0x5f56c2669d90	var t14
0x5f56c2669dd0	t14 = i - 1
0x5f56c2669e10	i = t14
0x5f56c2669e90	label L5
0x5f56c2669f50	goto L4
0x5f56c2669ed0	label L6
0x5f56c266a0d0	var t15
0x5f56c266a110	t15 = j - 1
0x5f56c266a150	j = t15
0x5f56c266a230	output L7
0x5f56c266a2b0	label L2
0x5f56c266a370	goto L1
0x5f56c266a2f0	label L3
0x5f56c266a450	output L8
0x5f56c266a4e0	output d
0x5f56c266a540	output L7
0x5f56c266a5d0	output e
0x5f56c266a630	output L8
0x5f56c266a770	end

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
