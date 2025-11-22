
# tac list

0x59bf0ba3dc40	var t2
0x59bf0ba3dd40	var t3
0x59bf0ba3dee0	var t4
0x59bf0ba3e030	var t5
0x59bf0ba3e130	var t6
0x59bf0ba3e5d0	var t9
0x59bf0ba3e770	var t10
0x59bf0ba3e8c0	var t11
0x59bf0ba3e9c0	var t12
0x59bf0ba3f6f0	label main
0x59bf0ba3f730	begin
0x59bf0ba3c830	var a
0x59bf0ba3c910	var b
0x59bf0ba3c9f0	var c
0x59bf0ba3cad0	var d
0x59bf0ba3cbb0	var e
0x59bf0ba3cc90	var i
0x59bf0ba3cd70	var j
0x59bf0ba3ce50	var k
0x59bf0ba3ceb0	input a
0x59bf0ba3cf10	input b
0x59bf0ba3cf70	input c
0x59bf0ba3d0a0	j = 5
0x59bf0ba3dc80	t2 = b * c
0x59bf0ba3dd80	t3 = a + t2
0x59bf0ba3df20	t4 = a + c
0x59bf0ba3e070	t5 = t4 / b
0x59bf0ba3e170	t6 = t3 - t5
0x59bf0ba3e7b0	t10 = c - a
0x59bf0ba3e900	t11 = t10 / b
0x59bf0ba3ea00	t12 = t3 - t11
0x59bf0bac1460	t7 = t6 + 9
0x59bf0bac14a0	d = t7
0x59bf0bac14e0	t13 = t12 + 9
0x59bf0bac1520	e = t13
0x59bf0ba3f270	label L1
0x59bf0ba3d280	var t0
0x59bf0ba3d2c0	t0 = (j > 0)
0x59bf0ba3f330	ifz t0 goto L3
0x59bf0ba3d530	output j
0x59bf0ba3d660	i = 9
0x59bf0ba3ee50	label L4
0x59bf0ba3d7c0	var t1
0x59bf0ba3d800	t1 = (i > 0)
0x59bf0ba3ef10	ifz t1 goto L6
0x59bf0ba3da70	output i
0x59bf0ba3e280	var t7
0x59bf0ba3e4d0	var t8
0x59bf0ba3eb10	var t13
0x59bf0ba3ed90	var t14
0x59bf0ba3edd0	t14 = i - 1
0x59bf0ba3ee10	i = t14
0x59bf0ba3ee90	label L5
0x59bf0ba3ef50	goto L4
0x59bf0ba3eed0	label L6
0x59bf0ba3f0d0	var t15
0x59bf0ba3f110	t15 = j - 1
0x59bf0ba3f150	j = t15
0x59bf0ba3f230	output L7
0x59bf0ba3f2b0	label L2
0x59bf0ba3f370	goto L1
0x59bf0ba3f2f0	label L3
0x59bf0ba3f450	output L8
0x59bf0ba3f4e0	output d
0x59bf0ba3f540	output L7
0x59bf0ba3f5d0	output e
0x59bf0ba3f630	output L8
0x59bf0ba3f770	end

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
