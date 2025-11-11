
# tac list

0x6067013117a0	var i
0x606701312420	label main
0x606701312460	begin
0x6067013118e0	var a
0x6067013119b0	var b
0x606701311a80	var c
0x606701311ae0	input a
0x606701311b40	input b
0x606701311cd0	var t0
0x606701311d10	actual a
0x606701311d50	actual b
0x606701311de0	t0 = call max
0x606701311e50	c = t0
0x606701311ee0	output c
0x606701311fb0	output L1
0x606701312190	var t1
0x6067013121d0	t1 = i + 1
0x606701312210	i = t1
0x6067013122a0	output i
0x606701312370	output L2
0x6067013124a0	end
0x606701312c70	label max
0x606701312cb0	begin
0x606701312570	formal x
0x606701312620	formal y
0x606701312770	var t2
0x6067013127b0	t2 = (x > y)
0x606701312af0	ifz t2 goto L3
0x606701312860	i = x
0x606701312b30	goto L4
0x6067013129e0	label L3
0x606701312910	i = y
0x606701312ab0	label L4
0x606701312bc0	return i
0x606701312cf0	end

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
