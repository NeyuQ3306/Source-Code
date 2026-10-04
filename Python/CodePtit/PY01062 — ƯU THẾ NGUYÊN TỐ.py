import math


def nt(n):
    for i in range(2,math.isqrt(n)+1):
        if n%i == 0: return False

    return n>1

def check(n):
    if not nt(len(n)): return False
    cnt = 0

    for i in n:
        if nt(int(i)): cnt += 1

    return cnt > len(n) - cnt

for _ in range(int(input())):
    n = input()
    print('YES' if check(n) else 'NO')