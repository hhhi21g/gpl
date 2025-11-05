
# tac list

0x594ba24032d0	label main
0x594ba2403310	begin
0x594ba24027f0	var i
0x594ba24028b0	var j
0x594ba2402970	var k
0x594ba24029d0	input i
0x594ba2402a30	input j
0x594ba2402b70	var t0
0x594ba2402bb0	t0 = (i == j)
0x594ba2402ef0	ifz t0 goto L3
0x594ba2402c70	output L1
0x594ba2402f30	goto L4
0x594ba2402df0	label L3
0x594ba2402d30	output L2
0x594ba2402eb0	label L4
0x594ba2403090	var t1
0x594ba24030d0	t1 = i + j
0x594ba2403110	k = t1
0x594ba2403170	output k
0x594ba2403230	output L5
0x594ba2403350	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
var k
input i
input j
var t0
t0 = (i == j)
ifz t0 goto L3
  succ: B3 B2 

[B2]
output L1
goto L4
  succ: B4 

[B3]
label L3
output L2
  succ: B4 

[B4]
label L4
var t1
t1 = i + j
k = t1
output k
output L5
end
  succ: 
