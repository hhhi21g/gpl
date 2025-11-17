
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

# tac list

0x60889f63d0f0	label main
0x60889f63d130	begin
0x60889f63c830	var a
0x60889f63c910	var b
0x60889f63c9f0	var c
0x60889f63cb70	var t0
0x60889f63cbb0	t0 = b + c
0x60889f63cbf0	a = t0
0x60889f63cd20	b = 10
0x60889f63cea0	var t1
0x60889f63cee0	t1 = a + 10
0x60889f63cf20	c = t1
0x60889f63d030	return 0
0x60889f63d170	end
