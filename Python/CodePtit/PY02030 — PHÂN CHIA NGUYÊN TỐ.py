import math
import sys


def nt(n):
    for i in range(2,int(math.isqrt(n))+1):
        if n%i == 0:
            return False
    return n > 1

n = int(input())

# ko dùng set được vì set mất thứ tự ban đầu
# dùng dict.fromkeys(iterable,defaultvalue: mặc định = None)
a = list(dict.fromkeys(map(int,input().split())))

presum = [0] * len(a)
presum[0] = a[0]

for i in range(1,len(a)):
    presum[i] = presum[i-1] + a[i]

total_sum = sum(a)
for i in range(len(a)):
    if nt(presum[i]) and nt(total_sum - presum[i]):
        print(i)
        sys.exit()

print('NOT FOUND')