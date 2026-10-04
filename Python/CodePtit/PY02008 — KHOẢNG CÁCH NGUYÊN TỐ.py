import math

primes = [True] * 10**6

def sang():
    primes[0] = primes[1] = False
    for i in range(2,int(math.isqrt(10**6))+1):
        if primes[i]:
            for j in range(i*i,10**6,i):
                primes[j] = False


if __name__ == '__main__':
    sang()
    real_Prime = [x for x in range(2, 10 ** 6) if primes[x]]
    n,x = map(int,input().split())

    print(x,end=' ')
    for i in range(0,n):
        x += real_Prime[i]
        print(x,end=' ')

