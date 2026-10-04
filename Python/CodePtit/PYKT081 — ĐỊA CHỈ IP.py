def okk(s):
    if not s.isdigit(): return False

    if int(s) >= 0 and int(s) <= 255:
        return True
    return False

for _ in range(int(input())):
    tok = list(input().split('.'))

    ok = True
    if len(tok) != 4: ok = False
    for i in tok:
        if not okk(i):
            ok = False
            break

    print('YES' if ok else 'NO')