
# tac list

0x5e535a162260	label main
0x5e535a1622a0	begin
0x5e535a1617f0	var i
0x5e535a1618b0	var j
0x5e535a161910	input j
0x5e535a161a20	i = 0
0x5e535a161f00	label L1
0x5e535a161b60	var t0
0x5e535a161ba0	t0 = (i < j)
0x5e535a1620c0	ifz t0 goto L3
0x5e535a161e40	output i
0x5e535a161fc0	label L2
0x5e535a161d60	var t1
0x5e535a161da0	t1 = i + 1
0x5e535a161de0	i = t1
0x5e535a162100	goto L1
0x5e535a162080	label L3
0x5e535a1621c0	output L4
0x5e535a1622e0	end

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
