
# tac list

0x56d53453e140	label main
0x56d53453e180	begin
0x56d53453bdb0	var i
0x56d53453be80	var j
0x56d53453bf50	var k
0x56d53453c020	var zs
0x56d53453c080	input i
0x56d53453c0e0	input j
0x56d53453c140	input k
0x56d53453c280	var t0
0x56d53453c2c0	t0 = &zs
0x56d53453c370	var t1
0x56d53453c420	t1 = t0 + 0
0x56d53453c460	*t1 = i
0x56d53453c5a0	var t2
0x56d53453c5e0	t2 = &zs
0x56d53453c690	var t3
0x56d53453c740	t3 = t2 + 4
0x56d53453c780	*t3 = j
0x56d53453c8c0	var t4
0x56d53453c900	t4 = &zs
0x56d53453c9b0	var t5
0x56d53453ca60	t5 = t4 + 8
0x56d53453caa0	*t5 = k
0x56d53453ccf0	ifz 0 goto L2
0x56d53453cbc0	output L1
0x56d53453ccb0	label L2
0x56d53453cde0	var t6
0x56d53453ce20	t6 = &zs
0x56d53453ced0	var t7
0x56d53453cf10	t7 = 8 + t6
0x56d53453cfc0	var t8
0x56d53453d000	t8 = *t7
0x56d53453d1a0	var t9
0x56d53453d1e0	t9 = t8 + 100
0x56d53453d220	i = t9
0x56d53453d330	var t10
0x56d53453d370	t10 = &zs
0x56d53453d420	var t11
0x56d53453d460	t11 = 4 + t10
0x56d53453d510	var t12
0x56d53453d550	t12 = *t11
0x56d53453d6f0	var t13
0x56d53453d730	t13 = t12 + 200
0x56d53453d770	j = t13
0x56d53453d880	var t14
0x56d53453d8c0	t14 = &zs
0x56d53453d970	var t15
0x56d53453d9b0	t15 = 0 + t14
0x56d53453da60	var t16
0x56d53453daa0	t16 = *t15
0x56d53453dc40	var t17
0x56d53453dc80	t17 = t16 + 300
0x56d53453dcc0	k = t17
0x56d53453de80	ifz 0 goto L3
0x56d53453dd70	output L1
0x56d53453de40	label L3
0x56d53453df10	output i
0x56d53453dfa0	output j
0x56d53453e030	output k
0x56d53453e090	output L1
0x56d53453e1c0	end

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
