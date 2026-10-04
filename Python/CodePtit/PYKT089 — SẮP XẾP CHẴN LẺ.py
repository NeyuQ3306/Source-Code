import sys

n = int(input())
a = list(map(int,sys.stdin.read().split()))

chan,le = [],[]
for i in a:
    if i%2 == 0:
        chan.append(i)
    else:
        le.append(i)

chan.sort()
le.sort(reverse=True)

idxc,idxl = 0,0
for i in range(n):
    if a[i] % 2 == 0:
        print(chan[idxc],end=' ')
        idxc += 1
    else:
        print(le[idxl],end=' ')
        idxl += 1