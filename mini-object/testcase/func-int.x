
# tac list

0x55ad5b5467a0	var i
0x55ad5b547830	label main
0x55ad5b547870	begin
0x55ad5b5468e0	var a
0x55ad5b5469b0	var b
0x55ad5b546a80	var c
0x55ad5b546ae0	input a
0x55ad5b546b40	input b
0x55ad5b5470e0	var t0
0x55ad5b547120	actual a
0x55ad5b547160	actual b
0x55ad5b5471f0	t0 = call max
0x55ad5b547260	c = t0
0x55ad5b5472f0	output c
0x55ad5b5473c0	output L1
0x55ad5b5475a0	var t1
0x55ad5b5475e0	t1 = i + 1
0x55ad5b547620	i = t1
0x55ad5b5476b0	output i
0x55ad5b547780	output L2
0x55ad5b5478b0	end
0x55ad5b548080	label max
0x55ad5b5480c0	begin
0x55ad5b547980	formal x
0x55ad5b547a30	formal y
0x55ad5b547b80	var t2
0x55ad5b547bc0	t2 = (x > y)
0x55ad5b547f00	ifz t2 goto L3
0x55ad5b547c70	i = x
0x55ad5b547f40	goto L4
0x55ad5b547df0	label L3
0x55ad5b547d20	i = y
0x55ad5b547ec0	label L4
0x55ad5b547fd0	return i
0x55ad5b548100	end

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
