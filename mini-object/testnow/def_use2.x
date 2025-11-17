
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

# tac list

0x5af59d3ae770	label main
0x5af59d3ae7b0	begin
0x5af59d3ad830	var a
0x5af59d3ad910	var b
0x5af59d3ad9f0	var c
0x5af59d3adb20	a = 1
0x5af59d3adc50	b = 2
0x5af59d3addb0	var t0
0x5af59d3ae3f0	ifz 0 goto L1
0x5af59d3adf70	var t1
0x5af59d3adfb0	t1 = a + 1
0x5af59d3adff0	c = t1
0x5af59d3ae430	goto L2
0x5af59d3ae2d0	label L1
0x5af59d3ae170	var t2
0x5af59d3ae1b0	t2 = b + 1
0x5af59d3ae1f0	c = t2
0x5af59d3ae3b0	label L2
0x5af59d3ae630	var t3
0x5af59d3ae670	t3 = c + 3
0x5af59d3ae6b0	a = t3
0x5af59d3ae7f0	end
