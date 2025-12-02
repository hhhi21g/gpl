
# tac list

0x557227532670	var t4
0x557227532570	var t3
0x557227534870	label main
0x5572275348b0	begin
0x557227530840	var a
0x557227530920	var b
0x557227530a00	var c
0x557227530ae0	var d
0x557227530bc0	var e
0x557227530ca0	var sumd
0x557227530d80	var sume
0x557227530e60	var i
0x557227530f40	var j
0x557227531020	var k
0x557227532810	var t5
0x557227532960	var t6
0x557227532a60	var t7
0x557227532f80	var t10
0x557227533120	var t11
0x557227533270	var t12
0x557227533370	var t13
0x5572275314e0	sumd = 0
0x557227531590	sume = 0
0x5572275316c0	k = 12
0x5572275343d0	label L1
0x557227531820	var t0
0x557227531860	t0 = (k > 0)
0x557227534490	ifz t0 goto L3
0x557227531b70	j = 15
0x557227534090	label L4
0x557227531cd0	var t1
0x557227531d10	t1 = (j > 0)
0x557227534150	ifz t1 goto L6
0x557227532020	i = 18
0x557227533d50	label L7
0x557227532180	var t2
0x5572275321c0	t2 = (i > 0)
0x557227533e10	ifz t2 goto L9
0x557227532c30	var t8
0x557227532e80	var t9
0x557227533540	var t14
0x557227533740	var t15
0x557227533780	t15 = sumd + 14
0x5572275337c0	sumd = t15
0x557227533940	var t16
0x557227533980	t16 = sume + 19
0x557227533a90	var t17
0x557227533ad0	t17 = t16 + 14
0x557227533b10	sume = t17
0x557227533c90	var t18
0x557227533cd0	t18 = i - 1
0x557227533d10	i = t18
0x557227533d90	label L8
0x557227533e50	goto L7
0x557227533dd0	label L9
0x557227533fd0	var t19
0x557227534010	t19 = j - 1
0x557227534050	j = t19
0x5572275340d0	label L5
0x557227534190	goto L4
0x557227534110	label L6
0x557227534310	var t20
0x557227534350	t20 = k - 1
0x557227534390	k = t20
0x557227534410	label L2
0x5572275344d0	goto L1
0x557227534450	label L3
0x557227534560	output sumd
0x557227534640	output L10
0x5572275346d0	output sume
0x5572275347b0	output L11
0x5572275348f0	end

[B0]
var t4
var t3
label main
  succ: B1 

[B1]
begin
var a
var b
var c
var d
var e
var sumd
var sume
var i
var j
var k
var t5
var t6
var t7
var t10
var t11
var t12
var t13
sumd = 0
sume = 0
k = 12
  succ: B2 

[B2]
label L1
var t0
t0 = (k > 0)
ifz t0 goto L3
  succ: B10 B3 

[B3]
j = 15
  succ: B4 

[B4]
label L4
var t1
t1 = (j > 0)
ifz t1 goto L6
  succ: B9 B5 

[B5]
i = 18
  succ: B6 

[B6]
label L7
var t2
t2 = (i > 0)
ifz t2 goto L9
  succ: B8 B7 

[B7]
var t8
var t9
var t14
var t15
t15 = sumd + 14
sumd = t15
var t16
t16 = sume + 19
var t17
t17 = t16 + 14
sume = t17
var t18
t18 = i - 1
i = t18
label L8
goto L7
  succ: B6 

[B8]
label L9
var t19
t19 = j - 1
j = t19
label L5
goto L4
  succ: B4 

[B9]
label L6
var t20
t20 = k - 1
k = t20
label L2
goto L1
  succ: B2 

[B10]
label L3
output sumd
output L10
output sume
output L11
end
  succ: 
