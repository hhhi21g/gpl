
# tac list

0x6419c7fbff00	label main
0x6419c7fbff40	begin
0x6419c7fbf830	var a
0x6419c7fbf960	a = 1
0x6419c7fbfca0	ifz 0 goto L1
0x6419c7fbfb60	a = 2
0x6419c7fbfc60	label L1
0x6419c7fbfdb0	a = 3
0x6419c7fbfe40	output a
0x6419c7fbff80	end

[B0]
label main
  succ: B1 

[B1]
begin
var a
a = 1
ifz 0 goto L1
  succ: B3 B2 

[B2]
a = 2
  succ: B3 

[B3]
label L1
a = 3
output a
end
  succ: 
