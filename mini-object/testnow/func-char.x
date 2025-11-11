
# tac list

0x613a41c257a0	var i
0x613a41c26420	label main
0x613a41c26460	begin
0x613a41c258e0	var a
0x613a41c259b0	var b
0x613a41c25a80	var c
0x613a41c25ae0	input a
0x613a41c25b40	input b
0x613a41c25cd0	var t0
0x613a41c25d10	actual a
0x613a41c25d50	actual b
0x613a41c25de0	t0 = call max
0x613a41c25e50	c = t0
0x613a41c25ee0	output c
0x613a41c25fb0	output L1
0x613a41c26190	var t1
0x613a41c261d0	t1 = i + 1
0x613a41c26210	i = t1
0x613a41c262a0	output i
0x613a41c26370	output L2
0x613a41c264a0	end
0x613a41c26c70	label max
0x613a41c26cb0	begin
0x613a41c26570	formal x
0x613a41c26620	formal y
0x613a41c26770	var t2
0x613a41c267b0	t2 = (x > y)
0x613a41c26af0	ifz t2 goto L3
0x613a41c26860	i = x
0x613a41c26b30	goto L4
0x613a41c269e0	label L3
0x613a41c26910	i = y
0x613a41c26ab0	label L4
0x613a41c26bc0	return i
0x613a41c26cf0	end

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
