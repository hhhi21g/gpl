
# tac list

0x64e8ef26d400	label main
0x64e8ef26d440	begin
0x64e8ef26b830	var i
0x64e8ef26b910	var j
0x64e8ef26b970	input i
0x64e8ef26d160	var t5
0x64e8ef26d1a0	t5 = (i != 1)
0x64e8ef26d1e0	ifz t5 goto L2
0x64e8ef26d020	var t4
0x64e8ef26d060	t4 = (i != 2)
0x64e8ef26d0a0	ifz t4 goto L3
0x64e8ef26cee0	var t3
0x64e8ef26cf20	t3 = (i != 3)
0x64e8ef26cf60	ifz t3 goto L4
0x64e8ef26d220	goto L6
0x64e8ef26cbe0	label L4
0x64e8ef26c9b0	var t2
0x64e8ef26c9f0	t2 = i + 3
0x64e8ef26ca30	j = t2
0x64e8ef26cac0	output j
0x64e8ef26cb00	goto L1
0x64e8ef26c750	label L3
0x64e8ef26c520	var t1
0x64e8ef26c560	t1 = i + 2
0x64e8ef26c5a0	j = t1
0x64e8ef26c630	output j
0x64e8ef26c670	goto L1
0x64e8ef26c2c0	label L2
0x64e8ef26c090	var t0
0x64e8ef26c0d0	t0 = i + 1
0x64e8ef26c110	j = t0
0x64e8ef26c1a0	output j
0x64e8ef26c1e0	goto L1
0x64e8ef26ce20	label L6
0x64e8ef26cd00	output L5
0x64e8ef26cd40	goto L1
0x64e8ef26d260	label L1
0x64e8ef26d340	output L7
0x64e8ef26d480	end

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
