p = list('ABCDEFGHIJKLMNOPQRSTUVWXYZ_.')

while True:
    s = input()
    if int(s[0]) == 0: break

    a,b = s.split()
    a = int(a)

    res = ''
    for i in range(len(b)):
        idx = p.index(b[i])
        res += p[(idx+a) % 28]

    print(res[::-1])