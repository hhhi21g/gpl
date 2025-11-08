
# tac list

0x5c336dfb20a0	label main
0x5c336dfb20e0	begin
0x5c336dfb07f0	var i
0x5c336dfb08b0	var j
0x5c336dfb09c0	i = 0
0x5c336dfb0a20	input j
0x5c336dfb13e0	label L1
0x5c336dfb0b60	var t0
0x5c336dfb0ba0	t0 = (i < j)
0x5c336dfb14a0	ifz t0 goto L3
0x5c336dfb0d80	output i
0x5c336dfb0f40	var t1
0x5c336dfb0f80	t1 = i + 1
0x5c336dfb0fc0	i = t1
0x5c336dfb1160	var t2
0x5c336dfb11a0	t2 = (i > 10)
0x5c336dfb13a0	ifz t2 goto L5
0x5c336dfb1260	output L4
0x5c336dfb12a0	goto L3
0x5c336dfb1360	label L5
0x5c336dfb1420	label L2
0x5c336dfb14e0	goto L1
0x5c336dfb1460	label L3
0x5c336dfb15a0	output L6
0x5c336dfb1ea0	label L7
0x5c336dfb16e0	var t3
0x5c336dfb1720	t3 = (i < j)
0x5c336dfb1f60	ifz t3 goto L9
0x5c336dfb1900	output i
0x5c336dfb1a60	var t4
0x5c336dfb1aa0	t4 = i + 1
0x5c336dfb1ae0	i = t4
0x5c336dfb1c20	var t5
0x5c336dfb1c60	t5 = (i == 10)
0x5c336dfb1e60	ifz t5 goto L11
0x5c336dfb1d20	output L10
0x5c336dfb1d60	goto L8
0x5c336dfb1e20	label L11
0x5c336dfb1ee0	label L8
0x5c336dfb1fa0	goto L7
0x5c336dfb1f20	label L9
0x5c336dfb2000	output L6
0x5c336dfb2120	end

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
  succ: B6 B3 

[B3]
output i
var t1
t1 = i + 1
i = t1
var t2
t2 = (i > 10)
ifz t2 goto L5
  succ: B5 B4 

[B4]
output L4
goto L3
  succ: B6 

[B5]
label L5
label L2
goto L1
  succ: B2 

[B6]
label L3
output L6
  succ: B7 

[B7]
label L7
var t3
t3 = (i < j)
ifz t3 goto L9
  succ: B12 B8 

[B8]
output i
var t4
t4 = i + 1
i = t4
var t5
t5 = (i == 10)
ifz t5 goto L11
  succ: B10 B9 

[B9]
output L10
goto L8
  succ: B11 

[B10]
label L11
  succ: B11 

[B11]
label L8
goto L7
  succ: B7 

[B12]
label L9
output L6
end
  succ: 
