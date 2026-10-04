Fibo = [0] * 93

def sinh():
    Fibo[0] = 0
    Fibo[1] = 1

    for i in range(2,93):
        Fibo[i] = Fibo[i-2] + Fibo[i-1]

def main():
    sinh()
    for _ in range(int(input())):
        a,b = map(int,input().split())
        for i in range(a,b+1):
            print(Fibo[i],end=' ')
        print()

if __name__ == '__main__':
    main()