
# tac list

0x59fe707d3930	label main
0x59fe707d3970	begin
0x59fe707d1810	var i
0x59fe707d18e0	var j
0x59fe707d1b00	vararray arr1[1D]
0x59fe707d1b60	input i
0x59fe707d2ab0	label L1
0x59fe707d1dd0	var t0
0x59fe707d2b70	ifz 1 goto L3
0x59fe707d2160	var t1
0x59fe707d2690	arr1[0] = i
0x59fe707d2800	var t2
0x59fe707d2840	t2 = i + 1
0x59fe707d2880	i = t2
0x59fe707d29f0	var t3
0x59fe707d2af0	label L2
0x59fe707d2bb0	goto L1
0x59fe707d2b30	label L3
0x59fe707d2de0	ifz 0 goto L5
0x59fe707d2cd0	output L4
0x59fe707d2da0	label L5
0x59fe707d3720	label L6
0x59fe707d2f30	var t4
0x59fe707d37e0	ifz 1 goto L8
0x59fe707d3290	var t5
0x59fe707d3480	var t6
0x59fe707d35a0	var t7
0x59fe707d35e0	t7 = arr1[0]
0x59fe707d3650	i = t7
0x59fe707d36e0	output i
0x59fe707d3760	label L7
0x59fe707d3820	goto L6
0x59fe707d37a0	label L8
0x59fe707d3880	output L4
0x59fe707d39b0	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
vararray arr1[1D]
input i
  succ: B2 

[B2]
label L1
var t0
ifz 1 goto L3
  succ: B4 B3 

[B3]
var t1
arr1[0] = i
var t2
t2 = i + 1
i = t2
var t3
label L2
goto L1
  succ: B2 

[B4]
label L3
ifz 0 goto L5
  succ: B6 B5 

[B5]
output L4
  succ: B6 

[B6]
label L5
  succ: B7 

[B7]
label L6
var t4
ifz 1 goto L8
  succ: B9 B8 

[B8]
var t5
var t6
var t7
t7 = arr1[0]
i = t7
output i
label L7
goto L6
  succ: B7 

[B9]
label L8
output L4
end
  succ: 
