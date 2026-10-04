n = int(input())
a = list(input().split())

ans = 0
for i in range(1,n):
    if a[i] != a[i-1]: ans += 1

print(ans)