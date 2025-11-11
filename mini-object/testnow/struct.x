
# tac list

0x571ed5419d30	label main
0x571ed5419d70	begin
0x571ed54179a0	var i
0x571ed5417a70	var j
0x571ed5417b40	var k
0x571ed5417c10	var zs
0x571ed5417c70	input i
0x571ed5417cd0	input j
0x571ed5417d30	input k
0x571ed5417e70	var t0
0x571ed5417eb0	t0 = &zs
0x571ed5417f60	var t1
0x571ed5418010	t1 = t0 + 0
0x571ed5418050	*t1 = i
0x571ed5418190	var t2
0x571ed54181d0	t2 = &zs
0x571ed5418280	var t3
0x571ed5418330	t3 = t2 + 4
0x571ed5418370	*t3 = j
0x571ed54184b0	var t4
0x571ed54184f0	t4 = &zs
0x571ed54185a0	var t5
0x571ed5418650	t5 = t4 + 8
0x571ed5418690	*t5 = k
0x571ed54188e0	ifz 0 goto L2
0x571ed54187b0	output L1
0x571ed54188a0	label L2
0x571ed54189d0	var t6
0x571ed5418a10	t6 = &zs
0x571ed5418ac0	var t7
0x571ed5418b00	t7 = 8 + t6
0x571ed5418bb0	var t8
0x571ed5418bf0	t8 = *t7
0x571ed5418d90	var t9
0x571ed5418dd0	t9 = t8 + 100
0x571ed5418e10	i = t9
0x571ed5418f20	var t10
0x571ed5418f60	t10 = &zs
0x571ed5419010	var t11
0x571ed5419050	t11 = 4 + t10
0x571ed5419100	var t12
0x571ed5419140	t12 = *t11
0x571ed54192e0	var t13
0x571ed5419320	t13 = t12 + 200
0x571ed5419360	j = t13
0x571ed5419470	var t14
0x571ed54194b0	t14 = &zs
0x571ed5419560	var t15
0x571ed54195a0	t15 = 0 + t14
0x571ed5419650	var t16
0x571ed5419690	t16 = *t15
0x571ed5419830	var t17
0x571ed5419870	t17 = t16 + 300
0x571ed54198b0	k = t17
0x571ed5419a70	ifz 0 goto L3
0x571ed5419960	output L1
0x571ed5419a30	label L3
0x571ed5419b00	output i
0x571ed5419b90	output j
0x571ed5419c20	output k
0x571ed5419c80	output L1
0x571ed5419db0	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
var k
var zs
input i
input j
input k
var t0
t0 = &zs
var t1
t1 = t0 + 0
*t1 = i
var t2
t2 = &zs
var t3
t3 = t2 + 4
*t3 = j
var t4
t4 = &zs
var t5
t5 = t4 + 8
*t5 = k
ifz 0 goto L2
  succ: B3 B2 

[B2]
output L1
  succ: B3 

[B3]
label L2
var t6
t6 = &zs
var t7
t7 = 8 + t6
var t8
t8 = *t7
var t9
t9 = t8 + 100
i = t9
var t10
t10 = &zs
var t11
t11 = 4 + t10
var t12
t12 = *t11
var t13
t13 = t12 + 200
j = t13
var t14
t14 = &zs
var t15
t15 = 0 + t14
var t16
t16 = *t15
var t17
t17 = t16 + 300
k = t17
ifz 0 goto L3
  succ: B5 B4 

[B4]
output L1
  succ: B5 

[B5]
label L3
output i
output j
output k
output L1
end
  succ: 
