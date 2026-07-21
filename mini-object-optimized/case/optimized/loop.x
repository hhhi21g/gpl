
# tac list

0x62ac1a960c40	var t2
0x62ac1a9626f0	label main
0x62ac1a962730	begin
0x62ac1a95f830	var a
0x62ac1a95f910	var b
0x62ac1a95f9f0	var c
0x62ac1a95fad0	var d
0x62ac1a95fbb0	var e
0x62ac1a95fc90	var i
0x62ac1a95fd70	var j
0x62ac1a95fe50	var k
0x62ac1a960d40	var t3
0x62ac1a960ee0	var t4
0x62ac1a961030	var t5
0x62ac1a961130	var t6
0x62ac1a9615d0	var t9
0x62ac1a961770	var t10
0x62ac1a9618c0	var t11
0x62ac1a9619c0	var t12
0x62ac1a95feb0	input a
0x62ac1a95ff10	input b
0x62ac1a95ff70	input c
0x62ac1a9600a0	j = 5
0x62ac1a960c80	t2 = b * c
0x62ac1a960d80	t3 = a + t2
0x62ac1a960f20	t4 = a + c
0x62ac1a961070	t5 = t4 / b
0x62ac1a961170	t6 = t3 - t5
0x62ac1a9617b0	t10 = c - a
0x62ac1a961900	t11 = t10 / b
0x62ac1a961a00	t12 = t3 - t11
0x62ac1a9e4460	t7 = t6 + 9
0x62ac1a9e44a0	d = t7
0x62ac1a9e44e0	t13 = t12 + 9
0x62ac1a9e4520	e = t13
0x62ac1a962270	label L1
0x62ac1a960280	var t0
0x62ac1a9602c0	t0 = (j > 0)
0x62ac1a962330	ifz t0 goto L3
0x62ac1a960530	output j
0x62ac1a960660	i = 9
0x62ac1a961e50	label L4
0x62ac1a9607c0	var t1
0x62ac1a960800	t1 = (i > 0)
0x62ac1a961f10	ifz t1 goto L6
0x62ac1a960a70	output i
0x62ac1a961280	var t7
0x62ac1a9614d0	var t8
0x62ac1a961b10	var t13
0x62ac1a961d90	var t14
0x62ac1a961dd0	t14 = i - 1
0x62ac1a961e10	i = t14
0x62ac1a961e90	label L5
0x62ac1a961f50	goto L4
0x62ac1a961ed0	label L6
0x62ac1a9620d0	var t15
0x62ac1a962110	t15 = j - 1
0x62ac1a962150	j = t15
0x62ac1a962230	output L7
0x62ac1a9622b0	label L2
0x62ac1a962370	goto L1
0x62ac1a9622f0	label L3
0x62ac1a962450	output L8
0x62ac1a9624e0	output d
0x62ac1a962540	output L7
0x62ac1a9625d0	output e
0x62ac1a962630	output L8
0x62ac1a962770	end

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
