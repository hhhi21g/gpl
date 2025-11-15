#!/bin/bash

make
./mini testcase/arr-struct.m
./asm testcase/arr-struct.s
./machine testcase/arr-struct.o

./mini testcase/arr.m
./asm testcase/arr.s
./machine testcase/arr.o

./mini testcase/for-bc.m
./asm testcase/for-bc.s
./machine testcase/for-bc.o

./mini testcase/for.m
./asm testcase/for.s
./machine testcase/for.o

./mini testcase/func-char.m
./asm testcase/func-char.s
./machine testcase/func-char.o

./mini testcase/func-int.m
./asm testcase/func-int.s
./machine testcase/func-int.o

./mini testcase/struct-arr.m
./asm testcase/struct-arr.s
./machine testcase/struct-arr.o

./mini testcase/struct-ptr.m
./asm testcase/struct-ptr.s
./machine testcase/struct-ptr.o

./mini testcase/struct.m
./asm testcase/struct.s
./machine testcase/struct.o

./mini testcase/switch.m
./asm testcase/switch.s
./machine testcase/switch.o

./mini testcase/while-bc.m
./asm testcase/while-bc.s
./machine testcase/while-bc.o


./mini testcase/arr-while.m
./asm testcase/arr-while.s
./machine testcase/arr-while.o
