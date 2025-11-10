
# tac list

<<<<<<< HEAD
0x61420a2f85c0	label main
0x61420a2f8600	begin
0x61420a2f6810	var i
0x61420a2f68e0	var j
0x61420a2f6b00	vararray arr1[1D]
0x61420a2f6d70	vararray arr2[2D]
0x61420a2f7030	vararray arr3[3D]
0x61420a2f7090	input i
0x61420a2f72d0	arr1[24] = i
0x61420a2f7570	var t0
0x61420a2f75b0	t0 = arr1[24]
0x61420a2f76e0	var t1
0x61420a2f7720	t1 = t0 + 6
0x61420a2f7800	arr2[504] = t1
0x61420a2f7ba0	var t2
0x61420a2f7be0	t2 = arr2[504]
0x61420a2f7d10	var t3
0x61420a2f7d50	t3 = t2 + 6
0x61420a2f7e30	arr3[15144] = t3
0x61420a2f80f0	ifz 0 goto L2
0x61420a2f7fc0	output L1
0x61420a2f80b0	label L2
0x61420a2f8370	var t4
0x61420a2f83b0	t4 = arr3[15144]
0x61420a2f8420	j = t4
0x61420a2f84b0	output j
0x61420a2f8510	output L1
0x61420a2f8640	end
=======
0x60171fdc35c0	label main
0x60171fdc3600	begin
0x60171fdc1810	var i
0x60171fdc18e0	var j
0x60171fdc1b00	vararray arr1[1D]
0x60171fdc1d70	vararray arr2[2D]
0x60171fdc2030	vararray arr3[3D]
0x60171fdc2090	input i
0x60171fdc22d0	arr1[24] = i
0x60171fdc2570	var t0
0x60171fdc25b0	t0 = arr1[24]
0x60171fdc26e0	var t1
0x60171fdc2720	t1 = t0 + 6
0x60171fdc2800	arr2[504] = t1
0x60171fdc2ba0	var t2
0x60171fdc2be0	t2 = arr2[504]
0x60171fdc2d10	var t3
0x60171fdc2d50	t3 = t2 + 6
0x60171fdc2e30	arr3[15144] = t3
0x60171fdc30f0	ifz 0 goto L2
0x60171fdc2fc0	output L1
0x60171fdc30b0	label L2
0x60171fdc3370	var t4
0x60171fdc33b0	t4 = arr3[15144]
0x60171fdc3420	j = t4
0x60171fdc34b0	output j
0x60171fdc3510	output L1
0x60171fdc3640	end
>>>>>>> parent of 9ae14e6 (tac优化完毕，未优化obj)

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
vararray arr1[1D]
vararray arr2[2D]
vararray arr3[3D]
input i
arr1[24] = i
var t0
t0 = arr1[24]
var t1
t1 = t0 + 6
arr2[504] = t1
var t2
t2 = arr2[504]
var t3
t3 = t2 + 6
arr3[15144] = t3
ifz 0 goto L2
  succ: B3 B2 

[B2]
output L1
  succ: B3 

[B3]
label L2
var t4
t4 = arr3[15144]
j = t4
output j
output L1
end
  succ: 
