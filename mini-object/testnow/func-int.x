
# tac list

0x60e8b7cc37a0	var i
0x60e8b7cc4420	label main
0x60e8b7cc4460	begin
0x60e8b7cc38e0	var a
0x60e8b7cc39b0	var b
0x60e8b7cc3a80	var c
0x60e8b7cc3ae0	input a
0x60e8b7cc3b40	input b
0x60e8b7cc3cd0	var t0
0x60e8b7cc3d10	actual a
0x60e8b7cc3d50	actual b
0x60e8b7cc3de0	t0 = call 
0x60e8b7cc3e50	c = t0
0x60e8b7cc3ee0	output c
0x60e8b7cc3fb0	output L1
0x60e8b7cc4190	var t1
0x60e8b7cc41d0	t1 = i + 1
0x60e8b7cc4210	i = t1
0x60e8b7cc42a0	output i
0x60e8b7cc4370	output L2
0x60e8b7cc44a0	end
0x60e8b7cc4c70	label max
0x60e8b7cc4cb0	begin
0x60e8b7cc4570	formal x
0x60e8b7cc4620	formal y
0x60e8b7cc4770	var t2
0x60e8b7cc47b0	t2 = (x > y)
0x60e8b7cc4af0	ifz t2 goto L3
0x60e8b7cc4860	i = x
0x60e8b7cc4b30	goto L4
0x60e8b7cc49e0	label L3
0x60e8b7cc4910	i = y
0x60e8b7cc4ab0	label L4
0x60e8b7cc4bc0	return i
0x60e8b7cc4cf0	end

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
t0 = call 
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
