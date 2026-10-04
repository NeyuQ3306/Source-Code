import math


def nt(n):
    for i in range(2,math.isqrt(n)+1):
        if n%i == 0: return False

    return n>1

def check(n):
    sumDigit = sum(map(int,n))

    for i in range(len(n)):
        if i%2 == 0 and int(n[i])%2 == 1: return False
        if i%2 == 1 and int(n[i])%2 == 0: return False

    return nt(sumDigit)

for t in range(int(input())):
    s = input()
    print('YES' if check(s) else 'NO')