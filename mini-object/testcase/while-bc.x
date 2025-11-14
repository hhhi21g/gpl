
# tac list

0x5e717608a280	label main
0x5e717608a2c0	begin
0x5e7176088810	var i
0x5e71760888e0	var j
0x5e7176088a00	i = 0
0x5e7176088a60	input j
0x5e71760894f0	label L1
0x5e7176088bb0	var t0
0x5e7176088bf0	t0 = (i < j)
0x5e71760895b0	ifz t0 goto L3
0x5e7176088e30	output i
0x5e7176089010	var t1
0x5e7176089050	t1 = i + 1
0x5e7176089090	i = t1
0x5e7176089250	var t2
0x5e7176089290	t2 = (i > 10)
0x5e71760894b0	ifz t2 goto L5
0x5e7176089360	output L4
0x5e71760893a0	goto L3
0x5e7176089470	label L5
0x5e7176089530	label L2
0x5e71760895f0	goto L1
0x5e7176089570	label L3
0x5e71760896c0	output L6
0x5e717608a070	label L7
0x5e7176089810	var t3
0x5e7176089850	t3 = (i < j)
0x5e717608a130	ifz t3 goto L9
0x5e7176089a90	output i
0x5e7176089c00	var t4
0x5e7176089c40	t4 = i + 1
0x5e7176089c80	i = t4
0x5e7176089dd0	var t5
0x5e7176089e10	t5 = (i == 10)
0x5e717608a030	ifz t5 goto L11
0x5e7176089ee0	output L10
0x5e7176089f20	goto L8
0x5e7176089ff0	label L11
0x5e717608a0b0	label L8
0x5e717608a170	goto L7
0x5e717608a0f0	label L9
0x5e717608a1d0	output L6
0x5e717608a300	end

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
