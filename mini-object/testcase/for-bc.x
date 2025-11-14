
# tac list

0x5c2dc96cf8c0	label main
0x5c2dc96cf900	begin
0x5c2dc96cd830	var i
0x5c2dc96cd910	var j
0x5c2dc96cd970	input j
0x5c2dc96cdaa0	i = 0
0x5c2dc96ce9e0	label L1
0x5c2dc96ce010	var t0
0x5c2dc96ce050	t0 = (i < j)
0x5c2dc96ceaa0	ifz t0 goto L3
0x5c2dc96ce690	var t2
0x5c2dc96ce6d0	t2 = (i > 10)
0x5c2dc96ce910	ifz t2 goto L5
0x5c2dc96ce7b0	output L4
0x5c2dc96ce7f0	goto L3
0x5c2dc96ce8d0	label L5
0x5c2dc96ce9a0	output i
0x5c2dc96cea20	label L2
0x5c2dc96ce250	var t1
0x5c2dc96ce290	t1 = i + 1
0x5c2dc96ce2d0	i = t1
0x5c2dc96ceae0	goto L1
0x5c2dc96cea60	label L3
0x5c2dc96cebc0	output L6
0x5c2dc96cec70	i = 0
0x5c2dc96cf6a0	label L7
0x5c2dc96cedd0	var t3
0x5c2dc96cee10	t3 = (i < j)
0x5c2dc96cf760	ifz t3 goto L9
0x5c2dc96cf350	var t5
0x5c2dc96cf390	t5 = (i == 10)
0x5c2dc96cf5d0	ifz t5 goto L11
0x5c2dc96cf470	output L10
0x5c2dc96cf4b0	goto L8
0x5c2dc96cf590	label L11
0x5c2dc96cf660	output i
0x5c2dc96cf6e0	label L8
0x5c2dc96cef90	var t4
0x5c2dc96cefd0	t4 = i + 1
0x5c2dc96cf010	i = t4
0x5c2dc96cf7a0	goto L7
0x5c2dc96cf720	label L9
0x5c2dc96cf800	output L6
0x5c2dc96cf940	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
input j
i = 0
  succ: B2 

[B2]
label L1
var t0
t0 = (i < j)
ifz t0 goto L3
  succ: B6 B3 

[B3]
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
output i
label L2
var t1
t1 = i + 1
i = t1
goto L1
  succ: B2 

[B6]
label L3
output L6
i = 0
  succ: B7 

[B7]
label L7
var t3
t3 = (i < j)
ifz t3 goto L9
  succ: B12 B8 

[B8]
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
output i
  succ: B11 

[B11]
label L8
var t4
t4 = i + 1
i = t4
goto L7
  succ: B7 

[B12]
label L9
output L6
end
  succ: 
