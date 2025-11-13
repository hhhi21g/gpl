
# tac list

0x5d0b98745760	label main
0x5d0b987457a0	begin
0x5d0b98744810	var i
0x5d0b987448e0	var j
0x5d0b98744940	input j
0x5d0b98744a60	i = 0
0x5d0b987454e0	label L1
0x5d0b98744fc0	var t0
0x5d0b98745000	t0 = (i < j)
0x5d0b987455a0	ifz t0 goto L3
0x5d0b987454a0	output i
0x5d0b98745520	label L2
0x5d0b987451e0	var t1
0x5d0b98745220	t1 = i + 1
0x5d0b98745260	i = t1
0x5d0b987455e0	goto L1
0x5d0b98745560	label L3
0x5d0b987456b0	output L4
0x5d0b987457e0	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
input j
i = 0
  succ: B2 

[B2]
label L1
var t0
t0 = (i < j)
ifz t0 goto L3
  succ: B4 B3 

[B3]
output i
label L2
var t1
t1 = i + 1
i = t1
goto L1
  succ: B2 

[B4]
label L3
output L4
end
  succ: 
