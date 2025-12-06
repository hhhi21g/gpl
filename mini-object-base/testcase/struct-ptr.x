
# tac list

0x5ecf0bb3c560	label main
0x5ecf0bb3c5a0	begin
0x5ecf0bb39e70	var i
0x5ecf0bb39f50	var j
0x5ecf0bb3a030	var pi
0x5ecf0bb3a110	var a
0x5ecf0bb3a1f0	var b
0x5ecf0bb3a2d0	var pc
0x5ecf0bb3a3b0	var c1
0x5ecf0bb3ac00	var t2
0x5ecf0bb3ac40	t2 = &c1
0x5ecf0bb3ad00	var t3
0x5ecf0bb3adc0	t3 = t2 + 14
0x5ecf0bb3ae80	var t4
0x5ecf0bb3af40	t4 = t3 + 1108
0x5ecf0bb3b000	var t5
0x5ecf0bb3b040	t5 = t4 + 14
0x5ecf0bb3b100	var t6
0x5ecf0bb3b1c0	t6 = t5 + 162
0x5ecf0bb3b280	var t7
0x5ecf0bb3b2c0	t7 = t6 + 0
0x5ecf0bb3a950	var t0
0x5ecf0bb3a990	t0 = &c1
0x5ecf0bb3aa50	var t1
0x5ecf0bb3ab10	t1 = t0 + 0
0x5ecf0bb3b300	*t7 = t1
0x5ecf0bb3b6f0	var t8
0x5ecf0bb3b730	t8 = &c1
0x5ecf0bb3b7f0	var t9
0x5ecf0bb3b830	t9 = t8 + 14
0x5ecf0bb3b8f0	var t10
0x5ecf0bb3b930	t10 = t9 + 1108
0x5ecf0bb3b9f0	var t11
0x5ecf0bb3ba30	t11 = t10 + 14
0x5ecf0bb3baf0	var t12
0x5ecf0bb3bb30	t12 = t11 + 162
0x5ecf0bb3bbf0	var t13
0x5ecf0bb3bc30	t13 = t12 + 0
0x5ecf0bb3bcf0	var t14
0x5ecf0bb3bd30	t14 = *t13
0x5ecf0bb3bda0	pi = t14
0x5ecf0bb3bed0	*pi = 999
0x5ecf0bb3c080	var t15
0x5ecf0bb3c0c0	t15 = &c1
0x5ecf0bb3c180	var t16
0x5ecf0bb3c1c0	t16 = t15 + 0
0x5ecf0bb3c280	var t17
0x5ecf0bb3c2c0	t17 = *t16
0x5ecf0bb3c330	i = t17
0x5ecf0bb3c3c0	output i
0x5ecf0bb3c4a0	output L1
0x5ecf0bb3c5e0	end

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
