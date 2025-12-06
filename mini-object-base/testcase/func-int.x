
# tac list

0x572360a2f7b0	var i
0x572360a304e0	label main
0x572360a30520	begin
0x572360a2f910	var a
0x572360a2f9f0	var b
0x572360a2fad0	var c
0x572360a2fb30	input a
0x572360a2fb90	input b
0x572360a2fd30	var t0
0x572360a2fd70	actual a
0x572360a2fdb0	actual b
0x572360a2fe50	t0 = call max
0x572360a2fec0	c = t0
0x572360a2ff50	output c
0x572360a30030	output L1
0x572360a30230	var t1
0x572360a30270	t1 = i + 1
0x572360a302b0	i = t1
0x572360a30340	output i
0x572360a30420	output L2
0x572360a30560	end
0x572360a30d90	label max
0x572360a30dd0	begin
0x572360a30640	formal x
0x572360a30700	formal y
0x572360a30860	var t2
0x572360a308a0	t2 = (x > y)
0x572360a30c00	ifz t2 goto L3
0x572360a30950	i = x
0x572360a30c40	goto L4
0x572360a30ae0	label L3
0x572360a30a00	i = y
0x572360a30bc0	label L4
0x572360a30cd0	return i
0x572360a30e10	end

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
