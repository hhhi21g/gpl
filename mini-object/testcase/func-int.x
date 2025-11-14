
# tac list

0x59017b5967b0	var i
0x59017b5978f0	label main
0x59017b597930	begin
0x59017b596910	var a
0x59017b5969f0	var b
0x59017b596ad0	var c
0x59017b596b30	input a
0x59017b596b90	input b
0x59017b597140	var t0
0x59017b597180	actual a
0x59017b5971c0	actual b
0x59017b597260	t0 = call max
0x59017b5972d0	c = t0
0x59017b597360	output c
0x59017b597440	output L1
0x59017b597640	var t1
0x59017b597680	t1 = i + 1
0x59017b5976c0	i = t1
0x59017b597750	output i
0x59017b597830	output L2
0x59017b597970	end
0x59017b5981a0	label max
0x59017b5981e0	begin
0x59017b597a50	formal x
0x59017b597b10	formal y
0x59017b597c70	var t2
0x59017b597cb0	t2 = (x > y)
0x59017b598010	ifz t2 goto L3
0x59017b597d60	i = x
0x59017b598050	goto L4
0x59017b597ef0	label L3
0x59017b597e10	i = y
0x59017b597fd0	label L4
0x59017b5980e0	return i
0x59017b598220	end

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
