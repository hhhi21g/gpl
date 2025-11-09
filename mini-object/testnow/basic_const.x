
# tac list

0x59cc2fe1f2b0	label main
0x59cc2fe1f2f0	begin
0x59cc2fe1e7f0	var a
0x59cc2fe1e8b0	var b
0x59cc2fe1e970	var c
0x59cc2fe1eb90	var t0
0x59cc2fe1ebd0	t0 = 3 + 4
0x59cc2fe1ec10	a = t0
0x59cc2fe1edd0	var t1
0x59cc2fe1ee10	t1 = a * 2
0x59cc2fe1ee50	b = t1
0x59cc2fe1efb0	var t2
0x59cc2fe1eff0	t2 = b - a
0x59cc2fe1f030	c = t2
0x59cc2fe1f090	output a
0x59cc2fe1f0f0	output b
0x59cc2fe1f150	output c
0x59cc2fe1f210	output L1
0x59cc2fe1f330	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var b
var c
var t0
t0 = 3 + 4
a = t0
var t1
t1 = a * 2
b = t1
var t2
t2 = b - a
c = t2
output a
output b
output c
output L1
end
  succ: 
