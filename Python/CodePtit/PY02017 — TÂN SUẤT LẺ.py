from collections import Counter

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    mp = dict(Counter(a))
    for i,j in mp.items():
        if j%2 == 1:
            print(i)
            break