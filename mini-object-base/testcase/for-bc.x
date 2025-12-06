
# tac list

0x58a02f1e14b0	label main
0x58a02f1e14f0	begin
0x58a02f1df830	var i
0x58a02f1df910	var j
0x58a02f1df970	input j
0x58a02f1dfaa0	i = 0
0x58a02f1e05d0	label L1
0x58a02f1dfc00	var t0
0x58a02f1dfc40	t0 = (i < j)
0x58a02f1e0690	ifz t0 goto L3
0x58a02f1e0280	var t2
0x58a02f1e02c0	t2 = (i > 10)
0x58a02f1e0500	ifz t2 goto L5
0x58a02f1e03a0	output L4
0x58a02f1e03e0	goto L3
0x58a02f1e04c0	label L5
0x58a02f1e0590	output i
0x58a02f1e0610	label L2
0x58a02f1dfe40	var t1
0x58a02f1dfe80	t1 = i + 1
0x58a02f1dfec0	i = t1
0x58a02f1e06d0	goto L1
0x58a02f1e0650	label L3
0x58a02f1e07b0	output L6
0x58a02f1e0860	i = 0
0x58a02f1e1290	label L7
0x58a02f1e09c0	var t3
0x58a02f1e0a00	t3 = (i < j)
0x58a02f1e1350	ifz t3 goto L9
0x58a02f1e0f40	var t5
0x58a02f1e0f80	t5 = (i == 10)
0x58a02f1e11c0	ifz t5 goto L11
0x58a02f1e1060	output L10
0x58a02f1e10a0	goto L8
0x58a02f1e1180	label L11
0x58a02f1e1250	output i
0x58a02f1e12d0	label L8
0x58a02f1e0b80	var t4
0x58a02f1e0bc0	t4 = i + 1
0x58a02f1e0c00	i = t4
0x58a02f1e1390	goto L7
0x58a02f1e1310	label L9
0x58a02f1e13f0	output L6
0x58a02f1e1530	end

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
  succ: B6 B3 

[B3]
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
output i
label L2
var t1
t1 = i + 1
i = t1
goto L1
  succ: B2 

[B6]
label L3
output L6
i = 0
  succ: B7 

[B7]
label L7
var t3
t3 = (i < j)
ifz t3 goto L9
  succ: B12 B8 

[B8]
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
output i
  succ: B11 

[B11]
label L8
var t4
t4 = i + 1
i = t4
goto L7
  succ: B7 

[B12]
label L9
output L6
end
  succ: 
