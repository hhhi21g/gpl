
# tac list

0x5d58d6eb0410	label main
0x5d58d6eb0450	begin
0x5d58d6eaf830	var i
0x5d58d6eaf910	var j
0x5d58d6eaf970	input j
0x5d58d6eafaa0	i = 0
0x5d58d6eb0170	label L1
0x5d58d6eafc00	var t0
0x5d58d6eafc40	t0 = (i < j)
0x5d58d6eb0230	ifz t0 goto L3
0x5d58d6eb0130	output i
0x5d58d6eb01b0	label L2
0x5d58d6eafe40	var t1
0x5d58d6eafe80	t1 = i + 1
0x5d58d6eafec0	i = t1
0x5d58d6eb0270	goto L1
0x5d58d6eb01f0	label L3
0x5d58d6eb0350	output L4
0x5d58d6eb0490	end

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
