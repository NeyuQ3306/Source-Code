import sys
def check(a):
    if a[0] == a[1] and a[1] == a[2] and a[2] == a[3]:
        return True
    return False

while True:
    a = list(map(int,input().split()))
    if sum(a) == 0: sys.exit()

    ans = 0
    while not check(a):
        # Chú ý phải giữ lại giá trị a[0] cho bước trừ của a[3]
        # Trừ đi a[0] mới sẽ bị sai
        tmp = a[0]
        a[0] = abs(a[0] - a[1])
        a[1] = abs(a[1] - a[2])
        a[2] = abs(a[2] - a[3])
        a[3] = abs(a[3] - tmp)
        ans += 1

    print(ans)