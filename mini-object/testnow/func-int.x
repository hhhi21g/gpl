
# tac list

0x5ca9276d2790	var i
0x5ca9276d32e0	label main
0x5ca9276d3320	begin
0x5ca9276d28b0	var a
0x5ca9276d2970	var b
0x5ca9276d2a30	var c
0x5ca9276d2a90	input a
0x5ca9276d2af0	input b
0x5ca9276d2c70	var t0
0x5ca9276d2cb0	actual b
0x5ca9276d2cf0	actual a
0x5ca9276d2d50	t0 = call max
0x5ca9276d2dc0	c = t0
0x5ca9276d2e20	output c
0x5ca9276d2ee0	output L1
0x5ca9276d30a0	var t1
0x5ca9276d30e0	t1 = i + 1
0x5ca9276d3120	i = t1
0x5ca9276d3180	output i
0x5ca9276d3240	output L2
0x5ca9276d3360	end
0x5ca9276d3b10	label max
0x5ca9276d3b50	begin
0x5ca9276d3460	formal x
0x5ca9276d3500	formal y
0x5ca9276d3640	var t2
0x5ca9276d3680	t2 = (x > y)
0x5ca9276d39a0	ifz t2 goto L3
0x5ca9276d3730	i = x
0x5ca9276d39e0	goto L4
0x5ca9276d38a0	label L3
0x5ca9276d37e0	i = y
0x5ca9276d3960	label L4
0x5ca9276d3a70	return i
0x5ca9276d3b90	end

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
