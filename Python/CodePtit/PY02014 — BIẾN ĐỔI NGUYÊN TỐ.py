import math
import bisect

primes = [True] * 10**6

def sang():
    primes[0] = primes[1] = False
    for i in range(2,math.isqrt(10**6)+1):
        if primes[i]:
            for j in range(i*i,10**6,i):
                primes[j] = False


if __name__ == '__main__':
    sang()
    real_prime = [x for x in range(10 ** 6) if primes[x]]
    n = int(input())
    a = list(map(int,input().split()))

    ans = 0
    for i in a:
        idx = bisect.bisect_left(real_prime,i)
        if idx == 0:
            steps = real_prime[0] - i
        elif idx == len(real_prime):
            steps = i - real_prime[-1]
        else:
            steps = min(real_prime[idx] - i, i - real_prime[idx - 1])

        # Số bước ít nhất = số bước lớn nhất của 1 số a[i] cần để thành snt
        ans = max(ans, steps)
    print(ans)

