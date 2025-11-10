
# tac list

0x602d9ae32520	label main
0x602d9ae32560	begin
0x602d9ae30810	var i
0x602d9ae308e0	var j
0x602d9ae30b00	vararray arr1[1D]
0x602d9ae30b60	input i
0x602d9ae30c80	j = 0
0x602d9ae316a0	label L1
0x602d9ae30dd0	var t0
0x602d9ae30e10	t0 = (j < 10)
0x602d9ae31760	ifz t0 goto L3
0x602d9ae31160	var t1
0x602d9ae31210	t1 = j * 4
0x602d9ae31280	arr1[t1] = i
0x602d9ae313f0	var t2
0x602d9ae31430	t2 = i + 1
0x602d9ae31470	i = t2
0x602d9ae315e0	var t3
0x602d9ae31620	t3 = j + 1
0x602d9ae31660	j = t3
0x602d9ae316e0	label L2
0x602d9ae317a0	goto L1
0x602d9ae31720	label L3
0x602d9ae319d0	ifz 0 goto L5
0x602d9ae318c0	output L4
0x602d9ae31990	label L5
0x602d9ae32310	label L6
0x602d9ae31b20	var t4
0x602d9ae31b60	t4 = (j > 0)
0x602d9ae323d0	ifz t4 goto L8
0x602d9ae31e80	var t5
0x602d9ae31ec0	t5 = j - 1
0x602d9ae31f00	j = t5
0x602d9ae32070	var t6
0x602d9ae320b0	t6 = j * 4
0x602d9ae32190	var t7
0x602d9ae321d0	t7 = arr1[t6]
0x602d9ae32240	i = t7
0x602d9ae322d0	output i
0x602d9ae32350	label L7
0x602d9ae32410	goto L6
0x602d9ae32390	label L8
0x602d9ae32470	output L4
0x602d9ae325a0	end

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
