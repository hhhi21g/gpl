
# tac list

0x58c809adc7b0	var i
0x58c809add4e0	label main
0x58c809add520	begin
0x58c809adc910	var a
0x58c809adc9f0	var b
0x58c809adcad0	var c
0x58c809adcb30	input a
0x58c809adcb90	input b
0x58c809adcd30	var t0
0x58c809adcd70	actual a
0x58c809adcdb0	actual b
0x58c809adce50	t0 = call max
0x58c809adcec0	c = t0
0x58c809adcf50	output c
0x58c809add030	output L1
0x58c809add230	var t1
0x58c809add270	t1 = i + 1
0x58c809add2b0	i = t1
0x58c809add340	output i
0x58c809add420	output L2
0x58c809add560	end
0x58c809addd90	label max
0x58c809adddd0	begin
0x58c809add640	formal x
0x58c809add700	formal y
0x58c809add860	var t2
0x58c809add8a0	t2 = (x > y)
0x58c809addc00	ifz t2 goto L3
0x58c809add950	i = x
0x58c809addc40	goto L4
0x58c809addae0	label L3
0x58c809adda00	i = y
0x58c809addbc0	label L4
0x58c809addcd0	return i
0x58c809adde10	end

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
