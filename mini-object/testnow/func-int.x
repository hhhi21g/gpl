
# tac list

0x5f1c31deb790	var i
0x5f1c31dec6f0	label main
0x5f1c31dec730	begin
0x5f1c31deb8b0	var a
0x5f1c31deb970	var b
0x5f1c31debe40	var c
0x5f1c31debea0	input a
0x5f1c31debf00	input b
0x5f1c31dec080	var t0
0x5f1c31dec0c0	actual b
0x5f1c31dec100	actual a
0x5f1c31dec160	t0 = call max
0x5f1c31dec1d0	c = t0
0x5f1c31dec230	output c
0x5f1c31dec2f0	output L1
0x5f1c31dec4b0	var t1
0x5f1c31dec4f0	t1 = i + 1
0x5f1c31dec530	i = t1
0x5f1c31dec590	output i
0x5f1c31dec650	output L2
0x5f1c31dec770	end
0x5f1c31decf20	label max
0x5f1c31decf60	begin
0x5f1c31dec870	formal x
0x5f1c31dec910	formal y
0x5f1c31deca50	var t2
0x5f1c31deca90	t2 = (x > y)
0x5f1c31decdb0	ifz t2 goto L3
0x5f1c31decb40	i = x
0x5f1c31decdf0	goto L4
0x5f1c31deccb0	label L3
0x5f1c31decbf0	i = y
0x5f1c31decd70	label L4
0x5f1c31dece80	return i
0x5f1c31decfa0	end

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
