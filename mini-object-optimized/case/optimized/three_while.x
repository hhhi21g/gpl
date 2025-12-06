
# tac list

0x5c8c091aa670	var t4
0x5c8c091aa570	var t3
0x5c8c091ac870	label main
0x5c8c091ac8b0	begin
0x5c8c091a8840	var a
0x5c8c091a8920	var b
0x5c8c091a8a00	var c
0x5c8c091a8ae0	var d
0x5c8c091a8bc0	var e
0x5c8c091a8ca0	var sumd
0x5c8c091a8d80	var sume
0x5c8c091a8e60	var i
0x5c8c091a8f40	var j
0x5c8c091a9020	var k
0x5c8c091aa810	var t5
0x5c8c091aa960	var t6
0x5c8c091aaa60	var t7
0x5c8c091aaf80	var t10
0x5c8c091ab120	var t11
0x5c8c091ab270	var t12
0x5c8c091ab370	var t13
0x5c8c091a94e0	sumd = 0
0x5c8c091a9590	sume = 0
0x5c8c091a96c0	k = 12
0x5c8c091ac3d0	label L1
0x5c8c091a9820	var t0
0x5c8c091a9860	t0 = (k > 0)
0x5c8c091ac490	ifz t0 goto L3
0x5c8c091a9b70	j = 15
0x5c8c091ac090	label L4
0x5c8c091a9cd0	var t1
0x5c8c091a9d10	t1 = (j > 0)
0x5c8c091ac150	ifz t1 goto L6
0x5c8c091aa020	i = 18
0x5c8c091abd50	label L7
0x5c8c091aa180	var t2
0x5c8c091aa1c0	t2 = (i > 0)
0x5c8c091abe10	ifz t2 goto L9
0x5c8c091aac30	var t8
0x5c8c091aae80	var t9
0x5c8c091ab540	var t14
0x5c8c091ab740	var t15
0x5c8c091ab780	t15 = sumd + 14
0x5c8c091ab7c0	sumd = t15
0x5c8c091ab940	var t16
0x5c8c091ab980	t16 = sume + 19
0x5c8c091aba90	var t17
0x5c8c091abad0	t17 = t16 + 14
0x5c8c091abb10	sume = t17
0x5c8c091abc90	var t18
0x5c8c091abcd0	t18 = i - 1
0x5c8c091abd10	i = t18
0x5c8c091abd90	label L8
0x5c8c091abe50	goto L7
0x5c8c091abdd0	label L9
0x5c8c091abfd0	var t19
0x5c8c091ac010	t19 = j - 1
0x5c8c091ac050	j = t19
0x5c8c091ac0d0	label L5
0x5c8c091ac190	goto L4
0x5c8c091ac110	label L6
0x5c8c091ac310	var t20
0x5c8c091ac350	t20 = k - 1
0x5c8c091ac390	k = t20
0x5c8c091ac410	label L2
0x5c8c091ac4d0	goto L1
0x5c8c091ac450	label L3
0x5c8c091ac560	output sumd
0x5c8c091ac640	output L10
0x5c8c091ac6d0	output sume
0x5c8c091ac7b0	output L11
0x5c8c091ac8f0	end

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
