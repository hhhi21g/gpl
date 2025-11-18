
# tac list

0x5f752828d0f0	label main
0x5f752828d130	begin
0x5f752828c830	var a
0x5f752828c910	var b
0x5f752828c9f0	var c
0x5f752828cb70	var t0
0x5f752828cbb0	t0 = b + c
0x5f752828cbf0	a = t0
0x5f752828cd20	b = 10
0x5f752828cea0	var t1
0x5f752828cee0	t1 = a + b
0x5f752828cf20	c = t1
0x5f752828d030	return 0
0x5f752828d170	end

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
b = 10
var t1
t1 = a + b
c = t1
return 0
  succ: 

[B2]
end
  succ: 
