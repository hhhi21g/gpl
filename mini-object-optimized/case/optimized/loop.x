
# tac list

0x5f8ed548fc40	var t2
0x5f8ed54916f0	label main
0x5f8ed5491730	begin
0x5f8ed548e830	var a
0x5f8ed548e910	var b
0x5f8ed548e9f0	var c
0x5f8ed548ead0	var d
0x5f8ed548ebb0	var e
0x5f8ed548ec90	var i
0x5f8ed548ed70	var j
0x5f8ed548ee50	var k
0x5f8ed548fd40	var t3
0x5f8ed548fee0	var t4
0x5f8ed5490030	var t5
0x5f8ed5490130	var t6
0x5f8ed54905d0	var t9
0x5f8ed5490770	var t10
0x5f8ed54908c0	var t11
0x5f8ed54909c0	var t12
0x5f8ed548eeb0	input a
0x5f8ed548ef10	input b
0x5f8ed548ef70	input c
0x5f8ed548f0a0	j = 5
0x5f8ed548fc80	t2 = b * c
0x5f8ed548fd80	t3 = a + t2
0x5f8ed548ff20	t4 = a + c
0x5f8ed5490070	t5 = t4 / b
0x5f8ed5490170	t6 = t3 - t5
0x5f8ed54907b0	t10 = c - a
0x5f8ed5490900	t11 = t10 / b
0x5f8ed5490a00	t12 = t3 - t11
0x5f8ed5513460	t7 = t6 + 9
0x5f8ed55134a0	d = t7
0x5f8ed55134e0	t13 = t12 + 9
0x5f8ed5513520	e = t13
0x5f8ed5491270	label L1
0x5f8ed548f280	var t0
0x5f8ed548f2c0	t0 = (j > 0)
0x5f8ed5491330	ifz t0 goto L3
0x5f8ed548f530	output j
0x5f8ed548f660	i = 9
0x5f8ed5490e50	label L4
0x5f8ed548f7c0	var t1
0x5f8ed548f800	t1 = (i > 0)
0x5f8ed5490f10	ifz t1 goto L6
0x5f8ed548fa70	output i
0x5f8ed5490280	var t7
0x5f8ed54904d0	var t8
0x5f8ed5490b10	var t13
0x5f8ed5490d90	var t14
0x5f8ed5490dd0	t14 = i - 1
0x5f8ed5490e10	i = t14
0x5f8ed5490e90	label L5
0x5f8ed5490f50	goto L4
0x5f8ed5490ed0	label L6
0x5f8ed54910d0	var t15
0x5f8ed5491110	t15 = j - 1
0x5f8ed5491150	j = t15
0x5f8ed5491230	output L7
0x5f8ed54912b0	label L2
0x5f8ed5491370	goto L1
0x5f8ed54912f0	label L3
0x5f8ed5491450	output L8
0x5f8ed54914e0	output d
0x5f8ed5491540	output L7
0x5f8ed54915d0	output e
0x5f8ed5491630	output L8
0x5f8ed5491770	end

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
