
# tac list

0x5c559af14400	label main
0x5c559af14440	begin
0x5c559af12830	var i
0x5c559af12910	var j
0x5c559af12970	input i
0x5c559af14160	var t5
0x5c559af141a0	t5 = (i != 1)
0x5c559af141e0	ifz t5 goto L2
0x5c559af14020	var t4
0x5c559af14060	t4 = (i != 2)
0x5c559af140a0	ifz t4 goto L3
0x5c559af13ee0	var t3
0x5c559af13f20	t3 = (i != 3)
0x5c559af13f60	ifz t3 goto L4
0x5c559af14220	goto L6
0x5c559af13be0	label L4
0x5c559af139b0	var t2
0x5c559af139f0	t2 = i + 3
0x5c559af13a30	j = t2
0x5c559af13ac0	output j
0x5c559af13b00	goto L1
0x5c559af13750	label L3
0x5c559af13520	var t1
0x5c559af13560	t1 = i + 2
0x5c559af135a0	j = t1
0x5c559af13630	output j
0x5c559af13670	goto L1
0x5c559af132c0	label L2
0x5c559af13090	var t0
0x5c559af130d0	t0 = i + 1
0x5c559af13110	j = t0
0x5c559af131a0	output j
0x5c559af131e0	goto L1
0x5c559af13e20	label L6
0x5c559af13d00	output L5
0x5c559af13d40	goto L1
0x5c559af14260	label L1
0x5c559af14340	output L7
0x5c559af14480	end

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
