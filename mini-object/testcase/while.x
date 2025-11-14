
# tac list

0x55fe0910d350	label main
0x55fe0910d390	begin
0x55fe0910c810	var i
0x55fe0910c8e0	var j
0x55fe0910ca00	i = 0
0x55fe0910ca60	input j
0x55fe0910d0d0	label L1
0x55fe0910cbb0	var t0
0x55fe0910cbf0	t0 = (i < j)
0x55fe0910d190	ifz t0 goto L3
0x55fe0910ce30	output i
0x55fe0910d010	var t1
0x55fe0910d050	t1 = i + 1
0x55fe0910d090	i = t1
0x55fe0910d110	label L2
0x55fe0910d1d0	goto L1
0x55fe0910d150	label L3
0x55fe0910d2a0	output L4
0x55fe0910d3d0	end

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
