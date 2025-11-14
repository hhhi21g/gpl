
# tac list

0x6133c993e7a0	var i
0x6133c993f830	label main
0x6133c993f870	begin
0x6133c993e8e0	var a
0x6133c993e9b0	var b
0x6133c993ea80	var c
0x6133c993eae0	input a
0x6133c993eb40	input b
0x6133c993f0e0	var t0
0x6133c993f120	actual a
0x6133c993f160	actual b
0x6133c993f1f0	t0 = call max
0x6133c993f260	c = t0
0x6133c993f2f0	output c
0x6133c993f3c0	output L1
0x6133c993f5a0	var t1
0x6133c993f5e0	t1 = i + 1
0x6133c993f620	i = t1
0x6133c993f6b0	output i
0x6133c993f780	output L2
0x6133c993f8b0	end
0x6133c9940080	label max
0x6133c99400c0	begin
0x6133c993f980	formal x
0x6133c993fa30	formal y
0x6133c993fb80	var t2
0x6133c993fbc0	t2 = (x > y)
0x6133c993ff00	ifz t2 goto L3
0x6133c993fc70	i = x
0x6133c993ff40	goto L4
0x6133c993fdf0	label L3
0x6133c993fd20	i = y
0x6133c993fec0	label L4
0x6133c993ffd0	return i
0x6133c9940100	end

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
