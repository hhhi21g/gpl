
# tac list

0x6224a8e880e0	label main
0x6224a8e88120	begin
0x6224a8e86840	var i
0x6224a8e86920	var j
0x6224a8e86a00	var k
0x6224a8e86b30	k = 0
0x6224a8e87f20	label L1
0x6224a8e86d10	var t0
0x6224a8e86d50	t0 = (k < 10)
0x6224a8e87fe0	ifz t0 goto L3
0x6224a8e86fe0	i = 0
0x6224a8e87be0	label L4
0x6224a8e87140	var t1
0x6224a8e87180	t1 = (i < 10)
0x6224a8e87ca0	ifz t1 goto L6
0x6224a8e87560	var t2
0x6224a8e875a0	t2 = 2 * i
0x6224a8e87730	var t3
0x6224a8e87770	t3 = t2 + 9
0x6224a8e877b0	j = t3
0x6224a8e87840	output j
0x6224a8e87920	output L7
0x6224a8e87b20	var t4
0x6224a8e87b60	t4 = i + 1
0x6224a8e87ba0	i = t4
0x6224a8e87c20	label L5
0x6224a8e87ce0	goto L4
0x6224a8e87c60	label L6
0x6224a8e87e60	var t5
0x6224a8e87ea0	t5 = k + 1
0x6224a8e87ee0	k = t5
0x6224a8e87f60	label L2
0x6224a8e88020	goto L1
0x6224a8e87fa0	label L3
0x6224a8e88160	end

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
