
# tac list

0x614d820acc40	var t2
0x614d820ae6f0	label main
0x614d820ae730	begin
0x614d820ab830	var a
0x614d820ab910	var b
0x614d820ab9f0	var c
0x614d820abad0	var d
0x614d820abbb0	var e
0x614d820abc90	var i
0x614d820abd70	var j
0x614d820abe50	var k
0x614d820acd40	var t3
0x614d820acee0	var t4
0x614d820ad030	var t5
0x614d820ad130	var t6
0x614d820ad5d0	var t9
0x614d820ad770	var t10
0x614d820ad8c0	var t11
0x614d820ad9c0	var t12
0x614d820abeb0	input a
0x614d820abf10	input b
0x614d820abf70	input c
0x614d820ac0a0	j = 5
0x614d820acc80	t2 = b * c
0x614d820acd80	t3 = a + t2
0x614d820acf20	t4 = a + c
0x614d820ad070	t5 = t4 / b
0x614d820ad170	t6 = t3 - t5
0x614d820ad7b0	t10 = c - a
0x614d820ad900	t11 = t10 / b
0x614d820ada00	t12 = t3 - t11
0x614d82130460	t7 = t6 + 9
0x614d821304a0	d = t7
0x614d821304e0	t13 = t12 + 9
0x614d82130520	e = t13
0x614d820ae270	label L1
0x614d820ac280	var t0
0x614d820ac2c0	t0 = (j > 0)
0x614d820ae330	ifz t0 goto L3
0x614d820ac530	output j
0x614d820ac660	i = 9
0x614d820ade50	label L4
0x614d820ac7c0	var t1
0x614d820ac800	t1 = (i > 0)
0x614d820adf10	ifz t1 goto L6
0x614d820aca70	output i
0x614d820ad280	var t7
0x614d820ad4d0	var t8
0x614d820adb10	var t13
0x614d820add90	var t14
0x614d820addd0	t14 = i - 1
0x614d820ade10	i = t14
0x614d820ade90	label L5
0x614d820adf50	goto L4
0x614d820aded0	label L6
0x614d820ae0d0	var t15
0x614d820ae110	t15 = j - 1
0x614d820ae150	j = t15
0x614d820ae230	output L7
0x614d820ae2b0	label L2
0x614d820ae370	goto L1
0x614d820ae2f0	label L3
0x614d820ae450	output L8
0x614d820ae4e0	output d
0x614d820ae540	output L7
0x614d820ae5d0	output e
0x614d820ae630	output L8
0x614d820ae770	end

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
