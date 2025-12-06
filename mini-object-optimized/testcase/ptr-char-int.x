
# tac list

0x5e4dfb40d980	label main
0x5e4dfb40d9c0	begin
0x5e4dfb40c810	var a
0x5e4dfb40c8e0	var pa
0x5e4dfb40c9b0	var b
0x5e4dfb40ca80	var i
0x5e4dfb40cb50	var pi
0x5e4dfb40cc20	var j
0x5e4dfb40cc80	input a
0x5e4dfb40cce0	input i
0x5e4dfb40cfa0	ifz 0 goto L2
0x5e4dfb40ce70	output L1
0x5e4dfb40cf60	label L2
0x5e4dfb40d000	pa = &a
0x5e4dfb40d080	pi = &i
0x5e4dfb40d100	b = *pa
0x5e4dfb40d180	j = *pi
0x5e4dfb40d340	ifz 0 goto L3
0x5e4dfb40d230	output L1
0x5e4dfb40d300	label L3
0x5e4dfb40d7e0	output b
0x5e4dfb40d870	output j
0x5e4dfb40d8d0	output L1
0x5e4dfb40da00	end

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
