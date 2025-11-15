
# tac list

0x563c30823ad0	label main
0x563c30823b10	begin
0x563c30822830	var x
0x563c30822910	var y
0x563c308229f0	var z
0x563c30822c70	var t0
0x563c30822cb0	t0 = 3 + 4
0x563c30822cf0	x = t0
0x563c30822ef0	var t1
0x563c30822f30	t1 = x * 2
0x563c30822f70	y = t1
0x563c30823150	var t2
0x563c30823190	t2 = (y > 20)
0x563c30823740	ifz t2 goto L1
0x563c30823390	var t3
0x563c308233d0	t3 = y - 14
0x563c30823410	z = t3
0x563c30823780	goto L2
0x563c30823620	label L1
0x563c30823540	z = 0
0x563c30823700	label L2
0x563c30823900	var t4
0x563c30823940	t4 = z + 0
0x563c30823980	z = t4
0x563c30823a10	output z
0x563c30823b50	end

[B0]
label main
  succ: B1 

[B1]
begin
var x
var y
var z
var t0
t0 = 3 + 4
x = t0
var t1
t1 = x * 2
y = t1
var t2
t2 = (y > 20)
ifz t2 goto L1
  succ: B3 B2 

[B2]
var t3
t3 = y - 14
z = t3
goto L2
  succ: B4 

[B3]
label L1
z = 0
  succ: B4 

[B4]
label L2
var t4
t4 = z + 0
z = t4
output z
end
  succ: 
