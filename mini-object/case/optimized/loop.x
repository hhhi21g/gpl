
# tac list

0x5aa5d6043c40	var t2
0x5aa5d6043d40	var t3
0x5aa5d6043ee0	var t4
0x5aa5d6044030	var t5
0x5aa5d6044130	var t6
0x5aa5d60445d0	var t9
0x5aa5d6044770	var t10
0x5aa5d60448c0	var t11
0x5aa5d60449c0	var t12
0x5aa5d60456f0	label main
0x5aa5d6045730	begin
0x5aa5d6042830	var a
0x5aa5d6042910	var b
0x5aa5d60429f0	var c
0x5aa5d6042ad0	var d
0x5aa5d6042bb0	var e
0x5aa5d6042c90	var i
0x5aa5d6042d70	var j
0x5aa5d6042e50	var k
0x5aa5d6042eb0	input a
0x5aa5d6042f10	input b
0x5aa5d6042f70	input c
0x5aa5d60430a0	j = 5
0x5aa5d6043c80	t2 = b * c
0x5aa5d6043d80	t3 = a + t2
0x5aa5d6043f20	t4 = a + c
0x5aa5d6044070	t5 = t4 / b
0x5aa5d6044170	t6 = t3 - t5
0x5aa5d60447b0	t10 = c - a
0x5aa5d6044900	t11 = t10 / b
0x5aa5d6044a00	t12 = t3 - t11
0x5aa5d6045270	label L1
0x5aa5d6043280	var t0
0x5aa5d60432c0	t0 = (j > 0)
0x5aa5d6045330	ifz t0 goto L3
0x5aa5d6043530	output j
0x5aa5d6043660	i = 9
0x5aa5d6044e50	label L4
0x5aa5d60437c0	var t1
0x5aa5d6043800	t1 = (i > 0)
0x5aa5d6044f10	ifz t1 goto L6
0x5aa5d6043a70	output i
0x5aa5d6044280	var t7
0x5aa5d60442c0	t7 = t6 + 9
0x5aa5d6044300	d = t7
0x5aa5d60444d0	var t8
0x5aa5d6044b10	var t13
0x5aa5d6044b50	t13 = t12 + 9
0x5aa5d6044b90	e = t13
0x5aa5d6044d90	var t14
0x5aa5d6044dd0	t14 = i - 1
0x5aa5d6044e10	i = t14
0x5aa5d6044e90	label L5
0x5aa5d6044f50	goto L4
0x5aa5d6044ed0	label L6
0x5aa5d60450d0	var t15
0x5aa5d6045110	t15 = j - 1
0x5aa5d6045150	j = t15
0x5aa5d6045230	output L7
0x5aa5d60452b0	label L2
0x5aa5d6045370	goto L1
0x5aa5d60452f0	label L3
0x5aa5d6045450	output L8
0x5aa5d60454e0	output d
0x5aa5d6045540	output L7
0x5aa5d60455d0	output e
0x5aa5d6045630	output L8
0x5aa5d6045770	end

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
