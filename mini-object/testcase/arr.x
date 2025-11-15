
# tac list

0x6399e0380b60	label main
0x6399e0380ba0	begin
0x6399e037e830	var i
0x6399e037e910	var j
0x6399e037eb60	vararray arr1[1D]
0x6399e037ee00	vararray arr2[2D]
0x6399e037f0f0	vararray arr3[3D]
0x6399e037f150	input i
0x6399e037f7c0	arr1[24] = i
0x6399e037fa70	var t0
0x6399e037fab0	t0 = arr1[24]
0x6399e037fbf0	var t1
0x6399e037fc30	t1 = t0 + 6
0x6399e037fd20	arr2[504] = t1
0x6399e03800d0	var t2
0x6399e0380110	t2 = arr2[504]
0x6399e0380250	var t3
0x6399e0380290	t3 = t2 + 6
0x6399e0380380	arr3[15144] = t3
0x6399e0380670	ifz 0 goto L2
0x6399e0380530	output L1
0x6399e0380630	label L2
0x6399e0380900	var t4
0x6399e0380940	t4 = arr3[15144]
0x6399e03809b0	j = t4
0x6399e0380a40	output j
0x6399e0380aa0	output L1
0x6399e0380be0	end

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
