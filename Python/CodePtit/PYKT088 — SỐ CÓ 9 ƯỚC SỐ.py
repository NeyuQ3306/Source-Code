'''
1 số có đúng 9 ước nếu là 1 trong 2 trường hợp:
th1, n = p**8
th2, n = p**2 * q**2

-> Từ ct tính ước từ phân tích tsnt của 1 số n:
n = p1^e1 + p2^e2 + p3^e3 + ... + pn^en
Tổng ước = (e1+1)(e2+1)...(en+1)
'''
import math

# Ta sàng snt đến sqrt(n)
n = int(input())
limits = int(math.isqrt(n)) + 1
primes = [True] * limits

primes[0] = primes[1] = False
for i in range(2, int(math.isqrt(limits)) + 1):
    if primes[i]:
        for j in range(i * i, limits, i):
            primes[j] = False

real_primes = [x for x in range(len(primes)) if primes[x]]

ans = 0

# th1
for i in real_primes:
    if i ** 8 <= n: ans += 1
    else: break

#th2
for i in range(len(real_primes)):
    p = real_primes[i]
    if p**2 > n: break
    else:
        for j in range(i+1,len(real_primes)):
            q = real_primes[j]
            if p**2 * q**2 <= n: ans += 1
            else: break

print(ans)



