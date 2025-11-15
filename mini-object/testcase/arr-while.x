
# tac list

0x5853ad1a2ac0	label main
0x5853ad1a2b00	begin
0x5853ad1a0830	var i
0x5853ad1a0910	var j
0x5853ad1a0b60	vararray arr1[1D]
0x5853ad1a0bc0	input i
0x5853ad1a0cf0	j = 0
0x5853ad1a1ba0	label L1
0x5853ad1a1260	var t0
0x5853ad1a12a0	t0 = (j < 10)
0x5853ad1a1c60	ifz t0 goto L3
0x5853ad1a1630	var t1
0x5853ad1a16f0	t1 = j * 4
0x5853ad1a1760	arr1[t1] = i
0x5853ad1a18e0	var t2
0x5853ad1a1920	t2 = i + 1
0x5853ad1a1960	i = t2
0x5853ad1a1ae0	var t3
0x5853ad1a1b20	t3 = j + 1
0x5853ad1a1b60	j = t3
0x5853ad1a1be0	label L2
0x5853ad1a1ca0	goto L1
0x5853ad1a1c20	label L3
0x5853ad1a1ef0	ifz 0 goto L5
0x5853ad1a1dd0	output L4
0x5853ad1a1eb0	label L5
0x5853ad1a28a0	label L6
0x5853ad1a2050	var t4
0x5853ad1a2090	t4 = (j > 0)
0x5853ad1a2960	ifz t4 goto L8
0x5853ad1a23f0	var t5
0x5853ad1a2430	t5 = j - 1
0x5853ad1a2470	j = t5
0x5853ad1a25f0	var t6
0x5853ad1a2630	t6 = j * 4
0x5853ad1a2720	var t7
0x5853ad1a2760	t7 = arr1[t6]
0x5853ad1a27d0	i = t7
0x5853ad1a2860	output i
0x5853ad1a28e0	label L7
0x5853ad1a29a0	goto L6
0x5853ad1a2920	label L8
0x5853ad1a2a00	output L4
0x5853ad1a2b40	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
vararray arr1[1D]
input i
j = 0
  succ: B2 

[B2]
label L1
var t0
t0 = (j < 10)
ifz t0 goto L3
  succ: B4 B3 

[B3]
var t1
t1 = j * 4
arr1[t1] = i
var t2
t2 = i + 1
i = t2
var t3
t3 = j + 1
j = t3
label L2
goto L1
  succ: B2 

[B4]
label L3
ifz 0 goto L5
  succ: B6 B5 

[B5]
output L4
  succ: B6 

[B6]
label L5
  succ: B7 

[B7]
label L6
var t4
t4 = (j > 0)
ifz t4 goto L8
  succ: B9 B8 

[B8]
var t5
t5 = j - 1
j = t5
var t6
t6 = j * 4
var t7
t7 = arr1[t6]
i = t7
output i
label L7
goto L6
  succ: B7 

[B9]
label L8
output L4
end
  succ: 
