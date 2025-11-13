
# tac list

0x57be580cfd30	label main
0x57be580cfd70	begin
0x57be580cd9a0	var i
0x57be580cda70	var j
0x57be580cdb40	var k
0x57be580cdc10	var zs
0x57be580cdc70	input i
0x57be580cdcd0	input j
0x57be580cdd30	input k
0x57be580cde70	var t0
0x57be580cdeb0	t0 = &zs
0x57be580cdf60	var t1
0x57be580ce010	t1 = t0 + 0
0x57be580ce050	*t1 = i
0x57be580ce190	var t2
0x57be580ce1d0	t2 = &zs
0x57be580ce280	var t3
0x57be580ce330	t3 = t2 + 4
0x57be580ce370	*t3 = j
0x57be580ce4b0	var t4
0x57be580ce4f0	t4 = &zs
0x57be580ce5a0	var t5
0x57be580ce650	t5 = t4 + 8
0x57be580ce690	*t5 = k
0x57be580ce8e0	ifz 0 goto L2
0x57be580ce7b0	output L1
0x57be580ce8a0	label L2
0x57be580ce9d0	var t6
0x57be580cea10	t6 = &zs
0x57be580ceac0	var t7
0x57be580ceb00	t7 = 8 + t6
0x57be580cebb0	var t8
0x57be580cebf0	t8 = *t7
0x57be580ced90	var t9
0x57be580cedd0	t9 = t8 + 100
0x57be580cee10	i = t9
0x57be580cef20	var t10
0x57be580cef60	t10 = &zs
0x57be580cf010	var t11
0x57be580cf050	t11 = 4 + t10
0x57be580cf100	var t12
0x57be580cf140	t12 = *t11
0x57be580cf2e0	var t13
0x57be580cf320	t13 = t12 + 200
0x57be580cf360	j = t13
0x57be580cf470	var t14
0x57be580cf4b0	t14 = &zs
0x57be580cf560	var t15
0x57be580cf5a0	t15 = 0 + t14
0x57be580cf650	var t16
0x57be580cf690	t16 = *t15
0x57be580cf830	var t17
0x57be580cf870	t17 = t16 + 300
0x57be580cf8b0	k = t17
0x57be580cfa70	ifz 0 goto L3
0x57be580cf960	output L1
0x57be580cfa30	label L3
0x57be580cfb00	output i
0x57be580cfb90	output j
0x57be580cfc20	output k
0x57be580cfc80	output L1
0x57be580cfdb0	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
var k
var zs
input i
input j
input k
var t0
t0 = &zs
var t1
t1 = t0 + 0
*t1 = i
var t2
t2 = &zs
var t3
t3 = t2 + 4
*t3 = j
var t4
t4 = &zs
var t5
t5 = t4 + 8
*t5 = k
ifz 0 goto L2
  succ: B3 B2 

[B2]
output L1
  succ: B3 

[B3]
label L2
var t6
t6 = &zs
var t7
t7 = 8 + t6
var t8
t8 = *t7
var t9
t9 = t8 + 100
i = t9
var t10
t10 = &zs
var t11
t11 = 4 + t10
var t12
t12 = *t11
var t13
t13 = t12 + 200
j = t13
var t14
t14 = &zs
var t15
t15 = 0 + t14
var t16
t16 = *t15
var t17
t17 = t16 + 300
k = t17
ifz 0 goto L3
  succ: B5 B4 

[B4]
output L1
  succ: B5 

[B5]
label L3
output i
output j
output k
output L1
end
  succ: 
