def check(a,b):
    for i in range(len(a)):
        if a[i] > b[i]: return False
    return True

for _ in range(int(input())):
     n = input()
     a = list(map(int,input().split()))
     b = list(map(int,input().split()))

     print('YES' if check(sorted(a),sorted(b)) else 'NO')