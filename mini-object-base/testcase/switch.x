
# tac list

0x6269e78acff0	label main
0x6269e78ad030	begin
0x6269e78ab830	var i
0x6269e78ab910	var j
0x6269e78ab970	input i
0x6269e78acd50	var t5
0x6269e78acd90	t5 = (i != 1)
0x6269e78acdd0	ifz t5 goto L2
0x6269e78acc10	var t4
0x6269e78acc50	t4 = (i != 2)
0x6269e78acc90	ifz t4 goto L3
0x6269e78acad0	var t3
0x6269e78acb10	t3 = (i != 3)
0x6269e78acb50	ifz t3 goto L4
0x6269e78ace10	goto L6
0x6269e78ac7d0	label L4
0x6269e78ac5a0	var t2
0x6269e78ac5e0	t2 = i + 3
0x6269e78ac620	j = t2
0x6269e78ac6b0	output j
0x6269e78ac6f0	goto L1
0x6269e78ac340	label L3
0x6269e78ac110	var t1
0x6269e78ac150	t1 = i + 2
0x6269e78ac190	j = t1
0x6269e78ac220	output j
0x6269e78ac260	goto L1
0x6269e78abeb0	label L2
0x6269e78abc80	var t0
0x6269e78abcc0	t0 = i + 1
0x6269e78abd00	j = t0
0x6269e78abd90	output j
0x6269e78abdd0	goto L1
0x6269e78aca10	label L6
0x6269e78ac8f0	output L5
0x6269e78ac930	goto L1
0x6269e78ace50	label L1
0x6269e78acf30	output L7
0x6269e78ad070	end

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
