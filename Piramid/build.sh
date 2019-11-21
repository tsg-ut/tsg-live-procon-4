#!/bin/bash
CXXFLAGS='-std=c++17 -Wall -Wextra -O2'
for file in $@; do
  g++ $CXXFLAGS $file -o ${file%.*} &
done

wait
