
# tac list

0x621ff5e3bed0	label main
0x621ff5e3bf10	begin
0x621ff5e3a830	var i
0x621ff5e3a910	var j
0x621ff5e3a9f0	var k
0x621ff5e3aad0	var l
0x621ff5e3abb0	var a
0x621ff5e3ac90	var b
0x621ff5e3ad70	var c
0x621ff5e3ae50	var d
0x621ff5e3aeb0	input d
0x621ff5e3afe0	c = 'c'
0x621ff5e3b110	b = 'b'
0x621ff5e3b170	input a
0x621ff5e3b440	ifz 0 goto L2
0x621ff5e3b320	output L1
0x621ff5e3b400	label L2
0x621ff5e3b4d0	output a
0x621ff5e3b560	output b
0x621ff5e3b5f0	output c
0x621ff5e3b680	output d
0x621ff5e3b6e0	output L1
0x621ff5e3b790	i = a
0x621ff5e3b840	j = b
0x621ff5e3b8f0	k = c
0x621ff5e3b9a0	l = d
0x621ff5e3bb70	ifz 0 goto L3
0x621ff5e3ba50	output L1
0x621ff5e3bb30	label L3
0x621ff5e3bc00	output i
0x621ff5e3bc90	output j
0x621ff5e3bd20	output k
0x621ff5e3bdb0	output l
0x621ff5e3be10	output L1
0x621ff5e3bf50	end

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
