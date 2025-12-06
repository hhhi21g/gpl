
# tac list

0x605f340f99d0	label main
0x605f340f9a10	begin
0x605f340f8830	var a
0x605f340f8910	var b
0x605f340f89f0	var c
0x605f340f8ad0	var x
0x605f340f8bb0	var y
0x605f340f8c10	input a
0x605f340f8c70	input b
0x605f340f8df0	var t0
0x605f340f8e30	t0 = a + b
0x605f340f8e70	c = t0
0x605f340f9050	var t1
0x605f340f9090	t1 = (a > 0)
0x605f340f9690	ifz t1 goto L1
0x605f340f9210	var t2
0x605f340f9250	t2 = t0
0x605f340f9290	x = t2
0x605f340f96d0	goto L2
0x605f340f9570	label L1
0x605f340f9410	var t3
0x605f340f9450	t3 = t0
0x605f340f9490	y = t3
0x605f340f9650	label L2
0x605f340f9760	output c
0x605f340f97f0	output x
0x605f340f9880	output y
0x605f340f9910	return 0
0x605f340f9a50	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var b
var c
var x
var y
input a
input b
var t0
t0 = a + b
c = t0
var t1
t1 = (a > 0)
ifz t1 goto L1
  succ: B3 B2 

[B2]
var t2
t2 = t0
x = t2
goto L2
  succ: B4 

[B3]
label L1
var t3
t3 = t0
y = t3
  succ: B4 

[B4]
label L2
output c
output x
output y
return 0
  succ: 

[B5]
end
  succ: 
