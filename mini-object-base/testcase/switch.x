
# tac list

0x62d75d844ff0	label main
0x62d75d845030	begin
0x62d75d843830	var i
0x62d75d843910	var j
0x62d75d843970	input i
0x62d75d844d50	var t5
0x62d75d844d90	t5 = (i != 1)
0x62d75d844dd0	ifz t5 goto L2
0x62d75d844c10	var t4
0x62d75d844c50	t4 = (i != 2)
0x62d75d844c90	ifz t4 goto L3
0x62d75d844ad0	var t3
0x62d75d844b10	t3 = (i != 3)
0x62d75d844b50	ifz t3 goto L4
0x62d75d844e10	goto L6
0x62d75d8447d0	label L4
0x62d75d8445a0	var t2
0x62d75d8445e0	t2 = i + 3
0x62d75d844620	j = t2
0x62d75d8446b0	output j
0x62d75d8446f0	goto L1
0x62d75d844340	label L3
0x62d75d844110	var t1
0x62d75d844150	t1 = i + 2
0x62d75d844190	j = t1
0x62d75d844220	output j
0x62d75d844260	goto L1
0x62d75d843eb0	label L2
0x62d75d843c80	var t0
0x62d75d843cc0	t0 = i + 1
0x62d75d843d00	j = t0
0x62d75d843d90	output j
0x62d75d843dd0	goto L1
0x62d75d844a10	label L6
0x62d75d8448f0	output L5
0x62d75d844930	goto L1
0x62d75d844e50	label L1
0x62d75d844f30	output L7
0x62d75d845070	end

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
