#!bin/bash

set -e

if [ -d testcases ]; then
  rm -rf testcases
fi
mkdir -p testcases/input testcases/output

cp samples/sample-yes.txt testcases/input/input00.txt
cp samples/sample-no.txt testcases/input/input01.txt

for id in $(seq -f '0%g' 0 9) $(seq 10 20); do
  input="testcases/input/input$id.txt"
  output="testcases/output/output$id.txt"
  if [ ! $id = 00 ] && [ ! $id = 01 ]; then
    python3 generator.py > $input
  fi
  cat $input | ./validator 
  cat $input | python3 solver.py > $output
done
