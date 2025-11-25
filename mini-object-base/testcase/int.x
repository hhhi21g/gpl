
# tac list

0x630ebdca2690	label main
0x630ebdca26d0	begin
0x630ebdca1830	var a
0x630ebdca1910	var b
0x630ebdca19f0	var c
0x630ebdca1ad0	var d
0x630ebdca1b30	input a
0x630ebdca1d30	var t0
0x630ebdca1d70	t0 = a + 10
0x630ebdca1db0	b = t0
0x630ebdca1fb0	var t1
0x630ebdca1ff0	t1 = b - 20
0x630ebdca2030	c = t1
0x630ebdca2230	var t2
0x630ebdca2270	t2 = c * 30
0x630ebdca22b0	d = t2
0x630ebdca2340	output a
0x630ebdca23d0	output b
0x630ebdca2460	output c
0x630ebdca24f0	output d
0x630ebdca25d0	output L1
0x630ebdca2710	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var b
var c
var d
input a
var t0
t0 = a + 10
b = t0
var t1
t1 = b - 20
c = t1
var t2
t2 = c * 30
d = t2
output a
output b
output c
output d
output L1
end
  succ: 
