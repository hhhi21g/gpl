
# tac list

0x570e9c846790	label main
0x570e9c8467d0	begin
0x570e9c845830	var a
0x570e9c845910	var b
0x570e9c8459f0	var c
0x570e9c845ad0	var d
0x570e9c845b30	input d
0x570e9c845c60	c = 'c'
0x570e9c845d90	b = 'b'
0x570e9c845df0	input a
0x570e9c8460c0	ifz 0 goto L2
0x570e9c845fa0	output L1
0x570e9c846080	label L2
0x570e9c846150	output a
0x570e9c8461e0	output b
0x570e9c846270	output c
0x570e9c846300	output d
0x570e9c846360	output L1
0x570e9c846560	var t0
0x570e9c8465a0	t0 = a + 1
0x570e9c8465e0	a = t0
0x570e9c846670	output a
0x570e9c8466d0	output L1
0x570e9c846810	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var b
var c
var d
input d
c = 'c'
b = 'b'
input a
ifz 0 goto L2
  succ: B3 B2 

[B2]
output L1
  succ: B3 

[B3]
label L2
output a
output b
output c
output d
output L1
var t0
t0 = a + 1
a = t0
output a
output L1
end
  succ: 
