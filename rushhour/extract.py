import sys

try:
  with open('rush.txt', 'r') as f:
    buffer = f.read()
except IOError:
  print('Cannot open rush.txt')
  sys.exit(1)

data = buffer.split()

lmin = [[100] * 100, [100] * 100, [100] * 100]
bmin = [{}, {}, {}]

for i in range(len(data) // 3):
  n = int(data[0 + i * 3])
  b = data[1 + i * 3]
  c = b.count('x')
  s = set(b) - {'x'} - {'o'} - {'.'}
  l = len(s)
  if lmin[c][n] > l:
    lmin[c][n] = l
    bmin[c][n] = b

for i in range(7, 60):
  for j in range(3):
    if(lmin[j][i] < 13): print(bmin[j][i])
