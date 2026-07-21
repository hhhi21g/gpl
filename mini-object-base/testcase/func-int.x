
# tac list

0x5d762cade7b0	var i
0x5d762cadf4e0	label main
0x5d762cadf520	begin
0x5d762cade910	var a
0x5d762cade9f0	var b
0x5d762cadead0	var c
0x5d762cadeb30	input a
0x5d762cadeb90	input b
0x5d762caded30	var t0
0x5d762caded70	actual a
0x5d762cadedb0	actual b
0x5d762cadee50	t0 = call max
0x5d762cadeec0	c = t0
0x5d762cadef50	output c
0x5d762cadf030	output L1
0x5d762cadf230	var t1
0x5d762cadf270	t1 = i + 1
0x5d762cadf2b0	i = t1
0x5d762cadf340	output i
0x5d762cadf420	output L2
0x5d762cadf560	end
0x5d762cadfd90	label max
0x5d762cadfdd0	begin
0x5d762cadf640	formal x
0x5d762cadf700	formal y
0x5d762cadf860	var t2
0x5d762cadf8a0	t2 = (x > y)
0x5d762cadfc00	ifz t2 goto L3
0x5d762cadf950	i = x
0x5d762cadfc40	goto L4
0x5d762cadfae0	label L3
0x5d762cadfa00	i = y
0x5d762cadfbc0	label L4
0x5d762cadfcd0	return i
0x5d762cadfe10	end

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
