#!/bin/bash

make
./mini case/optimized/one_while.m
./asm case/optimized/one_while.s
./machine case/optimized/one_while.o

