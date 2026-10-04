n = int(input())
res = []

for _ in range(n):
    s = input() + "#"
    digit = -1

    for i in range(len(s)):
        if s[i].isdigit():
            if digit == -1:
                digit = int(s[i])
            else:
                digit *= 10
                digit += int(s[i])
        else:
            if digit != -1:
                res.append(digit)
                digit = -1

res.sort()
for i in res:
    print(i)