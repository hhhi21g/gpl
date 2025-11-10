
# tac list

0x562cec1527a0	var i
0x562cec1533f0	label main
0x562cec153430	begin
0x562cec1528e0	var a
0x562cec1529b0	var b
0x562cec152a80	var c
0x562cec152ae0	input a
0x562cec152b40	input b
0x562cec152cd0	var t0
0x562cec152d10	actual a
0x562cec152d50	actual b
0x562cec152db0	t0 = call max
0x562cec152e20	c = t0
0x562cec152eb0	output c
0x562cec152f80	output L1
0x562cec153160	var t1
0x562cec1531a0	t1 = i + 1
0x562cec1531e0	i = t1
0x562cec153270	output i
0x562cec153340	output L2
0x562cec153470	end
0x562cec153c90	label max
0x562cec153cd0	begin
0x562cec153590	formal x
0x562cec153640	formal y
0x562cec153790	var t2
0x562cec1537d0	t2 = (x > y)
0x562cec153b10	ifz t2 goto L3
0x562cec153880	i = x
0x562cec153b50	goto L4
0x562cec153a00	label L3
0x562cec153930	i = y
0x562cec153ad0	label L4
0x562cec153be0	return i
0x562cec153d10	end

[B0]
var i
label main
  succ: B1 

[B1]
begin
var a
var b
var c
input a
input b
var t0
actual a
actual b
t0 = call max
c = t0
output c
output L1
var t1
t1 = i + 1
i = t1
output i
output L2
end
  succ: 

[B2]
label max
  succ: B3 

[B3]
begin
formal x
formal y
var t2
t2 = (x > y)
ifz t2 goto L3
  succ: B5 B4 

[B4]
i = x
goto L4
  succ: B6 

[B5]
label L3
i = y
  succ: B6 

[B6]
label L4
return i
  succ: 

[B7]
end
  succ: 
