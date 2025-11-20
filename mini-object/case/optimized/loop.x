
# tac list

0x5c904973fc40	var t2
0x5c904973fd40	var t3
0x5c904973fee0	var t4
0x5c9049740030	var t5
0x5c9049740130	var t6
0x5c9049740770	var t10
0x5c90497408c0	var t11
0x5c9049741b00	label main
0x5c9049741b40	begin
0x5c904973e830	var a
0x5c904973e910	var b
0x5c904973e9f0	var c
0x5c904973ead0	var d
0x5c904973ebb0	var e
0x5c904973ec90	var i
0x5c904973ed70	var j
0x5c904973ee50	var k
0x5c904973eeb0	input a
0x5c904973ef10	input b
0x5c904973ef70	input c
0x5c904973f0a0	j = 5
0x5c904973fc80	t2 = b * c
0x5c904973fd80	t3 = a + t2
0x5c904973ff20	t4 = a + c
0x5c9049740070	t5 = t4 / b
0x5c9049740170	t6 = t3 - t5
0x5c90497407b0	t10 = c - a
0x5c9049740900	t11 = t10 / b
0x5c9049741680	label L1
0x5c904973f280	var t0
0x5c904973f2c0	t0 = (j > 0)
0x5c9049741740	ifz t0 goto L3
0x5c904973f530	output j
0x5c904973f660	i = 9
0x5c9049741260	label L4
0x5c904973f7c0	var t1
0x5c904973f800	t1 = (i > 0)
0x5c9049741320	ifz t1 goto L6
0x5c904973fa70	output i
0x5c9049740280	var t7
0x5c90497402c0	t7 = t6 + 9
0x5c9049740300	d = t7
0x5c90497404d0	var t8
0x5c9049740510	t8 = t2
0x5c90497405d0	var t9
0x5c9049740610	t9 = a + t8
0x5c90497409c0	var t12
0x5c9049740a00	t12 = t9 - t11
0x5c9049740b10	var t13
0x5c9049740b50	t13 = t12 + 9
0x5c9049740b90	e = t13
0x5c9049740d90	var t14
0x5c9049740dd0	t14 = i - 1
0x5c9049740e10	i = t14
0x5c90497412a0	label L5
0x5c9049741360	goto L4
0x5c90497412e0	label L6
0x5c90497414e0	var t15
0x5c9049741520	t15 = j - 1
0x5c9049741560	j = t15
0x5c9049741640	output L7
0x5c90497416c0	label L2
0x5c9049741780	goto L1
0x5c9049741700	label L3
0x5c9049741860	output L8
0x5c90497418f0	output d
0x5c9049741950	output L7
0x5c90497419e0	output e
0x5c9049741a40	output L8
0x5c9049741b80	end

[B0]
var t2
var t3
var t4
var t5
var t6
var t10
var t11
label main
  succ: B1 

[B1]
begin
var a
var b
var c
var d
var e
var i
var j
var k
input a
input b
input c
j = 5
t2 = b * c
t3 = a + t2
t4 = a + c
t5 = t4 / b
t6 = t3 - t5
t10 = c - a
t11 = t10 / b
  succ: B2 

[B2]
label L1
var t0
t0 = (j > 0)
ifz t0 goto L3
  succ: B7 B3 

[B3]
output j
i = 9
  succ: B4 

[B4]
label L4
var t1
t1 = (i > 0)
ifz t1 goto L6
  succ: B6 B5 

[B5]
output i
var t7
t7 = t6 + 9
d = t7
var t8
t8 = t2
var t9
t9 = a + t8
var t12
t12 = t9 - t11
var t13
t13 = t12 + 9
e = t13
var t14
t14 = i - 1
i = t14
label L5
goto L4
  succ: B4 

[B6]
label L6
var t15
t15 = j - 1
j = t15
output L7
label L2
goto L1
  succ: B2 

[B7]
label L3
output L8
output d
output L7
output e
output L8
end
  succ: 
