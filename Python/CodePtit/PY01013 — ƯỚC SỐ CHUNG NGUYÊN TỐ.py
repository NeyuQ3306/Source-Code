import math


def nt(n):
    for i in range(2,math.isqrt(n)+1):
        if n%i==0: return False

    return n>1

def check(n):
    res = 0
    while n!=0:
        res += n%10
        n //= 10

    return nt(res)

if __name__ == '__main__':
    for t in range(int(input())):
        a,b = map(int,input().split())
        uc = math.gcd(a,b)
        print('YES' if check(uc) else 'NO')


