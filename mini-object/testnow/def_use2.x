
# tac list

0x57631e6e0770	label main
0x57631e6e07b0	begin
0x57631e6df830	var a
0x57631e6df910	var b
0x57631e6df9f0	var c
0x57631e6dfb20	a = 1
0x57631e6dfc50	b = 2
0x57631e6dfdb0	var t0
0x57631e6dfdf0	t0 = (a > b)
0x57631e6e03f0	ifz t0 goto L1
0x57631e6dff70	var t1
0x57631e6dffb0	t1 = a + 1
0x57631e6dfff0	c = t1
0x57631e6e0430	goto L2
0x57631e6e02d0	label L1
0x57631e6e0170	var t2
0x57631e6e01b0	t2 = b + 1
0x57631e6e01f0	c = t2
0x57631e6e03b0	label L2
0x57631e6e0630	var t3
0x57631e6e0670	t3 = c + 3
0x57631e6e06b0	a = t3
0x57631e6e07f0	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var b
var c
a = 1
b = 2
var t0
t0 = (a > b)
ifz t0 goto L1
  succ: B3 B2 

[B2]
var t1
t1 = a + 1
c = t1
goto L2
  succ: B4 

[B3]
label L1
var t2
t2 = b + 1
c = t2
  succ: B4 

[B4]
label L2
var t3
t3 = c + 3
a = t3
end
  succ: 
