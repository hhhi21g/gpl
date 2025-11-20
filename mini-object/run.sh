#!/bin/bash

make
./mini case/optimized/loop.m
./asm case/optimized/loop.s
./machine case/optimized/loop.o
