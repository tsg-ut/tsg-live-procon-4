import subprocess
import random

random.seed(341532)


testcases = []


#handmade
hand_cases = [
b"""4
....
.#..
#.#.
####
""",
b"""16
.....###..#####?
....?.##..######
...?##.###..####
....###.##..?###
.?#?....####..##
#.##....####..##
##.#....######..
###.?...######?.
..######.....###
..######....#.##
##..####....##.#
##..####....###.
####..##.###....
####..?##.##....
######..##.#....
######..###.....
""",

#小さいのを拡大したかんじのやつ
#全体がわりと同じやつ
]

for d in hand_cases:
	s = d
	testcases.append(s)

sizes = [2 ** i for i in range(1,11)]
#random
for i in range(20):
	proc = subprocess.run(["./generator","%d" % random.choice(sizes),"%d" % random.randint(0,10),"%d" % (i+31415)],stdout = subprocess.PIPE)
	testcases.append(proc.stdout)

#max
for i in range(10):
	proc = subprocess.run(["./generator","1024","10","%d" % (i+31415)],stdout = subprocess.PIPE)
	testcases.append(proc.stdout)

for i,s in enumerate(testcases):
	fp = open('testcases/input/input%02d.txt' % i,"wb")
	fp.write(s)
	fp.close()
	
	sol = subprocess.run(["./solution"],input=s,stdout = subprocess.PIPE)
	fp = open('testcases/output/output%02d.txt' % i,"wb")	
	fp.write(sol.stdout)
	fp.close()


