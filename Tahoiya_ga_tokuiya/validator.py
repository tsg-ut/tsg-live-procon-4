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
		
fns = os.listdir(os.path.join('testcases','input'))
for fn in fns:
	s = open(os.path.join('testcases','input',fn),'rb').read()
	output = open(os.path.join('testcases','output',fn.replace('input','output')),"rb").read()
	proc = subprocess.run(["./solution"],input=s,stdout = subprocess.PIPE)
	assert proc.stdout == output
	
	s = Stream(s)
	for _ in range(3):
		n = s.readInt()
		assert 1 <= n
		assert n <= 100
		s.readLF()
		s.readStr(n,b'[A-Z]*')
		s.readLF()
	s.readEOF()

print('validated %d test cases' % len(fns))

	
