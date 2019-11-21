import os
import re
import subprocess

class Stream:
	def __init__(sl,s):
		sl.s = s
	
	def readInt(sl):
		p = re.match(b'\d*',sl.s)
		res = int(p.group())
		sl.s = sl.s[p.end():]
		#print(p,res,sl.s[:10])
		return res
	
	def readLF(sl):
		assert sl.s[0]==10
		sl.s = sl.s[1:]

	def readStr(sl,ls,pat):
		res = sl.s[:ls]
		assert len(res) == ls
		assert re.match(b'^%s$' % pat,res)
		sl.s = sl.s[ls:]
		return res
	
	def readEOF(sl):
		assert len(sl.s) == 0


def is_two_beki(n):
	b = 1
	while n != b:
		if b > n:
			return False
		b *= 2
	return True

fns = os.listdir(os.path.join('testcases','input'))
for fn in fns:
	s = open(os.path.join('testcases','input',fn),'rb').read()
	output = open(os.path.join('testcases','output',fn.replace('input','output')),"rb").read()
	proc = subprocess.run(["./solution"],input=s,stdout = subprocess.PIPE)
	assert proc.stdout == output
	
	s = Stream(s)
	n = s.readInt()
	assert 1 <= n
	assert n <= 1024
	assert is_two_beki(n)
	
	s.readLF()
	qn = 0
	for _ in range(n):
		d = s.readStr(n,b'[#.?]*')
		qn += d.count(b'?')
		s.readLF()
	s.readEOF()
	assert qn<=10

print('validated %d test cases' % len(fns))

	
