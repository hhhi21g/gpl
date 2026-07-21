
# tac list

0x608b7dcd5670	var t4
0x608b7dcd5570	var t3
0x608b7dcd7870	label main
0x608b7dcd78b0	begin
0x608b7dcd3840	var a
0x608b7dcd3920	var b
0x608b7dcd3a00	var c
0x608b7dcd3ae0	var d
0x608b7dcd3bc0	var e
0x608b7dcd3ca0	var sumd
0x608b7dcd3d80	var sume
0x608b7dcd3e60	var i
0x608b7dcd3f40	var j
0x608b7dcd4020	var k
0x608b7dcd5810	var t5
0x608b7dcd5960	var t6
0x608b7dcd5a60	var t7
0x608b7dcd5f80	var t10
0x608b7dcd6120	var t11
0x608b7dcd6270	var t12
0x608b7dcd6370	var t13
0x608b7dcd44e0	sumd = 0
0x608b7dcd4590	sume = 0
0x608b7dcd46c0	k = 12
0x608b7dcd73d0	label L1
0x608b7dcd4820	var t0
0x608b7dcd4860	t0 = (k > 0)
0x608b7dcd7490	ifz t0 goto L3
0x608b7dcd4b70	j = 15
0x608b7dcd7090	label L4
0x608b7dcd4cd0	var t1
0x608b7dcd4d10	t1 = (j > 0)
0x608b7dcd7150	ifz t1 goto L6
0x608b7dcd5020	i = 18
0x608b7dcd6d50	label L7
0x608b7dcd5180	var t2
0x608b7dcd51c0	t2 = (i > 0)
0x608b7dcd6e10	ifz t2 goto L9
0x608b7dcd5c30	var t8
0x608b7dcd5e80	var t9
0x608b7dcd6540	var t14
0x608b7dcd6740	var t15
0x608b7dcd6780	t15 = sumd + 14
0x608b7dcd67c0	sumd = t15
0x608b7dcd6940	var t16
0x608b7dcd6980	t16 = sume + 19
0x608b7dcd6a90	var t17
0x608b7dcd6ad0	t17 = t16 + 14
0x608b7dcd6b10	sume = t17
0x608b7dcd6c90	var t18
0x608b7dcd6cd0	t18 = i - 1
0x608b7dcd6d10	i = t18
0x608b7dcd6d90	label L8
0x608b7dcd6e50	goto L7
0x608b7dcd6dd0	label L9
0x608b7dcd6fd0	var t19
0x608b7dcd7010	t19 = j - 1
0x608b7dcd7050	j = t19
0x608b7dcd70d0	label L5
0x608b7dcd7190	goto L4
0x608b7dcd7110	label L6
0x608b7dcd7310	var t20
0x608b7dcd7350	t20 = k - 1
0x608b7dcd7390	k = t20
0x608b7dcd7410	label L2
0x608b7dcd74d0	goto L1
0x608b7dcd7450	label L3
0x608b7dcd7560	output sumd
0x608b7dcd7640	output L10
0x608b7dcd76d0	output sume
0x608b7dcd77b0	output L11
0x608b7dcd78f0	end

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
