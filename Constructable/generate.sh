#!/bin/bash

set -e

if [ -d testcases ]; then
  rm -rf testcases
fi

mkdir -p testcases/input testcases/output

cp sample.txt testcases/input/input00.txt

for id in $(seq -f '0%g' 0 9) $(seq 10 30); do
  input="testcases/input/input${id}.txt"
  output="testcases/output/output${id}.txt"
  if [ ! $id = 00 ]; then
    ./generator $input > $input
  fi
  cat $input | ./validator
  cat $input | ./solver > $output
done
