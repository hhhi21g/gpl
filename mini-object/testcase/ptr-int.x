
# tac list

0x60d3d4e3da20	label main
0x60d3d4e3da60	begin
0x60d3d4e3c7f0	var a
0x60d3d4e3c8b0	var pa
0x60d3d4e3c970	var b
0x60d3d4e3ca30	var c
0x60d3d4e3caf0	var d
0x60d3d4e3cbb0	var ptr
0x60d3d4e3cc10	input a
0x60d3d4e3cdd0	var t0
0x60d3d4e3ce10	t0 = a + 10
0x60d3d4e3ce50	b = t0
0x60d3d4e3d010	var t1
0x60d3d4e3d050	t1 = b - 20
0x60d3d4e3d090	c = t1
0x60d3d4e3d250	var t2
0x60d3d4e3d290	t2 = c * 30
0x60d3d4e3d2d0	d = t2
0x60d3d4e3d330	output a
0x60d3d4e3d390	output b
0x60d3d4e3d3f0	output c
0x60d3d4e3d450	output d
0x60d3d4e3d510	output L1
0x60d3d4e3d590	pa = &a
0x60d3d4e3d6a0	*pa = 111
0x60d3d4e3d700	output a
0x60d3d4e3d7b0	ptr = pa
0x60d3d4e3d8c0	*ptr = 222
0x60d3d4e3d920	output a
0x60d3d4e3d980	output L1
0x60d3d4e3daa0	end
