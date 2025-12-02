#!/bin/bash

make
./mini case/optimized/three_while.m
./asm case/optimized/three_while.s
./machine case/optimized/three_while.o

