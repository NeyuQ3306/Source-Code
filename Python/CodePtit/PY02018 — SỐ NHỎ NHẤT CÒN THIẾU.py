import sys

n = int(input())
a = list(map(int,input().split()))

st = set(a)
i = 1
while True:
    if not i in st:
        print(i)
        sys.exit()
    i += 1

print(n+1)