
# tac list

0x637fa6b0cac0	label main
0x637fa6b0cb00	begin
0x637fa6b0a830	var i
0x637fa6b0a910	var j
0x637fa6b0ab60	vararray arr1[1D]
0x637fa6b0abc0	input i
0x637fa6b0acf0	j = 0
0x637fa6b0bba0	label L1
0x637fa6b0b260	var t0
0x637fa6b0b2a0	t0 = (j < 10)
0x637fa6b0bc60	ifz t0 goto L3
0x637fa6b0b630	var t1
0x637fa6b0b6f0	t1 = j * 4
0x637fa6b0b760	arr1[t1] = i
0x637fa6b0b8e0	var t2
0x637fa6b0b920	t2 = i + 1
0x637fa6b0b960	i = t2
0x637fa6b0bae0	var t3
0x637fa6b0bb20	t3 = j + 1
0x637fa6b0bb60	j = t3
0x637fa6b0bbe0	label L2
0x637fa6b0bca0	goto L1
0x637fa6b0bc20	label L3
0x637fa6b0bef0	ifz 0 goto L5
0x637fa6b0bdd0	output L4
0x637fa6b0beb0	label L5
0x637fa6b0c8a0	label L6
0x637fa6b0c050	var t4
0x637fa6b0c090	t4 = (j > 0)
0x637fa6b0c960	ifz t4 goto L8
0x637fa6b0c3f0	var t5
0x637fa6b0c430	t5 = j - 1
0x637fa6b0c470	j = t5
0x637fa6b0c5f0	var t6
0x637fa6b0c630	t6 = j * 4
0x637fa6b0c720	var t7
0x637fa6b0c760	t7 = arr1[t6]
0x637fa6b0c7d0	i = t7
0x637fa6b0c860	output i
0x637fa6b0c8e0	label L7
0x637fa6b0c9a0	goto L6
0x637fa6b0c920	label L8
0x637fa6b0ca00	output L4
0x637fa6b0cb40	end

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
