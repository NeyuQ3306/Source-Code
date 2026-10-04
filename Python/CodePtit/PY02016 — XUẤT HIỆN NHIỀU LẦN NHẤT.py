from collections import Counter

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    tanSo = dict(Counter(sorted(a)))
    maxfre = -10**18

    for i in tanSo.values():
        maxfre = max(maxfre,i)

    if maxfre <= n//2: print('NO')
    else:
        for i, j in tanSo.items():
            if j == maxfre:
                print(i)
                break
