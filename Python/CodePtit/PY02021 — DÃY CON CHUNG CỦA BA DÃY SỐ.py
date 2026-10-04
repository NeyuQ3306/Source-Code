for _ in range(int(input())):
    n,m,k = map(int,input().split())
    a,b,c = list(map(int,input().split())), list(map(int,input().split())), list(map(int,input().split()))

    ab = []
    idxa, idxb = 0,0

    while idxa < n and idxb < m:
        if a[idxa] == b[idxb]:
            ab.append(a[idxa])
            idxa += 1
            idxb += 1
        elif a[idxa] < b[idxb]:
            idxa += 1
        else:
            idxb += 1

    res = []
    idxab, idxc = 0,0

    while idxab < len(ab) and idxc < k:
        if ab[idxab] == c[idxc]:
            res.append(ab[idxab])
            idxab += 1
            idxc += 1
        elif ab[idxab] < c[idxc]:
            idxab += 1
        else:
            idxc += 1

    if len(res) > 0:
        for i in res:
            print(i,end=' ')
        print()
    else:
        print('NO')

