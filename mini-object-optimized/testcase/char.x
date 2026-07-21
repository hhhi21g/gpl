
# tac list

0x65240ec96790	label main
0x65240ec967d0	begin
0x65240ec95830	var a
0x65240ec95910	var b
0x65240ec959f0	var c
0x65240ec95ad0	var d
0x65240ec95b30	input d
0x65240ec95c60	c = 'c'
0x65240ec95d90	b = 'b'
0x65240ec95df0	input a
0x65240ec960c0	ifz 0 goto L2
0x65240ec95fa0	output L1
0x65240ec96080	label L2
0x65240ec96150	output a
0x65240ec961e0	output b
0x65240ec96270	output c
0x65240ec96300	output d
0x65240ec96360	output L1
0x65240ec96560	var t0
0x65240ec965a0	t0 = a + 1
0x65240ec965e0	a = t0
0x65240ec96670	output a
0x65240ec966d0	output L1
0x65240ec96810	end

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
