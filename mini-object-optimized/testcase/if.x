
# tac list

0x5ef48cf6a480	label main
0x5ef48cf6a4c0	begin
0x5ef48cf69830	var i
0x5ef48cf69910	var j
0x5ef48cf699f0	var k
0x5ef48cf69a50	input i
0x5ef48cf69ab0	input j
0x5ef48cf69c10	var t0
0x5ef48cf69c50	t0 = (i == j)
0x5ef48cf6a010	ifz t0 goto L3
0x5ef48cf69d30	output L1
0x5ef48cf6a050	goto L4
0x5ef48cf69ef0	label L3
0x5ef48cf69e10	output L2
0x5ef48cf69fd0	label L4
0x5ef48cf6a1d0	var t1
0x5ef48cf6a210	t1 = i + j
0x5ef48cf6a250	k = t1
0x5ef48cf6a2e0	output k
0x5ef48cf6a3c0	output L5
0x5ef48cf6a500	end

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
