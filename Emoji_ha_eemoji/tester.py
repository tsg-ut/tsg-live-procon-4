import subprocess

proc = subprocess.run(["./greedy"],stdout = subprocess.PIPE)
anss = proc.stdout.split(b'HEAD\n')[1:]
anss = list(map(lambda d: d.split(b'ANS\n'),anss))

print('test for %d test cases' % len(anss))
for d in anss:
  prob,ans = d
  #print(prob)
  #print(ans)
  proc = subprocess.run(["./solution"],input=prob,stdout = subprocess.PIPE)
  pans = proc.stdout
  #print(ans,pans)
  assert (ans==pans)
