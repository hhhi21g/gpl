
# tac list

0x59d8a2fdd400	label main
0x59d8a2fdd440	begin
0x59d8a2fdb830	var i
0x59d8a2fdb910	var j
0x59d8a2fdba40	i = 0
0x59d8a2fdbaa0	input j
0x59d8a2fdc5d0	label L1
0x59d8a2fdbc00	var t0
0x59d8a2fdbc40	t0 = (i < j)
0x59d8a2fdc690	ifz t0 goto L3
0x59d8a2fdbeb0	output i
0x59d8a2fdc0b0	var t1
0x59d8a2fdc0f0	t1 = i + 1
0x59d8a2fdc130	i = t1
0x59d8a2fdc310	var t2
0x59d8a2fdc350	t2 = (i > 10)
0x59d8a2fdc590	ifz t2 goto L5
0x59d8a2fdc430	output L4
0x59d8a2fdc470	goto L3
0x59d8a2fdc550	label L5
0x59d8a2fdc610	label L2
0x59d8a2fdc6d0	goto L1
0x59d8a2fdc650	label L3
0x59d8a2fdc7b0	output L6
0x59d8a2fdd1e0	label L7
0x59d8a2fdc910	var t3
0x59d8a2fdc950	t3 = (i < j)
0x59d8a2fdd2a0	ifz t3 goto L9
0x59d8a2fdcbc0	output i
0x59d8a2fdcd40	var t4
0x59d8a2fdcd80	t4 = i + 1
0x59d8a2fdcdc0	i = t4
0x59d8a2fdcf20	var t5
0x59d8a2fdcf60	t5 = (i == 10)
0x59d8a2fdd1a0	ifz t5 goto L11
0x59d8a2fdd040	output L10
0x59d8a2fdd080	goto L8
0x59d8a2fdd160	label L11
0x59d8a2fdd220	label L8
0x59d8a2fdd2e0	goto L7
0x59d8a2fdd260	label L9
0x59d8a2fdd340	output L6
0x59d8a2fdd480	end

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
