for t in range(int(input())):
    s = input() + '#'
    ans = ''

    cnt = 1
    for i in range(1,len(s)):
        if s[i] != s[i-1]:
            ans += str(cnt) + s[i-1]
            cnt = 1
        else: cnt += 1
    print(ans)