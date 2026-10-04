for t in range(int(input())):
    s = input()
    sumDigit = 0
    Alpha = ''

    for i in s:
        if i.isdigit():
            sumDigit += int(i)
        else:
            Alpha += i

    print(''.join(sorted(Alpha)) + str(sumDigit))