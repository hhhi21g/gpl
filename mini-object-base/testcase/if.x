
# tac list

0x5a226b368480	label main
0x5a226b3684c0	begin
0x5a226b367830	var i
0x5a226b367910	var j
0x5a226b3679f0	var k
0x5a226b367a50	input i
0x5a226b367ab0	input j
0x5a226b367c10	var t0
0x5a226b367c50	t0 = (i == j)
0x5a226b368010	ifz t0 goto L3
0x5a226b367d30	output L1
0x5a226b368050	goto L4
0x5a226b367ef0	label L3
0x5a226b367e10	output L2
0x5a226b367fd0	label L4
0x5a226b3681d0	var t1
0x5a226b368210	t1 = i + j
0x5a226b368250	k = t1
0x5a226b3682e0	output k
0x5a226b3683c0	output L5
0x5a226b368500	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
var k
input i
input j
var t0
t0 = (i == j)
ifz t0 goto L3
  succ: B3 B2 

[B2]
output L1
goto L4
  succ: B4 

[B3]
label L3
output L2
  succ: B4 

[B4]
label L4
var t1
t1 = i + j
k = t1
output k
output L5
end
  succ: 
