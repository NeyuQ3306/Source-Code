import sys
def solve():
    data = sys.stdin.read().split()
    if not data:
        return

    n = int(data[0])
    q = int(data[1])
    diff = [0] * (n+2)
    idx = 2
    for _ in range(q):
        x = int(data[idx])
        y = int(data[idx+1])
        idx += 2
        diff[x] += 1
        diff[y+1] -= 1

    ans = []
    cur = 0
    for i in range(1,n+1):
        cur += diff[i]
        if cur % 2 == 0:
            ans.append(0)
        else:
            ans.append(1)

    print(*(ans))

if __name__ == '__main__':
    solve()
