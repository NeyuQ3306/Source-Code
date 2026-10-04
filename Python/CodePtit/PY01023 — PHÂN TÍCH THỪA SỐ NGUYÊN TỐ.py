import math


def pttsnt(n):
    print('1',end='')
    for i in range(2,int(math.sqrt(n))+1):
        if n % i == 0:
            cnt = 0
            while n % i == 0:
                 cnt += 1
                 n //= i
            print(' * ',end='')
            print(f'{i}^{cnt}',end='')

    if n != 1: print(' * ' + f'{n}^1')
    print()


for t in range(int(input())):
    n = int(input())
    pttsnt(n)


