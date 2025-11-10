
# tac list

0x63d7bcc3f520	label main
0x63d7bcc3f560	begin
0x63d7bcc3d810	var i
0x63d7bcc3d8e0	var j
0x63d7bcc3db00	vararray arr1[1D]
0x63d7bcc3db60	input i
0x63d7bcc3dc80	j = 0
0x63d7bcc3e6a0	label L1
0x63d7bcc3ddd0	var t0
0x63d7bcc3de10	t0 = (j < 10)
0x63d7bcc3e760	ifz t0 goto L3
0x63d7bcc3e160	var t1
0x63d7bcc3e210	t1 = j * 4
0x63d7bcc3e280	arr1[t1] = i
0x63d7bcc3e3f0	var t2
0x63d7bcc3e430	t2 = i + 1
0x63d7bcc3e470	i = t2
0x63d7bcc3e5e0	var t3
0x63d7bcc3e620	t3 = j + 1
0x63d7bcc3e660	j = t3
0x63d7bcc3e6e0	label L2
0x63d7bcc3e7a0	goto L1
0x63d7bcc3e720	label L3
0x63d7bcc3e9d0	ifz 0 goto L5
0x63d7bcc3e8c0	output L4
0x63d7bcc3e990	label L5
0x63d7bcc3f310	label L6
0x63d7bcc3eb20	var t4
0x63d7bcc3eb60	t4 = (j > 0)
0x63d7bcc3f3d0	ifz t4 goto L8
0x63d7bcc3ee80	var t5
0x63d7bcc3eec0	t5 = j - 1
0x63d7bcc3ef00	j = t5
0x63d7bcc3f070	var t6
0x63d7bcc3f0b0	t6 = j * 4
0x63d7bcc3f190	var t7
0x63d7bcc3f1d0	t7 = arr1[t6]
0x63d7bcc3f240	i = t7
0x63d7bcc3f2d0	output i
0x63d7bcc3f350	label L7
0x63d7bcc3f410	goto L6
0x63d7bcc3f390	label L8
0x63d7bcc3f470	output L4
0x63d7bcc3f5a0	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
vararray arr1[1D]
input i
j = 0
  succ: B2 

[B2]
label L1
var t0
t0 = (j < 10)
ifz t0 goto L3
  succ: B4 B3 

[B3]
var t1
t1 = j * 4
arr1[t1] = i
var t2
t2 = i + 1
i = t2
var t3
t3 = j + 1
j = t3
label L2
goto L1
  succ: B2 

[B4]
label L3
ifz 0 goto L5
  succ: B6 B5 

[B5]
output L4
  succ: B6 

[B6]
label L5
  succ: B7 

[B7]
label L6
var t4
t4 = (j > 0)
ifz t4 goto L8
  succ: B9 B8 

[B8]
var t5
t5 = j - 1
j = t5
var t6
t6 = j * 4
var t7
t7 = arr1[t6]
i = t7
output i
label L7
goto L6
  succ: B7 

[B9]
label L8
output L4
end
  succ: 
