
# tac list

0x5c49031c1ce0	label main
0x5c49031c1d20	begin
0x5c49031c07f0	var i
0x5c49031c08b0	var j
0x5c49031c0910	input i
0x5c49031c1a80	var t5
0x5c49031c1ac0	t5 = (i != 1)
0x5c49031c1b00	ifz t5 goto L2
0x5c49031c1960	var t4
0x5c49031c19a0	t4 = (i != 2)
0x5c49031c19e0	ifz t4 goto L3
0x5c49031c1840	var t3
0x5c49031c1880	t3 = (i != 3)
0x5c49031c18c0	ifz t3 goto L4
0x5c49031c1b40	goto L6
0x5c49031c15a0	label L4
0x5c49031c13c0	var t2
0x5c49031c1400	t2 = i + 3
0x5c49031c1440	j = t2
0x5c49031c14a0	output j
0x5c49031c14e0	goto L1
0x5c49031c11a0	label L3
0x5c49031c0fc0	var t1
0x5c49031c1000	t1 = i + 2
0x5c49031c1040	j = t1
0x5c49031c10a0	output j
0x5c49031c10e0	goto L1
0x5c49031c0da0	label L2
0x5c49031c0bc0	var t0
0x5c49031c0c00	t0 = i + 1
0x5c49031c0c40	j = t0
0x5c49031c0ca0	output j
0x5c49031c0ce0	goto L1
0x5c49031c17a0	label L6
0x5c49031c16a0	output L5
0x5c49031c16e0	goto L1
0x5c49031c1b80	label L1
0x5c49031c1c40	output L7
0x5c49031c1d60	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
input i
var t5
t5 = (i != 1)
ifz t5 goto L2
  succ: B7 B2 

[B2]
var t4
t4 = (i != 2)
ifz t4 goto L3
  succ: B6 B3 

[B3]
var t3
t3 = (i != 3)
ifz t3 goto L4
  succ: B5 B4 

[B4]
goto L6
  succ: B8 

[B5]
label L4
var t2
t2 = i + 3
j = t2
output j
goto L1
  succ: B9 

[B6]
label L3
var t1
t1 = i + 2
j = t1
output j
goto L1
  succ: B9 

[B7]
label L2
var t0
t0 = i + 1
j = t0
output j
goto L1
  succ: B9 

[B8]
label L6
output L5
goto L1
  succ: B9 

[B9]
label L1
output L7
end
  succ: 
