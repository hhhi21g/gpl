
# tac list

0x61ed596e8ce0	label main
0x61ed596e8d20	begin
0x61ed596e77f0	var i
0x61ed596e78b0	var j
0x61ed596e7910	input i
0x61ed596e8a80	var t5
0x61ed596e8ac0	t5 = (i != 1)
0x61ed596e8b00	ifz t5 goto L2
0x61ed596e8960	var t4
0x61ed596e89a0	t4 = (i != 2)
0x61ed596e89e0	ifz t4 goto L3
0x61ed596e8840	var t3
0x61ed596e8880	t3 = (i != 3)
0x61ed596e88c0	ifz t3 goto L4
0x61ed596e8b40	goto L6
0x61ed596e85a0	label L4
0x61ed596e83c0	var t2
0x61ed596e8400	t2 = i + 3
0x61ed596e8440	j = t2
0x61ed596e84a0	output j
0x61ed596e84e0	goto L1
0x61ed596e81a0	label L3
0x61ed596e7fc0	var t1
0x61ed596e8000	t1 = i + 2
0x61ed596e8040	j = t1
0x61ed596e80a0	output j
0x61ed596e80e0	goto L1
0x61ed596e7da0	label L2
0x61ed596e7bc0	var t0
0x61ed596e7c00	t0 = i + 1
0x61ed596e7c40	j = t0
0x61ed596e7ca0	output j
0x61ed596e7ce0	goto L1
0x61ed596e87a0	label L6
0x61ed596e86a0	output L5
0x61ed596e86e0	goto L1
0x61ed596e8b80	label L1
0x61ed596e8c40	output L7
0x61ed596e8d60	end

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
