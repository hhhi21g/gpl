
# tac list

0x5730fa338790	var i
0x5730fa3392e0	label main
0x5730fa339320	begin
0x5730fa3388b0	var a
0x5730fa338970	var b
0x5730fa338a30	var c
0x5730fa338a90	input a
0x5730fa338af0	input b
0x5730fa338c70	var t0
0x5730fa338cb0	actual b
0x5730fa338cf0	actual a
0x5730fa338d50	t0 = call max
0x5730fa338dc0	c = t0
0x5730fa338e20	output c
0x5730fa338ee0	output L1
0x5730fa3390a0	var t1
0x5730fa3390e0	t1 = i + 1
0x5730fa339120	i = t1
0x5730fa339180	output i
0x5730fa339240	output L2
0x5730fa339360	end
0x5730fa339b10	label max
0x5730fa339b50	begin
0x5730fa339460	formal x
0x5730fa339500	formal y
0x5730fa339640	var t2
0x5730fa339680	t2 = (x > y)
0x5730fa3399a0	ifz t2 goto L3
0x5730fa339730	i = x
0x5730fa3399e0	goto L4
0x5730fa3398a0	label L3
0x5730fa3397e0	i = y
0x5730fa339960	label L4
0x5730fa339a70	return i
0x5730fa339b90	end

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
actual b
actual a
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
