
# tac list

0x62c09d05b7a0	var i
0x62c09d05c420	label main
0x62c09d05c460	begin
0x62c09d05b8e0	var a
0x62c09d05b9b0	var b
0x62c09d05ba80	var c
0x62c09d05bae0	input a
0x62c09d05bb40	input b
0x62c09d05bcd0	var t0
0x62c09d05bd10	actual a
0x62c09d05bd50	actual b
0x62c09d05bde0	t0 = call max
0x62c09d05be50	c = t0
0x62c09d05bee0	output c
0x62c09d05bfb0	output L1
0x62c09d05c190	var t1
0x62c09d05c1d0	t1 = i + 1
0x62c09d05c210	i = t1
0x62c09d05c2a0	output i
0x62c09d05c370	output L2
0x62c09d05c4a0	end
0x62c09d05cc70	label max
0x62c09d05ccb0	begin
0x62c09d05c570	formal x
0x62c09d05c620	formal y
0x62c09d05c770	var t2
0x62c09d05c7b0	t2 = (x > y)
0x62c09d05caf0	ifz t2 goto L3
0x62c09d05c860	i = x
0x62c09d05cb30	goto L4
0x62c09d05c9e0	label L3
0x62c09d05c910	i = y
0x62c09d05cab0	label L4
0x62c09d05cbc0	return i
0x62c09d05ccf0	end

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
