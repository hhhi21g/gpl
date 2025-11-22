
# tac list

0x5d5cd225c690	label main
0x5d5cd225c6d0	begin
0x5d5cd225b830	var a
0x5d5cd225b910	var b
0x5d5cd225b9f0	var c
0x5d5cd225bad0	var d
0x5d5cd225bb30	input a
0x5d5cd225bd30	var t0
0x5d5cd225bd70	t0 = a + 10
0x5d5cd225bdb0	b = t0
0x5d5cd225bfb0	var t1
0x5d5cd225bff0	t1 = b - 20
0x5d5cd225c030	c = t1
0x5d5cd225c230	var t2
0x5d5cd225c270	t2 = c * 30
0x5d5cd225c2b0	d = t2
0x5d5cd225c340	output a
0x5d5cd225c3d0	output b
0x5d5cd225c460	output c
0x5d5cd225c4f0	output d
0x5d5cd225c5d0	output L1
0x5d5cd225c710	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var b
var c
var d
input a
var t0
t0 = a + 10
b = t0
var t1
t1 = b - 20
c = t1
var t2
t2 = c * 30
d = t2
output a
output b
output c
output d
output L1
end
  succ: 
