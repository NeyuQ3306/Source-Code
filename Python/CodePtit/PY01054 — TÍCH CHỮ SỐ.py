for t in range(int(input())):
    s = input()
    ans = 1

    for i in s:
        if int(i) != 0:
            ans *= int(i)

    print(ans)