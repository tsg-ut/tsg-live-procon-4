#!/bin/bash

set -e

rm -rf testcases
mkdir -p testcases/input testcases/output

cp sample.txt testcases/input/input00.txt

for id in $(seq -f "0%g" 0 9) $(seq 10 20); do
  input="testcases/input/input${id}.txt"
  output="testcases/output/output${id}.txt"
  if [ ! $id = 00 ]; then
    ./generator $id > $input
  fi
  cat $input | ./validator
  cat $input | python3 solver.py > $output
done
