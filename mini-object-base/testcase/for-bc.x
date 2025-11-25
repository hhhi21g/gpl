
# tac list

0x5aa8da0a14b0	label main
0x5aa8da0a14f0	begin
0x5aa8da09f830	var i
0x5aa8da09f910	var j
0x5aa8da09f970	input j
0x5aa8da09faa0	i = 0
0x5aa8da0a05d0	label L1
0x5aa8da09fc00	var t0
0x5aa8da09fc40	t0 = (i < j)
0x5aa8da0a0690	ifz t0 goto L3
0x5aa8da0a0280	var t2
0x5aa8da0a02c0	t2 = (i > 10)
0x5aa8da0a0500	ifz t2 goto L5
0x5aa8da0a03a0	output L4
0x5aa8da0a03e0	goto L3
0x5aa8da0a04c0	label L5
0x5aa8da0a0590	output i
0x5aa8da0a0610	label L2
0x5aa8da09fe40	var t1
0x5aa8da09fe80	t1 = i + 1
0x5aa8da09fec0	i = t1
0x5aa8da0a06d0	goto L1
0x5aa8da0a0650	label L3
0x5aa8da0a07b0	output L6
0x5aa8da0a0860	i = 0
0x5aa8da0a1290	label L7
0x5aa8da0a09c0	var t3
0x5aa8da0a0a00	t3 = (i < j)
0x5aa8da0a1350	ifz t3 goto L9
0x5aa8da0a0f40	var t5
0x5aa8da0a0f80	t5 = (i == 10)
0x5aa8da0a11c0	ifz t5 goto L11
0x5aa8da0a1060	output L10
0x5aa8da0a10a0	goto L8
0x5aa8da0a1180	label L11
0x5aa8da0a1250	output i
0x5aa8da0a12d0	label L8
0x5aa8da0a0b80	var t4
0x5aa8da0a0bc0	t4 = i + 1
0x5aa8da0a0c00	i = t4
0x5aa8da0a1390	goto L7
0x5aa8da0a1310	label L9
0x5aa8da0a13f0	output L6
0x5aa8da0a1530	end

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
