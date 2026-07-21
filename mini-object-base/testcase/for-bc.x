
# tac list

0x590148b5b4b0	label main
0x590148b5b4f0	begin
0x590148b59830	var i
0x590148b59910	var j
0x590148b59970	input j
0x590148b59aa0	i = 0
0x590148b5a5d0	label L1
0x590148b59c00	var t0
0x590148b59c40	t0 = (i < j)
0x590148b5a690	ifz t0 goto L3
0x590148b5a280	var t2
0x590148b5a2c0	t2 = (i > 10)
0x590148b5a500	ifz t2 goto L5
0x590148b5a3a0	output L4
0x590148b5a3e0	goto L3
0x590148b5a4c0	label L5
0x590148b5a590	output i
0x590148b5a610	label L2
0x590148b59e40	var t1
0x590148b59e80	t1 = i + 1
0x590148b59ec0	i = t1
0x590148b5a6d0	goto L1
0x590148b5a650	label L3
0x590148b5a7b0	output L6
0x590148b5a860	i = 0
0x590148b5b290	label L7
0x590148b5a9c0	var t3
0x590148b5aa00	t3 = (i < j)
0x590148b5b350	ifz t3 goto L9
0x590148b5af40	var t5
0x590148b5af80	t5 = (i == 10)
0x590148b5b1c0	ifz t5 goto L11
0x590148b5b060	output L10
0x590148b5b0a0	goto L8
0x590148b5b180	label L11
0x590148b5b250	output i
0x590148b5b2d0	label L8
0x590148b5ab80	var t4
0x590148b5abc0	t4 = i + 1
0x590148b5ac00	i = t4
0x590148b5b390	goto L7
0x590148b5b310	label L9
0x590148b5b3f0	output L6
0x590148b5b530	end

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
