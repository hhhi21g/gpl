
# tac list

0x59ebaafaf970	label main
0x59ebaafaf9b0	begin
0x59ebaaface70	var i
0x59ebaafacf50	var j
0x59ebaafad030	var pi
0x59ebaafad110	var a
0x59ebaafad1f0	var b
0x59ebaafad2d0	var pc
0x59ebaafad3b0	var c1
0x59ebaafadc00	var t2
0x59ebaafadc40	t2 = &c1
0x59ebaafadd00	var t3
0x59ebaafaddc0	t3 = t2 + 14
0x59ebaafade80	var t4
0x59ebaafadf40	t4 = t3 + 1108
0x59ebaafae000	var t5
0x59ebaafae040	t5 = t4 + 14
0x59ebaafae100	var t6
0x59ebaafae1c0	t6 = t5 + 162
0x59ebaafae280	var t7
0x59ebaafae2c0	t7 = t6 + 0
0x59ebaafad950	var t0
0x59ebaafad990	t0 = &c1
0x59ebaafada50	var t1
0x59ebaafadb10	t1 = t0 + 0
0x59ebaafae300	*t7 = t1
0x59ebaafae6f0	var t8
0x59ebaafae730	t8 = &c1
0x59ebaafae7f0	var t9
0x59ebaafae830	t9 = t8 + 14
0x59ebaafae8f0	var t10
0x59ebaafae930	t10 = t9 + 1108
0x59ebaafae9f0	var t11
0x59ebaafaea30	t11 = t10 + 14
0x59ebaafaeaf0	var t12
0x59ebaafaeb30	t12 = t11 + 162
0x59ebaafaebf0	var t13
0x59ebaafaec30	t13 = t12 + 0
0x59ebaafaecf0	var t14
0x59ebaafaed30	t14 = *t13
0x59ebaafaeda0	pi = t14
0x59ebaafaeed0	*pi = 999
0x59ebaafaf080	var t15
0x59ebaafaf0c0	t15 = &c1
0x59ebaafaf180	var t16
0x59ebaafaf1c0	t16 = t15 + 0
0x59ebaafaf280	var t17
0x59ebaafaf2c0	t17 = *t16
0x59ebaafaf330	i = t17
0x59ebaafaf7d0	output i
0x59ebaafaf8b0	output L1
0x59ebaafaf9f0	end

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
