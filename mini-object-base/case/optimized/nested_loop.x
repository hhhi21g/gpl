
# tac list

0x5571de54a0e0	label main
0x5571de54a120	begin
0x5571de548840	var i
0x5571de548920	var j
0x5571de548a00	var k
0x5571de548b30	k = 0
0x5571de549f20	label L1
0x5571de548d10	var t0
0x5571de548d50	t0 = (k < 10)
0x5571de549fe0	ifz t0 goto L3
0x5571de548fe0	i = 0
0x5571de549be0	label L4
0x5571de549140	var t1
0x5571de549180	t1 = (i < 10)
0x5571de549ca0	ifz t1 goto L6
0x5571de549560	var t2
0x5571de5495a0	t2 = 2 * i
0x5571de549730	var t3
0x5571de549770	t3 = t2 + 9
0x5571de5497b0	j = t3
0x5571de549840	output j
0x5571de549920	output L7
0x5571de549b20	var t4
0x5571de549b60	t4 = i + 1
0x5571de549ba0	i = t4
0x5571de549c20	label L5
0x5571de549ce0	goto L4
0x5571de549c60	label L6
0x5571de549e60	var t5
0x5571de549ea0	t5 = k + 1
0x5571de549ee0	k = t5
0x5571de549f60	label L2
0x5571de54a020	goto L1
0x5571de549fa0	label L3
0x5571de54a160	end

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
