
# tac list

0x5dfe53808320	label main
0x5dfe53808360	begin
0x5dfe53806830	var a
0x5dfe53806910	var b
0x5dfe538069f0	var c
0x5dfe53806ad0	var d
0x5dfe53806bb0	var e
0x5dfe53806c10	input a
0x5dfe53806c70	input b
0x5dfe53806df0	var t0
0x5dfe53806e30	t0 = a + b
0x5dfe53806e70	c = t0
0x5dfe53806ff0	var t1
0x5dfe53807070	d = t0
0x5dfe538071f0	var t2
0x5dfe53807230	t2 = c * d
0x5dfe53807270	e = t2
0x5dfe53807320	c = c
0x5dfe538073d0	d = e
0x5dfe538075b0	var t3
0x5dfe538075f0	t3 = (a > 0)
0x5dfe53808070	ifz t3 goto L1
0x5dfe53807770	var t4
0x5dfe538077b0	t4 = a + b
0x5dfe538077f0	c = t4
0x5dfe53807970	var t5
0x5dfe538079b0	t5 = c + d
0x5dfe538079f0	e = t5
0x5dfe538080b0	goto L2
0x5dfe53807f50	label L1
0x5dfe53807b70	var t6
0x5dfe53807bb0	t6 = a + b
0x5dfe53807bf0	d = t6
0x5dfe53807df0	var t7
0x5dfe53807e30	t7 = d + 1
0x5dfe53807e70	e = t7
0x5dfe53808030	label L2
0x5dfe53808140	output c
0x5dfe538081d0	output d
0x5dfe53808260	output e
0x5dfe538083a0	end

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
