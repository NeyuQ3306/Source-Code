n = int(input())
a = []

for _ in range(n):
    s = input().strip()
    cur = ""

    for c in s:
        if c.isdigit():
            cur += c
        else:
            if cur:
                a.append(int(cur))
                cur = ""

    if cur:
        a.append(int(cur))
a.sort()
for x in a:
    print(x)