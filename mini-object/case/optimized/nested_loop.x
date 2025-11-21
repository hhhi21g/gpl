
# tac list

0x58d382af90e0	label main
0x58d382af9120	begin
0x58d382af7840	var i
0x58d382af7920	var j
0x58d382af7a00	var k
0x58d382af7b30	k = 0
0x58d382af8f20	label L1
0x58d382af7d10	var t0
0x58d382af7d50	t0 = (k < 10)
0x58d382af8fe0	ifz t0 goto L3
0x58d382af7fe0	i = 0
0x58d382af8be0	label L4
0x58d382af8140	var t1
0x58d382af8180	t1 = (i < 10)
0x58d382af8ca0	ifz t1 goto L6
0x58d382af8560	var t2
0x58d382af85a0	t2 = 2 * i
0x58d382af8730	var t3
0x58d382af8770	t3 = t2 + 9
0x58d382af87b0	j = t3
0x58d382af8840	output j
0x58d382af8920	output L7
0x58d382af8b20	var t4
0x58d382af8b60	t4 = i + 1
0x58d382af8ba0	i = t4
0x58d382af8c20	label L5
0x58d382af8ce0	goto L4
0x58d382af8c60	label L6
0x58d382af8e60	var t5
0x58d382af8ea0	t5 = k + 1
0x58d382af8ee0	k = t5
0x58d382af8f60	label L2
0x58d382af9020	goto L1
0x58d382af8fa0	label L3
0x58d382af9160	end

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
