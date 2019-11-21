import subprocess
import random

random.seed(341532)

testcases = []


#handmade
def fzs(f,ls):
	return bytes([ord('A') + f(i) for i in range(ls)])
azs = fzs(lambda i: i%26,100)
hand_cases = [
	[b"BFBC",b"ABFD",b"ACC"],
	[b"TSG",b"LIVE",b"FOUR"],
	[azs,azs,azs],
	[
		fzs(lambda _: ord('T')-ord('A'),100),
		fzs(lambda _: ord('S')-ord('A'),100),
		fzs(lambda _: ord('G')-ord('A'),100),
	],
]

for d in hand_cases:
	s = b""
	for v in d:
		s += b"%d\n%s\n" % (len(v),v)
	testcases.append(s)

#small
for i in range(10):
	proc = subprocess.run(["./generator","10","%d" % (i+31415)],stdout = subprocess.PIPE)
	testcases.append(proc.stdout)

#large
for i in range(10):
	proc = subprocess.run(["./generator","100","%d" % (i+1926)],stdout = subprocess.PIPE)
	testcases.append(proc.stdout)

#max
for i in range(10):
	s = b""
	for _ in range(3):
		s += b"100\n"
		s += bytes([ord('A') + random.randint(0,25) for _ in range(100)]) + b"\n"
	testcases.append(s)


for i,s in enumerate(testcases):
	fp = open('testcases/input/input%02d.txt' % i,"wb")
	fp.write(s)
	fp.close()
	
	sol = subprocess.run(["./solution"],input=s,stdout = subprocess.PIPE)
	fp = open('testcases/output/output%02d.txt' % i,"wb")	
	fp.write(sol.stdout)
	fp.close()

