
# tac list

0x5bc6683537b0	var i
0x5bc6683548f0	label main
0x5bc668354930	begin
0x5bc668353910	var a
0x5bc6683539f0	var b
0x5bc668353ad0	var c
0x5bc668353b30	input a
0x5bc668353b90	input b
0x5bc668354140	var t0
0x5bc668354180	actual a
0x5bc6683541c0	actual b
0x5bc668354260	t0 = call max
0x5bc6683542d0	c = t0
0x5bc668354360	output c
0x5bc668354440	output L1
0x5bc668354640	var t1
0x5bc668354680	t1 = i + 1
0x5bc6683546c0	i = t1
0x5bc668354750	output i
0x5bc668354830	output L2
0x5bc668354970	end
0x5bc6683551a0	label max
0x5bc6683551e0	begin
0x5bc668354a50	formal x
0x5bc668354b10	formal y
0x5bc668354c70	var t2
0x5bc668354cb0	t2 = (x > y)
0x5bc668355010	ifz t2 goto L3
0x5bc668354d60	i = x
0x5bc668355050	goto L4
0x5bc668354ef0	label L3
0x5bc668354e10	i = y
0x5bc668354fd0	label L4
0x5bc6683550e0	return i
0x5bc668355220	end

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
