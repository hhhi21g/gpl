
# tac list

0x5a1b22908ed0	label main
0x5a1b22908f10	begin
0x5a1b22907830	var i
0x5a1b22907910	var j
0x5a1b229079f0	var k
0x5a1b22907ad0	var l
0x5a1b22907bb0	var a
0x5a1b22907c90	var b
0x5a1b22907d70	var c
0x5a1b22907e50	var d
0x5a1b22907eb0	input d
0x5a1b22907fe0	c = 'c'
0x5a1b22908110	b = 'b'
0x5a1b22908170	input a
0x5a1b22908440	ifz 0 goto L2
0x5a1b22908320	output L1
0x5a1b22908400	label L2
0x5a1b229084d0	output a
0x5a1b22908560	output b
0x5a1b229085f0	output c
0x5a1b22908680	output d
0x5a1b229086e0	output L1
0x5a1b22908790	i = a
0x5a1b22908840	j = 'b'
0x5a1b229088f0	k = 'c'
0x5a1b229089a0	l = d
0x5a1b22908b70	ifz 0 goto L3
0x5a1b22908a50	output L1
0x5a1b22908b30	label L3
0x5a1b22908c00	output i
0x5a1b22908c90	output j
0x5a1b22908d20	output k
0x5a1b22908db0	output l
0x5a1b22908e10	output L1
0x5a1b22908f50	end

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
j = 'b'
k = 'c'
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
