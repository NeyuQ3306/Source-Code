from functools import cmp_to_key

def tongcs(n):
    res = 0
    while n != 0:
        res += n%10
        n //= 10
    return res

def cmp(a,b):
    if tongcs(a) != tongcs(b):
        return tongcs(a) - tongcs(b)
    else: return a - b

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    a.sort(key = cmp_to_key(cmp))
    for i in a:
        print(i,end=' ')
    print()