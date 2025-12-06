#!/bin/bash

make
./mini case/optimized/nested_loop.m
./asm case/optimized/nested_loop.s
./machine case/optimized/nested_loop.o

