
# tac list

0x63bcc4cb60e0	label main
0x63bcc4cb6120	begin
0x63bcc4cb4840	var i
0x63bcc4cb4920	var j
0x63bcc4cb4a00	var k
0x63bcc4cb4b30	k = 0
0x63bcc4cb5f20	label L1
0x63bcc4cb4d10	var t0
0x63bcc4cb4d50	t0 = (k < 10)
0x63bcc4cb5fe0	ifz t0 goto L3
0x63bcc4cb4fe0	i = 0
0x63bcc4cb5be0	label L4
0x63bcc4cb5140	var t1
0x63bcc4cb5180	t1 = (i < 10)
0x63bcc4cb5ca0	ifz t1 goto L6
0x63bcc4cb5560	var t2
0x63bcc4cb55a0	t2 = 2 * i
0x63bcc4cb5730	var t3
0x63bcc4cb5770	t3 = t2 + 9
0x63bcc4cb57b0	j = t3
0x63bcc4cb5840	output j
0x63bcc4cb5920	output L7
0x63bcc4cb5b20	var t4
0x63bcc4cb5b60	t4 = i + 1
0x63bcc4cb5ba0	i = t4
0x63bcc4cb5c20	label L5
0x63bcc4cb5ce0	goto L4
0x63bcc4cb5c60	label L6
0x63bcc4cb5e60	var t5
0x63bcc4cb5ea0	t5 = k + 1
0x63bcc4cb5ee0	k = t5
0x63bcc4cb5f60	label L2
0x63bcc4cb6020	goto L1
0x63bcc4cb5fa0	label L3
0x63bcc4cb6160	end

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
