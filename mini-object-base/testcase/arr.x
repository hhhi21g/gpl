
# tac list

0x57457ae06750	label main
0x57457ae06790	begin
0x57457ae04830	var i
0x57457ae04910	var j
0x57457ae04b60	vararray arr1[1D]
0x57457ae04e00	vararray arr2[2D]
0x57457ae050f0	vararray arr3[3D]
0x57457ae05150	input i
0x57457ae053b0	arr1[24] = i
0x57457ae05660	var t0
0x57457ae056a0	t0 = arr1[24]
0x57457ae057e0	var t1
0x57457ae05820	t1 = t0 + 6
0x57457ae05910	arr2[504] = t1
0x57457ae05cc0	var t2
0x57457ae05d00	t2 = arr2[504]
0x57457ae05e40	var t3
0x57457ae05e80	t3 = t2 + 6
0x57457ae05f70	arr3[15144] = t3
0x57457ae06260	ifz 0 goto L2
0x57457ae06120	output L1
0x57457ae06220	label L2
0x57457ae064f0	var t4
0x57457ae06530	t4 = arr3[15144]
0x57457ae065a0	j = t4
0x57457ae06630	output j
0x57457ae06690	output L1
0x57457ae067d0	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
vararray arr1[1D]
vararray arr2[2D]
vararray arr3[3D]
input i
arr1[24] = i
var t0
t0 = arr1[24]
var t1
t1 = t0 + 6
arr2[504] = t1
var t2
t2 = arr2[504]
var t3
t3 = t2 + 6
arr3[15144] = t3
ifz 0 goto L2
  succ: B3 B2 

[B2]
output L1
  succ: B3 

[B3]
label L2
var t4
t4 = arr3[15144]
j = t4
output j
output L1
end
  succ: 
