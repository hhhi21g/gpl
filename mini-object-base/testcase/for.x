
# tac list

0x5d2dc3f50410	label main
0x5d2dc3f50450	begin
0x5d2dc3f4f830	var i
0x5d2dc3f4f910	var j
0x5d2dc3f4f970	input j
0x5d2dc3f4faa0	i = 0
0x5d2dc3f50170	label L1
0x5d2dc3f4fc00	var t0
0x5d2dc3f4fc40	t0 = (i < j)
0x5d2dc3f50230	ifz t0 goto L3
0x5d2dc3f50130	output i
0x5d2dc3f501b0	label L2
0x5d2dc3f4fe40	var t1
0x5d2dc3f4fe80	t1 = i + 1
0x5d2dc3f4fec0	i = t1
0x5d2dc3f50270	goto L1
0x5d2dc3f501f0	label L3
0x5d2dc3f50350	output L4
0x5d2dc3f50490	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
input j
i = 0
  succ: B2 

[B2]
label L1
var t0
t0 = (i < j)
ifz t0 goto L3
  succ: B4 B3 

[B3]
output i
label L2
var t1
t1 = i + 1
i = t1
goto L1
  succ: B2 

[B4]
label L3
output L4
end
  succ: 
