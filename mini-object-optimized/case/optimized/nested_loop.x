
# tac list

0x64783b8e00e0	label main
0x64783b8e0120	begin
0x64783b8de840	var i
0x64783b8de920	var j
0x64783b8dea00	var k
0x64783b8deb30	k = 0
0x64783b8dff20	label L1
0x64783b8ded10	var t0
0x64783b8ded50	t0 = (k < 10)
0x64783b8dffe0	ifz t0 goto L3
0x64783b8defe0	i = 0
0x64783b8dfbe0	label L4
0x64783b8df140	var t1
0x64783b8df180	t1 = (i < 10)
0x64783b8dfca0	ifz t1 goto L6
0x64783b8df560	var t2
0x64783b8df5a0	t2 = 2 * i
0x64783b8df730	var t3
0x64783b8df770	t3 = t2 + 9
0x64783b8df7b0	j = t3
0x64783b8df840	output j
0x64783b8df920	output L7
0x64783b8dfb20	var t4
0x64783b8dfb60	t4 = i + 1
0x64783b8dfba0	i = t4
0x64783b8dfc20	label L5
0x64783b8dfce0	goto L4
0x64783b8dfc60	label L6
0x64783b8dfe60	var t5
0x64783b8dfea0	t5 = k + 1
0x64783b8dfee0	k = t5
0x64783b8dff60	label L2
0x64783b8e0020	goto L1
0x64783b8dffa0	label L3
0x64783b8e0160	end

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
