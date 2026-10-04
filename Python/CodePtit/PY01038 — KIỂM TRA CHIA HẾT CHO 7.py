
for t in range(int(input())):
    n = int(input())
    if n % 7 == 0: print(n)

    else:
        ans = -1
        for i in range(1000):
            n = int(int(n) + int(str(n)[::-1]))
            if n % 7 == 0:
                ans = n
                break

        print(ans)


