import subprocess

proc = subprocess.run(["./greedy"],stdout = subprocess.PIPE)
anss = proc.stdout
#anss = open('greedy_output.txt','rb').read()
anss = anss.split(b'head\n')[1:]
anss = list(map(lambda d: d.split(b'ans\n'),anss))

print('test for %d test cases' % len(anss))
for d in anss:
  prob,ans = d
  #print(prob)
  #print(ans)
  proc = subprocess.run(["./solution"],input=prob,stdout = subprocess.PIPE)
  pans = proc.stdout
  if ans != pans:
  	print(prob)
  	print(ans)
  	assert False

