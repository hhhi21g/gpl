
# tac list

0x5aaec25394f0	label main
0x5aaec2539530	begin
0x5aaec2537840	var i
0x5aaec2537920	var j
0x5aaec2537a00	var k
0x5aaec2537b30	k = 0
0x5aaec2539330	label L1
0x5aaec2537d10	var t0
0x5aaec2537d50	t0 = (k < 10)
0x5aaec25393f0	ifz t0 goto L3
0x5aaec2537fe0	i = 0
0x5aaec2538ff0	label L4
0x5aaec2538140	var t1
0x5aaec2538180	t1 = (i < 10)
0x5aaec25390b0	ifz t1 goto L6
0x5aaec2538560	var t2
0x5aaec25385a0	t2 = 2 * i
0x5aaec2538730	var t3
0x5aaec2538770	t3 = t2 + 9
0x5aaec25387b0	j = t3
0x5aaec2538840	output j
0x5aaec2538920	output L7
0x5aaec2538b20	var t4
0x5aaec2538b60	t4 = i + 1
0x5aaec2538ba0	i = t4
0x5aaec2539030	label L5
0x5aaec25390f0	goto L4
0x5aaec2539070	label L6
0x5aaec2539270	var t5
0x5aaec25392b0	t5 = k + 1
0x5aaec25392f0	k = t5
0x5aaec2539370	label L2
0x5aaec2539430	goto L1
0x5aaec25393b0	label L3
0x5aaec2539570	end

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
