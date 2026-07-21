
# tac list

0x604593adeaf0	label main
0x604593adeb30	begin
0x604593add830	var a
0x604593add910	var pa
0x604593add9f0	var b
0x604593addad0	var c
0x604593addbb0	var d
0x604593addc90	var ptr
0x604593addcf0	input d
0x604593adde20	c = 'c'
0x604593addf50	b = 'b'
0x604593addfb0	input a
0x604593ade280	ifz 0 goto L2
0x604593ade160	output L1
0x604593ade240	label L2
0x604593ade310	output a
0x604593ade3a0	output b
0x604593ade430	output c
0x604593ade4c0	output d
0x604593ade520	output L1
0x604593ade5a0	pa = &a
0x604593ade6d0	*pa = 'A'
0x604593ade760	output a
0x604593ade810	ptr = pa
0x604593ade940	*ptr = 'B'
0x604593ade9d0	output a
0x604593adea30	output L1
0x604593adeb70	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
var pa
var b
var c
var d
var ptr
input d
c = 'c'
b = 'b'
input a
ifz 0 goto L2
  succ: B3 B2 

[B2]
output L1
  succ: B3 

[B3]
label L2
output a
output b
output c
output d
output L1
pa = &a
*pa = 'A'
output a
ptr = pa
*ptr = 'B'
output a
output L1
end
  succ: 
