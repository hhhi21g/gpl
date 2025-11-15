
# tac list

0x6547bafa9820	label main
0x6547bafa9860	begin
0x6547bafa8830	var i
0x6547bafa8910	var j
0x6547bafa8970	input j
0x6547bafa8aa0	i = 0
0x6547bafa9580	label L1
0x6547bafa9010	var t0
0x6547bafa9050	t0 = (i < j)
0x6547bafa9640	ifz t0 goto L3
0x6547bafa9540	output i
0x6547bafa95c0	label L2
0x6547bafa9250	var t1
0x6547bafa9290	t1 = i + 1
0x6547bafa92d0	i = t1
0x6547bafa9680	goto L1
0x6547bafa9600	label L3
0x6547bafa9760	output L4
0x6547bafa98a0	end

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
