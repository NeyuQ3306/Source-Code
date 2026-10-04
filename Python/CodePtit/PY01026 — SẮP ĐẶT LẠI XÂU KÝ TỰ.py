cnt = 0
for _ in range(int(input())):
    cnt += 1
    s,t = input(),input()
    print('Test %d:' % (cnt),end=' ')
    print('YES' if sorted(s) == sorted(t) else 'NO')