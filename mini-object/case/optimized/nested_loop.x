
# tac list

0x5d4999e050e0	label main
0x5d4999e05120	begin
0x5d4999e03840	var i
0x5d4999e03920	var j
0x5d4999e03a00	var k
0x5d4999e03b30	k = 0
0x5d4999e04f20	label L1
0x5d4999e03d10	var t0
0x5d4999e03d50	t0 = (k < 10)
0x5d4999e04fe0	ifz t0 goto L3
0x5d4999e03fe0	i = 0
0x5d4999e04be0	label L4
0x5d4999e04140	var t1
0x5d4999e04180	t1 = (i < 10)
0x5d4999e04ca0	ifz t1 goto L6
0x5d4999e04560	var t2
0x5d4999e045a0	t2 = 2 * i
0x5d4999e04730	var t3
0x5d4999e04770	t3 = t2 + 9
0x5d4999e047b0	j = t3
0x5d4999e04840	output j
0x5d4999e04920	output L7
0x5d4999e04b20	var t4
0x5d4999e04b60	t4 = i + 1
0x5d4999e04ba0	i = t4
0x5d4999e04c20	label L5
0x5d4999e04ce0	goto L4
0x5d4999e04c60	label L6
0x5d4999e04e60	var t5
0x5d4999e04ea0	t5 = k + 1
0x5d4999e04ee0	k = t5
0x5d4999e04f60	label L2
0x5d4999e05020	goto L1
0x5d4999e04fa0	label L3
0x5d4999e05160	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
var k
k = 0
  succ: B2 

[B2]
label L1
var t0
t0 = (k < 10)
ifz t0 goto L3
  succ: B7 B3 

[B3]
i = 0
  succ: B4 

[B4]
label L4
var t1
t1 = (i < 10)
ifz t1 goto L6
  succ: B6 B5 

[B5]
var t2
t2 = 2 * i
var t3
t3 = t2 + 9
j = t3
output j
output L7
var t4
t4 = i + 1
i = t4
label L5
goto L4
  succ: B4 

[B6]
label L6
var t5
t5 = k + 1
k = t5
label L2
goto L1
  succ: B2 

[B7]
label L3
end
  succ: 
