import subprocess


testcases = []

"""
#small
for i in range(10):
	proc = subprocess.run(["./generator","8","2","%d" % (i+31415)],stdout = subprocess.PIPE)
	testcases.append(proc.stdout)

#medium
for i in range(10):
	proc = subprocess.run(["./generator","1024","10","%d" % (i+31415)],stdout = subprocess.PIPE)
	testcases.append(proc.stdout)
"""

#large
for i in range(10):
	proc = subprocess.run(["./generator","1024","10","%d" % (i+31415)],stdout = subprocess.PIPE)
	testcases.append(proc.stdout)

"""
#corner
for i in range(10):
	proc = subprocess.run(["./generator","1024","10","%d" % (i+31415)],stdout = subprocess.PIPE)
	testcases.append(proc.stdout)
"""

for i,s in enumerate(testcases):
	fp = open('testcases/input/input%02d.txt' % i,"wb")
	fp.write(s)
	fp.close()
	
	sol = subprocess.run(["./solution"],input=s,stdout = subprocess.PIPE)
	fp = open('testcases/output/output%02d.txt' % i,"wb")	
	fp.write(sol.stdout)
	fp.close()

