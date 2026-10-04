n = int(input())
a = []


for i in range(n):
    a.append(list(map(int,input().split())))

k = int(input())
uppersum,lowersum =  0,0

for i in range(n):
    for j in range(n):
        if j>i:
            uppersum += a[i][j]

        if i>j:
            lowersum += a[i][j]

print('YES' if abs(uppersum - lowersum) <= k else 'NO')
print(abs(uppersum - lowersum))
