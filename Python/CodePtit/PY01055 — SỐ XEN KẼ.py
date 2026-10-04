def check(n):
    if len(n)%2 == 0: return False
    if n[0] == n[1]: return False

    for i in range(2,len(n),2):
        if n[i] != n[0]: return False

    return True

for t in range(int(input())):
    s = input()
    print('YES' if check(s) else 'NO')
