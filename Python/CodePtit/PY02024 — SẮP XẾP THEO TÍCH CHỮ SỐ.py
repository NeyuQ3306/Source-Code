from functools import cmp_to_key


def tichcs(n):
    res = 1
    while n != 0:
        res *= n%10
        n //= 10

    return res

def cmp(a,b):
    if tichcs(a) != tichcs(b):
        return tichcs(a) - tichcs(b)
    else:
        return a - b

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))

    a.sort(key=cmp_to_key(cmp))
    for i in a:
        print(i,end=' ')
    print()