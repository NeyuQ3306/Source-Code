from collections import Counter

s = input()
thislist = []

idx = 0
while idx < len(s):
    if len(s[idx:idx+2]) > 1:
        thislist.append(s[idx:idx+2])
    idx += 2

res = Counter(thislist)
for i,j in res.items():
    print(i,j)