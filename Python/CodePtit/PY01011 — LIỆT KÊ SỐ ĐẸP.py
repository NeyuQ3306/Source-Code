def check(s):
    for i in range(len(s)//2):
        if s[i] != s[len(s)-i-1]:
            return False
        if int(s[i]) % 2 == 1:
            return False;

    return len(s) % 2 == 0

for t in range(int(input())):
    s = input()
    for i in range(22,int(s),2):
        if check(str(i)):
            print(i,end=' ')

    print()