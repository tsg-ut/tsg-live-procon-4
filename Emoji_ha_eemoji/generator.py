import subprocess
import random

random.seed(341532)


testcases = []


def scaleup(s,n):
	ls = len(s)
	res = [[s[y//n][x//n] for y in range(ls*n)] for x in range(ls*n)]
	return res

def duplicate(s,n):
	ls = len(s)
	res = [[s[y % ls][x % ls] for y in range(ls*n)] for x in range(ls*n)]
	return res

def randflip(s,r):
	ls = len(s)
	def g(c):
		if random.random() < r:
			if c == '#':
				return '.'
			else:
				return '#'
		return c
	
	res = [[g(s[y][x]) for y in range(ls)] for x in range(ls)]
	return res

def randmask(s,k):
	ls = len(s)
	#print(ls)
	res = [[s[y][x] for y in range(ls)] for x in range(ls)]
	for _ in range(k):
		y = random.randint(0,ls-1)
		x = random.randint(0,ls-1)
		res[y][x] = '?'
	return res

def str2arr(s):
	s = [list(s) for d in s.split('\n')[1:]]
	assert len(s) == len(s[0]) 
	return s


def randarr(ls):
	s = [[['#','.'][random.randint(0,1)] for y in range(ls)] for x in range(ls)]
	return s

def arr2case(s):
	ls = len(s)
	s = b''.join([bytes(map(lambda x: ord(x),d)) + b'\n' for d in s])
	return b'%d\n%s' % (ls,s)

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
#真っ白、真っ黒
arr2case(randmask([['#' for y in range(1024)] for x in range(1024)],10)),
arr2case(randmask([['.' for y in range(1024)] for x in range(1024)],10))
,
#小さいのを拡大したかんじのやつ
arr2case(randmask(scaleup(randarr(64),1024 // 64),10))
,
#全体がわりと同じやつ
arr2case(randmask(duplicate(randarr(64),1024 // 64),10))
,
#全体がわりと同じだけど一部違うやつ
arr2case(randmask(randflip(duplicate(randarr(64),1024 // 64),0.2),10))
,
#なんか混ぜたやつ
arr2case(randmask(duplicate(scaleup(randarr(16),8),1024 // 16 // 8),10))
]

#print(hand_cases)

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


