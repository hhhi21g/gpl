
# tac list

0x55a584ff26b0	label main
0x55a584ff26f0	begin
0x55a584ff0830	var i
0x55a584ff0910	var j
0x55a584ff0b60	vararray arr1[1D]
0x55a584ff0bc0	input i
0x55a584ff0cf0	j = 0
0x55a584ff1790	label L1
0x55a584ff0e50	var t0
0x55a584ff0e90	t0 = (j < 10)
0x55a584ff1850	ifz t0 goto L3
0x55a584ff1220	var t1
0x55a584ff12e0	t1 = j * 4
0x55a584ff1350	arr1[t1] = i
0x55a584ff14d0	var t2
0x55a584ff1510	t2 = i + 1
0x55a584ff1550	i = t2
0x55a584ff16d0	var t3
0x55a584ff1710	t3 = j + 1
0x55a584ff1750	j = t3
0x55a584ff17d0	label L2
0x55a584ff1890	goto L1
0x55a584ff1810	label L3
0x55a584ff1ae0	ifz 0 goto L5
0x55a584ff19c0	output L4
0x55a584ff1aa0	label L5
0x55a584ff2490	label L6
0x55a584ff1c40	var t4
0x55a584ff1c80	t4 = (j > 0)
0x55a584ff2550	ifz t4 goto L8
0x55a584ff1fe0	var t5
0x55a584ff2020	t5 = j - 1
0x55a584ff2060	j = t5
0x55a584ff21e0	var t6
0x55a584ff2220	t6 = j * 4
0x55a584ff2310	var t7
0x55a584ff2350	t7 = arr1[t6]
0x55a584ff23c0	i = t7
0x55a584ff2450	output i
0x55a584ff24d0	label L7
0x55a584ff2590	goto L6
0x55a584ff2510	label L8
0x55a584ff25f0	output L4
0x55a584ff2730	end

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
