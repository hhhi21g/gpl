
# tac list

0x5781e666c560	label main
0x5781e666c5a0	begin
0x5781e6669e70	var i
0x5781e6669f50	var j
0x5781e666a030	var pi
0x5781e666a110	var a
0x5781e666a1f0	var b
0x5781e666a2d0	var pc
0x5781e666a3b0	var c1
0x5781e666ac00	var t2
0x5781e666ac40	t2 = &c1
0x5781e666ad00	var t3
0x5781e666adc0	t3 = t2 + 14
0x5781e666ae80	var t4
0x5781e666af40	t4 = t3 + 1108
0x5781e666b000	var t5
0x5781e666b040	t5 = t4 + 14
0x5781e666b100	var t6
0x5781e666b1c0	t6 = t5 + 162
0x5781e666b280	var t7
0x5781e666b2c0	t7 = t6 + 0
0x5781e666a950	var t0
0x5781e666a990	t0 = &c1
0x5781e666aa50	var t1
0x5781e666ab10	t1 = t0 + 0
0x5781e666b300	*t7 = t1
0x5781e666b6f0	var t8
0x5781e666b730	t8 = &c1
0x5781e666b7f0	var t9
0x5781e666b830	t9 = t8 + 14
0x5781e666b8f0	var t10
0x5781e666b930	t10 = t9 + 1108
0x5781e666b9f0	var t11
0x5781e666ba30	t11 = t10 + 14
0x5781e666baf0	var t12
0x5781e666bb30	t12 = t11 + 162
0x5781e666bbf0	var t13
0x5781e666bc30	t13 = t12 + 0
0x5781e666bcf0	var t14
0x5781e666bd30	t14 = *t13
0x5781e666bda0	pi = t14
0x5781e666bed0	*pi = 999
0x5781e666c080	var t15
0x5781e666c0c0	t15 = &c1
0x5781e666c180	var t16
0x5781e666c1c0	t16 = t15 + 0
0x5781e666c280	var t17
0x5781e666c2c0	t17 = *t16
0x5781e666c330	i = t17
0x5781e666c3c0	output i
0x5781e666c4a0	output L1
0x5781e666c5e0	end

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
