
# tac list

0x5da523faf770	var i
0x5da523faffe0	label main
0x5da523fb0020	begin
0x5da523faf870	var a
0x5da523faf910	var b
0x5da523faf9b0	var c
0x5da523fafa10	input a
0x5da523fafa70	input b
0x5da523fafbf0	var t0
0x5da523fafc30	actual b
0x5da523fafc70	actual a
0x5da523fafcd0	t0 = call max
0x5da523fafd40	c = t0
0x5da523fafda0	output c
0x5da523fafe40	output L1
0x5da523fafea0	output i
0x5da523faff40	output L2
0x5da523fb0060	end
0x5da523fb0810	label max
0x5da523fb0850	begin
0x5da523fb0160	formal x
0x5da523fb0200	formal y
0x5da523fb0340	var t1
0x5da523fb0380	t1 = (x > y)
0x5da523fb06a0	ifz t1 goto L3
0x5da523fb0430	i = x
0x5da523fb06e0	goto L4
0x5da523fb05a0	label L3
0x5da523fb04e0	i = y
0x5da523fb0660	label L4
0x5da523fb0770	return i
0x5da523fb0890	end
