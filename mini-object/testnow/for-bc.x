
# tac list

0x624980694150	label main
0x624980694190	begin
0x6249806927f0	var i
0x6249806928b0	var j
0x624980692910	input j
0x624980692a20	i = 0
0x6249806933e0	label L1
0x624980692b60	var t0
0x624980692ba0	t0 = (i < j)
0x6249806934a0	ifz t0 goto L3
0x624980693100	var t2
0x624980693140	t2 = (i > 10)
0x624980693340	ifz t2 goto L5
0x624980693200	output L4
0x624980693240	goto L3
0x624980693300	label L5
0x6249806933a0	output i
0x624980693420	label L2
0x624980692d60	var t1
0x624980692da0	t1 = i + 1
0x624980692de0	i = t1
0x6249806934e0	goto L1
0x624980693460	label L3
0x6249806935a0	output L6
0x624980693650	i = 0
0x624980693f50	label L7
0x624980693790	var t3
0x6249806937d0	t3 = (i < j)
0x624980694010	ifz t3 goto L9
0x624980693c70	var t5
0x624980693cb0	t5 = (i == 10)
0x624980693eb0	ifz t5 goto L11
0x624980693d70	output L10
0x624980693db0	goto L8
0x624980693e70	label L11
0x624980693f10	output i
0x624980693f90	label L8
0x624980693930	var t4
0x624980693970	t4 = i + 1
0x6249806939b0	i = t4
0x624980694050	goto L7
0x624980693fd0	label L9
0x6249806940b0	output L6
0x6249806941d0	end

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
