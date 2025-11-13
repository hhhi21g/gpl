
# tac list

0x5bde852c37d0	label main
0x5bde852c3810	begin
0x5bde852c2810	var i
0x5bde852c28e0	var j
0x5bde852c29b0	var k
0x5bde852c2a10	input i
0x5bde852c2a70	input j
0x5bde852c2fd0	var t0
0x5bde852c3010	t0 = (i == j)
0x5bde852c3390	ifz t0 goto L3
0x5bde852c30e0	output L1
0x5bde852c33d0	goto L4
0x5bde852c3280	label L3
0x5bde852c31b0	output L2
0x5bde852c3350	label L4
0x5bde852c3540	var t1
0x5bde852c3580	t1 = i + j
0x5bde852c35c0	k = t1
0x5bde852c3650	output k
0x5bde852c3720	output L5
0x5bde852c3850	end

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
