
# tac list

0x61f6d97e5af0	label main
0x61f6d97e5b30	begin
0x61f6d97e4830	var a
0x61f6d97e4910	var pa
0x61f6d97e49f0	var b
0x61f6d97e4ad0	var c
0x61f6d97e4bb0	var d
0x61f6d97e4c90	var ptr
0x61f6d97e4cf0	input d
0x61f6d97e4e20	c = 'c'
0x61f6d97e4f50	b = 'b'
0x61f6d97e4fb0	input a
0x61f6d97e5280	ifz 0 goto L2
0x61f6d97e5160	output L1
0x61f6d97e5240	label L2
0x61f6d97e5310	output a
0x61f6d97e53a0	output b
0x61f6d97e5430	output c
0x61f6d97e54c0	output d
0x61f6d97e5520	output L1
0x61f6d97e55a0	pa = &a
0x61f6d97e56d0	*pa = 'A'
0x61f6d97e5760	output a
0x61f6d97e5810	ptr = pa
0x61f6d97e5940	*ptr = 'B'
0x61f6d97e59d0	output a
0x61f6d97e5a30	output L1
0x61f6d97e5b70	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var pa
var b
var c
var d
var ptr
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
pa = &a
*pa = 'A'
output a
ptr = pa
*ptr = 'B'
output a
output L1
end
  succ: 
