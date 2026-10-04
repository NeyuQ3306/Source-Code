def check(n):
    if n != n[::-1]: return False
    if len(n) % 2 == 1: return False

    for i in n:
        if int(i) % 2 == 1:
            return False

    return True

for t in range(int(input())):
    n = input()
    for i in range(10,int(n),2):
        if check(str(i)):
            print(i,end=' ')


    print()
