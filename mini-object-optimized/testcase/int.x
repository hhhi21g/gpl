
# tac list

0x5e2d0834b690	label main
0x5e2d0834b6d0	begin
0x5e2d0834a830	var a
0x5e2d0834a910	var b
0x5e2d0834a9f0	var c
0x5e2d0834aad0	var d
0x5e2d0834ab30	input a
0x5e2d0834ad30	var t0
0x5e2d0834ad70	t0 = a + 10
0x5e2d0834adb0	b = t0
0x5e2d0834afb0	var t1
0x5e2d0834aff0	t1 = b - 20
0x5e2d0834b030	c = t1
0x5e2d0834b230	var t2
0x5e2d0834b270	t2 = c * 30
0x5e2d0834b2b0	d = t2
0x5e2d0834b340	output a
0x5e2d0834b3d0	output b
0x5e2d0834b460	output c
0x5e2d0834b4f0	output d
0x5e2d0834b5d0	output L1
0x5e2d0834b710	end

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
