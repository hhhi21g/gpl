
# tac list

0x5e8c14c744f0	label main
0x5e8c14c74530	begin
0x5e8c14c72840	var i
0x5e8c14c72920	var j
0x5e8c14c72a00	var k
0x5e8c14c72b30	k = 0
0x5e8c14c74330	label L1
0x5e8c14c72d10	var t0
0x5e8c14c72d50	t0 = (k < 10)
0x5e8c14c743f0	ifz t0 goto L3
0x5e8c14c72fe0	i = 0
0x5e8c14c73ff0	label L4
0x5e8c14c73140	var t1
0x5e8c14c73180	t1 = (i < 10)
0x5e8c14c740b0	ifz t1 goto L6
0x5e8c14c73560	var t2
0x5e8c14c735a0	t2 = 2 * i
0x5e8c14c73730	var t3
0x5e8c14c73770	t3 = t2 + 9
0x5e8c14c737b0	j = t3
0x5e8c14c73840	output j
0x5e8c14c73920	output L7
0x5e8c14c73b20	var t4
0x5e8c14c73b60	t4 = i + 1
0x5e8c14c73ba0	i = t4
0x5e8c14c74030	label L5
0x5e8c14c740f0	goto L4
0x5e8c14c74070	label L6
0x5e8c14c74270	var t5
0x5e8c14c742b0	t5 = k + 1
0x5e8c14c742f0	k = t5
0x5e8c14c74370	label L2
0x5e8c14c74430	goto L1
0x5e8c14c743b0	label L3
0x5e8c14c74570	end

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
