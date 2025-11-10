
# tac list

0x62b467d3c7a0	var i
0x62b467d3d3f0	label main
0x62b467d3d430	begin
0x62b467d3c8e0	var a
0x62b467d3c9b0	var b
0x62b467d3ca80	var c
0x62b467d3cae0	input a
0x62b467d3cb40	input b
0x62b467d3ccd0	var t0
0x62b467d3cd10	actual a
0x62b467d3cd50	actual b
0x62b467d3cdb0	t0 = call max
0x62b467d3ce20	c = t0
0x62b467d3ceb0	output c
0x62b467d3cf80	output L1
0x62b467d3d160	var t1
0x62b467d3d1a0	t1 = i + 1
0x62b467d3d1e0	i = t1
0x62b467d3d270	output i
0x62b467d3d340	output L2
0x62b467d3d470	end
0x62b467d3dc90	label max
0x62b467d3dcd0	begin
0x62b467d3d590	formal x
0x62b467d3d640	formal y
0x62b467d3d790	var t2
0x62b467d3d7d0	t2 = (x > y)
0x62b467d3db10	ifz t2 goto L3
0x62b467d3d880	i = x
0x62b467d3db50	goto L4
0x62b467d3da00	label L3
0x62b467d3d930	i = y
0x62b467d3dad0	label L4
0x62b467d3dbe0	return i
0x62b467d3dd10	end

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
