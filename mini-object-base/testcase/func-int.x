
# tac list

0x590c637067b0	var i
0x590c637074e0	label main
0x590c63707520	begin
0x590c63706910	var a
0x590c637069f0	var b
0x590c63706ad0	var c
0x590c63706b30	input a
0x590c63706b90	input b
0x590c63706d30	var t0
0x590c63706d70	actual a
0x590c63706db0	actual b
0x590c63706e50	t0 = call max
0x590c63706ec0	c = t0
0x590c63706f50	output c
0x590c63707030	output L1
0x590c63707230	var t1
0x590c63707270	t1 = i + 1
0x590c637072b0	i = t1
0x590c63707340	output i
0x590c63707420	output L2
0x590c63707560	end
0x590c63707d90	label max
0x590c63707dd0	begin
0x590c63707640	formal x
0x590c63707700	formal y
0x590c63707860	var t2
0x590c637078a0	t2 = (x > y)
0x590c63707c00	ifz t2 goto L3
0x590c63707950	i = x
0x590c63707c40	goto L4
0x590c63707ae0	label L3
0x590c63707a00	i = y
0x590c63707bc0	label L4
0x590c63707cd0	return i
0x590c63707e10	end

[B0]
var i
label main
  succ: B1 

[B1]
begin
var a
var b
var c
input a
input b
var t0
actual a
actual b
t0 = call max
c = t0
output c
output L1
var t1
t1 = i + 1
i = t1
output i
output L2
end
  succ: 

[B2]
label max
  succ: B3 

[B3]
begin
formal x
formal y
var t2
t2 = (x > y)
ifz t2 goto L3
  succ: B5 B4 

[B4]
i = x
goto L4
  succ: B6 

[B5]
label L3
i = y
  succ: B6 

[B6]
label L4
return i
  succ: 

[B7]
end
  succ: 
