
# tac list

0x598416f3d790	var i
0x598416f3e2e0	label main
0x598416f3e320	begin
0x598416f3d8b0	var a
0x598416f3d970	var b
0x598416f3da30	var c
0x598416f3da90	input a
0x598416f3daf0	input b
0x598416f3dc70	var t0
0x598416f3dcb0	actual b
0x598416f3dcf0	actual a
0x598416f3dd50	t0 = call max
0x598416f3ddc0	c = t0
0x598416f3de20	output c
0x598416f3dee0	output L1
0x598416f3e0a0	var t1
0x598416f3e0e0	t1 = i + 1
0x598416f3e120	i = t1
0x598416f3e180	output i
0x598416f3e240	output L2
0x598416f3e360	end
0x598416f3eb10	label max
0x598416f3eb50	begin
0x598416f3e460	formal x
0x598416f3e500	formal y
0x598416f3e640	var t2
0x598416f3e680	t2 = (x > y)
0x598416f3e9a0	ifz t2 goto L3
0x598416f3e730	i = x
0x598416f3e9e0	goto L4
0x598416f3e8a0	label L3
0x598416f3e7e0	i = y
0x598416f3e960	label L4
0x598416f3ea70	return i
0x598416f3eb90	end

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
