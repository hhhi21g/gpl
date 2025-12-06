
# tac list

0x5caba5611ff0	label main
0x5caba5612030	begin
0x5caba56117d0	var i
0x5caba5611830	input i
0x5caba5611d70	label L1
0x5caba56119d0	var t0
0x5caba5611a10	t0 = (i < 10)
0x5caba5611eb0	ifz t0 goto L2
0x5caba5611a70	output i
0x5caba5611c30	var t1
0x5caba5611c70	t1 = i + 1
0x5caba5611cb0	i = t1
0x5caba5611db0	goto L1
0x5caba5611e70	label L2
0x5caba5611f50	output L3
0x5caba5612070	end
