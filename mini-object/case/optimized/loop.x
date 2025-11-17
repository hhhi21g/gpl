
# tac list

0x591c98916b00	label main
0x591c98916b40	begin
0x591c98913830	var a
0x591c98913910	var b
0x591c989139f0	var c
0x591c98913ad0	var d
0x591c98913bb0	var e
0x591c98913c90	var i
0x591c98913d70	var j
0x591c98913e50	var k
0x591c98913eb0	input a
0x591c98913f10	input b
0x591c98913f70	input c
0x591c989140a0	j = 5
0x591c98916680	label L1
0x591c98914280	var t0
0x591c989142c0	t0 = (j > 0)
0x591c98916740	ifz t0 goto L3
0x591c98914530	output j
0x591c98914660	i = 9
0x591c98916260	label L4
0x591c989147c0	var t1
0x591c98914800	t1 = (i > 0)
0x591c98916320	ifz t1 goto L6
0x591c98914a70	output i
0x591c98914c40	var t2
0x591c98914c80	t2 = b * c
0x591c98914d40	var t3
0x591c98914d80	t3 = a + t2
0x591c98914ee0	var t4
0x591c98914f20	t4 = a + c
0x591c98915030	var t5
0x591c98915070	t5 = t4 / b
0x591c98915130	var t6
0x591c98915170	t6 = t3 - t5
0x591c98915280	var t7
0x591c989152c0	t7 = t6 + 9
0x591c98915300	d = t7
0x591c989154d0	var t8
0x591c989155d0	var t9
0x591c98915770	var t10
0x591c989157b0	t10 = c - a
0x591c989158c0	var t11
0x591c98915900	t11 = t10 / b
0x591c989159c0	var t12
0x591c98915a00	t12 = t3 - t11
0x591c98915b10	var t13
0x591c98915b50	t13 = t12 + 9
0x591c98915b90	e = t13
0x591c98915d90	var t14
0x591c98915dd0	t14 = i - 1
0x591c98915e10	i = t14
0x591c989162a0	label L5
0x591c98916360	goto L4
0x591c989162e0	label L6
0x591c989164e0	var t15
0x591c98916520	t15 = j - 1
0x591c98916560	j = t15
0x591c98916640	output L7
0x591c989166c0	label L2
0x591c98916780	goto L1
0x591c98916700	label L3
0x591c98916860	output L8
0x591c989168f0	output d
0x591c98916950	output L7
0x591c989169e0	output e
0x591c98916a40	output L8
0x591c98916b80	end

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
var i
var j
var k
input a
input b
input c
j = 5
  succ: B2 

[B2]
label L1
var t0
t0 = (j > 0)
ifz t0 goto L3
  succ: B9 B3 

[B3]
output j
i = 9
  succ: B4 

[B4]
label L4
var t1
t1 = (i > 0)
ifz t1 goto L6
  succ: B7 B5 

[B5]
output i
var t2
t2 = b * c
var t3
t3 = a + t2
var t4
t4 = a + c
var t5
t5 = t4 / b
var t6
t6 = t3 - t5
var t7
t7 = t6 + 9
d = t7
var t8
var t9
var t10
t10 = c - a
var t11
t11 = t10 / b
var t12
t12 = t3 - t11
var t13
t13 = t12 + 9
e = t13
var t14
t14 = i - 1
i = t14
  succ: B6 

[B6]
label L5
goto L4
  succ: B4 

[B7]
label L6
var t15
t15 = j - 1
j = t15
output L7
  succ: B8 

[B8]
label L2
goto L1
  succ: B2 

[B9]
label L3
output L8
output d
output L7
output e
output L8
end
  succ: 
