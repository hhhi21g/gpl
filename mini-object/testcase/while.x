
# tac list

0x620d6eba41a0	label main
0x620d6eba41e0	begin
0x620d6eba37f0	var i
0x620d6eba38b0	var j
0x620d6eba39c0	i = 0
0x620d6eba3a20	input j
0x620d6eba3f00	label L1
0x620d6eba3b60	var t0
0x620d6eba3ba0	t0 = (i < j)
0x620d6eba4040	ifz t0 goto L2
0x620d6eba3c00	output i
0x620d6eba3dc0	var t1
0x620d6eba3e00	t1 = i + 1
0x620d6eba3e40	i = t1
0x620d6eba3f40	goto L1
0x620d6eba4000	label L2
0x620d6eba4100	output L3
0x620d6eba4220	end

[B0]
label main
  succ: B1 

[B1]
begin
var i
var j
i = 0
input j
  succ: B2 

[B2]
label L1
var t0
t0 = (i < j)
ifz t0 goto L2
  succ: B4 B3 

[B3]
output i
var t1
t1 = i + 1
i = t1
goto L1
  succ: B2 

[B4]
label L2
output L3
end
  succ: 
