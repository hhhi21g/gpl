
# tac list

0x64a9ae8a7eb0	label main
0x64a9ae8a7ef0	begin
0x64a9ae8a57d0	var a
0x64a9ae8a5870	var b
0x64a9ae8a5910	var c
0x64a9ae8a59b0	var d
0x64a9ae8a5a50	var e
0x64a9ae8a5af0	var i
0x64a9ae8a5b90	var j
0x64a9ae8a5c30	var k
0x64a9ae8a5c90	input a
0x64a9ae8a5cf0	input b
0x64a9ae8a5d50	input c
0x64a9ae8a5e60	j = 5
0x64a9ae8a7ab0	label L4
0x64a9ae8a6000	var t0
0x64a9ae8a6040	t0 = (j > 0)
0x64a9ae8a7bf0	ifz t0 goto L5
0x64a9ae8a60a0	output j
0x64a9ae8a61b0	i = 9
0x64a9ae8a7630	label L1
0x64a9ae8a62f0	var t1
0x64a9ae8a6330	t1 = (i > 0)
0x64a9ae8a7770	ifz t1 goto L2
0x64a9ae8a6390	output i
0x64a9ae8a6540	var t2
0x64a9ae8a6580	t2 = b * c
0x64a9ae8a6620	var t3
0x64a9ae8a6660	t3 = a + t2
0x64a9ae8a67a0	var t4
0x64a9ae8a67e0	t4 = a + c
0x64a9ae8a68d0	var t5
0x64a9ae8a6910	t5 = t4 / b
0x64a9ae8a69b0	var t6
0x64a9ae8a69f0	t6 = t3 - t5
0x64a9ae8a6ae0	var t7
0x64a9ae8a6b20	t7 = t6 + 9
0x64a9ae8a6b60	d = t7
0x64a9ae8a6d10	var t8
0x64a9ae8a6d50	t8 = b * c
0x64a9ae8a6df0	var t9
0x64a9ae8a6e30	t9 = a + t8
0x64a9ae8a6f70	var t10
0x64a9ae8a6fb0	t10 = c - a
0x64a9ae8a70a0	var t11
0x64a9ae8a70e0	t11 = t10 / b
0x64a9ae8a7180	var t12
0x64a9ae8a71c0	t12 = t9 - t11
0x64a9ae8a72b0	var t13
0x64a9ae8a72f0	t13 = t12 + 9
0x64a9ae8a7330	e = t13
0x64a9ae8a74f0	var t14
0x64a9ae8a7530	t14 = i - 1
0x64a9ae8a7570	i = t14
0x64a9ae8a7670	goto L1
0x64a9ae8a7730	label L2
0x64a9ae8a78d0	var t15
0x64a9ae8a7910	t15 = j - 1
0x64a9ae8a7950	j = t15
0x64a9ae8a79f0	output L3
0x64a9ae8a7af0	goto L4
0x64a9ae8a7bb0	label L5
0x64a9ae8a7c90	output L6
0x64a9ae8a7cf0	output d
0x64a9ae8a7d50	output L3
0x64a9ae8a7db0	output e
0x64a9ae8a7e10	output L6
0x64a9ae8a7f30	end
