
# tac list

0x5870dfbdf0e0	label main
0x5870dfbdf120	begin
0x5870dfbdd840	var i
0x5870dfbdd920	var j
0x5870dfbdda00	var k
0x5870dfbddb30	k = 0
0x5870dfbdef20	label L1
0x5870dfbddd10	var t0
0x5870dfbddd50	t0 = (k < 10)
0x5870dfbdefe0	ifz t0 goto L3
0x5870dfbddfe0	i = 0
0x5870dfbdebe0	label L4
0x5870dfbde140	var t1
0x5870dfbde180	t1 = (i < 10)
0x5870dfbdeca0	ifz t1 goto L6
0x5870dfbde560	var t2
0x5870dfbde5a0	t2 = 2 * i
0x5870dfbde730	var t3
0x5870dfbde770	t3 = t2 + 9
0x5870dfbde7b0	j = t3
0x5870dfbde840	output j
0x5870dfbde920	output L7
0x5870dfbdeb20	var t4
0x5870dfbdeb60	t4 = i + 1
0x5870dfbdeba0	i = t4
0x5870dfbdec20	label L5
0x5870dfbdece0	goto L4
0x5870dfbdec60	label L6
0x5870dfbdee60	var t5
0x5870dfbdeea0	t5 = k + 1
0x5870dfbdeee0	k = t5
0x5870dfbdef60	label L2
0x5870dfbdf020	goto L1
0x5870dfbdefa0	label L3
0x5870dfbdf160	end

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
