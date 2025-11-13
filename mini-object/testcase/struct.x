
# tac list

0x572bdce0dd60	label main
0x572bdce0dda0	begin
0x572bdce0b9d0	var i
0x572bdce0baa0	var j
0x572bdce0bb70	var k
0x572bdce0bc40	var zs
0x572bdce0bca0	input i
0x572bdce0bd00	input j
0x572bdce0bd60	input k
0x572bdce0bea0	var t0
0x572bdce0bee0	t0 = &zs
0x572bdce0bf90	var t1
0x572bdce0c040	t1 = t0 + 0
0x572bdce0c080	*t1 = i
0x572bdce0c1c0	var t2
0x572bdce0c200	t2 = &zs
0x572bdce0c2b0	var t3
0x572bdce0c360	t3 = t2 + 4
0x572bdce0c3a0	*t3 = j
0x572bdce0c4e0	var t4
0x572bdce0c520	t4 = &zs
0x572bdce0c5d0	var t5
0x572bdce0c680	t5 = t4 + 8
0x572bdce0c6c0	*t5 = k
0x572bdce0c910	ifz 0 goto L2
0x572bdce0c7e0	output L1
0x572bdce0c8d0	label L2
0x572bdce0ca00	var t6
0x572bdce0ca40	t6 = &zs
0x572bdce0caf0	var t7
0x572bdce0cb30	t7 = 8 + t6
0x572bdce0cbe0	var t8
0x572bdce0cc20	t8 = *t7
0x572bdce0cdc0	var t9
0x572bdce0ce00	t9 = t8 + 100
0x572bdce0ce40	i = t9
0x572bdce0cf50	var t10
0x572bdce0cf90	t10 = &zs
0x572bdce0d040	var t11
0x572bdce0d080	t11 = 4 + t10
0x572bdce0d130	var t12
0x572bdce0d170	t12 = *t11
0x572bdce0d310	var t13
0x572bdce0d350	t13 = t12 + 200
0x572bdce0d390	j = t13
0x572bdce0d4a0	var t14
0x572bdce0d4e0	t14 = &zs
0x572bdce0d590	var t15
0x572bdce0d5d0	t15 = 0 + t14
0x572bdce0d680	var t16
0x572bdce0d6c0	t16 = *t15
0x572bdce0d860	var t17
0x572bdce0d8a0	t17 = t16 + 300
0x572bdce0d8e0	k = t17
0x572bdce0daa0	ifz 0 goto L3
0x572bdce0d990	output L1
0x572bdce0da60	label L3
0x572bdce0db30	output i
0x572bdce0dbc0	output j
0x572bdce0dc50	output k
0x572bdce0dcb0	output L1
0x572bdce0dde0	end

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
