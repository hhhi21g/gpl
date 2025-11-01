
# tac list

0x555d6fe3e210	label main
0x555d6fe3e250	begin
0x555d6fe3d7d0	var i
0x555d6fe3d870	var j
0x555d6fe3d910	var k
0x555d6fe3d970	input i
0x555d6fe3d9d0	input j
0x555d6fe3db10	var t0
0x555d6fe3db50	t0 = (i == j)
0x555d6fe3de50	ifz t0 goto L3
0x555d6fe3dbf0	output L1
0x555d6fe3de90	goto L4
0x555d6fe3dd50	label L3
0x555d6fe3dc90	output L2
0x555d6fe3de10	label L4
0x555d6fe3dff0	var t1
0x555d6fe3e030	t1 = i + j
0x555d6fe3e070	k = t1
0x555d6fe3e0d0	output k
0x555d6fe3e170	output L5
0x555d6fe3e290	end
