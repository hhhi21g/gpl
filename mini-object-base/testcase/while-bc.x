
# tac list

0x61865f867400	label main
0x61865f867440	begin
0x61865f865830	var i
0x61865f865910	var j
0x61865f865a40	i = 0
0x61865f865aa0	input j
0x61865f8665d0	label L1
0x61865f865c00	var t0
0x61865f865c40	t0 = (i < j)
0x61865f866690	ifz t0 goto L3
0x61865f865eb0	output i
0x61865f8660b0	var t1
0x61865f8660f0	t1 = i + 1
0x61865f866130	i = t1
0x61865f866310	var t2
0x61865f866350	t2 = (i > 10)
0x61865f866590	ifz t2 goto L5
0x61865f866430	output L4
0x61865f866470	goto L3
0x61865f866550	label L5
0x61865f866610	label L2
0x61865f8666d0	goto L1
0x61865f866650	label L3
0x61865f8667b0	output L6
0x61865f8671e0	label L7
0x61865f866910	var t3
0x61865f866950	t3 = (i < j)
0x61865f8672a0	ifz t3 goto L9
0x61865f866bc0	output i
0x61865f866d40	var t4
0x61865f866d80	t4 = i + 1
0x61865f866dc0	i = t4
0x61865f866f20	var t5
0x61865f866f60	t5 = (i == 10)
0x61865f8671a0	ifz t5 goto L11
0x61865f867040	output L10
0x61865f867080	goto L8
0x61865f867160	label L11
0x61865f867220	label L8
0x61865f8672e0	goto L7
0x61865f867260	label L9
0x61865f867340	output L6
0x61865f867480	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
i = 0
input j
  succ: B2 

[B2]
label L1
var t0
t0 = (i < j)
ifz t0 goto L3
  succ: B6 B3 

[B3]
output i
var t1
t1 = i + 1
i = t1
var t2
t2 = (i > 10)
ifz t2 goto L5
  succ: B5 B4 

[B4]
output L4
goto L3
  succ: B6 

[B5]
label L5
label L2
goto L1
  succ: B2 

[B6]
label L3
output L6
  succ: B7 

[B7]
label L7
var t3
t3 = (i < j)
ifz t3 goto L9
  succ: B12 B8 

[B8]
output i
var t4
t4 = i + 1
i = t4
var t5
t5 = (i == 10)
ifz t5 goto L11
  succ: B10 B9 

[B9]
output L10
goto L8
  succ: B11 

[B10]
label L11
  succ: B11 

[B11]
label L8
goto L7
  succ: B7 

[B12]
label L9
output L6
end
  succ: 
