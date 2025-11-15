
# tac list

0x5649bf99f8c0	label main
0x5649bf99f900	begin
0x5649bf99d830	var i
0x5649bf99d910	var j
0x5649bf99d970	input j
0x5649bf99daa0	i = 0
0x5649bf99e9e0	label L1
0x5649bf99e010	var t0
0x5649bf99e050	t0 = (i < j)
0x5649bf99eaa0	ifz t0 goto L3
0x5649bf99e690	var t2
0x5649bf99e6d0	t2 = (i > 10)
0x5649bf99e910	ifz t2 goto L5
0x5649bf99e7b0	output L4
0x5649bf99e7f0	goto L3
0x5649bf99e8d0	label L5
0x5649bf99e9a0	output i
0x5649bf99ea20	label L2
0x5649bf99e250	var t1
0x5649bf99e290	t1 = i + 1
0x5649bf99e2d0	i = t1
0x5649bf99eae0	goto L1
0x5649bf99ea60	label L3
0x5649bf99ebc0	output L6
0x5649bf99ec70	i = 0
0x5649bf99f6a0	label L7
0x5649bf99edd0	var t3
0x5649bf99ee10	t3 = (i < j)
0x5649bf99f760	ifz t3 goto L9
0x5649bf99f350	var t5
0x5649bf99f390	t5 = (i == 10)
0x5649bf99f5d0	ifz t5 goto L11
0x5649bf99f470	output L10
0x5649bf99f4b0	goto L8
0x5649bf99f590	label L11
0x5649bf99f660	output i
0x5649bf99f6e0	label L8
0x5649bf99ef90	var t4
0x5649bf99efd0	t4 = i + 1
0x5649bf99f010	i = t4
0x5649bf99f7a0	goto L7
0x5649bf99f720	label L9
0x5649bf99f800	output L6
0x5649bf99f940	end

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
