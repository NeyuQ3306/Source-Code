import math


def nt(n):
    for i in range(2, math.isqrt(n)+1):
        if n%i == 0: return False

    return n>1

for t in range(int(input())):
    n = input()
    if(not nt(len(n))):
        print('NO')
        continue

    cnt = 0
    for i in n:
        if nt(int(i)): cnt += 1

    print('YES' if cnt > len(n) - cnt else 'NO')