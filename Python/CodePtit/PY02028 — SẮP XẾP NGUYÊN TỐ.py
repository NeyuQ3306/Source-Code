import math


def nt(n):
    for i in range(2,int(math.isqrt(n))+1):
        if n%i == 0:
            return False
    return n>1

n = int(input())
a = list(map(int,input().split()))

prime = []
for i in a:
    if nt(i):
        prime.append(i)

prime.sort()
idx = 0
for i in a:
    if not nt(i):
        print(i,end=' ')
    else:
        print(prime[idx],end=' ')
        idx += 1
        