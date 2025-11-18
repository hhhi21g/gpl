
# tac list

0x5f208dbae4f0	label main
0x5f208dbae530	begin
0x5f208dbac840	var i
0x5f208dbac920	var j
0x5f208dbaca00	var k
0x5f208dbacb30	k = 0
0x5f208dbae330	label L1
0x5f208dbacd10	var t0
0x5f208dbacd50	t0 = (k < 10)
0x5f208dbae3f0	ifz t0 goto L3
0x5f208dbacfe0	i = 0
0x5f208dbadff0	label L4
0x5f208dbad140	var t1
0x5f208dbad180	t1 = (i < 10)
0x5f208dbae0b0	ifz t1 goto L6
0x5f208dbad560	var t2
0x5f208dbad5a0	t2 = 2 * i
0x5f208dbad730	var t3
0x5f208dbad770	t3 = t2 + 9
0x5f208dbad7b0	j = t3
0x5f208dbad840	output j
0x5f208dbad920	output L7
0x5f208dbadb20	var t4
0x5f208dbadb60	t4 = i + 1
0x5f208dbadba0	i = t4
0x5f208dbae030	label L5
0x5f208dbae0f0	goto L4
0x5f208dbae070	label L6
0x5f208dbae270	var t5
0x5f208dbae2b0	t5 = k + 1
0x5f208dbae2f0	k = t5
0x5f208dbae370	label L2
0x5f208dbae430	goto L1
0x5f208dbae3b0	label L3
0x5f208dbae570	end

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
