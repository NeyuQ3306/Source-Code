for t in range(int(input())):
    s = input()
    chan = s[0:len(s):2]
    le = s[1:len(s):2]

    sumChan = sum(map(int,chan))
    mulLe = 1

    for i in range(1,len(s),2):
        if int(s[i]) != 0:
            mulLe *= int(s[i])

    print(sumChan, mulLe if mulLe != 1 else 0)