
# tac list

0x61753b1c87b0	var i
0x61753b1c98f0	label main
0x61753b1c9930	begin
0x61753b1c8910	var a
0x61753b1c89f0	var b
0x61753b1c8ad0	var c
0x61753b1c8b30	input a
0x61753b1c8b90	input b
0x61753b1c9140	var t0
0x61753b1c9180	actual a
0x61753b1c91c0	actual b
0x61753b1c9260	t0 = call max
0x61753b1c92d0	c = t0
0x61753b1c9360	output c
0x61753b1c9440	output L1
0x61753b1c9640	var t1
0x61753b1c9680	t1 = i + 1
0x61753b1c96c0	i = t1
0x61753b1c9750	output i
0x61753b1c9830	output L2
0x61753b1c9970	end
0x61753b1ca1a0	label max
0x61753b1ca1e0	begin
0x61753b1c9a50	formal x
0x61753b1c9b10	formal y
0x61753b1c9c70	var t2
0x61753b1c9cb0	t2 = (x > y)
0x61753b1ca010	ifz t2 goto L3
0x61753b1c9d60	i = x
0x61753b1ca050	goto L4
0x61753b1c9ef0	label L3
0x61753b1c9e10	i = y
0x61753b1c9fd0	label L4
0x61753b1ca0e0	return i
0x61753b1ca220	end

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
