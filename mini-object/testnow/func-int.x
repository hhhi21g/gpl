
# tac list

0x564801cc67a0	var i
0x564801cc73f0	label main
0x564801cc7430	begin
0x564801cc68e0	var a
0x564801cc69b0	var b
0x564801cc6a80	var c
0x564801cc6ae0	input a
0x564801cc6b40	input b
0x564801cc6cd0	var t0
0x564801cc6d10	actual a
0x564801cc6d50	actual b
0x564801cc6db0	t0 = call max
0x564801cc6e20	c = t0
0x564801cc6eb0	output c
0x564801cc6f80	output L1
0x564801cc7160	var t1
0x564801cc71a0	t1 = i + 1
0x564801cc71e0	i = t1
0x564801cc7270	output i
0x564801cc7340	output L2
0x564801cc7470	end
0x564801cc7c90	label max
0x564801cc7cd0	begin
0x564801cc7590	formal x
0x564801cc7640	formal y
0x564801cc7790	var t2
0x564801cc77d0	t2 = (x > y)
0x564801cc7b10	ifz t2 goto L3
0x564801cc7880	i = x
0x564801cc7b50	goto L4
0x564801cc7a00	label L3
0x564801cc7930	i = y
0x564801cc7ad0	label L4
0x564801cc7be0	return i
0x564801cc7d10	end

[B0]
var i
label main
  succ: B1 

[B1]
begin
var a
var b
var c
input a
input b
var t0
actual a
actual b
t0 = call max
c = t0
output c
output L1
var t1
t1 = i + 1
i = t1
output i
output L2
end
  succ: 

[B2]
label max
  succ: B3 

[B3]
begin
formal x
formal y
var t2
t2 = (x > y)
ifz t2 goto L3
  succ: B5 B4 

[B4]
i = x
goto L4
  succ: B6 

[B5]
label L3
i = y
  succ: B6 

[B6]
label L4
return i
  succ: 

[B7]
end
  succ: 
