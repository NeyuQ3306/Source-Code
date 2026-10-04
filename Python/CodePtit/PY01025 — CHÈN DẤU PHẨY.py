s = input()
cnt = 0

res = ''
for i in range(len(s)-1,-1,-1):
    if cnt == 3:
        res += ','
        cnt = 0

    cnt += 1
    res += s[i]

print(res[::-1])
