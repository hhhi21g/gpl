
# tac list

0x6487b013e480	label main
0x6487b013e4c0	begin
0x6487b013d830	var i
0x6487b013d910	var j
0x6487b013d9f0	var k
0x6487b013da50	input i
0x6487b013dab0	input j
0x6487b013dc10	var t0
0x6487b013dc50	t0 = (i == j)
0x6487b013e010	ifz t0 goto L3
0x6487b013dd30	output L1
0x6487b013e050	goto L4
0x6487b013def0	label L3
0x6487b013de10	output L2
0x6487b013dfd0	label L4
0x6487b013e1d0	var t1
0x6487b013e210	t1 = i + j
0x6487b013e250	k = t1
0x6487b013e2e0	output k
0x6487b013e3c0	output L5
0x6487b013e500	end

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
