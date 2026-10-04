n = int(input())
cnt = 0

while n != 0:
    if n%10 == 4 or n%10 == 7: cnt += 1
    n //= 10

print('YES' if (cnt == 4 or cnt == 7) else 'NO')