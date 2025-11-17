
# tac list

0x5b91e40ed320	label main
0x5b91e40ed360	begin
0x5b91e40eb830	var a
0x5b91e40eb910	var b
0x5b91e40eb9f0	var c
0x5b91e40ebad0	var d
0x5b91e40ebbb0	var e
0x5b91e40ebc10	input a
0x5b91e40ebc70	input b
0x5b91e40ebdf0	var t0
0x5b91e40ebe30	t0 = a + b
0x5b91e40ebe70	c = t0
0x5b91e40ebff0	var t1
0x5b91e40ec070	d = t0
0x5b91e40ec1f0	var t2
0x5b91e40ec230	t2 = c * d
0x5b91e40ec270	e = t2
0x5b91e40ec320	c = c
0x5b91e40ec3d0	d = e
0x5b91e40ec5b0	var t3
0x5b91e40ec5f0	t3 = (a > 0)
0x5b91e40ed070	ifz t3 goto L1
0x5b91e40ec770	var t4
0x5b91e40ec7b0	t4 = a + b
0x5b91e40ec7f0	c = t4
0x5b91e40ec970	var t5
0x5b91e40ec9b0	t5 = c + d
0x5b91e40ec9f0	e = t5
0x5b91e40ed0b0	goto L2
0x5b91e40ecf50	label L1
0x5b91e40ecb70	var t6
0x5b91e40ecbb0	t6 = a + b
0x5b91e40ecbf0	d = t6
0x5b91e40ecdf0	var t7
0x5b91e40ece30	t7 = d + 1
0x5b91e40ece70	e = t7
0x5b91e40ed030	label L2
0x5b91e40ed140	output c
0x5b91e40ed1d0	output d
0x5b91e40ed260	output e
0x5b91e40ed3a0	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var b
var c
var d
var e
input a
input b
var t0
t0 = a + b
c = t0
var t1
d = t0
var t2
t2 = c * d
e = t2
c = c
d = e
var t3
t3 = (a > 0)
ifz t3 goto L1
  succ: B3 B2 

[B2]
var t4
t4 = a + b
c = t4
var t5
t5 = c + d
e = t5
goto L2
  succ: B4 

[B3]
label L1
var t6
t6 = a + b
d = t6
var t7
t7 = d + 1
e = t7
  succ: B4 

[B4]
label L2
output c
output d
output e
end
  succ: 
