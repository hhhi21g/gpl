
# tac list

0x5e5d568856d0	label main
0x5e5d56885710	begin
0x5e5d56882810	var i
0x5e5d568828e0	var j
0x5e5d56882b00	vararray arr1[1D]
0x5e5d56882d70	vararray arr2[2D]
0x5e5d56883030	vararray arr3[3D]
0x5e5d56883090	input i
0x5e5d568832a0	var t0
0x5e5d56883760	t0 = 6 * 4
0x5e5d568837d0	arr1[t0] = i
0x5e5d56883dc0	var t4
0x5e5d56883e00	t4 = 6 * 20
0x5e5d56883e40	t4 = t4 + 6
0x5e5d56883f20	var t5
0x5e5d56883f60	t5 = t4 * 4
0x5e5d56883a40	var t1
0x5e5d56883a80	t1 = 6 * 4
0x5e5d56883b60	var t2
0x5e5d56883ba0	t2 = arr1[t1]
0x5e5d56883cd0	var t3
0x5e5d56883d10	t3 = t2 + 6
0x5e5d56883fd0	arr2[t5] = t3
0x5e5d56884820	var t10
0x5e5d56884860	t10 = 6 * 30
0x5e5d568848a0	t10 = t10 + 6
0x5e5d56884980	var t11
0x5e5d568849c0	t11 = t10 * 20
0x5e5d56884a00	t11 = t11 + 6
0x5e5d56884ae0	var t12
0x5e5d56884b20	t12 = t11 * 4
0x5e5d56884340	var t6
0x5e5d56884380	t6 = 6 * 20
0x5e5d568843c0	t6 = t6 + 6
0x5e5d568844a0	var t7
0x5e5d568844e0	t7 = t6 * 4
0x5e5d568845c0	var t8
0x5e5d56884600	t8 = arr2[t7]
0x5e5d56884730	var t9
0x5e5d56884770	t9 = t8 + 6
0x5e5d56884b90	arr3[t12] = t9
0x5e5d56884e50	ifz 0 goto L2
0x5e5d56884d20	output L1
0x5e5d56884e10	label L2
0x5e5d568850a0	var t13
0x5e5d568850e0	t13 = 6 * 30
0x5e5d56885120	t13 = t13 + 6
0x5e5d56885200	var t14
0x5e5d56885240	t14 = t13 * 20
0x5e5d56885280	t14 = t14 + 6
0x5e5d56885360	var t15
0x5e5d568853a0	t15 = t14 * 4
0x5e5d56885480	var t16
0x5e5d568854c0	t16 = arr3[t15]
0x5e5d56885530	j = t16
0x5e5d568855c0	output j
0x5e5d56885620	output L1
0x5e5d56885750	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
vararray arr1[1D]
vararray arr2[2D]
vararray arr3[3D]
input i
var t0
t0 = 6 * 4
arr1[t0] = i
var t4
t4 = 6 * 20
t4 = t4 + 6
var t5
t5 = t4 * 4
var t1
t1 = 6 * 4
var t2
t2 = arr1[t1]
var t3
t3 = t2 + 6
arr2[t5] = t3
var t10
t10 = 6 * 30
t10 = t10 + 6
var t11
t11 = t10 * 20
t11 = t11 + 6
var t12
t12 = t11 * 4
var t6
t6 = 6 * 20
t6 = t6 + 6
var t7
t7 = t6 * 4
var t8
t8 = arr2[t7]
var t9
t9 = t8 + 6
arr3[t12] = t9
ifz 0 goto L2
  succ: B3 B2 

[B2]
output L1
  succ: B3 

[B3]
label L2
var t13
t13 = 6 * 30
t13 = t13 + 6
var t14
t14 = t13 * 20
t14 = t14 + 6
var t15
t15 = t14 * 4
var t16
t16 = arr3[t15]
j = t16
output j
output L1
end
  succ: 
