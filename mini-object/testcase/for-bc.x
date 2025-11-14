
# tac list

0x64adca87a8c0	label main
0x64adca87a900	begin
0x64adca878830	var i
0x64adca878910	var j
0x64adca878970	input j
0x64adca878aa0	i = 0
0x64adca8799e0	label L1
0x64adca879010	var t0
0x64adca879050	t0 = (i < j)
0x64adca879aa0	ifz t0 goto L3
0x64adca879690	var t2
0x64adca8796d0	t2 = (i > 10)
0x64adca879910	ifz t2 goto L5
0x64adca8797b0	output L4
0x64adca8797f0	goto L3
0x64adca8798d0	label L5
0x64adca8799a0	output i
0x64adca879a20	label L2
0x64adca879250	var t1
0x64adca879290	t1 = i + 1
0x64adca8792d0	i = t1
0x64adca879ae0	goto L1
0x64adca879a60	label L3
0x64adca879bc0	output L6
0x64adca879c70	i = 0
0x64adca87a6a0	label L7
0x64adca879dd0	var t3
0x64adca879e10	t3 = (i < j)
0x64adca87a760	ifz t3 goto L9
0x64adca87a350	var t5
0x64adca87a390	t5 = (i == 10)
0x64adca87a5d0	ifz t5 goto L11
0x64adca87a470	output L10
0x64adca87a4b0	goto L8
0x64adca87a590	label L11
0x64adca87a660	output i
0x64adca87a6e0	label L8
0x64adca879f90	var t4
0x64adca879fd0	t4 = i + 1
0x64adca87a010	i = t4
0x64adca87a7a0	goto L7
0x64adca87a720	label L9
0x64adca87a800	output L6
0x64adca87a940	end

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
  succ: B6 B3 

[B3]
var t2
t2 = (i > 10)
ifz t2 goto L5
  succ: B5 B4 

[B4]
output L4
goto L3
  succ: B6 

[B5]
label L5
output i
label L2
var t1
t1 = i + 1
i = t1
goto L1
  succ: B2 

[B6]
label L3
output L6
i = 0
  succ: B7 

[B7]
label L7
var t3
t3 = (i < j)
ifz t3 goto L9
  succ: B12 B8 

[B8]
var t5
t5 = (i == 10)
ifz t5 goto L11
  succ: B10 B9 

[B9]
output L10
goto L8
  succ: B11 

[B10]
label L11
output i
  succ: B11 

[B11]
label L8
var t4
t4 = i + 1
i = t4
goto L7
  succ: B7 

[B12]
label L9
output L6
end
  succ: 
