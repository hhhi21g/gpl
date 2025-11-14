
# tac list

0x64f046656740	label main
0x64f046656780	begin
0x64f046654810	var i
0x64f0466548e0	var j
0x64f046654940	input j
0x64f046654a60	i = 0
0x64f046655900	label L1
0x64f046654fc0	var t0
0x64f046655000	t0 = (i < j)
0x64f0466559c0	ifz t0 goto L3
0x64f0466555d0	var t2
0x64f046655610	t2 = (i > 10)
0x64f046655830	ifz t2 goto L5
0x64f0466556e0	output L4
0x64f046655720	goto L3
0x64f0466557f0	label L5
0x64f0466558c0	output i
0x64f046655940	label L2
0x64f0466551e0	var t1
0x64f046655220	t1 = i + 1
0x64f046655260	i = t1
0x64f046655a00	goto L1
0x64f046655980	label L3
0x64f046655ad0	output L6
0x64f046655b80	i = 0
0x64f046656530	label L7
0x64f046655cd0	var t3
0x64f046655d10	t3 = (i < j)
0x64f0466565f0	ifz t3 goto L9
0x64f046656200	var t5
0x64f046656240	t5 = (i == 10)
0x64f046656460	ifz t5 goto L11
0x64f046656310	output L10
0x64f046656350	goto L8
0x64f046656420	label L11
0x64f0466564f0	output i
0x64f046656570	label L8
0x64f046655e80	var t4
0x64f046655ec0	t4 = i + 1
0x64f046655f00	i = t4
0x64f046656630	goto L7
0x64f0466565b0	label L9
0x64f046656690	output L6
0x64f0466567c0	end

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
