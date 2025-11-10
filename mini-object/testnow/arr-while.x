
# tac list

0x621b6c4f0520	label main
0x621b6c4f0560	begin
0x621b6c4ee810	var i
0x621b6c4ee8e0	var j
0x621b6c4eeb00	vararray arr1[1D]
0x621b6c4eeb60	input i
0x621b6c4eec80	j = 0
0x621b6c4ef6a0	label L1
0x621b6c4eedd0	var t0
0x621b6c4eee10	t0 = (j < 10)
0x621b6c4ef760	ifz t0 goto L3
0x621b6c4ef160	var t1
0x621b6c4ef210	t1 = j * 4
0x621b6c4ef280	arr1[t1] = i
0x621b6c4ef3f0	var t2
0x621b6c4ef430	t2 = i + 1
0x621b6c4ef470	i = t2
0x621b6c4ef5e0	var t3
0x621b6c4ef620	t3 = j + 1
0x621b6c4ef660	j = t3
0x621b6c4ef6e0	label L2
0x621b6c4ef7a0	goto L1
0x621b6c4ef720	label L3
0x621b6c4ef9d0	ifz 0 goto L5
0x621b6c4ef8c0	output L4
0x621b6c4ef990	label L5
0x621b6c4f0310	label L6
0x621b6c4efb20	var t4
0x621b6c4efb60	t4 = (j > 0)
0x621b6c4f03d0	ifz t4 goto L8
0x621b6c4efe80	var t5
0x621b6c4efec0	t5 = j - 1
0x621b6c4eff00	j = t5
0x621b6c4f0070	var t6
0x621b6c4f00b0	t6 = j * 4
0x621b6c4f0190	var t7
0x621b6c4f01d0	t7 = arr1[t6]
0x621b6c4f0240	i = t7
0x621b6c4f02d0	output i
0x621b6c4f0350	label L7
0x621b6c4f0410	goto L6
0x621b6c4f0390	label L8
0x621b6c4f0470	output L4
0x621b6c4f05a0	end

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
