
# tac list

0x5da0182e98c0	label main
0x5da0182e9900	begin
0x5da0182e7830	var i
0x5da0182e7910	var j
0x5da0182e7970	input j
0x5da0182e7aa0	i = 0
0x5da0182e89e0	label L1
0x5da0182e8010	var t0
0x5da0182e8050	t0 = (i < j)
0x5da0182e8aa0	ifz t0 goto L3
0x5da0182e8690	var t2
0x5da0182e86d0	t2 = (i > 10)
0x5da0182e8910	ifz t2 goto L5
0x5da0182e87b0	output L4
0x5da0182e87f0	goto L3
0x5da0182e88d0	label L5
0x5da0182e89a0	output i
0x5da0182e8a20	label L2
0x5da0182e8250	var t1
0x5da0182e8290	t1 = i + 1
0x5da0182e82d0	i = t1
0x5da0182e8ae0	goto L1
0x5da0182e8a60	label L3
0x5da0182e8bc0	output L6
0x5da0182e8c70	i = 0
0x5da0182e96a0	label L7
0x5da0182e8dd0	var t3
0x5da0182e8e10	t3 = (i < j)
0x5da0182e9760	ifz t3 goto L9
0x5da0182e9350	var t5
0x5da0182e9390	t5 = (i == 10)
0x5da0182e95d0	ifz t5 goto L11
0x5da0182e9470	output L10
0x5da0182e94b0	goto L8
0x5da0182e9590	label L11
0x5da0182e9660	output i
0x5da0182e96e0	label L8
0x5da0182e8f90	var t4
0x5da0182e8fd0	t4 = i + 1
0x5da0182e9010	i = t4
0x5da0182e97a0	goto L7
0x5da0182e9720	label L9
0x5da0182e9800	output L6
0x5da0182e9940	end

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
