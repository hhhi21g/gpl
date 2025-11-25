
# tac list

0x5e46c4e19630	label main
0x5e46c4e19670	begin
0x5e46c4e18830	var a
0x5e46c4e18910	var pa
0x5e46c4e189f0	var b
0x5e46c4e18ad0	var i
0x5e46c4e18bb0	var pi
0x5e46c4e18c90	var j
0x5e46c4e18cf0	input a
0x5e46c4e18d50	input i
0x5e46c4e19040	ifz 0 goto L2
0x5e46c4e18f00	output L1
0x5e46c4e19000	label L2
0x5e46c4e190a0	pa = &a
0x5e46c4e19120	pi = &i
0x5e46c4e191a0	b = *pa
0x5e46c4e19220	j = *pi
0x5e46c4e193f0	ifz 0 goto L3
0x5e46c4e192d0	output L1
0x5e46c4e193b0	label L3
0x5e46c4e19480	output b
0x5e46c4e19510	output j
0x5e46c4e19570	output L1
0x5e46c4e196b0	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var pa
var b
var i
var pi
var j
input a
input i
ifz 0 goto L2
  succ: B3 B2 

[B2]
output L1
  succ: B3 

[B3]
label L2
pa = &a
pi = &i
b = *pa
j = *pi
ifz 0 goto L3
  succ: B5 B4 

[B4]
output L1
  succ: B5 

[B5]
label L3
output b
output j
output L1
end
  succ: 
