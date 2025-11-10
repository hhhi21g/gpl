
# tac list

0x6517c9f737a0	var i
0x6517c9f743f0	label main
0x6517c9f74430	begin
0x6517c9f738e0	var a
0x6517c9f739b0	var b
0x6517c9f73a80	var c
0x6517c9f73ae0	input a
0x6517c9f73b40	input b
0x6517c9f73cd0	var t0
0x6517c9f73d10	actual b
0x6517c9f73d50	actual a
0x6517c9f73db0	t0 = call max
0x6517c9f73e20	c = t0
0x6517c9f73eb0	output c
0x6517c9f73f80	output L1
0x6517c9f74160	var t1
0x6517c9f741a0	t1 = i + 1
0x6517c9f741e0	i = t1
0x6517c9f74270	output i
0x6517c9f74340	output L2
0x6517c9f74470	end
0x6517c9f74c90	label max
0x6517c9f74cd0	begin
0x6517c9f74590	formal x
0x6517c9f74640	formal y
0x6517c9f74790	var t2
0x6517c9f747d0	t2 = (x > y)
0x6517c9f74b10	ifz t2 goto L3
0x6517c9f74880	i = x
0x6517c9f74b50	goto L4
0x6517c9f74a00	label L3
0x6517c9f74930	i = y
0x6517c9f74ad0	label L4
0x6517c9f74be0	return i
0x6517c9f74d10	end

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
actual b
actual a
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
