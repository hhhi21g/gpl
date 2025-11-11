
# tac list

0x55e63d5607a0	var i
0x55e63d561420	label main
0x55e63d561460	begin
0x55e63d5608e0	var a
0x55e63d5609b0	var b
0x55e63d560a80	var c
0x55e63d560ae0	input a
0x55e63d560b40	input b
0x55e63d560cd0	var t0
0x55e63d560d10	actual a
0x55e63d560d50	actual b
0x55e63d560de0	t0 = call max
0x55e63d560e50	c = t0
0x55e63d560ee0	output c
0x55e63d560fb0	output L1
0x55e63d561190	var t1
0x55e63d5611d0	t1 = i + 1
0x55e63d561210	i = t1
0x55e63d5612a0	output i
0x55e63d561370	output L2
0x55e63d5614a0	end
0x55e63d561c70	label max
0x55e63d561cb0	begin
0x55e63d561570	formal x
0x55e63d561620	formal y
0x55e63d561770	var t2
0x55e63d5617b0	t2 = (x > y)
0x55e63d561af0	ifz t2 goto L3
0x55e63d561860	i = x
0x55e63d561b30	goto L4
0x55e63d5619e0	label L3
0x55e63d561910	i = y
0x55e63d561ab0	label L4
0x55e63d561bc0	return i
0x55e63d561cf0	end

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
