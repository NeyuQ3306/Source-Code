import math


def nt(n):
    for i in range(2,math.isqrt(n)+1):
        if n%i == 0: return False
    return n>1

for t in range(int(input())):
    n = input()
    print('YES' if nt(int(n[len(n)-4:len(n)])) else 'NO')