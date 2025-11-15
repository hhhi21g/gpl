
# tac list

0x5e80d4215810	label main
0x5e80d4215850	begin
0x5e80d4213830	var i
0x5e80d4213910	var j
0x5e80d4213a40	i = 0
0x5e80d4213aa0	input j
0x5e80d42149e0	label L1
0x5e80d4214010	var t0
0x5e80d4214050	t0 = (i < j)
0x5e80d4214aa0	ifz t0 goto L3
0x5e80d42142c0	output i
0x5e80d42144c0	var t1
0x5e80d4214500	t1 = i + 1
0x5e80d4214540	i = t1
0x5e80d4214720	var t2
0x5e80d4214760	t2 = (i > 10)
0x5e80d42149a0	ifz t2 goto L5
0x5e80d4214840	output L4
0x5e80d4214880	goto L3
0x5e80d4214960	label L5
0x5e80d4214a20	label L2
0x5e80d4214ae0	goto L1
0x5e80d4214a60	label L3
0x5e80d4214bc0	output L6
0x5e80d42155f0	label L7
0x5e80d4214d20	var t3
0x5e80d4214d60	t3 = (i < j)
0x5e80d42156b0	ifz t3 goto L9
0x5e80d4214fd0	output i
0x5e80d4215150	var t4
0x5e80d4215190	t4 = i + 1
0x5e80d42151d0	i = t4
0x5e80d4215330	var t5
0x5e80d4215370	t5 = (i == 10)
0x5e80d42155b0	ifz t5 goto L11
0x5e80d4215450	output L10
0x5e80d4215490	goto L8
0x5e80d4215570	label L11
0x5e80d4215630	label L8
0x5e80d42156f0	goto L7
0x5e80d4215670	label L9
0x5e80d4215750	output L6
0x5e80d4215890	end

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
