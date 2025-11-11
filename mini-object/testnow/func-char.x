
# tac list

0x5b31bb3bc7a0	var i
0x5b31bb3bd420	label main
0x5b31bb3bd460	begin
0x5b31bb3bc8e0	var a
0x5b31bb3bc9b0	var b
0x5b31bb3bca80	var c
0x5b31bb3bcae0	input a
0x5b31bb3bcb40	input b
0x5b31bb3bccd0	var t0
0x5b31bb3bcd10	actual a
0x5b31bb3bcd50	actual b
0x5b31bb3bcde0	t0 = call max
0x5b31bb3bce50	c = t0
0x5b31bb3bcee0	output c
0x5b31bb3bcfb0	output L1
0x5b31bb3bd190	var t1
0x5b31bb3bd1d0	t1 = i + 1
0x5b31bb3bd210	i = t1
0x5b31bb3bd2a0	output i
0x5b31bb3bd370	output L2
0x5b31bb3bd4a0	end
0x5b31bb3bdc70	label max
0x5b31bb3bdcb0	begin
0x5b31bb3bd570	formal x
0x5b31bb3bd620	formal y
0x5b31bb3bd770	var t2
0x5b31bb3bd7b0	t2 = (x > y)
0x5b31bb3bdaf0	ifz t2 goto L3
0x5b31bb3bd860	i = x
0x5b31bb3bdb30	goto L4
0x5b31bb3bd9e0	label L3
0x5b31bb3bd910	i = y
0x5b31bb3bdab0	label L4
0x5b31bb3bdbc0	return i
0x5b31bb3bdcf0	end

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
