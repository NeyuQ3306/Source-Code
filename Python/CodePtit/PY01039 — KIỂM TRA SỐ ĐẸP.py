import sys
from collections import Counter

for t in range(int(input())):
    n = input()
    ok = True
    dem = Counter(n)
    # print(len(dem))

    if len(dem) > 2:
        print('NO')
        continue

    for i in range(len(n)-2):
        if n[i] != n[i+2]:
            ok = False
            break

    print('YES' if ok else 'NO')

