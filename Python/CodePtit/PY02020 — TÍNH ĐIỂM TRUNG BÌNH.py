n = int(input())
a = list(map(float,input().split()))

a.sort()
b = []

for i in a:
    if i != a[0] and i != a[n-1]:
        b.append(i)

print('%.2f' % (sum(b) / len(b)))