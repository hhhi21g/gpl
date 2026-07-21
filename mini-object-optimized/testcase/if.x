
# tac list

0x62df02e32480	label main
0x62df02e324c0	begin
0x62df02e31830	var i
0x62df02e31910	var j
0x62df02e319f0	var k
0x62df02e31a50	input i
0x62df02e31ab0	input j
0x62df02e31c10	var t0
0x62df02e31c50	t0 = (i == j)
0x62df02e32010	ifz t0 goto L3
0x62df02e31d30	output L1
0x62df02e32050	goto L4
0x62df02e31ef0	label L3
0x62df02e31e10	output L2
0x62df02e31fd0	label L4
0x62df02e321d0	var t1
0x62df02e32210	t1 = i + j
0x62df02e32250	k = t1
0x62df02e322e0	output k
0x62df02e323c0	output L5
0x62df02e32500	end

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
