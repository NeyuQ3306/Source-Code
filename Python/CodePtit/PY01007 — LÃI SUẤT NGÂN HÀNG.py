for t in range(int(input())):
    n,x,m = map(float,input().split())
    ans = 0

    while n < m:
        n += n*x/100
        ans += 1

    print(ans)