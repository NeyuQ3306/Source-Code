import re

n = int(input())
mp = dict()

for i in range(n):
    s = input().lower()
    tok = re.split(r'[^a-z]', s)

    for word in tok:
        if len(word) == 0:
            continue

        mp[word] = mp.get(word,0) + 1

res = list(mp.items())
res.sort(key = lambda x : (-x[1],x[0]))
for i,j in res:
    print(i,j)
