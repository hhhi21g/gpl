
# tac list

0x5e15dbb777b0	var i
0x5e15dbb788f0	label main
0x5e15dbb78930	begin
0x5e15dbb77910	var a
0x5e15dbb779f0	var b
0x5e15dbb77ad0	var c
0x5e15dbb77b30	input a
0x5e15dbb77b90	input b
0x5e15dbb78140	var t0
0x5e15dbb78180	actual a
0x5e15dbb781c0	actual b
0x5e15dbb78260	t0 = call max
0x5e15dbb782d0	c = t0
0x5e15dbb78360	output c
0x5e15dbb78440	output L1
0x5e15dbb78640	var t1
0x5e15dbb78680	t1 = i + 1
0x5e15dbb786c0	i = t1
0x5e15dbb78750	output i
0x5e15dbb78830	output L2
0x5e15dbb78970	end
0x5e15dbb791a0	label max
0x5e15dbb791e0	begin
0x5e15dbb78a50	formal x
0x5e15dbb78b10	formal y
0x5e15dbb78c70	var t2
0x5e15dbb78cb0	t2 = (x > y)
0x5e15dbb79010	ifz t2 goto L3
0x5e15dbb78d60	i = x
0x5e15dbb79050	goto L4
0x5e15dbb78ef0	label L3
0x5e15dbb78e10	i = y
0x5e15dbb78fd0	label L4
0x5e15dbb790e0	return i
0x5e15dbb79220	end

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
