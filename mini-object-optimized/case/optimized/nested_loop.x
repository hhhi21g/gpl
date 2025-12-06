
# tac list

0x56b9f7c940e0	label main
0x56b9f7c94120	begin
0x56b9f7c92840	var i
0x56b9f7c92920	var j
0x56b9f7c92a00	var k
0x56b9f7c92b30	k = 0
0x56b9f7c93f20	label L1
0x56b9f7c92d10	var t0
0x56b9f7c92d50	t0 = (k < 10)
0x56b9f7c93fe0	ifz t0 goto L3
0x56b9f7c92fe0	i = 0
0x56b9f7c93be0	label L4
0x56b9f7c93140	var t1
0x56b9f7c93180	t1 = (i < 10)
0x56b9f7c93ca0	ifz t1 goto L6
0x56b9f7c93560	var t2
0x56b9f7c935a0	t2 = 2 * i
0x56b9f7c93730	var t3
0x56b9f7c93770	t3 = t2 + 9
0x56b9f7c937b0	j = t3
0x56b9f7c93840	output j
0x56b9f7c93920	output L7
0x56b9f7c93b20	var t4
0x56b9f7c93b60	t4 = i + 1
0x56b9f7c93ba0	i = t4
0x56b9f7c93c20	label L5
0x56b9f7c93ce0	goto L4
0x56b9f7c93c60	label L6
0x56b9f7c93e60	var t5
0x56b9f7c93ea0	t5 = k + 1
0x56b9f7c93ee0	k = t5
0x56b9f7c93f60	label L2
0x56b9f7c94020	goto L1
0x56b9f7c93fa0	label L3
0x56b9f7c94160	end

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
