
# tac list

0x5b45f8bd34f0	label main
0x5b45f8bd3530	begin
0x5b45f8bd1840	var i
0x5b45f8bd1920	var j
0x5b45f8bd1a00	var k
0x5b45f8bd1b30	k = 0
0x5b45f8bd3330	label L1
0x5b45f8bd1d10	var t0
0x5b45f8bd1d50	t0 = (k < 10)
0x5b45f8bd33f0	ifz t0 goto L3
0x5b45f8bd1fe0	i = 0
0x5b45f8bd2ff0	label L4
0x5b45f8bd2140	var t1
0x5b45f8bd2180	t1 = (i < 10)
0x5b45f8bd30b0	ifz t1 goto L6
0x5b45f8bd2560	var t2
0x5b45f8bd25a0	t2 = 2 * i
0x5b45f8bd2730	var t3
0x5b45f8bd2770	t3 = t2 + 9
0x5b45f8bd27b0	j = t3
0x5b45f8bd2840	output j
0x5b45f8bd2920	output L7
0x5b45f8bd2b20	var t4
0x5b45f8bd2b60	t4 = i + 1
0x5b45f8bd2ba0	i = t4
0x5b45f8bd3030	label L5
0x5b45f8bd30f0	goto L4
0x5b45f8bd3070	label L6
0x5b45f8bd3270	var t5
0x5b45f8bd32b0	t5 = k + 1
0x5b45f8bd32f0	k = t5
0x5b45f8bd3370	label L2
0x5b45f8bd3430	goto L1
0x5b45f8bd33b0	label L3
0x5b45f8bd3570	end

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
