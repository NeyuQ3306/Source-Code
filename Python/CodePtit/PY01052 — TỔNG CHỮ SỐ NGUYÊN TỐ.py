import math


def nt(n):
    for i in range(2,math.isqrt(n)+1):
        if n%i == 0: return False

    return n>1

for t in range(int(input())):
    n = input()
    sumDigit = 0

    for i in n:
        sumDigit += int(i)

    print('YES' if nt(sumDigit) else 'NO')