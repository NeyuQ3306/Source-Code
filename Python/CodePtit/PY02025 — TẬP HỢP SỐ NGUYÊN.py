n,m = map(int,input().split())
a = set(map(int,input().split()))
b = set(map(int,input().split()))

for i in sorted(list(a&b)):
    print(i,end=' ')
print()

for i in sorted(list(a-b)):
    print(i,end=' ')
print()

for i in sorted(list(b-a)):
    print(i,end=' ')