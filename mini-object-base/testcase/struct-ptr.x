
# tac list

0x56b4f912a560	label main
0x56b4f912a5a0	begin
0x56b4f9127e70	var i
0x56b4f9127f50	var j
0x56b4f9128030	var pi
0x56b4f9128110	var a
0x56b4f91281f0	var b
0x56b4f91282d0	var pc
0x56b4f91283b0	var c1
0x56b4f9128c00	var t2
0x56b4f9128c40	t2 = &c1
0x56b4f9128d00	var t3
0x56b4f9128dc0	t3 = t2 + 14
0x56b4f9128e80	var t4
0x56b4f9128f40	t4 = t3 + 1108
0x56b4f9129000	var t5
0x56b4f9129040	t5 = t4 + 14
0x56b4f9129100	var t6
0x56b4f91291c0	t6 = t5 + 162
0x56b4f9129280	var t7
0x56b4f91292c0	t7 = t6 + 0
0x56b4f9128950	var t0
0x56b4f9128990	t0 = &c1
0x56b4f9128a50	var t1
0x56b4f9128b10	t1 = t0 + 0
0x56b4f9129300	*t7 = t1
0x56b4f91296f0	var t8
0x56b4f9129730	t8 = &c1
0x56b4f91297f0	var t9
0x56b4f9129830	t9 = t8 + 14
0x56b4f91298f0	var t10
0x56b4f9129930	t10 = t9 + 1108
0x56b4f91299f0	var t11
0x56b4f9129a30	t11 = t10 + 14
0x56b4f9129af0	var t12
0x56b4f9129b30	t12 = t11 + 162
0x56b4f9129bf0	var t13
0x56b4f9129c30	t13 = t12 + 0
0x56b4f9129cf0	var t14
0x56b4f9129d30	t14 = *t13
0x56b4f9129da0	pi = t14
0x56b4f9129ed0	*pi = 999
0x56b4f912a080	var t15
0x56b4f912a0c0	t15 = &c1
0x56b4f912a180	var t16
0x56b4f912a1c0	t16 = t15 + 0
0x56b4f912a280	var t17
0x56b4f912a2c0	t17 = *t16
0x56b4f912a330	i = t17
0x56b4f912a3c0	output i
0x56b4f912a4a0	output L1
0x56b4f912a5e0	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
var pi
var a
var b
var pc
var c1
var t2
t2 = &c1
var t3
t3 = t2 + 14
var t4
t4 = t3 + 1108
var t5
t5 = t4 + 14
var t6
t6 = t5 + 162
var t7
t7 = t6 + 0
var t0
t0 = &c1
var t1
t1 = t0 + 0
*t7 = t1
var t8
t8 = &c1
var t9
t9 = t8 + 14
var t10
t10 = t9 + 1108
var t11
t11 = t10 + 14
var t12
t12 = t11 + 162
var t13
t13 = t12 + 0
var t14
t14 = *t13
pi = t14
*pi = 999
var t15
t15 = &c1
var t16
t16 = t15 + 0
var t17
t17 = *t16
i = t17
output i
output L1
end
  succ: 
