for t in range(int(input())):
    s = input()
    n = int(s[len(s)-2:len(s)])

    print('YES' if n == 86 else 'NO')