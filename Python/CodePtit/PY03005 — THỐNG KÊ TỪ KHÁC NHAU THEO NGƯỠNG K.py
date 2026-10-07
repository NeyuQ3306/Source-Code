import re

n,k = map(int,input().split())
mp = dict()

for i in range(n):
    s = input().lower()
    tok = re.split(r'[^a-z0-9]',s)

    for word in tok:
        if len(word) == 0: continue
        else: mp[word] = mp.get(word,0) + 1

res = []
for key,value in mp.items():
    if value >= k:
        res.append((key,value))

res.sort(key = lambda x : (-x[1],x[0]))
for i,j in res:
    print(i,j)