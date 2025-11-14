
# tac list

0x6426b6ff87b0	var i
0x6426b6ff98f0	label main
0x6426b6ff9930	begin
0x6426b6ff8910	var a
0x6426b6ff89f0	var b
0x6426b6ff8ad0	var c
0x6426b6ff8b30	input a
0x6426b6ff8b90	input b
0x6426b6ff9140	var t0
0x6426b6ff9180	actual a
0x6426b6ff91c0	actual b
0x6426b6ff9260	t0 = call max
0x6426b6ff92d0	c = t0
0x6426b6ff9360	output c
0x6426b6ff9440	output L1
0x6426b6ff9640	var t1
0x6426b6ff9680	t1 = i + 1
0x6426b6ff96c0	i = t1
0x6426b6ff9750	output i
0x6426b6ff9830	output L2
0x6426b6ff9970	end
0x6426b6ffa1a0	label max
0x6426b6ffa1e0	begin
0x6426b6ff9a50	formal x
0x6426b6ff9b10	formal y
0x6426b6ff9c70	var t2
0x6426b6ff9cb0	t2 = (x > y)
0x6426b6ffa010	ifz t2 goto L3
0x6426b6ff9d60	i = x
0x6426b6ffa050	goto L4
0x6426b6ff9ef0	label L3
0x6426b6ff9e10	i = y
0x6426b6ff9fd0	label L4
0x6426b6ffa0e0	return i
0x6426b6ffa220	end

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
