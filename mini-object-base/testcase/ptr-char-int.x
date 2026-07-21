
# tac list

0x650cfb5c9630	label main
0x650cfb5c9670	begin
0x650cfb5c8830	var a
0x650cfb5c8910	var pa
0x650cfb5c89f0	var b
0x650cfb5c8ad0	var i
0x650cfb5c8bb0	var pi
0x650cfb5c8c90	var j
0x650cfb5c8cf0	input a
0x650cfb5c8d50	input i
0x650cfb5c9040	ifz 0 goto L2
0x650cfb5c8f00	output L1
0x650cfb5c9000	label L2
0x650cfb5c90a0	pa = &a
0x650cfb5c9120	pi = &i
0x650cfb5c91a0	b = *pa
0x650cfb5c9220	j = *pi
0x650cfb5c93f0	ifz 0 goto L3
0x650cfb5c92d0	output L1
0x650cfb5c93b0	label L3
0x650cfb5c9480	output b
0x650cfb5c9510	output j
0x650cfb5c9570	output L1
0x650cfb5c96b0	end

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
