#!/bin/bash

make
./mini testcase/arr-while.m
./asm testcase/arr-while.s
./machine testcase/arr-while.o

