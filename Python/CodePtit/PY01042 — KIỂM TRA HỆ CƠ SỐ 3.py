for t in range(int(input())):
    s = input()
    ok = True

    for i in s:
        if not i.isdigit():
            ok = False
            break

        if int(i) != 0 and int(i) != 1 and int(i) != 2:
            ok = False
            break

    print('YES' if ok else 'NO')