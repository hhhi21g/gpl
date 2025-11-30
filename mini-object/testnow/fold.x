
# tac list

0x607506f719d0	label main
0x607506f71a10	begin
0x607506f70830	var x
0x607506f70910	var y
0x607506f709f0	var z
0x607506f70e70	var t0
0x607506f70ef0	y = 14
0x607506f710d0	var t1
0x607506f716c0	ifz 0 goto L1
0x607506f71240	z = 1
0x607506f71700	goto L2
0x607506f715a0	label L1
0x607506f71440	var t2
0x607506f71480	t2 = y - 14
0x607506f714c0	z = t2
0x607506f71680	label L2
0x607506f71880	z = z
0x607506f71910	output z
0x607506f71a50	end

[B0]
label main
  succ: B1 

[B1]
begin
var x
var y
var z
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
