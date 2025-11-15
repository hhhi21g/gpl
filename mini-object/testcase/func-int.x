
# tac list

0x5dee92edc7b0	var i
0x5dee92edd8f0	label main
0x5dee92edd930	begin
0x5dee92edc910	var a
0x5dee92edc9f0	var b
0x5dee92edcad0	var c
0x5dee92edcb30	input a
0x5dee92edcb90	input b
0x5dee92edd140	var t0
0x5dee92edd180	actual a
0x5dee92edd1c0	actual b
0x5dee92edd260	t0 = call max
0x5dee92edd2d0	c = t0
0x5dee92edd360	output c
0x5dee92edd440	output L1
0x5dee92edd640	var t1
0x5dee92edd680	t1 = i + 1
0x5dee92edd6c0	i = t1
0x5dee92edd750	output i
0x5dee92edd830	output L2
0x5dee92edd970	end
0x5dee92ede1a0	label max
0x5dee92ede1e0	begin
0x5dee92edda50	formal x
0x5dee92eddb10	formal y
0x5dee92eddc70	var t2
0x5dee92eddcb0	t2 = (x > y)
0x5dee92ede010	ifz t2 goto L3
0x5dee92eddd60	i = x
0x5dee92ede050	goto L4
0x5dee92eddef0	label L3
0x5dee92edde10	i = y
0x5dee92eddfd0	label L4
0x5dee92ede0e0	return i
0x5dee92ede220	end

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
