for t in range(int(input())):
    s = input()
    head = int(s[0:2])
    tail = int(s[len(s)-2:len(s)])

    # print(head,tail)
    print('YES' if head == tail else 'NO')