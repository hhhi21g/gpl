
# tac list

0x5652c31267a0	var i
0x5652c3127420	label main
0x5652c3127460	begin
0x5652c31268e0	var a
0x5652c31269b0	var b
0x5652c3126a80	var c
0x5652c3126ae0	input a
0x5652c3126b40	input b
0x5652c3126cd0	var t0
0x5652c3126d10	actual a
0x5652c3126d50	actual b
0x5652c3126de0	t0 = call max
0x5652c3126e50	c = t0
0x5652c3126ee0	output c
0x5652c3126fb0	output L1
0x5652c3127190	var t1
0x5652c31271d0	t1 = i + 1
0x5652c3127210	i = t1
0x5652c31272a0	output i
0x5652c3127370	output L2
0x5652c31274a0	end
0x5652c3127c70	label max
0x5652c3127cb0	begin
0x5652c3127570	formal x
0x5652c3127620	formal y
0x5652c3127770	var t2
0x5652c31277b0	t2 = (x > y)
0x5652c3127af0	ifz t2 goto L3
0x5652c3127860	i = x
0x5652c3127b30	goto L4
0x5652c31279e0	label L3
0x5652c3127910	i = y
0x5652c3127ab0	label L4
0x5652c3127bc0	return i
0x5652c3127cf0	end

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
