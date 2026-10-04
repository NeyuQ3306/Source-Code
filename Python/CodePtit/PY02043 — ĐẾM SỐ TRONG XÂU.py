for _ in range(int(input())):
    s = input()
    n = input()

    ans = 0
    idx = 0
    n_len = len(n)

    while idx <= len(s) - n_len:
        if s[idx:idx + n_len] == n:
            ans += 1
            idx += n_len
        else:
            idx += 1

    print(ans)