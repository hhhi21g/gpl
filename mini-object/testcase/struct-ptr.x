
# tac list

0x5fd9fd360970	label main
0x5fd9fd3609b0	begin
0x5fd9fd35de70	var i
0x5fd9fd35df50	var j
0x5fd9fd35e030	var pi
0x5fd9fd35e110	var a
0x5fd9fd35e1f0	var b
0x5fd9fd35e2d0	var pc
0x5fd9fd35e3b0	var c1
0x5fd9fd35ec00	var t2
0x5fd9fd35ec40	t2 = &c1
0x5fd9fd35ed00	var t3
0x5fd9fd35edc0	t3 = t2 + 14
0x5fd9fd35ee80	var t4
0x5fd9fd35ef40	t4 = t3 + 1108
0x5fd9fd35f000	var t5
0x5fd9fd35f040	t5 = t4 + 14
0x5fd9fd35f100	var t6
0x5fd9fd35f1c0	t6 = t5 + 162
0x5fd9fd35f280	var t7
0x5fd9fd35f2c0	t7 = t6 + 0
0x5fd9fd35e950	var t0
0x5fd9fd35e990	t0 = &c1
0x5fd9fd35ea50	var t1
0x5fd9fd35eb10	t1 = t0 + 0
0x5fd9fd35f300	*t7 = t1
0x5fd9fd35f6f0	var t8
0x5fd9fd35f730	t8 = &c1
0x5fd9fd35f7f0	var t9
0x5fd9fd35f830	t9 = t8 + 14
0x5fd9fd35f8f0	var t10
0x5fd9fd35f930	t10 = t9 + 1108
0x5fd9fd35f9f0	var t11
0x5fd9fd35fa30	t11 = t10 + 14
0x5fd9fd35faf0	var t12
0x5fd9fd35fb30	t12 = t11 + 162
0x5fd9fd35fbf0	var t13
0x5fd9fd35fc30	t13 = t12 + 0
0x5fd9fd35fcf0	var t14
0x5fd9fd35fd30	t14 = *t13
0x5fd9fd35fda0	pi = t14
0x5fd9fd35fed0	*pi = 999
0x5fd9fd360080	var t15
0x5fd9fd3600c0	t15 = &c1
0x5fd9fd360180	var t16
0x5fd9fd3601c0	t16 = t15 + 0
0x5fd9fd360280	var t17
0x5fd9fd3602c0	t17 = *t16
0x5fd9fd360330	i = t17
0x5fd9fd3607d0	output i
0x5fd9fd3608b0	output L1
0x5fd9fd3609f0	end

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
