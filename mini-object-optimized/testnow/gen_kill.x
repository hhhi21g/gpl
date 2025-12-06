
# tac list

0x62f586f163b0	label main
0x62f586f163f0	begin
0x62f586f15830	var a
0x62f586f15910	var b
0x62f586f159f0	var c
0x62f586f15b70	var t0
0x62f586f15bb0	t0 = b + c
0x62f586f15bf0	a = t0
0x62f586f15dd0	var t1
0x62f586f15e10	t1 = (b > 0)
0x62f586f16080	ifz t1 goto L1
0x62f586f15f40	b = 1
0x62f586f16040	label L1
0x62f586f161e0	var t2
0x62f586f16220	t2 = b + c
0x62f586f16260	a = t2
0x62f586f162f0	return 0
0x62f586f16430	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var b
var c
var t0
t0 = b + c
a = t0
var t1
t1 = (b > 0)
ifz t1 goto L1
  succ: B3 B2 

[B2]
b = 1
  succ: B3 

[B3]
label L1
var t2
t2 = b + c
a = t2
return 0
  succ: 

[B4]
end
  succ: 
