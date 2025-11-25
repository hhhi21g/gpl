
# tac list

0x6529edb07820	label main
0x6529edb07860	begin
0x6529edb06830	var i
0x6529edb06910	var j
0x6529edb06a40	i = 0
0x6529edb06aa0	input j
0x6529edb07580	label L1
0x6529edb06c00	var t0
0x6529edb06c40	t0 = (i < j)
0x6529edb07640	ifz t0 goto L3
0x6529edb06eb0	output i
0x6529edb070b0	var t1
0x6529edb070f0	t1 = i + 1
0x6529edb07130	i = t1
0x6529edb075c0	label L2
0x6529edb07680	goto L1
0x6529edb07600	label L3
0x6529edb07760	output L4
0x6529edb078a0	end

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
