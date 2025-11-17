
# tac list

0x5f780543c240	label main
0x5f780543c280	begin
0x5f780543b830	var a
0x5f780543b910	var b
0x5f780543b9f0	var c
0x5f780543bb20	a = 1
0x5f780543bc50	a = 2
0x5f780543be30	var t0
0x5f780543c0f0	ifz 1 goto L1
0x5f780543bf20	b = a
0x5f780543bfd0	c = b
0x5f780543c0b0	label L1
0x5f780543c180	output c
0x5f780543c2c0	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var b
var c
a = 1
a = 2
var t0
ifz 1 goto L1
  succ: B3 B2 

[B2]
b = a
c = b
  succ: B3 

[B3]
label L1
output c
end
  succ: 
