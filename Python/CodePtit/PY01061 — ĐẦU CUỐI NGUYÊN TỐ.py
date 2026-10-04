import math


def nt(n):
    for i in range(2,math.isqrt(n)+1):
        if n%i == 0: return False

    return n>1

for _ in range(int(input())):
    n = input()
    print('YES' if nt(int(n[0:3])) and nt(int(n[len(n)-3:])) else 'NO')