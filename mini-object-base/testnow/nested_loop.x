
# tac list

0x57dd7c9524e0	label main
0x57dd7c952520	begin
0x57dd7c950830	var i
0x57dd7c950910	var j
0x57dd7c9509f0	var k
0x57dd7c950b20	k = 0
0x57dd7c952320	label L1
0x57dd7c950d00	var t0
0x57dd7c950d40	t0 = (k < 10)
0x57dd7c9523e0	ifz t0 goto L3
0x57dd7c950fd0	i = 0
0x57dd7c951fe0	label L4
0x57dd7c951130	var t1
0x57dd7c951170	t1 = (i < 10)
0x57dd7c9520a0	ifz t1 goto L6
0x57dd7c951550	var t2
0x57dd7c951590	t2 = 2 * i
0x57dd7c951720	var t3
0x57dd7c951760	t3 = t2 + 9
0x57dd7c9517a0	j = t3
0x57dd7c951830	output j
0x57dd7c951910	output L7
0x57dd7c951b10	var t4
0x57dd7c951b50	t4 = i + 1
0x57dd7c951b90	i = t4
0x57dd7c952020	label L5
0x57dd7c9520e0	goto L4
0x57dd7c952060	label L6
0x57dd7c952260	var t5
0x57dd7c9522a0	t5 = k + 1
0x57dd7c9522e0	k = t5
0x57dd7c952360	label L2
0x57dd7c952420	goto L1
0x57dd7c9523a0	label L3
0x57dd7c952560	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
var k
k = 0
  succ: B2 

[B2]
label L1
var t0
t0 = (k < 10)
ifz t0 goto L3
  succ: B7 B3 

[B3]
i = 0
  succ: B4 

[B4]
label L4
var t1
t1 = (i < 10)
ifz t1 goto L6
  succ: B6 B5 

[B5]
var t2
t2 = 2 * i
var t3
t3 = t2 + 9
j = t3
output j
output L7
var t4
t4 = i + 1
i = t4
label L5
goto L4
  succ: B4 

[B6]
label L6
var t5
t5 = k + 1
k = t5
label L2
goto L1
  succ: B2 

[B7]
label L3
end
  succ: 
