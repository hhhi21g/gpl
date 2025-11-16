
# tac list

0x63ebaa2ad690	label main
0x63ebaa2ad6d0	begin
0x63ebaa2ac830	var a
0x63ebaa2ac910	var b
0x63ebaa2ac9f0	var c
0x63ebaa2acad0	var d
0x63ebaa2acb30	input a
0x63ebaa2acd30	var t0
0x63ebaa2acd70	t0 = a + 10
0x63ebaa2acdb0	b = t0
0x63ebaa2acfb0	var t1
0x63ebaa2acff0	t1 = b - 20
0x63ebaa2ad030	c = t1
0x63ebaa2ad230	var t2
0x63ebaa2ad270	t2 = c * 30
0x63ebaa2ad2b0	d = t2
0x63ebaa2ad340	output a
0x63ebaa2ad3d0	output b
0x63ebaa2ad460	output c
0x63ebaa2ad4f0	output d
0x63ebaa2ad5d0	output L1
0x63ebaa2ad710	end

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
