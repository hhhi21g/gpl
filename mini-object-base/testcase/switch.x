
# tac list

0x5d13ef0adff0	label main
0x5d13ef0ae030	begin
0x5d13ef0ac830	var i
0x5d13ef0ac910	var j
0x5d13ef0ac970	input i
0x5d13ef0add50	var t5
0x5d13ef0add90	t5 = (i != 1)
0x5d13ef0addd0	ifz t5 goto L2
0x5d13ef0adc10	var t4
0x5d13ef0adc50	t4 = (i != 2)
0x5d13ef0adc90	ifz t4 goto L3
0x5d13ef0adad0	var t3
0x5d13ef0adb10	t3 = (i != 3)
0x5d13ef0adb50	ifz t3 goto L4
0x5d13ef0ade10	goto L6
0x5d13ef0ad7d0	label L4
0x5d13ef0ad5a0	var t2
0x5d13ef0ad5e0	t2 = i + 3
0x5d13ef0ad620	j = t2
0x5d13ef0ad6b0	output j
0x5d13ef0ad6f0	goto L1
0x5d13ef0ad340	label L3
0x5d13ef0ad110	var t1
0x5d13ef0ad150	t1 = i + 2
0x5d13ef0ad190	j = t1
0x5d13ef0ad220	output j
0x5d13ef0ad260	goto L1
0x5d13ef0aceb0	label L2
0x5d13ef0acc80	var t0
0x5d13ef0accc0	t0 = i + 1
0x5d13ef0acd00	j = t0
0x5d13ef0acd90	output j
0x5d13ef0acdd0	goto L1
0x5d13ef0ada10	label L6
0x5d13ef0ad8f0	output L5
0x5d13ef0ad930	goto L1
0x5d13ef0ade50	label L1
0x5d13ef0adf30	output L7
0x5d13ef0ae070	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
input i
var t5
t5 = (i != 1)
ifz t5 goto L2
  succ: B7 B2 

[B2]
var t4
t4 = (i != 2)
ifz t4 goto L3
  succ: B6 B3 

[B3]
var t3
t3 = (i != 3)
ifz t3 goto L4
  succ: B5 B4 

[B4]
goto L6
  succ: B8 

[B5]
label L4
var t2
t2 = i + 3
j = t2
output j
goto L1
  succ: B9 

[B6]
label L3
var t1
t1 = i + 2
j = t1
output j
goto L1
  succ: B9 

[B7]
label L2
var t0
t0 = i + 1
j = t0
output j
goto L1
  succ: B9 

[B8]
label L6
output L5
goto L1
  succ: B9 

[B9]
label L1
output L7
end
  succ: 
