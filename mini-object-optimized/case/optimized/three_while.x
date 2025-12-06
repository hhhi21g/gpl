
# tac list

0x5ba098bbe670	var t4
0x5ba098bbe570	var t3
0x5ba098bc0870	label main
0x5ba098bc08b0	begin
0x5ba098bbc840	var a
0x5ba098bbc920	var b
0x5ba098bbca00	var c
0x5ba098bbcae0	var d
0x5ba098bbcbc0	var e
0x5ba098bbcca0	var sumd
0x5ba098bbcd80	var sume
0x5ba098bbce60	var i
0x5ba098bbcf40	var j
0x5ba098bbd020	var k
0x5ba098bbe810	var t5
0x5ba098bbe960	var t6
0x5ba098bbea60	var t7
0x5ba098bbef80	var t10
0x5ba098bbf120	var t11
0x5ba098bbf270	var t12
0x5ba098bbf370	var t13
0x5ba098bbd4e0	sumd = 0
0x5ba098bbd590	sume = 0
0x5ba098bbd6c0	k = 12
0x5ba098bc03d0	label L1
0x5ba098bbd820	var t0
0x5ba098bbd860	t0 = (k > 0)
0x5ba098bc0490	ifz t0 goto L3
0x5ba098bbdb70	j = 15
0x5ba098bc0090	label L4
0x5ba098bbdcd0	var t1
0x5ba098bbdd10	t1 = (j > 0)
0x5ba098bc0150	ifz t1 goto L6
0x5ba098bbe020	i = 18
0x5ba098bbfd50	label L7
0x5ba098bbe180	var t2
0x5ba098bbe1c0	t2 = (i > 0)
0x5ba098bbfe10	ifz t2 goto L9
0x5ba098bbec30	var t8
0x5ba098bbee80	var t9
0x5ba098bbf540	var t14
0x5ba098bbf740	var t15
0x5ba098bbf780	t15 = sumd + 14
0x5ba098bbf7c0	sumd = t15
0x5ba098bbf940	var t16
0x5ba098bbf980	t16 = sume + 19
0x5ba098bbfa90	var t17
0x5ba098bbfad0	t17 = t16 + 14
0x5ba098bbfb10	sume = t17
0x5ba098bbfc90	var t18
0x5ba098bbfcd0	t18 = i - 1
0x5ba098bbfd10	i = t18
0x5ba098bbfd90	label L8
0x5ba098bbfe50	goto L7
0x5ba098bbfdd0	label L9
0x5ba098bbffd0	var t19
0x5ba098bc0010	t19 = j - 1
0x5ba098bc0050	j = t19
0x5ba098bc00d0	label L5
0x5ba098bc0190	goto L4
0x5ba098bc0110	label L6
0x5ba098bc0310	var t20
0x5ba098bc0350	t20 = k - 1
0x5ba098bc0390	k = t20
0x5ba098bc0410	label L2
0x5ba098bc04d0	goto L1
0x5ba098bc0450	label L3
0x5ba098bc0560	output sumd
0x5ba098bc0640	output L10
0x5ba098bc06d0	output sume
0x5ba098bc07b0	output L11
0x5ba098bc08f0	end

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
