
# tac list

0x61b8e598d0e0	label main
0x61b8e598d120	begin
0x61b8e598b840	var i
0x61b8e598b920	var j
0x61b8e598ba00	var k
0x61b8e598bb30	k = 0
0x61b8e598cf20	label L1
0x61b8e598bd10	var t0
0x61b8e598bd50	t0 = (k < 10)
0x61b8e598cfe0	ifz t0 goto L3
0x61b8e598bfe0	i = 0
0x61b8e598cbe0	label L4
0x61b8e598c140	var t1
0x61b8e598c180	t1 = (i < 10)
0x61b8e598cca0	ifz t1 goto L6
0x61b8e598c560	var t2
0x61b8e598c5a0	t2 = 2 * i
0x61b8e598c730	var t3
0x61b8e598c770	t3 = t2 + 9
0x61b8e598c7b0	j = t3
0x61b8e598c840	output j
0x61b8e598c920	output L7
0x61b8e598cb20	var t4
0x61b8e598cb60	t4 = i + 1
0x61b8e598cba0	i = t4
0x61b8e598cc20	label L5
0x61b8e598cce0	goto L4
0x61b8e598cc60	label L6
0x61b8e598ce60	var t5
0x61b8e598cea0	t5 = k + 1
0x61b8e598cee0	k = t5
0x61b8e598cf60	label L2
0x61b8e598d020	goto L1
0x61b8e598cfa0	label L3
0x61b8e598d160	end

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
