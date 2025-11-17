
# tac list

0x584338995320	label main
0x584338995360	begin
0x584338993830	var a
0x584338993910	var b
0x5843389939f0	var c
0x584338993ad0	var d
0x584338993bb0	var e
0x584338993c10	input a
0x584338993c70	input b
0x584338993df0	var t0
0x584338993e30	t0 = a + b
0x584338993e70	c = t0
0x584338993ff0	var t1
0x584338994070	d = t0
0x5843389941f0	var t2
0x584338994230	t2 = c * d
0x584338994270	e = t2
0x584338994320	c = c
0x5843389943d0	d = e
0x5843389945b0	var t3
0x5843389945f0	t3 = (a > 0)
0x584338995070	ifz t3 goto L1
0x584338994770	var t4
0x5843389947b0	t4 = a + b
0x5843389947f0	c = t4
0x584338994970	var t5
0x5843389949b0	t5 = c + d
0x5843389949f0	e = t5
0x5843389950b0	goto L2
0x584338994f50	label L1
0x584338994b70	var t6
0x584338994bb0	t6 = a + b
0x584338994bf0	d = t6
0x584338994df0	var t7
0x584338994e30	t7 = d + 1
0x584338994e70	e = t7
0x584338995030	label L2
0x584338995140	output c
0x5843389951d0	output d
0x584338995260	output e
0x5843389953a0	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var b
var c
var d
var e
input a
input b
var t0
t0 = a + b
c = t0
var t1
d = t0
var t2
t2 = c * d
e = t2
c = c
d = e
var t3
t3 = (a > 0)
ifz t3 goto L1
  succ: B3 B2 

[B2]
var t4
t4 = a + b
c = t4
var t5
t5 = c + d
e = t5
goto L2
  succ: B4 

[B3]
label L1
var t6
t6 = a + b
d = t6
var t7
t7 = d + 1
e = t7
  succ: B4 

[B4]
label L2
output c
output d
output e
end
  succ: 
