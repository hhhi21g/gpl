
# tac list

0x5bd1142f77b0	var i
0x5bd1142f84e0	label main
0x5bd1142f8520	begin
0x5bd1142f7910	var a
0x5bd1142f79f0	var b
0x5bd1142f7ad0	var c
0x5bd1142f7b30	input a
0x5bd1142f7b90	input b
0x5bd1142f7d30	var t0
0x5bd1142f7d70	actual a
0x5bd1142f7db0	actual b
0x5bd1142f7e50	t0 = call max
0x5bd1142f7ec0	c = t0
0x5bd1142f7f50	output c
0x5bd1142f8030	output L1
0x5bd1142f8230	var t1
0x5bd1142f8270	t1 = i + 1
0x5bd1142f82b0	i = t1
0x5bd1142f8340	output i
0x5bd1142f8420	output L2
0x5bd1142f8560	end
0x5bd1142f8d90	label max
0x5bd1142f8dd0	begin
0x5bd1142f8640	formal x
0x5bd1142f8700	formal y
0x5bd1142f8860	var t2
0x5bd1142f88a0	t2 = (x > y)
0x5bd1142f8c00	ifz t2 goto L3
0x5bd1142f8950	i = x
0x5bd1142f8c40	goto L4
0x5bd1142f8ae0	label L3
0x5bd1142f8a00	i = y
0x5bd1142f8bc0	label L4
0x5bd1142f8cd0	return i
0x5bd1142f8e10	end

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
