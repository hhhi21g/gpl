
# tac list

0x5cd6b15ee790	var i
0x5cd6b15ef2e0	label main
0x5cd6b15ef320	begin
0x5cd6b15ee8b0	var a
0x5cd6b15ee970	var b
0x5cd6b15eea30	var c
0x5cd6b15eea90	input a
0x5cd6b15eeaf0	input b
0x5cd6b15eec70	var t0
0x5cd6b15eecb0	actual b
0x5cd6b15eecf0	actual a
0x5cd6b15eed50	t0 = call max
0x5cd6b15eedc0	c = t0
0x5cd6b15eee20	output c
0x5cd6b15eeee0	output L1
0x5cd6b15ef0a0	var t1
0x5cd6b15ef0e0	t1 = i + 1
0x5cd6b15ef120	i = t1
0x5cd6b15ef180	output i
0x5cd6b15ef240	output L2
0x5cd6b15ef360	end
0x5cd6b15efb10	label max
0x5cd6b15efb50	begin
0x5cd6b15ef460	formal x
0x5cd6b15ef500	formal y
0x5cd6b15ef640	var t2
0x5cd6b15ef680	t2 = (x > y)
0x5cd6b15ef9a0	ifz t2 goto L3
0x5cd6b15ef730	i = x
0x5cd6b15ef9e0	goto L4
0x5cd6b15ef8a0	label L3
0x5cd6b15ef7e0	i = y
0x5cd6b15ef960	label L4
0x5cd6b15efa70	return i
0x5cd6b15efb90	end

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
