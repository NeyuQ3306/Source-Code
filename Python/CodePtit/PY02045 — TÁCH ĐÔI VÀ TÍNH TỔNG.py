n = input()
while len(n) != 1:
    pos = len(n) // 2
    left = n[:pos]
    right = n[pos:]

    n = str(int(left) + int(right))
    print(n)