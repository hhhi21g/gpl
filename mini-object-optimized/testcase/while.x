
# tac list

0x62844dd3f820	label main
0x62844dd3f860	begin
0x62844dd3e830	var i
0x62844dd3e910	var j
0x62844dd3ea40	i = 0
0x62844dd3eaa0	input j
0x62844dd3f580	label L1
0x62844dd3f010	var t0
0x62844dd3f050	t0 = (i < j)
0x62844dd3f640	ifz t0 goto L3
0x62844dd3f2c0	output i
0x62844dd3f4c0	var t1
0x62844dd3f500	t1 = i + 1
0x62844dd3f540	i = t1
0x62844dd3f5c0	label L2
0x62844dd3f680	goto L1
0x62844dd3f600	label L3
0x62844dd3f760	output L4
0x62844dd3f8a0	end

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
