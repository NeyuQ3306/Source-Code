from collections import Counter

for _ in range(int(input())):
    n = int(input())

    a = []
    for i in range(n):
        a.append(int(input()))

    a.sort()
    mp = dict(Counter(a))
    maxfre = -10**18

    for i in mp.values():
        maxfre = max(maxfre,i)

    for key,value in mp.items():
        if value == maxfre:
            print(key)
            break