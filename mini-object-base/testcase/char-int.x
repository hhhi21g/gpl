
# tac list

0x55c58358bed0	label main
0x55c58358bf10	begin
0x55c58358a830	var i
0x55c58358a910	var j
0x55c58358a9f0	var k
0x55c58358aad0	var l
0x55c58358abb0	var a
0x55c58358ac90	var b
0x55c58358ad70	var c
0x55c58358ae50	var d
0x55c58358aeb0	input d
0x55c58358afe0	c = 'c'
0x55c58358b110	b = 'b'
0x55c58358b170	input a
0x55c58358b440	ifz 0 goto L2
0x55c58358b320	output L1
0x55c58358b400	label L2
0x55c58358b4d0	output a
0x55c58358b560	output b
0x55c58358b5f0	output c
0x55c58358b680	output d
0x55c58358b6e0	output L1
0x55c58358b790	i = a
0x55c58358b840	j = b
0x55c58358b8f0	k = c
0x55c58358b9a0	l = d
0x55c58358bb70	ifz 0 goto L3
0x55c58358ba50	output L1
0x55c58358bb30	label L3
0x55c58358bc00	output i
0x55c58358bc90	output j
0x55c58358bd20	output k
0x55c58358bdb0	output l
0x55c58358be10	output L1
0x55c58358bf50	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
var k
var l
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
i = a
j = b
k = c
l = d
ifz 0 goto L3
  succ: B5 B4 

[B4]
output L1
  succ: B5 

[B5]
label L3
output i
output j
output k
output l
output L1
end
  succ: 
