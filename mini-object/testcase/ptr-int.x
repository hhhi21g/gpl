
# tac list

0x55cec6a07a20	label main
0x55cec6a07a60	begin
0x55cec6a067f0	var a
0x55cec6a068b0	var pa
0x55cec6a06970	var b
0x55cec6a06a30	var c
0x55cec6a06af0	var d
0x55cec6a06bb0	var ptr
0x55cec6a06c10	input a
0x55cec6a06dd0	var t0
0x55cec6a06e10	t0 = a + 10
0x55cec6a06e50	b = t0
0x55cec6a07010	var t1
0x55cec6a07050	t1 = b - 20
0x55cec6a07090	c = t1
0x55cec6a07250	var t2
0x55cec6a07290	t2 = c * 30
0x55cec6a072d0	d = t2
0x55cec6a07330	output a
0x55cec6a07390	output b
0x55cec6a073f0	output c
0x55cec6a07450	output d
0x55cec6a07510	output L1
0x55cec6a07590	pa = &a
0x55cec6a076a0	*pa = 111
0x55cec6a07700	output a
0x55cec6a077b0	ptr = pa
0x55cec6a078c0	*ptr = 222
0x55cec6a07920	output a
0x55cec6a07980	output L1
0x55cec6a07aa0	end
