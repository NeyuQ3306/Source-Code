n,m = map(int,input().split())
a = set(map(int,input().split()))
b = set(map(int,input().split()))

print('YES' if len(a-b) == 0 else 'NO')