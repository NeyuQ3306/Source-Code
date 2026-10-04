import math
from collections import Counter


def nt(n):
    for i in range(2,int(math.isqrt(n))+1):
        if n%i == 0:
            return False
    return n > 1

if __name__ == '__main__':
    n = int(input())
    a = list(map(int,input().split()))
    b = []

    for i in a:
        if nt(i):
            b.append(i)

    res = dict(Counter(b))
    for i,j in res.items():
        print(i,j)