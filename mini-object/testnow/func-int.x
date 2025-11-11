
# tac list

0x5595f53017a0	var i
0x5595f5302420	label main
0x5595f5302460	begin
0x5595f53018e0	var a
0x5595f53019b0	var b
0x5595f5301a80	var c
0x5595f5301ae0	input a
0x5595f5301b40	input b
0x5595f5301cd0	var t0
0x5595f5301d10	actual a
0x5595f5301d50	actual b
0x5595f5301de0	t0 = call max
0x5595f5301e50	c = t0
0x5595f5301ee0	output c
0x5595f5301fb0	output L1
0x5595f5302190	var t1
0x5595f53021d0	t1 = i + 1
0x5595f5302210	i = t1
0x5595f53022a0	output i
0x5595f5302370	output L2
0x5595f53024a0	end
0x5595f5302c70	label max
0x5595f5302cb0	begin
0x5595f5302570	formal x
0x5595f5302620	formal y
0x5595f5302770	var t2
0x5595f53027b0	t2 = (x > y)
0x5595f5302af0	ifz t2 goto L3
0x5595f5302860	i = x
0x5595f5302b30	goto L4
0x5595f53029e0	label L3
0x5595f5302910	i = y
0x5595f5302ab0	label L4
0x5595f5302bc0	return i
0x5595f5302cf0	end

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
