
# tac list

0x61645ac29670	var t4
0x61645ac29570	var t3
0x61645ac2b870	label main
0x61645ac2b8b0	begin
0x61645ac27840	var a
0x61645ac27920	var b
0x61645ac27a00	var c
0x61645ac27ae0	var d
0x61645ac27bc0	var e
0x61645ac27ca0	var sumd
0x61645ac27d80	var sume
0x61645ac27e60	var i
0x61645ac27f40	var j
0x61645ac28020	var k
0x61645ac29810	var t5
0x61645ac29960	var t6
0x61645ac29a60	var t7
0x61645ac29f80	var t10
0x61645ac2a120	var t11
0x61645ac2a270	var t12
0x61645ac2a370	var t13
0x61645ac284e0	sumd = 0
0x61645ac28590	sume = 0
0x61645ac286c0	k = 12
0x61645ac2b3d0	label L1
0x61645ac28820	var t0
0x61645ac28860	t0 = (k > 0)
0x61645ac2b490	ifz t0 goto L3
0x61645ac28b70	j = 15
0x61645ac2b090	label L4
0x61645ac28cd0	var t1
0x61645ac28d10	t1 = (j > 0)
0x61645ac2b150	ifz t1 goto L6
0x61645ac29020	i = 18
0x61645ac2ad50	label L7
0x61645ac29180	var t2
0x61645ac291c0	t2 = (i > 0)
0x61645ac2ae10	ifz t2 goto L9
0x61645ac29c30	var t8
0x61645ac29e80	var t9
0x61645ac2a540	var t14
0x61645ac2a740	var t15
0x61645ac2a780	t15 = sumd + 14
0x61645ac2a7c0	sumd = t15
0x61645ac2a940	var t16
0x61645ac2a980	t16 = sume + 19
0x61645ac2aa90	var t17
0x61645ac2aad0	t17 = t16 + 14
0x61645ac2ab10	sume = t17
0x61645ac2ac90	var t18
0x61645ac2acd0	t18 = i - 1
0x61645ac2ad10	i = t18
0x61645ac2ad90	label L8
0x61645ac2ae50	goto L7
0x61645ac2add0	label L9
0x61645ac2afd0	var t19
0x61645ac2b010	t19 = j - 1
0x61645ac2b050	j = t19
0x61645ac2b0d0	label L5
0x61645ac2b190	goto L4
0x61645ac2b110	label L6
0x61645ac2b310	var t20
0x61645ac2b350	t20 = k - 1
0x61645ac2b390	k = t20
0x61645ac2b410	label L2
0x61645ac2b4d0	goto L1
0x61645ac2b450	label L3
0x61645ac2b560	output sumd
0x61645ac2b640	output L10
0x61645ac2b6d0	output sume
0x61645ac2b7b0	output L11
0x61645ac2b8f0	end

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
