
# tac list

0x5978f7d0e820	label main
0x5978f7d0e860	begin
0x5978f7d0d830	var i
0x5978f7d0d910	var j
0x5978f7d0d970	input j
0x5978f7d0daa0	i = 0
0x5978f7d0e580	label L1
0x5978f7d0e010	var t0
0x5978f7d0e050	t0 = (i < j)
0x5978f7d0e640	ifz t0 goto L3
0x5978f7d0e540	output i
0x5978f7d0e5c0	label L2
0x5978f7d0e250	var t1
0x5978f7d0e290	t1 = i + 1
0x5978f7d0e2d0	i = t1
0x5978f7d0e680	goto L1
0x5978f7d0e600	label L3
0x5978f7d0e760	output L4
0x5978f7d0e8a0	end

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
