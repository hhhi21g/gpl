
# tac list

0x64aba1d352d0	label main
0x64aba1d35310	begin
0x64aba1d347f0	var i
0x64aba1d348b0	var j
0x64aba1d34970	var k
0x64aba1d349d0	input i
0x64aba1d34a30	input j
0x64aba1d34b70	var t0
0x64aba1d34bb0	t0 = (i == j)
0x64aba1d34ef0	ifz t0 goto L3
0x64aba1d34c70	output L1
0x64aba1d34f30	goto L4
0x64aba1d34df0	label L3
0x64aba1d34d30	output L2
0x64aba1d34eb0	label L4
0x64aba1d35090	var t1
0x64aba1d350d0	t1 = i + j
0x64aba1d35110	k = t1
0x64aba1d35170	output k
0x64aba1d35230	output L5
0x64aba1d35350	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
var k
input i
input j
var t0
t0 = (i == j)
ifz t0 goto L3
  succ: B3 B2 

[B2]
output L1
goto L4
  succ: B4 

[B3]
label L3
output L2
  succ: B4 

[B4]
label L4
var t1
t1 = i + j
k = t1
output k
output L5
end
  succ: 
