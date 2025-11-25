
# tac list

0x63e4a464fac0	label main
0x63e4a464fb00	begin
0x63e4a464d830	var i
0x63e4a464d910	var j
0x63e4a464db60	vararray arr1[1D]
0x63e4a464dbc0	input i
0x63e4a464dcf0	j = 0
0x63e4a464eba0	label L1
0x63e4a464de50	var t0
0x63e4a464de90	t0 = (j < 10)
0x63e4a464ec60	ifz t0 goto L3
0x63e4a464e220	var t1
0x63e4a464e2e0	t1 = j * 4
0x63e4a464e350	arr1[t1] = i
0x63e4a464e4d0	var t2
0x63e4a464e510	t2 = i + 1
0x63e4a464e550	i = t2
0x63e4a464e6d0	var t3
0x63e4a464e710	t3 = j + 1
0x63e4a464e750	j = t3
0x63e4a464ebe0	label L2
0x63e4a464eca0	goto L1
0x63e4a464ec20	label L3
0x63e4a464eef0	ifz 0 goto L5
0x63e4a464edd0	output L4
0x63e4a464eeb0	label L5
0x63e4a464f8a0	label L6
0x63e4a464f050	var t4
0x63e4a464f090	t4 = (j > 0)
0x63e4a464f960	ifz t4 goto L8
0x63e4a464f3f0	var t5
0x63e4a464f430	t5 = j - 1
0x63e4a464f470	j = t5
0x63e4a464f5f0	var t6
0x63e4a464f630	t6 = j * 4
0x63e4a464f720	var t7
0x63e4a464f760	t7 = arr1[t6]
0x63e4a464f7d0	i = t7
0x63e4a464f860	output i
0x63e4a464f8e0	label L7
0x63e4a464f9a0	goto L6
0x63e4a464f920	label L8
0x63e4a464fa00	output L4
0x63e4a464fb40	end

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
