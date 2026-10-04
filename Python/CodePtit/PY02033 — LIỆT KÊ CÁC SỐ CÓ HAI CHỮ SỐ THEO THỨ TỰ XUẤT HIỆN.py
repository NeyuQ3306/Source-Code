s = input()
thislist = []

idx = 0
while idx < len(s):
    if len(s[idx:idx+2]) > 1:
        thislist.append(s[idx:idx+2])
    idx += 2

res = list(dict.fromkeys(thislist))
for i in res:
    print(i,end=' ')