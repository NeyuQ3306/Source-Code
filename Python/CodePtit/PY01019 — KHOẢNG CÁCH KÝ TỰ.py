for t in range(int(input())):
    s = input()
    t = s[::-1]

    ok = True
    for i in  range(1,len(s)):
        if abs(ord(s[i]) - ord(s[i-1])) != abs(ord(t[i]) - ord(t[i-1])):
            ok = False
            break

    print('YES' if ok else 'NO')