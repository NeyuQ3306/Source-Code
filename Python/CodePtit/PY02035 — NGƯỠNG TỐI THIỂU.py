from collections import Counter

s = input();
k = int(input())

a = []
for i in range(len(s)):
    if i%2 == 1: continue

    tmp = s[i:i+2]
    if len(tmp) == 2:
        a.append(tmp)

found = False
res = Counter(sorted(a))
for i,j in res.items():
    if j >= k:
        print(i,j)
        found = True

if not found: print('NOT FOUND')