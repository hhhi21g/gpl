
# tac list

0x616347d97d70	var t2
0x616347d97e90	var t3
0x616347d98050	var t4
0x616347d981c0	var t5
0x616347d982e0	var t6
0x616347d987f0	var t9
0x616347d989b0	var t10
0x616347d98b20	var t11
0x616347d98c40	var t12
0x616347d99b20	label main
0x616347d99b70	begin
0x616347d96830	var a
0x616347d96920	var b
0x616347d96a10	var c
0x616347d96b00	var d
0x616347d96bf0	var e
0x616347d96ce0	var i
0x616347d96dd0	var j
0x616347d96ec0	var k
0x616347d96f30	input a
0x616347d96fa0	input b
0x616347d97010	input c
0x616347d97150	j = 5
0x616347d97dc0	t2 = b * c
0x616347d97ee0	t3 = a + t2
0x616347d980a0	t4 = a + c
0x616347d98210	t5 = t4 / b
0x616347d98330	t6 = t3 - t5
0x616347d98a00	t10 = c - a
0x616347d98b70	t11 = t10 / b
0x616347d98c90	t12 = t3 - t11
0x616347d99600	label L1
0x616347d97340	var t0
0x616347d97390	t0 = (j > 0)
0x616347d996f0	ifz t0 goto L3
0x616347d97610	output j
0x616347d97750	i = 9
0x616347d99150	label L4
0x616347d978c0	var t1
0x616347d97910	t1 = (i > 0)
0x616347d99240	ifz t1 goto L6
0x616347d97b90	output i
0x616347d98450	var t7
0x616347d984a0	t7 = t6 + 9
0x616347d984f0	d = t7
0x616347d986d0	var t8
0x616347d98db0	var t13
0x616347d98e00	t13 = t12 + 9
0x616347d98e50	e = t13
0x616347d99060	var t14
0x616347d990b0	t14 = i - 1
0x616347d99100	i = t14
0x616347d991a0	label L5
0x616347d99290	goto L4
0x616347d991f0	label L6
0x616347d99420	var t15
0x616347d99470	t15 = j - 1
0x616347d994c0	j = t15
0x616347d995b0	output L7
0x616347d99650	label L2
0x616347d99740	goto L1
0x616347d996a0	label L3
0x616347d99830	output L8
0x616347d998d0	output d
0x616347d99940	output L7
0x616347d999e0	output e
0x616347d99a50	output L8
0x616347d99bc0	end

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
