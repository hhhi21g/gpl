
# tac list

0x556aa520c400	label main
0x556aa520c440	begin
0x556aa520a830	var i
0x556aa520a910	var j
0x556aa520a970	input i
0x556aa520c160	var t5
0x556aa520c1a0	t5 = (i != 1)
0x556aa520c1e0	ifz t5 goto L2
0x556aa520c020	var t4
0x556aa520c060	t4 = (i != 2)
0x556aa520c0a0	ifz t4 goto L3
0x556aa520bee0	var t3
0x556aa520bf20	t3 = (i != 3)
0x556aa520bf60	ifz t3 goto L4
0x556aa520c220	goto L6
0x556aa520bbe0	label L4
0x556aa520b9b0	var t2
0x556aa520b9f0	t2 = i + 3
0x556aa520ba30	j = t2
0x556aa520bac0	output j
0x556aa520bb00	goto L1
0x556aa520b750	label L3
0x556aa520b520	var t1
0x556aa520b560	t1 = i + 2
0x556aa520b5a0	j = t1
0x556aa520b630	output j
0x556aa520b670	goto L1
0x556aa520b2c0	label L2
0x556aa520b090	var t0
0x556aa520b0d0	t0 = i + 1
0x556aa520b110	j = t0
0x556aa520b1a0	output j
0x556aa520b1e0	goto L1
0x556aa520be20	label L6
0x556aa520bd00	output L5
0x556aa520bd40	goto L1
0x556aa520c260	label L1
0x556aa520c340	output L7
0x556aa520c480	end

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
