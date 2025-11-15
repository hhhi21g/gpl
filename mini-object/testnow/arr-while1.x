
# tac list

0x6412a4a6f9c0	label main
0x6412a4a6fa00	begin
0x6412a4a6d830	var i
0x6412a4a6d910	var j
0x6412a4a6db60	vararray arr1[1D]
0x6412a4a6dc90	i = 42
0x6412a4a6ddc0	j = 0
0x6412a4a6ec70	label L1
0x6412a4a6e330	var t0
0x6412a4a6e370	t0 = (j < 10)
0x6412a4a6ed30	ifz t0 goto L3
0x6412a4a6e700	var t1
0x6412a4a6e7c0	t1 = j * 4
0x6412a4a6e830	arr1[t1] = i
0x6412a4a6e9b0	var t2
0x6412a4a6e9f0	t2 = i + 1
0x6412a4a6ea30	i = t2
0x6412a4a6ebb0	var t3
0x6412a4a6ebf0	t3 = j + 1
0x6412a4a6ec30	j = t3
0x6412a4a6ecb0	label L2
0x6412a4a6ed70	goto L1
0x6412a4a6ecf0	label L3
0x6412a4a6f720	label L4
0x6412a4a6eed0	var t4
0x6412a4a6ef10	t4 = (j > 0)
0x6412a4a6f7e0	ifz t4 goto L6
0x6412a4a6f270	var t5
0x6412a4a6f2b0	t5 = j - 1
0x6412a4a6f2f0	j = t5
0x6412a4a6f470	var t6
0x6412a4a6f4b0	t6 = j * 4
0x6412a4a6f5a0	var t7
0x6412a4a6f5e0	t7 = arr1[t6]
0x6412a4a6f650	i = t7
0x6412a4a6f6e0	output i
0x6412a4a6f760	label L5
0x6412a4a6f820	goto L4
0x6412a4a6f7a0	label L6
0x6412a4a6f900	output L7
0x6412a4a6fa40	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
vararray arr1[1D]
i = 42
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
  succ: B5 

[B5]
label L4
var t4
t4 = (j > 0)
ifz t4 goto L6
  succ: B7 B6 

[B6]
var t5
t5 = j - 1
j = t5
var t6
t6 = j * 4
var t7
t7 = arr1[t6]
i = t7
output i
label L5
goto L4
  succ: B5 

[B7]
label L6
output L7
end
  succ: 
