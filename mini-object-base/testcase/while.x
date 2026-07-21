
# tac list

0x5aed35d9d410	label main
0x5aed35d9d450	begin
0x5aed35d9c830	var i
0x5aed35d9c910	var j
0x5aed35d9ca40	i = 0
0x5aed35d9caa0	input j
0x5aed35d9d170	label L1
0x5aed35d9cc00	var t0
0x5aed35d9cc40	t0 = (i < j)
0x5aed35d9d230	ifz t0 goto L3
0x5aed35d9ceb0	output i
0x5aed35d9d0b0	var t1
0x5aed35d9d0f0	t1 = i + 1
0x5aed35d9d130	i = t1
0x5aed35d9d1b0	label L2
0x5aed35d9d270	goto L1
0x5aed35d9d1f0	label L3
0x5aed35d9d350	output L4
0x5aed35d9d490	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
i = 0
input j
  succ: B2 

[B2]
label L1
var t0
t0 = (i < j)
ifz t0 goto L3
  succ: B4 B3 

[B3]
output i
var t1
t1 = i + 1
i = t1
label L2
goto L1
  succ: B2 

[B4]
label L3
output L4
end
  succ: 
