
# tac list

0x62d369143690	label main
0x62d3691436d0	begin
0x62d369142830	var a
0x62d369142910	var b
0x62d3691429f0	var c
0x62d369142ad0	var d
0x62d369142b30	input a
0x62d369142d30	var t0
0x62d369142d70	t0 = a + 10
0x62d369142db0	b = t0
0x62d369142fb0	var t1
0x62d369142ff0	t1 = b - 20
0x62d369143030	c = t1
0x62d369143230	var t2
0x62d369143270	t2 = c * 30
0x62d3691432b0	d = t2
0x62d369143340	output a
0x62d3691433d0	output b
0x62d369143460	output c
0x62d3691434f0	output d
0x62d3691435d0	output L1
0x62d369143710	end

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
