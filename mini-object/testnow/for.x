
# tac list

0x5ca4c2cde260	label main
0x5ca4c2cde2a0	begin
0x5ca4c2cdd7f0	var i
0x5ca4c2cdd8b0	var j
0x5ca4c2cdd910	input j
0x5ca4c2cdda20	i = 0
0x5ca4c2cddf00	label L1
0x5ca4c2cddb60	var t0
0x5ca4c2cddba0	t0 = (i < j)
0x5ca4c2cde0c0	ifz t0 goto L3
0x5ca4c2cdde40	output i
0x5ca4c2cddfc0	label L2
0x5ca4c2cddd60	var t1
0x5ca4c2cddda0	t1 = i + 1
0x5ca4c2cddde0	i = t1
0x5ca4c2cde100	goto L1
0x5ca4c2cde080	label L3
0x5ca4c2cde1c0	output L4
0x5ca4c2cde2e0	end

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
