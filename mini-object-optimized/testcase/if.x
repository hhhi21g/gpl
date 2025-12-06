
# tac list

0x62208e33d480	label main
0x62208e33d4c0	begin
0x62208e33c830	var i
0x62208e33c910	var j
0x62208e33c9f0	var k
0x62208e33ca50	input i
0x62208e33cab0	input j
0x62208e33cc10	var t0
0x62208e33cc50	t0 = (i == j)
0x62208e33d010	ifz t0 goto L3
0x62208e33cd30	output L1
0x62208e33d050	goto L4
0x62208e33cef0	label L3
0x62208e33ce10	output L2
0x62208e33cfd0	label L4
0x62208e33d1d0	var t1
0x62208e33d210	t1 = i + j
0x62208e33d250	k = t1
0x62208e33d2e0	output k
0x62208e33d3c0	output L5
0x62208e33d500	end

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
