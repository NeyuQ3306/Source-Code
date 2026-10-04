def check(s):
    sum = int(s[0])
    for i in range(1,len(s)):
        sum += int(s[i])
        if abs(int(s[i]) - int(s[i-1])) != 2:
            return False

    return sum % 10 == 0

for t in range(int(input())):
    s = input()
    print('YES' if check(s) else 'NO')
