
# tac list

0x64c60b9aa770	var i
0x64c60b9ab220	label main
0x64c60b9ab260	begin
0x64c60b9aa870	var a
0x64c60b9aa910	var b
0x64c60b9aa9b0	var c
0x64c60b9aaa10	input a
0x64c60b9aaa70	input b
0x64c60b9aabf0	var t0
0x64c60b9aac30	actual b
0x64c60b9aac70	actual a
0x64c60b9aacd0	t0 = call max
0x64c60b9aad40	c = t0
0x64c60b9aada0	output c
0x64c60b9aae40	output L1
0x64c60b9ab000	var t1
0x64c60b9ab040	t1 = i + 1
0x64c60b9ab080	i = t1
0x64c60b9ab0e0	output i
0x64c60b9ab180	output L2
0x64c60b9ab2a0	end
0x64c60b9aba50	label max
0x64c60b9aba90	begin
0x64c60b9ab3a0	formal x
0x64c60b9ab440	formal y
0x64c60b9ab580	var t2
0x64c60b9ab5c0	t2 = (x > y)
0x64c60b9ab8e0	ifz t2 goto L3
0x64c60b9ab670	i = x
0x64c60b9ab920	goto L4
0x64c60b9ab7e0	label L3
0x64c60b9ab720	i = y
0x64c60b9ab8a0	label L4
0x64c60b9ab9b0	return i
0x64c60b9abad0	end
