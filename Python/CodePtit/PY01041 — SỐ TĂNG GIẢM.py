for t in range(int(input())):
    n = input()

    ok = True
    if len(n) < 3:
        print('NO')
        continue

    idx = 0
    for i in range(1,len(n)):
        if n[i] == n[i-1]:
            ok = False
            break

        if n[i] < n[i-1]:
            idx = i-1
            break

    for i in range(idx,len(n)-1):
        if n[i] <= n[i+1]:
            ok = False
            break

    print('YES' if ok else 'NO')