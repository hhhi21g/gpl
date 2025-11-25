
# tac list

0x639baa54b7b0	var i
0x639baa54c4e0	label main
0x639baa54c520	begin
0x639baa54b910	var a
0x639baa54b9f0	var b
0x639baa54bad0	var c
0x639baa54bb30	input a
0x639baa54bb90	input b
0x639baa54bd30	var t0
0x639baa54bd70	actual a
0x639baa54bdb0	actual b
0x639baa54be50	t0 = call max
0x639baa54bec0	c = t0
0x639baa54bf50	output c
0x639baa54c030	output L1
0x639baa54c230	var t1
0x639baa54c270	t1 = i + 1
0x639baa54c2b0	i = t1
0x639baa54c340	output i
0x639baa54c420	output L2
0x639baa54c560	end
0x639baa54cd90	label max
0x639baa54cdd0	begin
0x639baa54c640	formal x
0x639baa54c700	formal y
0x639baa54c860	var t2
0x639baa54c8a0	t2 = (x > y)
0x639baa54cc00	ifz t2 goto L3
0x639baa54c950	i = x
0x639baa54cc40	goto L4
0x639baa54cae0	label L3
0x639baa54ca00	i = y
0x639baa54cbc0	label L4
0x639baa54ccd0	return i
0x639baa54ce10	end

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
