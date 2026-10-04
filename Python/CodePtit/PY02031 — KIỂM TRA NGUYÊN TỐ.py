import math


def nt(n):
    for i in range(2, int(math.isqrt(n))+1):
        if n%i == 0: return False
    return n > 1

n,m = map(int, input().split())
a = []

for i in range(n):
    tmp = list(map(int,input().split()))
    a.append(tmp)

for i in range(n):
    for j in range(m):
        if nt(a[i][j]):
            print(1,end = ' ')
        else:
            print(0,end = ' ')
    print()