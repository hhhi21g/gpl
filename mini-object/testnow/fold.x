
# tac list

0x57c6212069d0	label main
0x57c621206a10	begin
0x57c621205830	var x
0x57c621205910	var y
0x57c6212059f0	var z
0x57c621205c70	x = 7
0x57c621205e70	var t0
0x57c621205ef0	y = 14
0x57c6212060d0	var t1
0x57c6212066c0	ifz 0 goto L1
0x57c621206240	z = 1
0x57c621206700	goto L2
0x57c6212065a0	label L1
0x57c621206440	var t2
0x57c621206480	t2 = y - 14
0x57c6212064c0	z = t2
0x57c621206680	label L2
0x57c621206880	z = z
0x57c621206910	output z
0x57c621206a50	end

[B0]
label main
  succ: B1 

[B1]
begin
var x
var y
var z
x = 7
var t0
y = 14
var t1
ifz 0 goto L1
  succ: B3 B2 

[B2]
z = 1
goto L2
  succ: B4 

[B3]
label L1
var t2
t2 = y - 14
z = t2
  succ: B4 

[B4]
label L2
z = z
output z
end
  succ: 
