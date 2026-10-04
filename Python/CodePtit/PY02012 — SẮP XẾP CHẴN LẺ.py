import sys

n = int(input())
# Chú ý input bài này có thể nằm trên nhiều dòng
bdau = list(map(int,sys.stdin.read().split()))

chan,le = [], []

for i in bdau:
    if i%2 == 0: chan.append(i)
    else: le.append(i)

chan.sort()
le.sort(reverse=True)

idxc, idxl = 0, 0
for i in range(n):
    if bdau[i] % 2 == 0:
        print(chan[idxc],end=' ')
        idxc += 1
    else:
        print(le[idxl],end=' ')
        idxl += 1

