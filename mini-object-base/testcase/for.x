
# tac list

0x5efb89f68410	label main
0x5efb89f68450	begin
0x5efb89f67830	var i
0x5efb89f67910	var j
0x5efb89f67970	input j
0x5efb89f67aa0	i = 0
0x5efb89f68170	label L1
0x5efb89f67c00	var t0
0x5efb89f67c40	t0 = (i < j)
0x5efb89f68230	ifz t0 goto L3
0x5efb89f68130	output i
0x5efb89f681b0	label L2
0x5efb89f67e40	var t1
0x5efb89f67e80	t1 = i + 1
0x5efb89f67ec0	i = t1
0x5efb89f68270	goto L1
0x5efb89f681f0	label L3
0x5efb89f68350	output L4
0x5efb89f68490	end

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
var t0
t0 = (i < j)
ifz t0 goto L3
  succ: B4 B3 

[B3]
output i
label L2
var t1
t1 = i + 1
i = t1
goto L1
  succ: B2 

[B4]
label L3
output L4
end
  succ: 
