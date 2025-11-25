
# tac list

0x5c3e03413480	label main
0x5c3e034134c0	begin
0x5c3e03412830	var i
0x5c3e03412910	var j
0x5c3e034129f0	var k
0x5c3e03412a50	input i
0x5c3e03412ab0	input j
0x5c3e03412c10	var t0
0x5c3e03412c50	t0 = (i == j)
0x5c3e03413010	ifz t0 goto L3
0x5c3e03412d30	output L1
0x5c3e03413050	goto L4
0x5c3e03412ef0	label L3
0x5c3e03412e10	output L2
0x5c3e03412fd0	label L4
0x5c3e034131d0	var t1
0x5c3e03413210	t1 = i + j
0x5c3e03413250	k = t1
0x5c3e034132e0	output k
0x5c3e034133c0	output L5
0x5c3e03413500	end

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
