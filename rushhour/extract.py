import sys
from random import choice

try:
  with open('rush.txt', 'r') as f:
    buffer = f.read()
except IOError:
  print('Cannot open rush.txt')
  sys.exit(1)

data = buffer.split()

l = [ [[], [], []] for _ in range(61) ]

for i in range(len(data) // 3):
  n = int(data[0 + i * 3])
  if n < 14: continue
  b = data[1 + i * 3]
  c = b.count('x')
  s = set(b) - {'x'} - {'o'} - {'.'}
  if len(s) > 12: continue
  l[n][c].append(b)

for i in l:
  for j in i:
    if j: print(choice(j))

