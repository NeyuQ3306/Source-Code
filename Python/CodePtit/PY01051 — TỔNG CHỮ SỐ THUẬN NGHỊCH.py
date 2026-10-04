def tn(n):
    if len(n) <= 1: return False
    if n != n[::-1]: return False

    return True

for t in range(int(input())):
    s = input()
    sumDigit = 0

    for i in s:
        sumDigit += int(i)

    print('YES' if tn(str(sumDigit)) else 'NO')