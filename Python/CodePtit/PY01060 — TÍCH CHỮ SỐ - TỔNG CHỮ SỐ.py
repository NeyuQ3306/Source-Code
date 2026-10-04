for t in range(int(input())):
    s = input()
    chan = s[0:len(s):2]
    le = s[1:len(s):2]

    sumLe = sum(map(int,le))
    mulChan = 1

    for i in range(len(chan)):
        if int(chan[i]) != 0:
            mulChan *= int(chan[i])

    print(mulChan,sumLe)