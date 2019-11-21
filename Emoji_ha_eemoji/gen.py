import random
n = 2 ** 10
res = [['#' if random.randint(0,1)==1 else '.' for _ in range(n)]  for _ in range(n)]

k = 10
for _ in range(k):
  x,y = [random.randint(0,n-1) for _ in range(2)]
  res[y][x] = '?'


print('%d' % n)
for s in res:
  print(''.join(s))
