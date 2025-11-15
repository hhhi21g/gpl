
# tac list

0x5f32c1a89ac0	label main
0x5f32c1a89b00	begin
0x5f32c1a87830	var i
0x5f32c1a87910	var j
0x5f32c1a87b60	vararray arr1[1D]
0x5f32c1a87bc0	input i
0x5f32c1a87cf0	j = 0
0x5f32c1a88ba0	label L1
0x5f32c1a88260	var t0
0x5f32c1a882a0	t0 = (j < 10)
0x5f32c1a88c60	ifz t0 goto L3
0x5f32c1a88630	var t1
0x5f32c1a886f0	t1 = j * 4
0x5f32c1a88760	arr1[t1] = i
0x5f32c1a888e0	var t2
0x5f32c1a88920	t2 = i + 1
0x5f32c1a88960	i = t2
0x5f32c1a88ae0	var t3
0x5f32c1a88b20	t3 = j + 1
0x5f32c1a88b60	j = t3
0x5f32c1a88be0	label L2
0x5f32c1a88ca0	goto L1
0x5f32c1a88c20	label L3
0x5f32c1a88ef0	ifz 0 goto L5
0x5f32c1a88dd0	output L4
0x5f32c1a88eb0	label L5
0x5f32c1a898a0	label L6
0x5f32c1a89050	var t4
0x5f32c1a89090	t4 = (j > 0)
0x5f32c1a89960	ifz t4 goto L8
0x5f32c1a893f0	var t5
0x5f32c1a89430	t5 = j - 1
0x5f32c1a89470	j = t5
0x5f32c1a895f0	var t6
0x5f32c1a89630	t6 = j * 4
0x5f32c1a89720	var t7
0x5f32c1a89760	t7 = arr1[t6]
0x5f32c1a897d0	i = t7
0x5f32c1a89860	output i
0x5f32c1a898e0	label L7
0x5f32c1a899a0	goto L6
0x5f32c1a89920	label L8
0x5f32c1a89a00	output L4
0x5f32c1a89b40	end

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
