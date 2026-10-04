from collections import Counter

n = int(input())
se = set(Counter(a))
a = list(se)

presum = []
presum[0] = a[0]
for i in range(1,len(b)):
    presum[i] = presum[i-1] + b