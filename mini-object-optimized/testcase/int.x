
# tac list

0x5af035522690	label main
0x5af0355226d0	begin
0x5af035521830	var a
0x5af035521910	var b
0x5af0355219f0	var c
0x5af035521ad0	var d
0x5af035521b30	input a
0x5af035521d30	var t0
0x5af035521d70	t0 = a + 10
0x5af035521db0	b = t0
0x5af035521fb0	var t1
0x5af035521ff0	t1 = b - 20
0x5af035522030	c = t1
0x5af035522230	var t2
0x5af035522270	t2 = c * 30
0x5af0355222b0	d = t2
0x5af035522340	output a
0x5af0355223d0	output b
0x5af035522460	output c
0x5af0355224f0	output d
0x5af0355225d0	output L1
0x5af035522710	end

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
