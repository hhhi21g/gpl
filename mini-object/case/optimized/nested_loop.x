
# tac list

0x58481f6dc4f0	label main
0x58481f6dc530	begin
0x58481f6da840	var i
0x58481f6da920	var j
0x58481f6daa00	var k
0x58481f6dab30	k = 0
0x58481f6dc330	label L1
0x58481f6dad10	var t0
0x58481f6dad50	t0 = (k < 10)
0x58481f6dc3f0	ifz t0 goto L3
0x58481f6dafe0	i = 0
0x58481f6dbff0	label L4
0x58481f6db140	var t1
0x58481f6db180	t1 = (i < 10)
0x58481f6dc0b0	ifz t1 goto L6
0x58481f6db560	var t2
0x58481f6db5a0	t2 = 2 * i
0x58481f6db730	var t3
0x58481f6db770	t3 = t2 + 9
0x58481f6db7b0	j = t3
0x58481f6db840	output j
0x58481f6db920	output L7
0x58481f6dbb20	var t4
0x58481f6dbb60	t4 = i + 1
0x58481f6dbba0	i = t4
0x58481f6dc030	label L5
0x58481f6dc0f0	goto L4
0x58481f6dc070	label L6
0x58481f6dc270	var t5
0x58481f6dc2b0	t5 = k + 1
0x58481f6dc2f0	k = t5
0x58481f6dc370	label L2
0x58481f6dc430	goto L1
0x58481f6dc3b0	label L3
0x58481f6dc570	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
var k
k = 0
  succ: B2 

[B2]
label L1
var t0
t0 = (k < 10)
ifz t0 goto L3
  succ: B7 B3 

[B3]
i = 0
  succ: B4 

[B4]
label L4
var t1
t1 = (i < 10)
ifz t1 goto L6
  succ: B6 B5 

[B5]
var t2
t2 = 2 * i
var t3
t3 = t2 + 9
j = t3
output j
output L7
var t4
t4 = i + 1
i = t4
label L5
goto L4
  succ: B4 

[B6]
label L6
var t5
t5 = k + 1
k = t5
label L2
goto L1
  succ: B2 

[B7]
label L3
end
  succ: 
