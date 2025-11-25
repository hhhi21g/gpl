
# tac list

0x62f7af5ac810	label main
0x62f7af5ac850	begin
0x62f7af5aa830	var i
0x62f7af5aa910	var j
0x62f7af5aaa40	i = 0
0x62f7af5aaaa0	input j
0x62f7af5ab9e0	label L1
0x62f7af5aac00	var t0
0x62f7af5aac40	t0 = (i < j)
0x62f7af5abaa0	ifz t0 goto L3
0x62f7af5aaeb0	output i
0x62f7af5ab0b0	var t1
0x62f7af5ab0f0	t1 = i + 1
0x62f7af5ab130	i = t1
0x62f7af5ab310	var t2
0x62f7af5ab350	t2 = (i > 10)
0x62f7af5ab590	ifz t2 goto L5
0x62f7af5ab430	output L4
0x62f7af5ab470	goto L3
0x62f7af5ab550	label L5
0x62f7af5aba20	label L2
0x62f7af5abae0	goto L1
0x62f7af5aba60	label L3
0x62f7af5abbc0	output L6
0x62f7af5ac5f0	label L7
0x62f7af5abd20	var t3
0x62f7af5abd60	t3 = (i < j)
0x62f7af5ac6b0	ifz t3 goto L9
0x62f7af5abfd0	output i
0x62f7af5ac150	var t4
0x62f7af5ac190	t4 = i + 1
0x62f7af5ac1d0	i = t4
0x62f7af5ac330	var t5
0x62f7af5ac370	t5 = (i == 10)
0x62f7af5ac5b0	ifz t5 goto L11
0x62f7af5ac450	output L10
0x62f7af5ac490	goto L8
0x62f7af5ac570	label L11
0x62f7af5ac630	label L8
0x62f7af5ac6f0	goto L7
0x62f7af5ac670	label L9
0x62f7af5ac750	output L6
0x62f7af5ac890	end

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
