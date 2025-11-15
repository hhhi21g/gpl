
# tac list

0x5e3a1c69d7b0	var i
0x5e3a1c69e8f0	label main
0x5e3a1c69e930	begin
0x5e3a1c69d910	var a
0x5e3a1c69d9f0	var b
0x5e3a1c69dad0	var c
0x5e3a1c69db30	input a
0x5e3a1c69db90	input b
0x5e3a1c69e140	var t0
0x5e3a1c69e180	actual a
0x5e3a1c69e1c0	actual b
0x5e3a1c69e260	t0 = call max
0x5e3a1c69e2d0	c = t0
0x5e3a1c69e360	output c
0x5e3a1c69e440	output L1
0x5e3a1c69e640	var t1
0x5e3a1c69e680	t1 = i + 1
0x5e3a1c69e6c0	i = t1
0x5e3a1c69e750	output i
0x5e3a1c69e830	output L2
0x5e3a1c69e970	end
0x5e3a1c69f1a0	label max
0x5e3a1c69f1e0	begin
0x5e3a1c69ea50	formal x
0x5e3a1c69eb10	formal y
0x5e3a1c69ec70	var t2
0x5e3a1c69ecb0	t2 = (x > y)
0x5e3a1c69f010	ifz t2 goto L3
0x5e3a1c69ed60	i = x
0x5e3a1c69f050	goto L4
0x5e3a1c69eef0	label L3
0x5e3a1c69ee10	i = y
0x5e3a1c69efd0	label L4
0x5e3a1c69f0e0	return i
0x5e3a1c69f220	end

[B0]
var i
label main
  succ: B1 

[B1]
begin
var a
var b
var c
input a
input b
var t0
actual a
actual b
t0 = call max
c = t0
output c
output L1
var t1
t1 = i + 1
i = t1
output i
output L2
end
  succ: 

[B2]
label max
  succ: B3 

[B3]
begin
formal x
formal y
var t2
t2 = (x > y)
ifz t2 goto L3
  succ: B5 B4 

[B4]
i = x
goto L4
  succ: B6 

[B5]
label L3
i = y
  succ: B6 

[B6]
label L4
return i
  succ: 

[B7]
end
  succ: 
