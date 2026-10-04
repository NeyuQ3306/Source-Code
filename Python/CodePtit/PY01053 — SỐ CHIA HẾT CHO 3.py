for t in range(int(input())):
    n = input()
    sum = 0

    for i in n:
        sum += int(i)

    print('YES' if sum % 3 == 0 else 'NO')