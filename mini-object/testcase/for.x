
# tac list

0x5865362d4260	label main
0x5865362d42a0	begin
0x5865362d37f0	var i
0x5865362d38b0	var j
0x5865362d3910	input j
0x5865362d3a20	i = 0
0x5865362d3f00	label L1
0x5865362d3ba0	t0 = (i < j)
0x5865362d40c0	ifz t0 goto L3
0x5865362d3e40	output i
0x5865362d3fc0	label L2
0x5865362d3de0	i = t1
0x5865362d4100	goto L1
0x5865362d4080	label L3
0x5865362d41c0	output L4
0x5865362d42e0	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
input j
i = 0
  succ: B2 

[B2]
label L1
t0 = (i < j)
ifz t0 goto L3
  succ: B5 B3 

[B3]
output i
  succ: B4 

[B4]
label L2
i = t1
goto L1
  succ: B2 

[B5]
label L3
output L4
end
  succ: 
