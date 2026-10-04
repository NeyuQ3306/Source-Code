n = int(input())
a = []

ans = 0
for i in range(n):
    a.append(list(input()))

tmp = []
for i in range(n):
    cnt = 0
    for j in a[i]:
        if j == 'C':
            cnt += 1

    if cnt > 1: tmp.append(cnt)

for j in range(n):
    cnt = 0
    for i in range(n):
        if a[i][j] == 'C':
            cnt += 1

    if cnt > 1: tmp.append(cnt)

for i in tmp:
    ans += i * (i-1) // 2

print(ans)

