mod = 10**9 + 7
m,d = map(int,input().split())
a,b = input().split()

def solve(s):
    n = len(s)
    dp = [[0] * 2 for _ in range(m)]
    dp[0][1] = 1

    for pos in range(n):
        ndp = [[0] * 2 for _ in range(m)]
        for rem in range(m):
            for tight in range(2):

                if dp[rem][tight] == 0:
                    continue
                limit = int(s[pos]) if tight else 9
                for digit in range(limit+1):
                    if pos == 0 and digit == 0:
                        continue
                    vt = pos + 1
                    if vt % 2 == 0:
                        if digit != d:
                            continue
                    else:
                        if digit == d:
                            continue
                    new_rem = (rem*10 + digit) % m
                    if tight == 1 and digit == limit:
                        new_tight = 1
                    else:
                        new_tight = 0

                    ndp[new_rem][new_tight] += dp[rem][tight]
                    ndp[new_rem][new_tight] %= mod

        dp = ndp
    return (dp[0][0] + dp[0][1]) % mod

def sub_one(s):
    a = list(s)
    i = len(a) - 1

    while i >= 0 and a[i] == '0':
        a[i] = '9'
        i -= 1
    if i >= 0:
        a[i] = str(int(a[i]) - 1)

    res = ''.join(a).lstrip('0')
    if res == '':
        return '0'
    return res

ans = solve(b) - solve(sub_one(a))
ans %= mod
print(ans)