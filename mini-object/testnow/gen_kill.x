
# tac list

0x654aa5d403b0	label main
0x654aa5d403f0	begin
0x654aa5d3f830	var a
0x654aa5d3f910	var b
0x654aa5d3f9f0	var c
0x654aa5d3fb70	var t0
0x654aa5d3fbb0	t0 = b + c
0x654aa5d3fbf0	a = t0
0x654aa5d3fdd0	var t1
0x654aa5d3fe10	t1 = (b > 0)
0x654aa5d40080	ifz t1 goto L1
0x654aa5d3ff40	b = 1
0x654aa5d40040	label L1
0x654aa5d401e0	var t2
0x654aa5d40220	t2 = b + c
0x654aa5d40260	a = t2
0x654aa5d402f0	return 0
0x654aa5d40430	end

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
