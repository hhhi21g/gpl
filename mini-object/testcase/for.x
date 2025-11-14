
# tac list

0x56539c777820	label main
0x56539c777860	begin
0x56539c776830	var i
0x56539c776910	var j
0x56539c776970	input j
0x56539c776aa0	i = 0
0x56539c777580	label L1
0x56539c777010	var t0
0x56539c777050	t0 = (i < j)
0x56539c777640	ifz t0 goto L3
0x56539c777540	output i
0x56539c7775c0	label L2
0x56539c777250	var t1
0x56539c777290	t1 = i + 1
0x56539c7772d0	i = t1
0x56539c777680	goto L1
0x56539c777600	label L3
0x56539c777760	output L4
0x56539c7778a0	end

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
