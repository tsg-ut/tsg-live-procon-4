#!/bin/bash
set -e

for directory in testcases testcases/input testcases/output; do
  if [ ! -d $directory ]; then
    mkdir $directory
  fi
done

# small integer cases
smalls=$(seq -f '0%g' 0 9)
for id in $smalls; do
  ./generator 0 3.135 100 $id > testcases/input/input${id}.txt
done

# totally random
randoms=$(seq 10 14)
for id in $randoms; do
  ./generator 0 3.135 1000000 $id > testcases/input/input${id}.txt
done

# medium size
mediums=$(seq 15 20)
for id in $mediums; do
  ./generator 2 3.135 1000000 $id > testcases/input/input${id}.txt
done

# large cases
larges=$(seq 20 29)
for id in $larges; do
  ./generator 3 3.135 1000000 $id > testcases/input/input${id}.txt
done

# max cases
maxes=$(seq 30 35)
for id in $maxes; do
  ./generator 3.135 3.135 1000000 $id > testcases/input/input${id}.txt
done

# edge cases
# selected by hand
edges=$(seq 36 40)
cp edge-cases/* testcases/input/

for id in $smalls $randoms $mediums $larges $maxes $edges; do
  cat testcases/input/input${id}.txt | ./validator
  cat testcases/input/input${id}.txt | ./solver > testcases/output/output${id}.txt
done
