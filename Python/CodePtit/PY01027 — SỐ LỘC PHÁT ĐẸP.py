s = input()
ok = True
cnt = 0

for i in s:
    if int(i) != 6 and int(i) != 8:
        ok = False
        break

    if int(i) == 8:
        cnt += 1
    else: cnt = 0

    if cnt == 3:
        ok = False
        break

print('YES' if ok else 'NO')