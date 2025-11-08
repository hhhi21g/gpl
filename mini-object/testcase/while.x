
# tac list

0x62c5c12a61a0	label main
0x62c5c12a61e0	begin
0x62c5c12a57f0	var i
0x62c5c12a58b0	var j
0x62c5c12a59c0	i = 0
0x62c5c12a5a20	input j
0x62c5c12a5f00	label L1
0x62c5c12a5b60	var t0
0x62c5c12a5ba0	t0 = (i < j)
0x62c5c12a6040	ifz t0 goto L2
0x62c5c12a5c00	output i
0x62c5c12a5dc0	var t1
0x62c5c12a5e00	t1 = i + 1
0x62c5c12a5e40	i = t1
0x62c5c12a5f40	goto L1
0x62c5c12a6000	label L2
0x62c5c12a6100	output L3
0x62c5c12a6220	end

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
ifz t0 goto L2
  succ: B4 B3 

[B3]
output i
var t1
t1 = i + 1
i = t1
goto L1
  succ: B2 

[B4]
label L2
output L3
end
  succ: 
