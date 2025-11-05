
# tac list

0x55cf0ab441a0	label main
0x55cf0ab441e0	begin
0x55cf0ab437f0	var i
0x55cf0ab438b0	var j
0x55cf0ab439c0	i = 0
0x55cf0ab43a20	input j
0x55cf0ab43f00	label L1
0x55cf0ab43b60	var t0
0x55cf0ab43ba0	t0 = (i < j)
0x55cf0ab44040	ifz t0 goto L2
0x55cf0ab43c00	output i
0x55cf0ab43dc0	var t1
0x55cf0ab43e00	t1 = i + 1
0x55cf0ab43e40	i = t1
0x55cf0ab43f40	goto L1
0x55cf0ab44000	label L2
0x55cf0ab44100	output L3
0x55cf0ab44220	end

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
