
# tac list

0x59c1fd644930	label main
0x59c1fd644970	begin
0x59c1fd642810	var i
0x59c1fd6428e0	var j
0x59c1fd642b00	vararray arr1[1D]
0x59c1fd642b60	input i
0x59c1fd642c80	j = 0
0x59c1fd643ab0	label L1
0x59c1fd642dd0	var t0
0x59c1fd642e10	t0 = (j < 10)
0x59c1fd643b70	ifz t0 goto L3
0x59c1fd643160	var t1
0x59c1fd643620	t1 = j * 4
0x59c1fd643690	arr1[t1] = i
0x59c1fd643800	var t2
0x59c1fd643840	t2 = i + 1
0x59c1fd643880	i = t2
0x59c1fd6439f0	var t3
0x59c1fd643a30	t3 = j + 1
0x59c1fd643a70	j = t3
0x59c1fd643af0	label L2
0x59c1fd643bb0	goto L1
0x59c1fd643b30	label L3
0x59c1fd643de0	ifz 0 goto L5
0x59c1fd643cd0	output L4
0x59c1fd643da0	label L5
0x59c1fd644720	label L6
0x59c1fd643f30	var t4
0x59c1fd643f70	t4 = (j > 0)
0x59c1fd6447e0	ifz t4 goto L8
0x59c1fd644290	var t5
0x59c1fd6442d0	t5 = j - 1
0x59c1fd644310	j = t5
0x59c1fd644480	var t6
0x59c1fd6444c0	t6 = j * 4
0x59c1fd6445a0	var t7
0x59c1fd6445e0	t7 = arr1[t6]
0x59c1fd644650	i = t7
0x59c1fd6446e0	output i
0x59c1fd644760	label L7
0x59c1fd644820	goto L6
0x59c1fd6447a0	label L8
0x59c1fd644880	output L4
0x59c1fd6449b0	end

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
